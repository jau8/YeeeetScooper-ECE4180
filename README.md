# ECE 4180 - Spring 2021 - Final Project
### Project Members: 
\nEunsan Mo
\nPeiqi Zhao
\nJason Au
\nPooja Prabakaran  

<br/>

## Overview

The YeeeetScooper Robot connects to a phone using the Bluefruit app. The app uses a bluetooth connection to control the direction of the robot’s motion, the opening and closing of the scoop, and the lifting and lowering of the scoop. The arm connects to a scoop to pick up tiny objects and trash such as paper. The scoop can open approximately 180 degrees to dump the trash into a trashcan. 
<br/> <br/>
The project was inspired by intelligent, recycling robots. There is great potential for the advancement of this technology in waste management, such as the addition of neural networks so that robots may clean streets and buildings.
<br/><br/>  

![](https://user-images.githubusercontent.com/72982370/116879828-29197600-abef-11eb-91e4-8b08333e0f76.png)
<br/>
## Design
### Components
- Mbed LPC1768
- Sparkfun vehicle chassis
- 2 DC motors 
- 3 servos
- 2 Wheels 
- Dual H bridge L293D
- Adafruit Bluefruit LE UART Bluetooth Low Energy (BLE)
- Mechanical gears
- 2 5V Battery packs
- External power supply jacks
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
The scoop's servo frame (these servos will open and close the scoop):
<br/> 
![2021-05-03-00-06-40](https://user-images.githubusercontent.com/72982370/116843037-a8d22100-abac-11eb-8204-949f75b329f0.png)

<br/> <br/> 
Arm's servo connector (a support connecting the chassis and the large servo that moves the scoop arm up and down): 
<br/> 
![2021-05-03-00-07-24](https://user-images.githubusercontent.com/72982370/116843049-b7b8d380-abac-11eb-8b4b-2f8843206fd7.png)

<br/> <br/> 
The arm for the scoop with a triangular support: 
<br/> 
![armBeam2](https://user-images.githubusercontent.com/72982370/116843062-c0a9a500-abac-11eb-8f6b-0fdb5508259f.png)
<br/><br/> <br/> 
### Wiring
The following image shows the design schematic and wiring of the motors, portable battery, battery pack, mbed, H-bridge, Adafruit Bluetooth module, and servos:
![](https://user-images.githubusercontent.com/72982370/116879723-fcfdf500-abee-11eb-87d3-c920c43e5931.png)
<br/><br/><br/><br/> 
Here is the wiring for the dual H-bridge:
![](https://user-images.githubusercontent.com/72982370/116844547-5f380500-abb1-11eb-8da4-c900aee2abc3.png)
<br/><br/> <br/><br/> 
Here is the wiring table for the Adafruit Bluetooth module:
![](https://user-images.githubusercontent.com/72982370/116844684-c5bd2300-abb1-11eb-8ba8-ac845fefd1fa.png)

<br/><br/> <br/><br/> 
## Hardware Setup
Follow the steps below to assemble the robot. Here are a couple images with different views for reference.
<br/>
Top view:
<br/>
![](https://user-images.githubusercontent.com/72982370/116887243-15bed880-abf8-11eb-9326-22913b578427.png)
<br/>
Breadboard:
<br/>
![](https://user-images.githubusercontent.com/72982370/116887320-2d965c80-abf8-11eb-9af4-325afd3d4f2e.png)
<br/>
Side view:
<br/>
![](https://user-images.githubusercontent.com/72982370/116887426-4b63c180-abf8-11eb-8ab7-06f0dd7672f2.png)

<br/><br/> <br/>
### Mbed
1.	On a breadboard, insert an mbed, dual H-bridge L293D, Adafruit Bluefruit (BLE) module, and external power supply jacks.  
2.	Complete the wiring as described in the wiring section.
<br/><br/>

### Robot Chassis
1.	Assemble the robot’s frame with the Sparkfun kit. There are no screws needed in this step as the pieces snap in place.
2.	Attach the two wheels.
<br/> <br/> 
### 3D printing
1.	Create designs for the scoop, scoop's servo frame, arm's servo connector, and arm. The project files are available under the 3d_print_files folder.
2.	3D print the parts.
3.	Sand the inner edges of the scoop’s claw so that the edges close together smoothly.
4.	Using screws and glue, attach the scoop’s handles to the scoop’s servo frame.
5.	On the arm for the scoop with a triangular support, drill a tiny hole for a screw at the end of the bottom base of the triangle’s lower extension. With a screw, attach the arm to the scoop’s servo frame.
6.	Add glue as reinforcement wherever needed.
<br/> <br/> 
### Motors and Servos
1.	Attach the 2 DC motors to the wheels and wire it up to the H-bridge.
2.	Find tiny screws that fit in the right and left claw servos. Drill holes according to its size in the frame for the servos that open and close the scoop. Using the screws, attach the right and left claw servos to the frame.
3.	Attach the large arm servo to the 3D printed arm with screws.
4.	Screw down the large arm servo into its rectangular support.
<br/> <br/> 
### Integration
1.	Put the breadboard on the back of the car and secure it with tape.
2.	Under the surface of the car, insert a battery pack and secure it with tape.
3.	On the surface of the car, secure an external power supply and secure it with tape.
4.	Screw down the large arm servo’s rectangular support and 3d printed arm onto the chassis.
5.	Connect the power 
<br/><br/> <br/>
## Implementation
The design process involved finding suitable components, CAD design, embedded systems wiring, microcontroller programming, testing, and debugging. Most of the components were available for check out from the 4180 lab or already in the Mbed and Sparkfun kit. However as mentioned in the section above, the scoop, scoop's servo frame, arm's servo connector, and arm had to be designed in Fusion 360 and 3D printed. The components were assembled by attaching parts with screws, glue, and tape.
<br/> <br/>
A real time operating system(RTOS) was used for precise motor control and quick responses to user inputs. Testing was done in stages. First, the left and right DC wheel motors were tested independently with sample code. Then, it was integrated with the Bluefruit connect app so that a user could control the movement of the wheels from their phone. Afterwards, the servos were tested with code that would move the arms up and down, and also open and close the scoop claws. Finally, all the functions were combined in threads to drive the car, move the claw (scoop), and move the arm. Refer to ECE4180_FinalProject.cpp for the complete code.
<br/> <br/>
Here are the corresponding movements to the Bluefruit Connect App's buttons.
<br/><br/>
![](https://user-images.githubusercontent.com/72982370/116894300-e318de00-abff-11eb-8437-33f214eed1cb.png)
<br/><br/>
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
[![4180 Demo Video](https://user-images.githubusercontent.com/72982370/116843088-db7c1980-abac-11eb-97d6-28799c1b5da6.jpg)](https://www.youtube.com/watch?v=gscUUBd-H84 "4180 Demo Video")
<br/> 
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
The robot could be improved by adding sound effects and LEDs to indicate when the trash is picked up and dropped. Another possible modification is the capability to control the speed of the forward and backward motion. An advanced improvement would be deep learning, neural networks, and computer vision so that the robot could be autonomous and identify trash and pick it up.
