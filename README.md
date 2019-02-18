# Arrow-Follower-Robot-Car
## Description:
The main purpose of the project is to **detect arrow directions and follow it**, using **python Open CV** library and Arduino to control the directions of the motors, using bluetooth **serial communication** between them.
Small application of a **Self-Driving Car.** 
## Video: 

## Software:
**Python**, Which include Open CV, Numpy, and Pyserial libraries.
**Arduino IDE** for controlling the motion of the motors.
**IP Webcam** mobile application, used instead of using camera module.

## Conclusion:
First, when we run the python code , it sends ‘f’ to bluetooth using **Pyserial**, the arduino reads the bluetooth signal and convert it into motors move forward, then if the ultrasonic module find any object in the specified distance, it send ‘s’ to arduino directly , which stops the motors, after that arduino sends a **‘q’** to python ,then the mobile takes a picture of the object  and send it to the labtop using **urllib** which allows the python code to process that picture using **openCV** and if that picture matches one of our stored data, Finally python sends the direction of the image been recognized to move the robot in that direction.
