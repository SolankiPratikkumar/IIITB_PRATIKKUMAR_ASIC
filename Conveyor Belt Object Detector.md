
# RISC-V CONVEYOR BELT OBJECT DETECTOR


## Aim

Our Target in this project is to make a detector that detects objects running on the conveyor belt by IR Proximity Sensor and output is obtained in LED and Buzzer. As automation is increasing this project can be used as an indicator in the Industry Conveyor Belt

## Hardware

![Idea_Object Detector](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/43a98878-a10f-4490-8124-b4db6dd9fac8)

## Block Diagram

![IR_BLOCK_DIAGRAM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/044369d4-b92c-492b-a292-eb22ccbd8983)

## Functionality

* In this project,  the object is detected either stationary or moving by an Infrared Radiation(IR) and Photoelectric Sensor. The IR LED and the photodiode are linked in a parallel configuration, serving as both a transmitter and receiver. When an obstacle is in the path of the IR LED, which emits light, the reflected light is captured by the photodiode, acting as a receiver. This reflection causes a reduction in the photodiode's resistance, leading to the generation of a significant number of charge carriers and the creation of an electrical signal.
* Then that signal is passed through the potentiometer to meet the distant object up to 500cm and the obtained signal is kept as an input to the RISC-V core which will process the signal and provide output to the Buzzer and LED.
* So, by this process, we would get the detection of a moving object and our output target will be met

## C-Code
```
int main()
{
	int input;// 1_bit taken
	int buzzer;// 1_bit taken
	int led;// 1_bit taken
	int buf;// 1_bit taken
	int dummy=0xFFFFFFFE;
		while(1)
	{
          
		asm volatile(
	    	"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
		:"=r"(buf)
	    	:
	    	:"x30"
	    	);

          asm volatile(
		"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
		:"=r"(buf) 
		:
                :"x10");


		if(buf==1)
		{
		  led = 1;
		  dummy=0xFFFFFFF2;
		  asm volatile(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
                      :
		      :"r"(led),"r"(dummy)
		      :"x30"
		      );
		}
		else
		{
		  led = 0;
		  dummy=0xFFFFFFF4;
		  asm volatile(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
                      :
		      :"r"(led),"r"(dummy)
		      :"x30"
		      );
                    
		}
	


                        buzzer = 1;
			dummy=0xFFFFFFF4;
			asm volatile(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:
			:"r"(buzzer),"r"(dummy)
			:"x30"
			);
			
			led = 1;
			dummy=0xFFFFFFF8;
			asm volatile(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:
			:"r"(led),"r"(dummy)
			:"x30"
			);
			
			}
			
		}
```

## Testing of Code:

* Run the following code to run Test code:
  
```
gcc test_object.c
./a.out
```

![Screenshot from 2023-10-05 22-47-17](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5b9c2a7a-2cf1-48de-be71-c2a5ccf3f280)


## Assembly Code

```

output.o:     file format elf32-littleriscv


Disassembly of section .text:

00010074 <main>:
   10074:	fe010113          	add	sp,sp,-32
   10078:	00812e23          	sw	s0,28(sp)
   1007c:	02010413          	add	s0,sp,32
   10080:	ffe00793          	li	a5,-2
   10084:	fef42623          	sw	a5,-20(s0)
   10088:	000f0513          	mv	a0,t5
   1008c:	00157793          	and	a5,a0,1
   10090:	fef42423          	sw	a5,-24(s0)
   10094:	000f0513          	mv	a0,t5
   10098:	00157793          	and	a5,a0,1
   1009c:	fef42423          	sw	a5,-24(s0)
   100a0:	fe842703          	lw	a4,-24(s0)
   100a4:	00100793          	li	a5,1
   100a8:	02f71463          	bne	a4,a5,100d0 <main+0x5c>
   100ac:	00100793          	li	a5,1
   100b0:	fef42223          	sw	a5,-28(s0)
   100b4:	ff200793          	li	a5,-14
   100b8:	fef42623          	sw	a5,-20(s0)
   100bc:	fe442783          	lw	a5,-28(s0)
   100c0:	fec42703          	lw	a4,-20(s0)
   100c4:	00ef7f33          	and	t5,t5,a4
   100c8:	00ff6f33          	or	t5,t5,a5
   100cc:	0200006f          	j	100ec <main+0x78>
   100d0:	fe042223          	sw	zero,-28(s0)
   100d4:	ff400793          	li	a5,-12
   100d8:	fef42623          	sw	a5,-20(s0)
   100dc:	fe442783          	lw	a5,-28(s0)
   100e0:	fec42703          	lw	a4,-20(s0)
   100e4:	00ef7f33          	and	t5,t5,a4
   100e8:	00ff6f33          	or	t5,t5,a5
   100ec:	00100793          	li	a5,1
   100f0:	fef42023          	sw	a5,-32(s0)
   100f4:	ff400793          	li	a5,-12
   100f8:	fef42623          	sw	a5,-20(s0)
   100fc:	fe042783          	lw	a5,-32(s0)
   10100:	fec42703          	lw	a4,-20(s0)
   10104:	00ef7f33          	and	t5,t5,a4
   10108:	00ff6f33          	or	t5,t5,a5
   1010c:	00100793          	li	a5,1
   10110:	fef42223          	sw	a5,-28(s0)
   10114:	ff800793          	li	a5,-8
   10118:	fef42623          	sw	a5,-20(s0)
   1011c:	fe442783          	lw	a5,-28(s0)
   10120:	fec42703          	lw	a4,-20(s0)
   10124:	00ef7f33          	and	t5,t5,a4
   10128:	00ff6f33          	or	t5,t5,a5
   1012c:	f5dff06f          	j	10088 <main+0x14>
```

## Unique Assembly Instruction

Number of different instructions: 9
List of unique instructions:

```
mv
sw
add
or
lw
bne
li
j
and
```

## References

* https://github.com/SakethGajawada/RISCV_GNU
* https://circuitdigest.com/microcontroller-projects/interfacing-ir-sensor-module-with-arduino

