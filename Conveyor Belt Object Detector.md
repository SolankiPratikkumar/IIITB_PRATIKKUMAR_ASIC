
# RISC-V CONVEYOR BELT OBJECT DETECTOR


## Aim

Our Target in this project is to make a detector that detects objects running on the conveyor belt by IR Proximity Sensor and output is obtained in LED and Buzzer. As automation is increasing this project can be used as an indicator in the Industry Conveyor Belt Process Initiation

## Hardware

![Idea_Object Detector](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/43a98878-a10f-4490-8124-b4db6dd9fac8)

## Block Diagram

![IR_BLOCK_DIAGRAM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/044369d4-b92c-492b-a292-eb22ccbd8983)

## Functionality

* In this project,  the object is detected either stationary or moving by an Infrared Radiation(IR) and Photoelectric Sensor. The IR LED and the photodiode are linked in a parallel configuration, serving as both a transmitter and receiver. When an obstacle is in the path of the IR LED, which emits light, the reflected light is captured by the photodiode, acting as a receiver. This reflection causes a reduction in the photodiode's resistance, leading to the generation of a significant number of charge carriers and the creation of an electrical signal.
  
![IR-sensor-Working](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f4c65e8b-b122-4a53-909c-bee121a5c4cf)

* Then that signal is passed through the potentiometer to meet the distant object up to 500cm and the obtained signal is kept as an input to the RISC-V core which will process the signal and provide output to the Buzzer and LED.
* So, by this process, we would get the detection of a moving object and our output target will be met
  
![downloadirsensorrrrrr](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a65b808c-c264-4c35-b55a-f99d602d5d5c)

## C-Code for Assembly
```


int main() {
    int sensor_input;
    int buzzer;
    int led;
    int mask = 0xFFFFFFF9;
  
while(1)
{
     asm (
                
		"andi %0, x30, 1\n\t"
		: "=r"(sensor_input) 
		: 
                :
                 );

    if (sensor_input == 1) {
        asm (
            "ori x30, x30, 6\n\t"
            "andi %0, x30, 4\n\t"
            "andi %1, x30, 2"
            : "=r"(buzzer), "=r"(led)
            : "r"(mask)
        );
    } 
    else {
        asm (
            "and x30, x30, %2\n\t"
            "andi %0,x30, 4\n\t"
            "andi %1, x30, 2"
            : "=r"(buzzer), "=r"(led)
            : "r"(mask)
        );
    }

   } 
    return 0;
}


```

## Testing of Code

* Run the following code to run Test code:
  
```
gcc test_object.c
./a.out
```

![Screenshot from 2023-10-05 22-47-17](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5b9c2a7a-2cf1-48de-be71-c2a5ccf3f280)


## Code for Conversion of C-Code to Assembly Code

```
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib -o out objectdetector.c 
riscv64-unknown-elf-objdump -d -r out > asm.txt
```

## Assembly Code

```

out:     file format elf32-littleriscv


Disassembly of section .text:

00010054 <main>:
   10054:	fe010113          	addi	sp,sp,-32
   10058:	00812e23          	sw	s0,28(sp)
   1005c:	02010413          	addi	s0,sp,32
   10060:	ff900793          	li	a5,-7
   10064:	fef42623          	sw	a5,-20(s0)
   10068:	001f7793          	andi	a5,t5,1
   1006c:	fef42423          	sw	a5,-24(s0)
   10070:	fe842703          	lw	a4,-24(s0)
   10074:	00100793          	li	a5,1
   10078:	02f71063          	bne	a4,a5,10098 <main+0x44>
   1007c:	fec42783          	lw	a5,-20(s0)
   10080:	006f6f13          	ori	t5,t5,6
   10084:	004f7713          	andi	a4,t5,4
   10088:	002f7793          	andi	a5,t5,2
   1008c:	fee42223          	sw	a4,-28(s0)
   10090:	fef42023          	sw	a5,-32(s0)
   10094:	fd5ff06f          	j	10068 <main+0x14>
   10098:	fec42783          	lw	a5,-20(s0)
   1009c:	00ff7f33          	and	t5,t5,a5
   100a0:	004f7713          	andi	a4,t5,4
   100a4:	002f7793          	andi	a5,t5,2
   100a8:	fee42223          	sw	a4,-28(s0)
   100ac:	fef42023          	sw	a5,-32(s0)
   100b0:	fb9ff06f          	j	10068 <main+0x14>

```

## Unique Assembly Instruction

Number of different instructions: 9
List of unique instructions:
```
bne
and
j
li
andi
ori
sw
addi
lw

```
![Screenshot from 2023-11-02 18-59-09](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9ea142dc-037e-4713-a21e-f14c2d4196d4)



## Spike Working Functionality

