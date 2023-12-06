<br><img src="robot.png" style="height:600px:>

# TechTreat Trailblazer

Georgia Institute of Technology ECE 4180 Final Project

Team Members: Chanel Gautama, Gayoung Nam, Jeremy Chen

## Description

TechTreat Trailblazer is a bluetooth-controlled pet feeder robot that dispenses food, drive around and play with your pets.
The main functionalities are:
  - Move forward, backward, and make left/right turns
  - A ultrasonic sensor prevents the robot from crashing to objects
  - Dispenses pet food
  - Honk and display a mini light show

## List of Components
  - Mbed
  - 4 DC Motors
  - 4 Wheels
  - H-Bridge
  - Ultrasonic Sensor (HC-SR04)
  - Speaker
  - Power Amplifier
  - LED
  - RC Servo
  - Solenoid [TODO]: Delete??
  - MOSFET Driver Motor [TODO]: Delete??
  - Adafruit Bluetooth Module
  - 2 5V External Power Supplies
  - Metal Plate
  - Breadboard
  - Jumper Wires
  - Plastic water bottles
  - Cardboard

## Mbed Components Pinouts
[TODO]: Make sure the pins are correct

 H-Bridge and Motors
 
 |  H-Bridge  |  Mbed  |  Right Motor  |  Left Motor  |  Battery Pack  |
 |------------|--------|---------------|--------------|----------------|
 |     VM     |        |               |              |        +       |
 |    VCC     |  VOUT  |               |              |                |
 |    GND     |   GND  |               |              |        -       |
 |    STBY    |  VOUT  |               |              |                |
 |    PWMA    |   p22  |               |              |                |
 |    AIN1    |   p13  |               |              |                |
 |    AIN2    |   p12  |               |              |                |
 |    AO1     |        |       +       |              |                |
 |    AO2     |        |       -       |              |                |
 |    PWMA    |   p21  |               |              |                |
 |    AIN1    |   p11  |               |              |                |
 |    AIN2    |   p8   |               |              |                |
 |    AO1     |        |               |       +      |                |
 |    AO2     |        |               |       -      |                |
 
 Ultrasonic Sensor
 
 |  Mbed    |   HC-SR04   |
 |----------|-------------|
 |  Vu(5V)  |     Vcc     |
 |   Gnd    |     Gnd     |
 |    p6    |     trig    |
 |    p7    |     echo    |
 
 Power Amplifier and Speaker
 
 |  Mbed   |  Class D Audio Amp  | Speaker | External Battery |
 |---------|---------------------|---------|------------------|
 |   GND   |     PWR, IN-        |         |                  |
 |         |       PWR+          |         |        5V        |
 |   p18   |        IN+          |         |                  |
 |         |       OUT+          |    +    |                  |
 |         |       OUT-          |    -    |                  |

 LED
 |          Mbed         |   LED   |
 |-----------------------|---------|
 |          gnd          |    +    |
 |          GND          |    -    |
 

 RC Servo
 |  Mbed   |       servo      | External Battery |
 |---------|------------------|------------------|
 |   GND   |        Gnd       |       Gnd        |
 |         |       Power      |        5V        |
 |   p18   | PWM Signal Input |                  |


 Solenoid [TODO]: Delete??

 MOSFET Driver [TODO]: Delete??

 Adafruit Bluetooth
 |          Mbed         |   Adafruit BLE   |
 |-----------------------|------------------|
 |          gnd          |        gnd       |
 |          Vu           |        Vin       |
 |          nc           |        RTS       |
 |          gnd          |        CTS       |
 |     p27 (Serial RX)   |        TXO       |
 |     p28 (Serial TX)   |        RXI       |


## Wiring Diagram
[TODO]: Include a schematic here

## Mbed Code
The entire code for this robot can be found at ().
