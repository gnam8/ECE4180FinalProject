#include "mbed.h"
#include "Motor.h"
#include "ultrasonic.h"
#include "SDFileSystem.h"
#include "wave_player.h"
#include "SongPlayer.h"
#include "Servo.h"

Motor motorA(p21, p5, p6); // pwm, fwd, rev
Motor motorB(p22, p7, p8); // pwm, fwd, rev
Serial blue(p28,p27); // bluetooth
DigitalOut myled(LED1); //testing LED
DigitalOut redLED(p30);  //external LED on and OFF
DigitalOut Ctrl(p18); //Solenoid output control bit
PwmOut PWM (p26); // pwm for speaker
Servo myservo(p24); //pwm for servo
// SDFileSystem sd(p11, p12, p13, p14, "sd"); //SD card
// AnalogOut DACout(p18);
// wave_player waver(&DACout);

volatile bool button_ready = 0;
volatile int  bnum = 0;
volatile int  bhit  ;
// state used to remember previous characters read in a button message
enum statetype {start = 0, got_exclm, got_B, got_num, got_hit};
statetype state = start;

void dist(int distance)
{
    printf("Distance %d mm\r\n", distance);
}
ultrasonic mu(p15, p16, .1, 1, &dist); // ultrasonic range finder

float note[1]= {400.0};
float duration[1]= {0.20};

//movement commands
void forward() {
    motorA.speed(1.0);
    motorB.speed(1.0);
}
void backward() {
    motorA.speed(-1.0);
    motorB.speed(-1.0);
}
void left() {
    motorA.speed(1.0);
    motorB.speed(-1.0);
}
void right() {
    motorA.speed(-1.0);
    motorB.speed(1.0);
}
void stop() {
    motorA.speed(0);
    motorB.speed(0);
}

//Interrupt routine to parse message with one new character per serial RX interrupt
void parse_message()
{
    switch (state) {
        case start:
            if (blue.getc()=='!') state = got_exclm;
            else state = start;
            break;
        case got_exclm:
            if (blue.getc() == 'B') state = got_B;
            else state = start;
            break;
        case got_B:
            bnum = blue.getc();
            state = got_num;
            break;
        case got_num:
            bhit = blue.getc();
            state = got_hit;
            break;
        case got_hit:
            if (blue.getc() == char(~('!' + 'B' + bnum + bhit))) button_ready = 1;
            state = start;
            break;
        default:
            blue.getc();
            state = start;
    }
}


int main() {
    mu.startUpdates();
    blue.attach(&parse_message,Serial::RxIrq);
    SongPlayer mySpeaker(p26);
    while(1) {
        mu.checkDistance();
        if (mu.getCurrentDistance() < 100)
            stop();
        if (button_ready) {
            switch (bnum) {
                case '1': // '1' button, car horn
                    if (bhit=='1'){
                        mySpeaker.PlaySong(note, duration);
                    }
                    break;                       
                case '2': // servo
                    if (bhit == '1') {
                        myservo = 0;
                    } else {
                        myservo = 1;
                    }
                    break;
                case '3': // solenoid
                    if (bhit == '1') {
                        Ctrl = 1; //ON
                    } else {
                        Ctrl = 0; //OFF
                    }
                    break;
                case '4': //red led
                    if (bhit == '1') {
                        redLED = 0; //ON
                    } else {
                        redLED = 1; //OFF
                    }
                    break;
                case '5': // up arrow
                    if (bhit=='1') {
                        if (mu.getCurrentDistance() > 100) {
                            forward();
                        }
                    } else {
                        stop();
                    }
                    break;
                case '6': // down arrow
                    if (bhit=='1') {
                        backward();
                    } else {
                        stop();
                    }
                    break;
                case '7': // left arrow
                    if (bhit=='1') {
                        left();
                    } else {
                        stop();
                    }
                    break;
                case '8': // right arrow
                    if (bhit=='1') {
                        right();
                    } else {
                        stop();
                    }
                    break;
                default:
                    break;
            }
        }
    }
}