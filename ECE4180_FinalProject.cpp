#include "mbed.h"
#include "rtos.h"
#include "Servo.h"
//***** fix the pin numbers***
//calibrate the servos first before moving it
// Sweep the motor speed from full-speed reverse (-1.0) to full speed forwards (1.0)

#include "mbed.h"
#include "Motor.h"
#include "rtos.h"
DigitalOut led(LED1);
Thread thread;
Motor left_motor(p23, p6, p5); // pwm, fwd, rev
Motor right_motor(p24, p11, p12);
Servo clawServo1(p21);
Servo clawServo2(p22);
Servo armServo(p25);
Serial  blue(p28,p27);
float left_motorSpeed = 0.0;
float right_motorSpeed = 0.0;
volatile int closed = 2;
volatile bool alreadyClosed = true;
volatile int armDown = 2;
volatile bool armAlready = true;
float offset = 0.1;
//5 = fwd, 6 = rev, 7 = left, 8 = right, 0 = stop
volatile int direction = 0;
Mutex drive;
void drive_car(void const *args){
    while(1){
        drive.lock();
        if(direction == 5) {
            left_motor.speed(1);
            right_motor.speed(1);
        } else if(direction == 6) {
            left_motor.speed(-1);
            right_motor.speed(-1);
        } else if(direction == 7) {
            left_motor.speed(1);
            right_motor.speed(-1);
        } else if(direction == 8) {
            left_motor.speed(-1);
            right_motor.speed(1);
        } else if(direction == 0){
            left_motor.speed(0.0);
            right_motor.speed(0.0);        
        }
        drive.unlock();
    }
}
//
void move_arm(void const *args) {
    while(1){
        //for raising the arm
        if(armDown == 1 && armAlready) {
            for(float p = 5; p > 0; p -= 1){
                armServo = armServo + offset;
                Thread::wait(50);
            }
            armAlready = false;
        } else if(armDown == 0 && !armAlready) {
            for(float p = 5; p > 0; p -= 1){
                armServo = armServo - offset;
                Thread::wait(50);
            }
            armAlready = true;    
        }
    }    
}
void move_claw(void const *args) {
    while(1){
        //open the claw
        if(closed == 1 && alreadyClosed){
            for(float p = 5; p > 0; p -= 1){
                clawServo2 = clawServo2 - offset;
                clawServo1 = clawServo1 + offset;
                Thread::wait(50);
            }
            alreadyClosed = false;
        //closes the claw
        } else if(closed == 0 && !alreadyClosed) {
            for(float p = 5; p > 0; p -=1) {
                clawServo2 = clawServo2 + offset;
                clawServo1 = clawServo1 - offset;    
                Thread::wait(50);
            }
            alreadyClosed = true; 
        }
    }    
}
int main() {
    led = 0;
    clawServo1 = 0.5;
    clawServo2 = 0.6;
    armServo = 0.0;
    char bnum=0;
    char bhit=0;
    Thread thread1(drive_car);
    Thread thread2(move_claw);
    Thread thread3(move_arm);
    while(1) {
        if (blue.readable() && blue.getc()=='!') {
            if (blue.getc()=='B') { //button data packet
                bnum = blue.getc(); //button number
                bhit = blue.getc(); //1=hit, 0=release
                    switch (bnum) {
                        //open the claw
                        case '1': //number button 1 && to close the claw
                            if (bhit=='1') {
                                closed = 1;
                                //add hit code here
                            } 
                            break;
                        //close the claw
                        case '2': //number button 2
                            if (bhit=='1') {
                                closed = 0;
                                //add hit code here
                            } 
                            break;
                        case '3': //number button 3
                            if (bhit=='1') {
                                armDown = 1;
                            } 
                            break;
                        case '4': //number button 4
                            if (bhit=='1') {
                                armDown = 0;
                            } 
                            break;
                        case '5': //button 5 up arrow
                            if (bhit=='1') {
                                direction = 5; 
                            } else {
                                direction = 0;
                            }
                            break;
                        case '6': //button 6 down arrow
                            if (bhit=='1') {
                                led = 1;
                                direction = 6;
                            } else {
                                led = 0;
                                direction = 0;
                            }
                            break;
                        case '7': //button 7 left arrow
                            if (bhit=='1') {
                                led = 1;
                                direction = 7;
                            } else {
                                led = 0;
                                direction = 0;
                            }
                            break;
                        case '8': //button 8 right arrow
                            if (bhit=='1') {
                                led = 1;
                                direction = 8;
                            } else {
                                led = 0;
                                direction = 0;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
    }
}