
# RISC-V CONVEYOR BELT OBJECT DETECTOR


## AIM

Our Target in this project is to make a detector that detects objects running on the conveyor belt by IR Proximity Sensor and output is obtained in LED and Buzzer. As automation is increasing this project can be used as an indicator in the Industry Conveyor Belt

## Hardware

![Idea_Object Detector](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/43a98878-a10f-4490-8124-b4db6dd9fac8)

## Block Diagram

![IR_BLOCK_DIAGRAM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/044369d4-b92c-492b-a292-eb22ccbd8983)

## Functionality

The work of this project as the object is detected either stationary or moving by an Infrared Radiation(IR) and Photoelectric Sensor; 
The IR LED and the photodiode are linked in a parallel configuration, serving as both a transmitter and receiver. The photodiode is reverse-biased. When an obstacle is in the path of the IR LED, which emits light, the reflected light is captured by the photodiode, acting as a receiver. This reflection causes a reduction in the photodiode's resistance, leading to the generation of a significant number of charge carriers and the creation of an electrical signal.
Then a signal is passed through the potentiometer to meet the distant object up to 500cm and the signal is obtained as an input to the RISC-V core which will process the signal and provide output to the Buzzer and LED. So, by this process, we would get the detection of a moving object and our output target will be meet

## C-Code


## Assembly Code

## Unique Instruction
