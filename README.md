# ECE 4180 - Spring 2021 - Final Project
### Project Members: Eunsan Mo, Peiqi Zhao, Jason Au, Pooja Prabakaran  

<br/>

## Overview

The YeeeetScooper Robot connects to a phone using the Bluefruit app. The app uses a bluetooth connection to control the direction of the robot’s motion, the opening and closing of the scoop, and the lifting and lowering of the scoop. The arm connects to a scoop to pick up tiny objects and trash such as paper. The scoop can open approximately 180 degrees to dumb the trash into a trashcan. 
<br/> <br/>
The project was inspired by intelligent, recycling robots. There is great potential for the advancement of this technology in waste management, such as the addition of neural networks so that robots may clean streets and buildings.
<br/><br/>  
Click for quick link to demo video:
<br/>
[![4180 Demo Video](https://user-images.githubusercontent.com/72982370/116843088-db7c1980-abac-11eb-97d6-28799c1b5da6.jpg)](https://youtu.be/hyVIhcKYEOI "4180 Demo Video")
## Design
### Components
- Mbed
- Sparkfun vehicle chassis
- 2 DC motors 
- 3 servos
- 2 Wheels 
- Dual H bridge
- Bluetooth module
- Mechanical gears
- 2 5V Battery packs
<br/><br/>  

### 3D Printed Parts
In addition to assembling the chassis of the robot using the Sparkfun kit, the team needed to 3D print parts to build the robot. Prior to this project, the team did not have any experience in 3D CAD, and so a member had to learn how to use Autodesk's Fusion 360 software. Refer to the 3d_print_files folder for the raw files.
<br/> <br/> 
The following parts were 3D printed and attached to the robot with screws and glue.
<br/> <br/> 
The scoop: 
<br/> 
![2021-05-03-00-05-56](https://user-images.githubusercontent.com/72982370/116842997-850edb00-abac-11eb-99da-4061e67026a1.png)

<br/> <br/> 
The frame for the servos that open and close the scoop:
<br/> 
![2021-05-03-00-06-40](https://user-images.githubusercontent.com/72982370/116843037-a8d22100-abac-11eb-8204-949f75b329f0.png)

<br/> <br/> 
A support and connector to the chassis for the large servo that moves the scoop arm up and dowm: 
<br/> 
![2021-05-03-00-07-24](https://user-images.githubusercontent.com/72982370/116843049-b7b8d380-abac-11eb-8b4b-2f8843206fd7.png)

<br/> <br/> 
The arm for the scoop with a triangular support: 
<br/> 
![armBeam2](https://user-images.githubusercontent.com/72982370/116843062-c0a9a500-abac-11eb-8f6b-0fdb5508259f.png)
<br/><br/> <br/> 
### Wiring
**INSERT DIAGRAM + WIRING TABLE**
<br/><br/> 
## Implementation
The design process involved finding suitable components, CAD design, embedded systems wiring, microcontroller programming, testing, and debugging. Most of the components were available for check out from the 4180 lab or already in the Mbed and Sparkfun kit. However as mentioned in the section above, the scoop, scoop's servo frame, arm's servo connector, and arm had to be designed in Fusion 360 and 3D printed. The components were assembled by attaching parts with screws, glue, and tape.
<br/>
A real time operating system(RTOS) was used for precise motor control and quick responses to user inputs. Testing was done in stages. First, the left and right DC wheel motors were tested independently with sample code. Then, it was integrated with the Bluefruit connect app so that a user could control the movement of the wheels from their phone. Afterwards, the servos were tested with code that would move the arms up and down, and also open and close the scoop claws. Finally, all the functions were combined in threads to drive the car, move the claw (scoop), and move the arm. Refer to ECE4180_FinalProject.cpp for the complete code.
<br/> <br/>
Under demos, there is a video of the Bluefruit Connect App's buttons, and here are the corresponding movements:
<br/>
    - Up arrow: Forward
 <br/>
    - Down arrow: Backward
 <br/>
    - Right arrow: Turn Right
 <br/>
    - Left arrow: Turn Left
 <br/>
    - Button (1): Open Scoop
 <br/>
    - Button (2): Close Scoop
 <br/>
    - Button (3): Lift Arm
 <br/>
    - Button (4): Lower Arm
<br/>

## Demo
Click for the demo video: 
<br/> 
[![4180 Demo Video](https://user-images.githubusercontent.com/72982370/116843088-db7c1980-abac-11eb-97d6-28799c1b5da6.jpg)](https://youtu.be/hyVIhcKYEOI "4180 Demo Video")
<br/> 
Click for Bluetooth Module control video:
<br/>  
[![Bluefruit Connect](https://user-images.githubusercontent.com/72982370/116843238-57766180-abad-11eb-9e3e-bdb7fb5f7dd9.png)](https://youtu.be/8H74jWEbRB8 "Bluefruit Connect")
<br/><br/> 
To setup the device you first need to do the following:

1. Download the code 'ECE4180_FinalProject.cpp' onto the Mbed via USB. 
2. Download the Bluefruit Connect app onto your phone.
3. Power the Mbed by connecting to the 5V external power supply. 
4. Power the servos and motors by connecting to the second 5 V battery pack.
5. Pair the Bluefruit connect app with the bluetooth module.
6. Move the robot according to these directions
    - Up arrow: Forward
    - Down arrow: Backward
    - Right arrow: Turn Right
    - Left arrow: Turn Left
    - Button (1): Open Scoop
    - Button (2): Close Scoop
    - Button (3): Lift Arm
    - Button (4): Lower Arm
<br/><br/>  

## Future Work
The robot could be improved by adding sound effects and LEDs to indicate when the trash is picked up and dropped. Another possible modification is the capability to control the speed of the forward and backward motion. An advanced imporvement would be deep learning, neural networks, and computer vision so that the robot could be autonomous and identify trash and pick it up.
