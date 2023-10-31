
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
//#include <stdio.h>
int main()
{
	int input;// 1_bit taken
	int buzzer,buzzer_reg;// 1_bit taken
	int led,led_reg;// 1_bit taken
	int mask=0xFFFFFFFE;
	//int i,j;
	
	
	//for(i=0;i<2;i++)
	 while(1)	
	{
          
		asm volatile(
	    	"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
		:"=r"(input)
	    	:
	    	:"x30"
	    	);

          asm volatile(
		"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
		:"=r"(input) 
		:
                :"x10");
                 
        	
        	//printf("input is %d\n",input);
		asm volatile(
			"addi x10, x30, 0\n\t"
			"and %0, x10, 1\n\t"
			:"=r"(input)
			:
			:"x10"
			);
		  input=1;
		//printf("input_objectdetected = %d\n",input);
				
		
		if(input)
		{
		 //printf("entering if loop as input is 1\n");
		  led = 1;
		  led_reg = led * 2;
		  mask=0xFFFFFFFD;
		  asm volatile(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
                      :
		      :"r"(led_reg),"r"(mask)
		      :"x30"
		      );
		  //printf("led = %d\n",led);
		  
		                       
                        buzzer = 1;
                        buzzer_reg = buzzer * 4;
			mask=0xFFFFFFFC;
			asm volatile(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:
			:"r"(buzzer_reg),"r"(mask)
			:"x30"
			);
	        	//	  printf("buzzer = %d\n",buzzer);
		}
		else
		{
		 //printf("entering else loop as input is 0");
		  led = 0;
		  led_reg = led * 2;
		   mask=0xFFFFFFFD;
		  asm volatile(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
                      :
		      :"r"(led_reg),"r"(mask)
		      :"x30"
		      );
		      
                  //printf("led = %d\n",led); 
                  
                                       
                        buzzer = 0;
                        buzzer_reg = buzzer * 4;
			mask=0xFFFFFFFC;
			asm volatile(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:
			:"r"(buzzer_reg),"r"(mask)
			:"x30"
			); 
			
	       //printf("buzzer sounds=%d\n",buzzer);
		}
	                                    
                      
			
			}
			
	         //    printf("led blinked=%d\n",led);
                   //  printf("buzzer sounds=%d\n",buzzer);
			
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
   10060:	ffe00793          	li	a5,-2
   10064:	fef42623          	sw	a5,-20(s0)
   10068:	000f0513          	mv	a0,t5
   1006c:	00157793          	andi	a5,a0,1
   10070:	fef42423          	sw	a5,-24(s0)
   10074:	000f0513          	mv	a0,t5
   10078:	00157793          	andi	a5,a0,1
   1007c:	fef42423          	sw	a5,-24(s0)
   10080:	000f0513          	mv	a0,t5
   10084:	00157793          	andi	a5,a0,1
   10088:	fef42423          	sw	a5,-24(s0)
   1008c:	00100793          	li	a5,1
   10090:	fef42423          	sw	a5,-24(s0)
   10094:	fe842783          	lw	a5,-24(s0)
   10098:	04078463          	beqz	a5,100e0 <main+0x8c>
   1009c:	00100793          	li	a5,1
   100a0:	fef42223          	sw	a5,-28(s0)
   100a4:	ff200793          	li	a5,-14
   100a8:	fef42623          	sw	a5,-20(s0)
   100ac:	fe442783          	lw	a5,-28(s0)
   100b0:	fec42703          	lw	a4,-20(s0)
   100b4:	00ef7f33          	and	t5,t5,a4
   100b8:	00ff6f33          	or	t5,t5,a5
   100bc:	00100793          	li	a5,1
   100c0:	fef42023          	sw	a5,-32(s0)
   100c4:	ff400793          	li	a5,-12
   100c8:	fef42623          	sw	a5,-20(s0)
   100cc:	fe042783          	lw	a5,-32(s0)
   100d0:	fec42703          	lw	a4,-20(s0)
   100d4:	00ef7f33          	and	t5,t5,a4
   100d8:	00ff6f33          	or	t5,t5,a5
   100dc:	f8dff06f          	j	10068 <main+0x14>
   100e0:	fe042223          	sw	zero,-28(s0)
   100e4:	ff400793          	li	a5,-12
   100e8:	fef42623          	sw	a5,-20(s0)
   100ec:	fe442783          	lw	a5,-28(s0)
   100f0:	fec42703          	lw	a4,-20(s0)
   100f4:	00ef7f33          	and	t5,t5,a4
   100f8:	00ff6f33          	or	t5,t5,a5
   100fc:	fe042023          	sw	zero,-32(s0)
   10100:	ff400793          	li	a5,-12
   10104:	fef42623          	sw	a5,-20(s0)
   10108:	fe042783          	lw	a5,-32(s0)
   1010c:	fec42703          	lw	a4,-20(s0)
   10110:	00ef7f33          	and	t5,t5,a4
   10114:	00ff6f33          	or	t5,t5,a5
   10118:	f51ff06f          	j	10068 <main+0x14>
```

## Unique Assembly Instruction

Number of different instructions: 10
List of unique instructions:
```
and
addi
beqz
or
mv
sw
j
andi
lw
li
```
## Spike Working Functionality

* In Spike Simulation Code we have verified the C-code by using 2 iteration
* Firstly, when the object is not detected then input = 0 then we have printed input_objectdetected=0 by which the program has entered into the "else" loop and at output led=0 and buzzer=0
* Secondly, when the object is detected than input = 1 then we have printed input_objectdetected=1 by which we entered into "if" loop because input=1 and made the output led = 1 and buzzer=1 and Finally the output was both printed as the object is detected


## Spike Simulation Code

```
#include <stdio.h>
int main()
{
	int input;// 1_bit taken
	int buzzer;// 1_bit taken
	int led;// 1_bit taken
	int mask=0xFFFFFFFE;
	int i,j;
	
	
	for(i=0;i<2;i++)
		
	{
          
		asm volatile(
	    	"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
		:"=r"(input)
	    	:
	    	:"x30"
	    	);

          asm volatile(
		"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
		:"=r"(input) 
		:
                :"x10");
                 
        	
        	printf("input is %d\n",input);
		asm volatile(
			"addi x10, x30, 0\n\t"
			"and %0, x10, 1\n\t"
			:"=r"(input)
			:
			:"x10"
			);
			if(i==1){
			input=1;}
			else {
			input=0;
			}
		printf("input_objectdetected = %d\n",input);
				
		
		if(input)
		{
		 printf("entering if loop as input is 1\n");
		  led = 1;
		  mask=0xFFFFFFFD;
		  asm volatile(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
                      :
		      :"r"(led),"r"(mask)
		      :"x30"
		      );
		  printf("led = %d\n",led);
		  
		                       
                        buzzer = 1;
			mask=0xFFFFFFFC;
			asm volatile(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:
			:"r"(buzzer),"r"(mask)
			:"x30"
			);
	        		  printf("buzzer = %d\n",buzzer);
		}
		else
		{
		 printf("entering else loop as input is 0");
		  led = 0;
		   mask=0xFFFFFFFD;
		  asm volatile(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
                      :
		      :"r"(led),"r"(mask)
		      :"x30"
		      );
		      
                  printf("led = %d\n",led); 
                  
                                       
                        buzzer = 0;
			mask=0xFFFFFFFC;
			asm volatile(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:
			:"r"(buzzer),"r"(mask)
			:"x30"
			); 
			
	       printf("buzzer sounds=%d\n",buzzer);
		}
	                                    
                      
			
			}
			
	             printf("led blinked=%d\n",led);
                     printf("buzzer sounds=%d\n",buzzer);
			
		}


```
## Commands to Get Output of Spike
```
riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o out file.c
spike pk out
```
## Spike Simulation Output

![Screenshot from 2023-10-25 17-23-04](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e61bdcdd-30f5-421f-a0fd-87a858f11112)



## Functionality Simulation Commands:

```
iverilog -o test processor.v testbench.v
./test
gtkwave waveform.vcd
```

## Functional Simulation Output:

* Here firstly we have taken input as 0 so the expected output must be 00 at pins 2 and 3 and we can verify that in the waveform led=0 and buzzer=0 for 0 input with write=1 and ID_instruction is running with clk which confirms the running of assembly language

![Screenshot from 2023-10-28 17-17-19](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e0e0b674-caab-4103-b6de-8dee921593bc)

*  Here secondly we have taken input as 1 so the expected output must be 11 at pins 2 and 3 and we can verify that in the waveform led=1 and buzzer=1 for 1 input with write=1 and ID_instruction is running with clk which confirms the running of assembly language
  
![Screenshot from 2023-10-28 17-11-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ebe336df-9e41-41e9-a7e6-6695787c666e)


## References

* https://github.com/SakethGajawada/RISCV_GNU
* https://circuitdigest.com/microcontroller-projects/interfacing-ir-sensor-module-with-arduino
* https://chat.openai.com/

## Acknowledgement

* Kunal Ghosh, VSD Corp. Pvt. Ltd.
* Mayank Kabra,iM.Tech
* Bhargav DV,MS Collegue
* Pruthvi parate, MS Collegue
* Divyam Satle, M.Tech Collegue