* In Spike Simulation Code we have verified the C-code by using 2 iteration
* Firstly, when the object is not detected then input = 0 then we have printed input_objectdetected=0 by which the program has entered into the "else" loop and at output led=0 and buzzer=0
* Secondly, when the object is detected than input = 1 then we have printed input_objectdetected=1 by which we entered into "if" loop because input=1 and made the output led = 1 and buzzer=1 and Finally the output was both printed as the object is detected


## Spike Simulation Code

```
#include <stdio.h>

int main() {
    int sensor_input;
    int buzzer;
    int led;
    int mask = 0xFFFFFFF0;
    int input = 0x00000001;

     asm (
                "or x30, x30, %1\n\t"
		"andi %0, x30, 1\n\t"
		: "=r"(sensor_input) 
		: "r"(input) 
                :
                 );

    if (sensor_input == 1) {
        asm (
            "or x30, x30, 6\n\t"
            "andi %0, x30, 4\n\t"
            "andi %1, x30, 2"
            : "=r"(buzzer), "=r"(led)
        );
    } else {
        asm (
            "and x30, x30, %2\n\t"
            "andi %0,x30, 4\n\t"
            "andi %1, x30, 2"
            : "=r"(buzzer), "=r"(led)
            : "r"(0xFFFFFFF9)
        );
    }

    if (buzzer) {
        printf("input is 1. Buzzer is on. Value of BUZZER is %d\n", buzzer);
    } else {
        printf("input is 0. Buzzer is off. Value of BUZZER is %d\n", buzzer);
    }

    if (led) {
        printf("input is 1. LED is on. Value of LED is %d\n", led);
    } else {
        printf("input is 0. LED is off. Value of LED is %d\n", led);
    }

    return 0;
}

```
## Commands to Get Output of Spike
```
riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o out file.c
spike pk out
```
## Spike Simulation Output

![Screenshot from 2023-10-31 23-07-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f249c9dc-d965-43de-a5da-7c8d3251489d)


## Functionality Simulation Commands:

* We will do the functional simulation for the processors that are being created for the assembly program that is being created for my application. The processor.v and the testbench.v is uploaded and those can be seen above.


```
iverilog -o test processor.v testbench.v
./test
gtkwave waveform.vcd
```

![Screenshot from 2023-11-01 15-49-54](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2daf0c9a-8450-44cf-b29a-38218b506d4e)

## Functional Simulation Output:

* We get the output waveform with input toggle at 4000 seconds

![Screenshot from 2023-11-02 19-02-55](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4b67d0f1-1da5-4078-b59d-9c7fc990ab7f)


* Here firstly we have taken input as 0 so the expected output must be '00' at pins 1 and 2 and we can verify that in the waveform led=0 and buzzer=0 for 0 input with write=1 and ID_instruction is running with clk which confirms the running of assembly language code of 004F7713 which is ori instruction line "10080: 06f6f13  ori  t5,t5,6"

![Screenshot from 2023-11-02 20-20-52](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7a12c6db-d5af-444f-9f6c-049213d50fef)

![Screenshot from 2023-11-02 20-20-32](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b8a0379d-e391-4c80-b740-739990e27b2f)


*  Here secondly we have taken input as 1 so the expected output must be '11' at pins 2 and 3 and we can verify that in the waveform led=1 and buzzer=1 for 1 input with write=1 and ID_instruction is running with clk which confirms the running of assembly language instruction of "004F7713" with assembly code line of  "100a0:	004f7713  andi  a4,t5,4"
  
![Screenshot from 2023-11-02 19-16-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9cbb1527-241c-4efc-918a-a7351979411c)

![Screenshot from 2023-11-02 19-17-14](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3a68d41e-4346-47eb-b9ec-6e9a012ae2b5)


* Now, the third example shows that input gets low  to 0 but the output stays '11' for some delay and the instruction written over here is "FEF42023" from assembly code of " 100ac: fef42023 sw a5,-32(s0)"

![Screenshot from 2023-11-02 19-32-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ec442482-b922-4267-b41f-4873b77cce0a)

![Screenshot from 2023-11-02 19-32-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f140fad0-ac71-4de2-bd36-eb7177e4d515)


## References

* https://github.com/SakethGajawada/RISCV_GNU
* https://circuitdigest.com/microcontroller-projects/interfacing-ir-sensor-module-with-arduino
* https://chat.openai.com/

## Acknowledgement

* Kunal Ghosh, VSD Corp. Pvt. Ltd.
* Mayank Kabra, Founder Chipcron Pvt.Ltd
* Bhargav DV,MS Collegue
* Pruthvi parate, MS Collegue
* Divyam Satle, M.Tech Collegue
* Nitesh Sharma, M.Tech Collegue
