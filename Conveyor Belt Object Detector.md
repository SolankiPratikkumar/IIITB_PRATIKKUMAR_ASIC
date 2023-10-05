
# RISC-V CONVEYOR BELT OBJECT DETECTOR


## AIM

Our Target in this project is to make a detector that detects objects running on the conveyor belt by IR Proximity Sensor and output is obtained in LED and Buzzer. As automation is increasing this project can be used as an indicator in the Industry Conveyor Belt

## Hardware

![Idea_Object Detector](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/43a98878-a10f-4490-8124-b4db6dd9fac8)

## Block Diagram

![IR_BLOCK_DIAGRAM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/044369d4-b92c-492b-a292-eb22ccbd8983)

## Functionality

In this project as the object is detected either stationary or moving by an Infrared Radiation(IR) and Photoelectric Sensor; 
The IR LED and the photodiode are linked in a parallel configuration, serving as both a transmitter and receiver. The photodiode is reverse-biased. When an obstacle is in the path of the IR LED, which emits light, the reflected light is captured by the photodiode, acting as a receiver. This reflection causes a reduction in the photodiode's resistance, leading to the generation of a significant number of charge carriers and the creation of an electrical signal.
Then that signal is passed through the potentiometer to meet the distant object up to 500cm and the obtained signal is kept as an input to the RISC-V core which will process the signal and provide output to the Buzzer and LED. So, by this process, we would get the detection of a moving object and our output target will be meet

## C-Code
```
int main()
{
	int input;// 1_bit taken
	int speaker;// 1_bit taken
	int led;// 1_bit taken
	int buf;// 1_bit taken
	float space;
	int dummy=0xFFFFFFFE;
	unsigned int k;
	unsigned int time;
	while(1)
	{

          asm(
		"addi x10, x30, 0\n\t"
		"and %0, x10, 1\n\t"
			:"=r"(buf)); 
			
		if(buf==1)
		{
		  led = 1;
		  dummy=0xFFFFFFF2;
		  asm(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
		      :"=r"(led)
		      :"r"(dummy));
		}
		else
		{
		  led = 0;
		  dummy=0xFFFFFFF4;
		  asm(
		      "and x30, x30, %1\n\t"
		      "or x30, x30, %0\n\t"
		      :"=r"(led)
		      :"r"(dummy));
		}
	return 0;
}


```
## Convert C code into Assembly Code:

```
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o objectsense.o objectsense.c load.S
riscv64-unknown-elf-objdump -d objectsense.o > objectsense.txt
```


## Assembly Code

```
objectsense.o:     file format elf32-littleriscv

Disassembly of section .text:

00000000 <main>:
   0:	fe010113          	addi	sp,sp,-32
   4:	00812e23          	sw	s0,28(sp)
   8:	02010413          	addi	s0,sp,32
   c:	009897b7          	lui	a5,0x989
  10:	68078793          	addi	a5,a5,1664 # 989680 <.L2+0x989624>
  14:	fef42623          	sw	a5,-20(s0)
  18:	ffe00793          	li	a5,-2
  1c:	fef42423          	sw	a5,-24(s0)

00000020 <.L4>:
  20:	000f0513          	mv	a0,t5
  24:	00157793          	andi	a5,a0,1
  28:	fef42223          	sw	a5,-28(s0)
  2c:	fe442703          	lw	a4,-28(s0)
  30:	00100793          	li	a5,1
  34:	02f71463          	bne	a4,a5,5c <.L2>
  38:	00100793          	li	a5,1
  3c:	fef42023          	sw	a5,-32(s0)
  40:	ff200793          	li	a5,-14
  44:	fef42423          	sw	a5,-24(s0)
  48:	fe842783          	lw	a5,-24(s0)
  4c:	00ff7f33          	and	t5,t5,a5
  50:	00ff6f33          	or	t5,t5,a5
  54:	fef42023          	sw	a5,-32(s0)
  58:	fc9ff06f          	j	20 <.L4>

0000005c <.L2>:
  5c:	fe042023          	sw	zero,-32(s0)
  60:	ff400793          	li	a5,-12
  64:	fef42423          	sw	a5,-24(s0)
  68:	fe842783          	lw	a5,-24(s0)
  6c:	00ff7f33          	and	t5,t5,a5
  70:	00ff6f33          	or	t5,t5,a5
  74:	fef42023          	sw	a5,-32(s0)
  78:	fa9ff06f          	j	20 <.L4>
```

## Unique Instruction

Number of different instructions: 11
List of unique instructions:

```
andi
bne
mv
j
or
and
addi
li
lw
sw
lui
```

## REFERENCES

* https://github.com/SakethGajawada/RISCV_GNU
* https://circuitdigest.com/microcontroller-projects/interfacing-ir-sensor-module-with-arduino

