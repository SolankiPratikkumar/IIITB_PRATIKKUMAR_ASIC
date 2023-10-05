
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
int main(){
	int signal;// 1_bit taken
	int speaker;// 1_bit taken
	int led;// 1_bit taken
	int buf;// 1_bit taken
	int clk_freq = 10000000;
	float space;
	int dummy=0xFFFFFFFE;
	unsigned int j;
	unsigned int time;
	while(1)
	{
		signal = 1;
		asm(
		"and x30, x30, %1\n\t"
    	"or x30, x30, %0\n\t"
    	:"=r"(signal)
		:"r"(dummy));
		for(j=0;j<10000000;j++);
			
		signal = 0;
		asm(
		"and x30, x30, %1\n\t"
    	"or x30, x30, %0\n\t"
    	:"=r"(signal)
		:"r"(dummy));
		i=0;
		
		asm(
		"addi x10, x30, 0\n\t"
		"and %0, x10, 2\n\t"
			:"=r"(buf));         
			
		while(buf!= 1){
			i++;
			asm(
			"addi x10, x30, 0\n\t"
			"and %0, x10, 2\n\t"
				:"=r"(buf));
		}
		time = i/clk_freq;
		space =time*172;
		
		speaker = 0;
		dummy=0xFFFFFFF4;
		asm(
		"and x30, x30, %1\n\t"
    	"or x30, x30, %0\n\t"
    	:"=r"(speaker)
		:"r"(dummy));
		
		led = 0;
		dummy=0xFFFFFFF8;
		asm(
		"and x30, x30, %1\n\t"
    	"or x30, x30, %0\n\t"
    	:"=r"(led)
		:"r"(dummy));
		
		
		if(space<= 0.5 && space >= 0){
			speaker = 1;
			dummy=0xFFFFFFF4;
			asm(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:"=r"(speaker)
			:"r"(dummy));
			
			led = 1;
			dummy=0xFFFFFFF8;
			asm(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:"=r"(led)
			:"r"(dummy));
		}
		else{
			speaker = 0;
			dummy=0xFFFFFFF4;
			asm(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:"=r"(speaker)
			:"r"(dummy));
			
			led = 0;
			dummy=0xFFFFFFF8;
			asm(
			"and x30, x30, %1\n\t"
			"or x30, x30, %0\n\t"
			:"=r"(led)
			:"r"(dummy));
		}
	}
	return 0;
}

```

## Assembly Code

## Unique Instruction
