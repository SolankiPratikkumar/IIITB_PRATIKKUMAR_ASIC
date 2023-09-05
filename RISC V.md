[](url) Physical Design of ASICs - RISC V


## DAY 1
<details>
<summary>DAY-1</summary>
<br>
 <details>
 <summary>RISC-V Installation Steps</summary>

* Below are the steps and commands to install RISC-V toolchain

```
git clone https://github.com/kunalg123/riscv_workshop_collaterals.git
cd riscv_workshop_collaterals
chmod 755 run.sh
./run.sh
```
Once the cloning is done and if there is not any error then set the PATH variable in .bashrc file using below commands
 
```
gedit .bashrc
export PATH="/home/user/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH" #Instead of user replace it with your user name
```
* Now try the "riscv64-unknown-elf-gcc" command and if there is any error shown below is how to debug: If you are getting the error about "iverilog" then use the below commands

```
sudo apt-get install libboost-regex-dev
git clone https://github.com/steveicarus/iverilog.git
cd iverilog/
git checkout --track -b v10-branch origin/v10-branch
git pull 
chmod 777 autoconf.sh 
./autoconf.sh 
./configure 
make
sudo make install
```

* If you are getting the error about "riscv-pk" then use the below commands

```
sudo apt-get install libboost-regex-dev
git clone https://github.com/riscv/riscv-pk.git
cd riscv-pk/
mkdir build
cd build/
../configure --prefix=$pwd/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14 --host=riscv64-unknown-elf
make
sudo make install
```
If there is an error showing that "Spike-command is not found" when running the spike, Try running the run.sh again, it will be resolved.
Don't forget to add PATH in .bashrc and source the .bashrc file

Acknowledgement: Bhargav D V, Pruthvi Parate, Alwin Shaju, Emil Jayanth Lal, Kanish R, Divyam Satle: Colleagues(IIIT-B)

 </details>

 
 <details>
 <summary>Introduction to RISC-V Basic Keywords</summary>

 <details>
  <summary>Instruction Set Architecture(ISA)</summary>

* C-Program is run by the compile to assembly language of RISC V and that makes Hardware Layout operation (qflow); that Hardware can be RISC-V

***WHAT IS RISC-V***

* RISC-V is an open-source instruction set architecture (ISA) for designing computer processors. 
* An instruction set architecture defines the instructions a processor can execute, the formats for those instructions, and the corresponding hardware behaviour. 
* RISC-V is designed to be versatile, customizable, and open, making it well-suited for a wide range of applications, from embedded systems to high-performance computing.
* RISC-V supports both 32-bit and 64-bit address spaces, and it can be implemented with varying levels of performance and complexity, from simple microcontrollers to high-end supercomputers.
* Briefly the architecture can be understood below:
*  RISC-V Architecture --->  Implementation (picorv32 cpu core) ---> Hardware Layout(qflow)

</details>

 <details>
  <summary>From App to Hardware</summary>

* The Flow of the RISC-V is explained in the below image:
   
 ![Screenshot from 2023-08-20 14-48-36](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8415bef2-9de6-494e-95dd-d00528000659)

* "Application Software" (like Mozilla Firefox, Stopwatch app) is input to the "System Software" which then passes through the compiler and generated to RISC-V in instruction.exe file and the exe file is passed to the Assembler which converts to Machine Binary language and Finally that is executed to "Hardware" Chip layout

 * The example of the RISC-V flow can be understood by below StopWatch application:
   
![Screenshot from 2023-08-20 14-47-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9ccf5217-418a-4c1d-95f2-5ea503bc70dd)

* Same way it works for other Application Software:

  ![Screenshot from 2023-08-20 14-55-09](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c0679442-3926-4659-b170-e361fe0fb134)


![r1aWhatsApp Image 2023-08-20 at 4 11 34 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/50799b6e-38b9-437b-a360-963def94357e)


  </details>
  
   <details>
  <summary>Detailed Discription of Course</summary>

* Detailed Description is dropped in the below images:

   ![Screenshot from 2023-08-20 16-04-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7ce7902b-cc5f-4665-9e89-4cc1737ecf43)

* The Important Application Binary Interface (ABI) is listed below:
* 
  ![Screenshot from 2023-08-20 16-00-52](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/df859947-b91a-48ef-a34d-10daaecf5d9d)

* Course content in block format:
* 
![r1bWhatsApp Image 2023-08-20 at 4 12 28 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/40076075-fee3-48a4-8566-1d4dd014563a)

 </details>
  </details>

 <details>
  <summary>Labwork for RISC-V Software Toolchain</summary>
 <details>
  <summary>C-Program to compute sum 1 to n</summary>

* Commands used in Ubuntu to call the text editor for C-program are:
```
$ cd
$ gedit sum1ton.c
//write the C-program in editor and save
$ gcc sum1ton.c
$ ./a.out
```

* The C- Program of sum 1 to n is as follows:

```
#include<stdio.h>
int main ()
{ 
int i,sum=0,n=50;
for(i=0;i<=n;i++)
 {
  sum+=i;
 }
 printf("sum of number from 1 to %d is %d\n",n,sum);
 return 0;
}
```

![Screenshot from 2023-08-20 17-19-05](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/de168949-8a89-45d6-bfcb-aa9129599490)



 </details>

 <details>
  <summary>RISCV GCC Compile And Disassemble</summary>

```
$ cat sum1ton.c
$ riscv64-unknown-elf-gcc -o1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
$ ls -ltr sum1ton.o
$ riscv64-unknown-elf-objdump -d sum1ton.o 
$ riscv64-unknown-elf-objdump -d sum1ton.o | less
/..press enter
$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```


![Screenshot from 2023-08-20 20-37-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1871dbe3-2333-436c-ae3e-c0b7fd01cab8)

* We can find total number of instruction by subtracting next instruction and 1st hex instruction of existing divide to 4
* Total Number of instruction= (101c0-10184)/4 = 15 instruction

</details>

 <details>
  <summary>Spike Simulation and Debug</summary>

```
$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
$ gcc sum1ton.c
$ ./a.out
$ rReiscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
$ riscv64-unknown-elf-objdump -d sum1ton.o | less
$ spike -d pk sum1ton.o
:until pc 0 to 100b0
: reg 0 a2
//(press enter)
:reg 0 a1
//(press enter)
```

* go on multiple manual spike instruction writing
  
  ![Screenshot from 2023-08-21 01-11-02](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/bced2476-aaa8-44af-b5ee-2a47bf2d71f9)


* We can observe below the register details:

![Screenshot from 2023-08-21 00-27-47](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/34a68f81-d296-490c-ac74-61b5346a0466)

![Screenshot from 2023-08-21 00-34-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d33bbf75-f5a6-42b4-ae90-2262e7ab4165)

</details>
</details>

 <details>
  <summary>Integer Number Representation</summary>

 <details>
  <summary>64bit Number System for Unsigned Number</summary>

* Human can understand Decimal while computer understand Binary
* So, we are trying to understand this type of Implementation for RISC V
  
  ![Screenshot from 2023-08-21 10-11-04](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a8b5bbde-c9f9-41d1-ba71-228f08219b85)

  * So, the important part to note here is 64bits =8 bytes= 2 words= 1doublewords

![Screenshot from 2023-08-21 10-13-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/18efe934-0e92-49dd-bcba-5ffc1e8e2197)

  
![Screenshot from 2023-08-21 10-15-40](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/79a2a928-f798-4b55-98aa-91cdbb2a0a2c)

* From the above image we can understand the total number of Decimal Equivalent for 0 to all bits is 1's

![Screenshot from 2023-08-21 10-17-56](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/538391d9-ead3-47d6-99f8-53cabca94710)

* From above we can understand the total number of patterns for 64bits Unsigned Number= 0 to (2^64-1)

  </details>
  
   <details>
  <summary>64bit Number System for Signed Number</summary>
  
![Screenshot from 2023-08-21 10-43-14](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e79472b4-0ade-408a-a596-b5b92ab29d71)

* The Signed number can be identified by MSB as '1'
  
[Screenshot from 2023-08-21 10-45-27](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c5c468d5-f72c-4d5f-acf7-f382d46720d3)

* We can observe how the binary-to-decimal conversion takes place for signed bits where -2^63 is the final multiplied
  
![Screenshot from 2023-08-21 10-48-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/67aba151-0a86-4a93-b18e-ddabde93389f)

* So, the important note here is the final 3 decimal 808 in signed -2^63 where there is 807dec in unsigned which is (2^63-1)
  
![Screenshot from 2023-08-21 10-50-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2a89b213-2e65-4010-bba5-cd094f616159)

* These 4 Points are Important to note  which are mentioned above
* Instruction that runs on it is Base Instructions RV641

  
  </details>
  
   <details>
  <summary>Labs on Unsigned Number and Signed Number</summary>

**Code for Unsigned Number**

* Unsigned numbers lack a sign and can only express the magnitude of a number. Consequently, the representation of unsigned binary numbers exclusively encompasses positive numbers.
* In unsigned binary numbers, there is no sign bit, meaning that an N-bit binary number represents only its magnitude. Zero (0) is also considered an unsigned number.
* Each number in unsigned number representation possesses only a single, unique binary equivalent form, making it an unambiguous representation technique. The range of unsigned binary numbers extends from 0 to ((2^n)-1)
  
* C-program on highest unsigned number is given below:
  
```
#include <stdio.h>
#include <math.h>
int main()
{
unsigned long long int max = (unsigned long long int) (pow(2,64) -1);
printf("highest number represented by unsigned long long int is %llu\n", max);
return 0;
}
```

* Command to get output debugged using spike of unsigned number:

```
$ gedit unsignedHighest.c
$ gcc unsignedHighest.c
$ ./a.out

$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o unsignedHighest.o unsignedHighest.c
$ spike pk unsignedHighest.o
```

![Screenshot from 2023-08-21 12-09-47](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/caafc9e0-1abf-4c4f-9c8a-79aeac7dcc5f)

* Using the same C-program and checking for her power 2^127 we get the unsignedHighest same Highest Number
  
```
#include <stdio.h>
#include <math.h>
int main()
{
unsigned long long int max = (unsigned long long int) (pow(2,127) -1);
printf("highest number represented by unsigned long long int is %llu\n", max);
return 0;
}
```

* Now changing the power as 2^10 to get an unsigned number in decimal:
  
```
#include <stdio.h>
#include <math.h>
int main()
{
unsigned long long int max = (unsigned long long int) (pow(2,10) -1);
printf("highest number represented by unsigned long long int is %llu\n", max);
return 0;
}
```

![Screenshot from 2023-08-21 12-19-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7c26f9bb-c8e3-41ff-9d77-37ba802f3b18)

**Code for Signed Number**

* In general, signed numbers are often represented using the 2's complement representation. To obtain the 2's complement of a number, you invert each bit of the given number and then add 1 to the least significant bit (LSB).
* Consequently, positive numbers are typically represented in their simple binary form, while negative numbers are represented in 2's complement form, with an extra bit used for sign representation. When the sign bit's value is 0, the number is positive and can be directly expressed in straightforward binary form.
* However, if the sign bit's value is 1, the number is negative, and you should use the 2's complement of the given binary number.
* Notably, in this representation, the value zero (0) has only one unique representation, which is always positive. The range of numbers in 2's complement form spans from -(2^(n-1)) to ((2^(n-1))-1)
 C-program on highest Signed number is given below:
  
```
#include <stdio.h>
#include <math.h>
int main()
{
long long int max = (int) (pow(2,63) -1);
long long int min = (int) (pow(2,63) * -1);
printf("highest number represented by long long int is %lld\n", max);
printf("lowest number represented by long long int is %lld\n", min);
return 0;
}

```

* Commands for running signedHighest program in Ubuntu are as follows:

```
$ gedit signedHighest.c
$ gcc signedHighest.c
$ ./a.out

$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o signedHighest.o signedHighest.c
$ spike pk signedHighest.o
```


* Here we don't get required result as here we have used (int), by which overflow condition arrives. now for fixing this we will use long long int instead of int

```
include <stdio.h>
#include <math.h>
int main() {
long long int max = (long long int) (pow(2,63) -1);
long long int min = (long long int) (pow(2,63) * -1);
printf("highest number represented by long long int is %lld\n", max);
printf("lowest number represented by long long int is %lld\n", min);
return 0;
```

* Others data types extension can used as below :

![Screenshot from 2023-08-21 11-17-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/07a59ddf-1c63-4ec1-a675-81643fae40da)


  </details>
 </details>
   </details>  
     </details>

     
 ## DAY 2
<details>
<summary>DAY-2</summary>
<br>
 <details>
 <summary>Application Binary Interface(ABI)</summary>

<details>
 <summary>Introduction to Application Binary Interface(ABI)</summary>


**What is ABI**

* ABI stands for "Application Binary Interface." It is a set of rules and conventions that dictate how different software components interact at the binary level.
* In simpler terms, ABI defines how programs running on the same or different architectures can communicate with each other.
  
* ABI encompasses various aspects of low-level programming and software development, including:

* Data Representation: How data types are represented in memory or storage, including integers, floating-point numbers, structures, and more.

* Function Calling Convention: How functions are invoked and how their parameters and return values are passed between different parts of a program. This includes details about registers, stack usage, and parameter passing order.

* Memory Layout: How memory is organized, including the stack, heap, and data segments, and how variables are allocated and accessed.

* Exception Handling: How exceptions and errors are handled by the system, including mechanisms for raising, catching, and propagating exceptions.

* System Calls: How higher-level programming languages interact with the operating system's services and resources, often involving system calls or function calls to kernel routines.

* Register Usage: Which registers are used for specific purposes, how they are saved/restored during function calls, and how they might be preserved across different components of a program.

* ABI is crucial for interoperability between different programming languages, libraries, and operating systems. It ensures that compiled code from different sources can work seamlessly together, as long as they adhere to the same ABI.
  
* Different architectures and platforms might have their own ABIs due to differences in hardware, system architectures, and operating systems.


![Screenshot from 2023-08-21 11-17-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8fd13e4c-8741-4794-bbee-d8c6d8606e6b)

* Above is the clear example of how are the command of ABI looks:

![Screenshot from 2023-08-21 15-07-47](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2d66c5ad-77ff-4d18-9fef-8050d81726e6)

* ABI is an system call interface which is used to run application program on Hardware
   
![Screenshot from 2023-08-21 15-09-26](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/902edcc4-b3fd-4b3d-a7da-25042384c19b)

* ABI has 32 bit register for RV32 and 64 register for RV64, why it is so can be understaood in upcoming class

</details>

<details>
 <summary>Memory Allocation for Double Words</summary>

 ![Screenshot from 2023-08-21 15-35-44](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/572389ee-b2cb-4383-bb59-8d8981949413)

* The lower Byte is m[0] is LSB while the upper Byte is m[8]
  
![Screenshot from 2023-08-21 15-37-11](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e5bf66fc-23bf-4cd8-98c0-80972e7c8cb5)


* Here we have 64 bit register but we have 32 bit wide register available for storage of our 64 bit instruction. So 1st we divide 64 bits into eight 8 bit and store it into a paricular memory location.
* Hence , In the context of RISC-V, a "word" typically refers to a 32-bit value, and a "byte" is 8 bits. The splitting of a 64-bit number into bytes and words is straightforward

* A 64-bit number consists of 8 bytes (64 bits / 8 bits per byte). A 64-bit number consists of 2 words (64 bits / 32 bits per word).

* Each byte or word of the 64-bit number can be accessed and manipulated independently.

* Keep in mind that RISC-V provides specific instructions for working with 64-bit data, including arithmetic, load/store, and conversion operations. These instructions handle the splitting and management of 64-bit data in a 32-bit architecture like RISC-V.

* It uses different registers(32 in number) which are each of width XLEN = 32 bit for RV32 (~XLEN = 64 for RV64) . On a higher level of abstraction these registers are accessed by their respective ABI names.
  
  </details>
  
  <details>
 <summary>Load, Add and Store Instructions with Examples</summary>

![Screenshot from 2023-08-21 15-51-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8d284e08-78f9-4c1a-98b1-3dc958c7671b)

* Here ld is used for double word; and all the numbers 16 and all are converted to binary inside register

![Screenshot from 2023-08-21 16-03-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/99f9107f-a296-4292-948d-70cdc0295f04)

*Above command is used to adding into previous operation

![Screenshot from 2023-08-21 16-02-57](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e4d67fd4-c359-4b7a-a64d-ff7fc69e299f)

* Above sd command is used for storing back to different memory address
* And all the above instruction are called as Base Integer Instruction RV64I
  
 </details>
  
  <details>
 <summary>Conclusion and Reason behind of 32bit RV64</summary>
   
![Screenshot from 2023-08-21 16-16-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/91aad6a6-20ef-454e-9a1a-03774e2d0df6)

* There are different type of Instructions are classified as I-Type by Immediate type MSB in that register, the R-type register on basis of more blocks of r block in register here and  S-type register on the basis of 2 immediate block in register
  
* Reason for 32 bit register: Here is there are always 5 bits to represent each register block hence 2^5= 32bit register and the total register starts from 0 to (2^5-1)
  
![Screenshot from 2023-08-21 16-17-54](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/03b35e80-cc8a-43f6-8513-935e937871d8)

* Different Register with their ABI name and their usage are mentioned in above image which will be used in upcoming labs.

</details>
</details>



 <details>
 <summary>Labs works ABI function calls</summary>

<details>
 <summary>Study New Algorithm for sum 1 to N using ASM</summary>

![Screenshot from 2023-08-21 18-03-51](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d6e6267c-0193-4cba-b7c3-f5adc8b8d4a0)

* You can use register a0 to a7 in ASM
* Other types of Flowchart can also be used here for execution of same program

</details>

<details>
 <summary>Simulate new C program with Function Call</summary>

* C program from sum of number from 1 to n:
 
```
#include<stdio.h>
extern int load(int x,int y);
int main(){

	int result=0;
	int count =9;
	result=load(0x0,count+1);
	printf("sum of number from 1 to %d is %d\n",count,result);

}
```

* Code of load file:

```
.section .text
.global load
.type load,@function

load:
	add a4, a0, zero
	add a2, a0, a1
	add a3, a0, zero
loop:	add a4, a3, a4
	addi a3, a3, 1
	blt a3, a2, loop
	add a0, a4,zero
	ret
```

![Screenshot from 2023-08-21 18-42-40](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9dd4ac8d-660f-4bfd-be9d-34bcbcea1f41)


![Screenshot from 2023-08-21 18-38-12](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4fc5f597-d942-4b13-8c41-1921bc93ddb6)

</details>

<details>
 <summary>Basic Verification Flow</summary>

 ![Screenshot from 2023-08-21 19-56-18](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1626fa79-3416-4028-831d-6e7f30b1a638)

 ![Screenshot from 2023-08-21 19-56-56](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5dd15c57-f6f4-4fc9-a88e-01fedf4dbd9d)

 ![Screenshot from 2023-08-21 19-57-20](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/875a36bd-6a79-46c8-993e-a25f7cf9d7f5)

 ![Screenshot from 2023-08-21 19-59-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9f0b6e01-fbe7-4118-8815-9c862be5266a)

 ![Screenshot from 2023-08-21 20-00-03](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2b238491-cdf3-4b89-a6a7-7517c7f54a1a)

 ![Screenshot from 2023-08-21 20-00-27](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ad2ad9f9-0dee-448b-8940-ec87b8e11fef)

* Below are all the code run in colleteral / lab folder and generated above output images:
  
 ![Screenshot from 2023-08-21 20-00-49](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e96f40ab-3d8c-4233-9b4c-81abc542caed)

</details>
</details>
</details>
</details>


 ## DAY 3
<details>
<summary>DAY-3</summary>
<br>
 <details>
 <summary>Digital Logic with TL-verilog and Makerchip</summary>

<details>
 <summary>Combinational Logic with TL-verilog and Makerchip</summary>

![drd](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/aa84b1bf-c1b7-4c81-8bff-285dda08fe36)
 
AND Gate: Outputs are true if all inputs are true. OR Gate: Outputs true if at least one input is true. NOT Gate: Outputs the opposite (complement) of the input. XOR Gate: Outputs true if the number of true inputs is odd. NAND Gate: Outputs false only if all inputs are true. NOR Gate: Outputs true only if all inputs are false. XNOR Gate: Outputs true if the number of true inputs is even.

** Verilog expression for different Logic Gates:**

![Screenshot from 2023-08-22 11-59-02](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/83ac359c-e606-42d0-90d4-af7871a0b0a0)

**Combinational Circuits:**

![Screenshot from 2023-08-22 16-34-48](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8531818d-ef90-4bc2-b6ce-1ec074c4cece)

**Chaining Ternary Operation on MUX**

  ![Screenshot from 2023-08-22 16-34-24](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f75cb4c2-cdb3-4417-9683-46f027746904)
  

**Makerchip**

* Makerchip is an online platform that provides an integrated development environment (IDE) for designing, simulating, and testing digital circuits and systems. It's particularly focused on hardware description languages (HDLs) like Verilog and SystemVerilog.

</details>

<details>
 <summary>Labs on Digital Logic Combinational Circuits Using  Makerchip</summary>
 
**NOT Gate**

![NOT Screenshot from 2023-08-22 18-08-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ad3970b1-c774-4131-9a7b-7f78e5abcd39)


**AND Gate**

![AND Screenshot from 2023-08-22 18-07-19](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3af229a6-8d2d-40a6-9ec0-fdd0c248b727)


**OR Gate**

![OR Screenshot from 2023-08-22 18-08-35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8ff6b434-c08a-4108-85a1-d320e0317a83)


**XOR Gate**
![XOR Screenshot from 2023-08-22 18-08-56](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/df9198d5-c509-4b2d-ba59-271bf391fde7)


**Vector**
![Vector Screenshot from 2023-08-22 18-09-33](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/647d6adc-319c-4ffd-9da5-081afee003af)


**MUX**

![MUX Screenshot from 2023-08-22 18-09-51](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1e6f7ce7-2ab8-4fe8-b085-1abcd66a77b2)

![MUX 2Screenshot from 2023-08-22 18-10-55](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d693b1aa-095e-4bde-a235-6fc10497a6be)


**Combinational Calculator**

![Screenshot from 2023-08-22 18-40-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2598f3e8-a931-4b9c-8149-5e7b1080cf67)


![CombinationalScreenshot from 2023-08-22 18-11-19](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/41e62812-dfbc-40ed-ae04-1c0b0431571f)

</details>

<details>
 <summary>Sequential Circuits Using Makerchip</summary>

 ## Sequential Circuits:

* Sequential circuits have memory elements that retain information between clock cycles or input changes, allowing them to perform tasks like counting, storing previous states, and enabling more complex operations like data storage and manipulation. Examples of sequential circuits include shift registers, counters, and memory units like flip-flop-based storage elements.

![26Seq1841244-fbd8d615-c13f-4b97-8a10-b6a5609bec77](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0b18763b-86bb-476c-a35d-2ba8bee7c4df)

**Fibbonacci Series on Makerchip**

![fibbo261841400-ce6ca185-dfd7-46ce-8053-c7c7be4cdf3f](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/416a77dd-6fc1-4771-885b-802653640553)

**Counter on Makerchip**

![counter261841567-c41b769d-c443-4d48-ab7d-cf7b72195b2a](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/edbe0728-2127-457a-bed9-ad7537d8ea3e)

**Sequential Calculator on Makerchip**

![calculation261841622-29f9ed75-575f-4f23-9bb4-31a2c250b607](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/51c6d140-ae82-4b92-8b1b-ec0611a3e62d)

 
</details>


<details>
 <summary>Pipeline Logic</summary>
	
* Pipeline logic refers to the systematic arrangement of processes or tasks in a sequential manner, where the output of one process becomes the input for the next process. 
* This approach is commonly used in various fields, including software development, data analysis, manufacturing, and more.
* Pipelines are efficient because they enable automation, parallel processing, and modularity in complex
   
* Now let's implement Pythagoras's theorem and compute it on hardware

![phy 261843647-53ab4774-0a09-4f00-8209-bc213e82321b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c01e9070-95bb-4f67-9826-92f67733ecb0)


* Let us compute Pythagoras's theorem over 3 cycles In Makerchip

* Cycle 1: Squaring on the sides a and b; Cycle 2: Adding the squared values of a and b; Cycle3: Finding the square root value of the sum
  
**Makerchip Implementation of Pythagoras's Theorem:**

![pythagorus 261843881-91afe442-6246-46fc-9415-cd30002a4c5a](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6bac34d7-90db-415e-bd44-2b2a57168717)


* Code reduction is the most useful property of the TL-Verilog when compared to System Verilog.

* The Retiming property in TL-Verilog is very easy and safe to implement whereas in SystemVerilog, it is very bug-prone.

* The pipelining also allows us to run the clock at a high frequency. Regardless of the way we structure our logic, we will be able to produce a new set of inputs on every clock edge. As a result, we get high throughput for our circuit.

**TL Verilog Syntax:**

![tl 261844564-2986c5d0-905d-47cf-b1a8-d1adb1dc9ecf](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7b34e0a3-28a4-4194-ab81-78be1b205d97)

**Fibbonaaci Series in Pipeline:**

![fibbo pipeline261845116-054b5cb7-123f-4637-8548-aaa17907e8c8](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/91434cd6-e026-4f6a-a8e8-c065d207704a)

**Implementation of Pipeline through TL-Verilog:**

![TL Pipeline fibbo261845214-4590d788-e40c-44e2-a972-937840b3ccf1](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/74e38833-10f4-4463-b335-e981baabe208)

* we can observe errors in the Pipeline:

![error pipeline fibbo261845252-4f8bdec4-025e-4220-aa3b-414d2a447152](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4d0c12a7-7ffe-4925-afaa-929216fe63af)

**Lab 1: Counter and Calculator in Pipeline** 

* Pipeline structure:

![pipeline structure261845315-e2fe6720-f561-430a-a39d-2c3441bf5643](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5170347e-3fe8-4367-8455-d2e88aa9229f)

* Makerchip Logic Implementation:
  
![pll](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/80c07b93-14bc-4a77-8ebc-23ca17b57f88)

**Lab2 : Cycle Calculator:**

* Pipeline structure:
  
![pl2](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0886bcb6-fab0-44bb-844a-ae013b6f3166)

* Makerchip Logic implementation:

 ![pli2 261848114-31e4f643-894e-4370-9830-92b6524fb300](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6db87d26-69d5-4bf9-9912-8fb902f677ed)


 
</details>


<details>
 <summary>Validity</summary>

* Validity is another feature in TL verilog which is asserted if a particular transactions in a pipeline is valid or true. A new scope, called “when” scope is introduced for this and it is denoted as ?$valid. This new scope has many advantages - easier design, cleaner debug, better error checking and automated clock gating.
  
* Validity provides :

(1) Automated Clock gating
(2) Easier debug
(3) Better error checking
(4) Cleaner design 

**Implementation of Pythagoran's Theorem with Validity:**

![L261848454-f85062ab-35aa-4644-8a52-7d44750ab5d4](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0b622844-3ef2-42ee-90b1-3a137c40e7fa)

* Clock Gating is a power-saving property.

**Lab Distance Accumulator with Pythagoran's Theorem:**

* Pipeline structure:
  
 ![p261852154-217a0e1a-55f7-41a6-aa47-4f42e9182609](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c48ee947-b4b2-4b78-a2a4-fc6035e0d2fb)

* Makerchip Implementation of Distance Accumulator of Pythagoran's Theorem:

  ![pi261852159-d8dd50fb-1f93-4d7c-8768-5c7a5eb52c78](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/07312989-f1a9-46c0-ac0d-791181d8d200)


**Lab Cycle Calculator with Validity:**

* Pipeline Structure:

![pm](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c498c2db-c4cd-42ff-8f1e-56bc55ab2c2b)


* Makerchip Implementation:
  
![pmo261852343-40f04672-543d-4705-b340-3ff00b774c1f](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/44ccbea9-d19d-4fc0-91a7-4a212eb8ebe3)


**Lab Calculator with Single Value Memory:**

![po261852971-e1a3acc0-4388-43fc-862b-dd197cad6617](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3d0fde0d-0424-4301-abd5-acb2dd1dccda)

</details>

<details>
 <summary>Wrap Up</summary>

 **Lab:Conway Game of Life**

 ![cw261852668-48b9a59c-d329-4e8b-9a73-956806ae8b0e](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c68320ac-28b3-475a-8ada-1a60c7b66053)


**Pythagoran's theorem**

* Pipeline structure:
  
![cli261852745-635ab276-17c3-4c28-a1fe-fb74380cfd96](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/79fb15f2-a852-443a-870b-5aeb8c2d6f4b)

* Makerchip Implementation:

![clii 261852671-72343c4b-d972-40ab-bf0d-6dfe32a09857](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/640f419c-d6eb-4d0e-9a81-d0ac717a8e09)

</details>
</details>
</details>


## DAY 4
<details>
<summary>DAY-4</summary>
<br>
 <details>
 <summary>Basic RISC-V CPU Micro-Architecture</summary>

**Introduction to Simple RISC-V Micro-Architecture**

![MC 261853432-c4589d82-eecb-4ed3-875a-40441e20ab5d](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4d173557-ad88-4b0c-87df-75e46b9a37a3)

* A single-cycle microarchitecture for a RISC-V CPU is a simple and straightforward design in which each instruction is executed within a single clock cycle. While this approach is easy to understand, it has limitations in terms of performance and efficiency. Let's break down the key components of a single-cycle RISC-V CPU's microarchitecture:

(1) Instruction Fetch (IF): This stage is responsible for fetching the next instruction from memory. The program counter (PC) is used to determine the address of the next instruction to fetch. The fetched instruction is then passed to the next stage.

(2) Instruction Decode (ID): In this stage, the fetched instruction is decoded to determine the operation it represents and the operands it requires. Register values are read from the register file if needed.

(3) Execution (EX): This stage performs the actual computation or operation specified by the instruction. For arithmetic and logical operations, this stage performs the required calculations. For memory access instructions, the memory address may be calculated here.

(4) Memory Access (MEM): In this stage, memory access operations such as load and store instructions are performed. If a load instruction is being executed, the data is read from memory. If a store instruction is being executed, the data is written to memory.

(5) Write-Back (WB): The final result of the instruction is written back to the appropriate register in this stage. This stage completes the execution of the instruction.

* Note that these are the fundamental stages of a classic five-stage pipeline. Some processors may have additional stages, or they may combine certain stages for improved performance. Additionally, some high-performance CPUs might use techniques like out-of-order execution to increase instruction-level parallelism, which can complicate the pipeline structure.

</details>

<details>
 <summary>Fetch and Decode</summary>
	
**L1 - Implementation Plan and Lab for PC**

 * Pipeline structure

![L1262119772-30fc43ad-fd1d-4065-b113-72b537a5659f](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e275c95d-5aa1-4e60-a0a2-884a5f748314)


![26L1B2089499-79905e9b-cb1e-447f-ba69-000124897741](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8c4438a6-5a34-46b7-9029-fe109396e5f1)

* Makerchip Implementation:

![L1C262089513-1809b4c3-40e5-40a4-94ab-790d4d914fec](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8650006d-f780-4dd3-9119-8df130638191)



**L2 - Lab for instruction fetch logic**

 * Pipeline structure (part 1):
	
![4aa261861824-d4f837f2-82b2-4253-b818-b336518e1476](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/97c848d9-e4c4-4e87-8847-5cf4d3ebacd7)

* Pipeline structure (part 2):

![4ab 261861853-3700e20f-e543-4c19-9d35-2c25b1d67bfe](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/46563c65-9b82-42fd-95d7-66b9e5729f66)

* Makerchip Implementation:
  
![Screenshot from 2023-08-22 21-42-20](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/478593c9-a791-4a98-a8fc-abd475359161)


**L3 - Lab for RV instruction types Decode Logic**

* Pipeline structure:
  
![L4a261862793-58ec9bda-6754-4337-8a77-ded3442cd3de](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8e085b02-eec8-4b4d-a538-62922f106856)

* Makerchip output:
  
![L4a261862793-58ec9bda-6754-4337-8a77-ded3442cd3de](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a5d1917e-ede9-42d9-8783-2a99e9c91528)

**L4 - Instruction immediate Decode**

![L4aa261863215-e040c77e-3bf8-452a-916e-c42f3b38b780](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/14391136-61d8-4c84-b078-60bd4a3a9f03)

* Makerchip output:
  
![L4bb 261863229-48fdc48e-5d2c-448d-b2ab-811f9c035ed6](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/980cbc39-bc18-43b2-b6d8-fd03e666164b)

**L5 - Instruction Decode**

![L45261863364-520d2924-cfda-4ddd-9779-ffa88619f976](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3d8f5e7d-7b25-47e6-a10f-1fc7bae31f08)

* Makerchip output:
 
![L45B261863387-6b08bebf-3938-41ec-84ed-2bec32cae7e4](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/805ae28e-23b7-4a89-b9e2-22b1a2a76f3c)

**L6 - Instruction Field Decode**

![L46 261863610-3aa09860-ea31-4f94-a6d7-cb30dd9405dc](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7efff408-affe-42c5-87cd-f8999dd3975a)

* Makerchip output:
  
![L46B 261863629-41305a3a-ba44-4a58-912f-e286f6f58cc6](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/49a6eea1-886c-46d8-842a-08852d53c65e)

**L7 - Instruction Decode_2**

![261863655-61a5ae40-8803-4fb4-b45f-dbc0316f05bf](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6807090a-2d4e-4ba0-85f2-c3228be43187)


* Makerchip output:

![L7b 261863677-c268a250-e8fc-4cde-828e-3ed13f646ad8](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9900a0bb-034c-4f30-af56-8d0836adc549)

</details>

<details>
 <summary>RISC-V Control Logic</summary>

**L1 : Register File Read**

* Pipeline structure:
  
![l4 a261865078-bb6d8153-9b7b-444c-bc76-f9c1b30cf097](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d2b900a4-d114-4d2b-aa46-4825b52875ca)


* Makerchip Implementation:

![l4b 261865102-0f770030-b163-4665-a201-3dea20163d35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/bff227f3-9ba0-425b-97e9-a3b39cefeae2)


**L2: Register file Read -2**

* Pipeline structure:
  
![ls1 262119908-6d5282fb-1da5-47c3-b557-72c0189743a3](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f93efdd1-2724-4716-959a-14ef4825a59e)


* Makerchip Implementation:
  
![ls2 262130943-267fffcb-4a75-4be4-bd0b-4c7bffd9d9d2](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9fa607e6-f25e-4e1c-be43-328dcb810470)

**L3 : Arithmetic and Logic unit(ALU)**

* Pipeline structure:

![L4p261865159-354573dc-fdf5-4300-b207-7444128fd37c](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c7851734-cb18-494d-9497-061783e7017a)

* Makerchip Implementation:

![L4q261865233-7fd0d43c-9e3a-48fb-a621-de17d6f76488](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4301701a-f20d-46d1-ad67-60646302d636)

**L4 : Register File Write**

* Pipeline structure:
  
![4ls261865442-d2412f07-ffe3-43c1-b607-77d1a5929932](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e61553bf-05eb-45f3-9d12-cad2d42c20e8)

* Makerchip Output:

  ![4lt 261865510-23d81210-e835-4b26-a47b-5d1c4702b424](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9d65ce27-3f54-4014-85fc-bf7d0c35e87c)

**L5 : Concept of array and Register file details**

* Pipeline structure:

![lp1 262119943-424d6240-c7c5-4332-801d-0d4348e27387](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8820ff85-bd23-4e18-9531-97fd47b0b8ab)

* Makerchip Implementation

![lp2 262130969-126ca197-6f8e-457e-8a93-bc395b3b744e](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0ac29389-8fe2-4876-b3d0-94eee147c0a2)

**L6 :Completing Branch Instructions Implementations**

* Pipeline structure:
  
![Screenshot from 2023-08-23 01-08-43](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/52908f63-1fcd-4693-bde7-d4f79e76ab86)

* Makerchip Implementation:

![4LTR 262130980-2845cc10-0808-4351-bca8-03d80daabfda](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/10eedfc2-90e9-4d56-bd58-1149b45594eb)

**L7 - Lab to create simple Testbench**

* Pipeline structure:
  
![mb262119979-e4b9243d-dfda-4cd4-b898-02ee75d4cb96](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/39a00439-7abf-48cd-93cd-416c00792909)

* Makerchip Implementation:

![mba 26230986-1820b072-7fe8-4cef-9399-57d09542b0d3](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/384956e6-9582-454f-803f-7add3a36d144)

 
</details>
</details>

## DAY-5
<details>
 <summary>DAY-5</summary>
	
 <details>
 <summary>Complete Pipelined RISCV CPU Micro-Architecture</summary>
	 
 <details>
 <summary>Pipeline Hazards</summary>

* Control flow hazards occur when the execution of instructions is affected by changes in the program's control flow, such as branches or jumps. These hazards can lead to incorrect instruction execution and can slow down the pipeline.
  
* There are three main types of control flow hazards:
  
* Branch Hazards: These occur when a pipeline encounters a branch instruction that changes the program counter (PC) before the previous instructions have completed their execution. This can lead to wasted work if the pipeline has already started executing instructions following the branch that will not be needed.
  
* Control Hazards: Control hazards refer to situations where the pipeline has to stall or insert "bubble" stages in order to resolve the branch instruction. This happens when the outcome of a branch is not yet known, and subsequent instructions that depend on the branch outcome cannot proceed until the branch is resolved.

* Jump Hazards: Similar to branch hazards, jump hazards occur when a jump instruction changes the program counter before instructions following the jump have completed. This can also lead to wasted work and inefficient pipeline utilization.

* Read-After-Write (RAW) Hazards:
Read-after-write hazards occur when an instruction depends on the result of a previous instruction that writes to a register or memory location. These hazards can lead to incorrect results if not handled properly.

* True Dependency (RAW): An instruction depends on the result of a previous instruction that writes to the same location. For example, if instruction B reads a value produced by instruction A, and instruction A has not yet completed execution, a hazard exists.

* Anti-Dependency (WAR): An instruction depends on a value that a subsequent instruction is going to write. For example, if instruction A writes to a register and then instruction B reads from the same register, instruction B might read the wrong value if it's executed before A's write.

* Output Dependency (WAW): Two instructions are trying to write to the same location, and the order of their execution affects the final result. This can lead to incorrect results if not properly managed.

* Below is the load-store diagram shown:
  
![d5 262429014-de432e69-b349-4398-912b-53811cd7c4b0](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1a28eee2-cf32-46f9-981d-fa2e8a297bc7)

* To understand the pipeline look below the waterfall logic diagram:

  ![image-2](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d6f899d8-c6b7-432e-8973-59ff5c1ee2f0)

**Lab to 3 Cycle Valid Signal** 

The implementation output is:

![p1 261847180-4e094372-0f25-4c77-b7c1-906d3b04ee5f](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8e234d51-3870-4599-95eb-c609ff975877)

</details>

 <details>
 <summary>Solutions to Pipeline Hazards</summary>

**Lab to Register File Bypass**

* Pipeline structure:
  
![D5A261848118-50d9c9b0-05bc-4a5a-976e-c253deddaa59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8c653e83-c468-473a-a743-0739c553b480)


![Screenshot from 2023-08-22 01-47-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3838aebf-f87b-458e-8475-4a301ab1d5e2)


* The implementation output is as shown below:

![D5B 261848345-d15c47be-6335-4db8-9689-429d927a1ca5](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3aa71a46-e837-48aa-9f68-256542b3bb30)

**Lab to BRANCHES**

* Pipeline structure:

![Screenshot from 2023-08-22 02-07-14](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/be478175-7ce8-4897-8b31-1aa6021c6615)

* The implementation output is as shown below:
  
![p4 261848718-6f4a4895-03ea-47fd-8a19-ae23269ec885](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/86aa0ae2-2381-4917-9f53-990a69c9ae0d)

**Lab to ALU**

![p5 261849691-96477a58-80a0-43d8-9716-11be0385e3e9](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c7fdaa40-9fd9-4e2d-b327-bc8323da791e)

</details>

 <details>
 <summary>Load/Store Instructions and Completing RISC-V CPU</summary>

**Lab to LOAD:**

* Pipeline structure:
  
![Screenshot from 2023-08-22 02-13-30](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/52dc5c72-27d2-4c1d-8f26-abd5c985dae9)

![Screenshot from 2023-08-22 02-13-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5c5251ee-dc1e-481f-8be3-688d9a001966)


* The Makerchip output is as shown below:

![p6 261852929-a5bbd00d-df08-4294-bcfe-3f1157b88b0a](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/790e2907-fe09-4ec1-839a-8ea43e6e552d)


**Lab to LOAD/STORE:**

* Pipeline structure:
  
![pf1 261853239-4106c86c-15c4-4543-8a40-67fa9e28d4bf](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9d9916a6-bdd6-4318-9f7a-3bdc5caf58c6)


* The Makerchip output is as shown below:

![pf261853264-1eded761-772a-46e3-9a80-584da3f4afb5](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3572cfba-514f-4cce-9ad0-2bc6506ecb3d)

**Lab to JUMPS:**

* Pipeline structure:

![pf1 261853239-4106c86c-15c4-4543-8a40-67fa9e28d4bf](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/51e848fe-3bca-4e27-b6e0-e8df0adcffd4)


* The Makerchip output is as shown below:

![pf261853264-1eded761-772a-46e3-9a80-584da3f4afb5](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7b1eacb2-c226-4773-89ce-642008fd3051)

</details>

<details>
<summary>RISC-V Core CPU Final</summary>

* The RISC-V final code is shown below:

```
\m4_TLV_version 1d: tl-x.org
\SV
   // This code can be found in: https://github.com/stevehoover/RISC-V_MYTH_Workshop
   
   m4_include_lib(['https://raw.githubusercontent.com/Lasya-G/Risc_V/main/risc-v_shell_lib.tlv'])

\SV
   m4_makerchip_module   // (Expanded in Nav-TLV pane.)
\TLV

   // /====================\
   // | Sum 1 to 9 Program |
   // \====================/
   //
   // Program for MYTH Workshop to test RV32I
   // Add 1,2,3,...,9 (in that order).
   //
   // Regs:
   //  r10 (a0): In: 0, Out: final sum
   //  r12 (a2): 10
   //  r13 (a3): 1..10
   //  r14 (a4): Sum
   //
   // External to function:
   m4_asm(ADD, r10, r0, r0)             // Initialize r10 (a0) to 0.
   // Function:
   m4_asm(ADD, r14, r10, r0)            // Initialize sum register a4 with 0x0
   m4_asm(ADDI, r12, r10, 1010)         // Store count of 10 in register a2.
   m4_asm(ADD, r13, r10, r0)            // Initialize intermediate sum register a3 with 0
   // Loop:
   m4_asm(ADD, r14, r13, r14)           // Incremental addition
   m4_asm(ADDI, r13, r13, 1)            // Increment intermediate register by 1
   m4_asm(BLT, r13, r12, 1111111111000) // If a3 is less than a2, branch to label named <loop>
   m4_asm(ADD, r10, r14, r0)            // Store final result to register a0 so that it can be read by main program
   m4_asm(SW, r0, r10, 10000)           // Store the final result value to byte address 16
   m4_asm(LW, r15, r0, 10000)           // Load the final result value from adress 16 to x17
   
   // Optional:
   // m4_asm(JAL, r7, 00000000000000000000) // Done. Jump to itself (infinite loop). (Up to 20-bit signed immediate plus implicit 0 bit (unlike JALR) provides byte address; last immediate bit should also be 0)
   m4_define_hier(['M4_IMEM'], M4_NUM_INSTRS)


   |cpu
      @0
         $reset = *reset;
         
         //MODIFIED NEXT PC LOGIC FOR INCLUDING BRANCH INSTRCUTIONS
         $pc[31:0] = >>1$reset ? 32'b0 :
                     >>3$valid_taken_branch ? >>3$br_target_pc :
                     >>3$valid_load ? >>3$inc_pc :
                     >>3$valid_jump && >>3$is_jal ? >>3$br_target_pc :
                     >>3$valid_jump && >>3$is_jalr ? >>3$jalr_target_pc :
                     >>1$inc_pc ;
         //START LOGIC TO PROVIDE FIRST VALID LOGIC
         //$start = (>>1$reset && $reset == 0) ? 1'b1 : 1'b0;
         //$valid = $reset ? 1'b0 :
                  //$start ? 1'b1 : >>3$valid;
     
      @1  
         //INSTRUCTION FETCH
         $inc_pc[31:0] = $pc + 32'd4;
         
         $imem_rd_en = !$reset;
         $imem_rd_addr[M4_IMEM_INDEX_CNT-1:0] = $pc[M4_IMEM_INDEX_CNT+1:2];
         
         $instr[31:0] = $imem_rd_data[31:0];
         
         //INSTRUCTION TYPES DECODE        
         
         $is_u_instr = $instr[6:2] ==? 5'b0x101;
         
         $is_s_instr = $instr[6:2] ==? 5'b0100x;
         
         $is_r_instr = $instr[6:2] ==? 5'b011x0 ||
                       $instr[6:2] ==? 5'b01011 ||
                       $instr[6:2] ==? 5'b10100;
         
         $is_j_instr = $instr[6:2] ==? 5'b11011;
         
         $is_i_instr = $instr[6:2] ==? 5'b0000x ||
                       $instr[6:2] ==? 5'b001x0 ||
                       $instr[6:2] ==? 5'b11001;
         
         $is_b_instr = $instr[6:2] ==? 5'b11000;
         
         //INSTRUCTION IMMEDIATE DECODE
         $imm[31:0] = $is_i_instr ? {{21{$instr[31]}}, $instr[30:20]} :
                      $is_s_instr ? {{21{$instr[31]}}, $instr[30:25], $instr[11:7]} :
                      $is_b_instr ? {{20{$instr[31]}}, $instr[7], $instr[30:25], $instr[11:8], 1'b0} :
                      $is_u_instr ? {$instr[31:12], 12'b0} :
                      $is_j_instr ? {{12{$instr[31]}}, $instr[19:12], $instr[20], $instr[30:21], 1'b0} :
                                                            32'b0;
         //INSTRUCTION DECODE
         $opcode[6:0] = $instr[6:0];
         
         
         //INSTRUCTION FIELD DECODE
         $rs2_valid = $is_r_instr || $is_s_instr || $is_b_instr;
         ?$rs2_valid
            $rs2[4:0] = $instr[24:20];
           
         $rs1_valid = $is_r_instr  || $is_s_instr || $is_b_instr || $is_i_instr;
         ?$rs1_valid
            $rs1[4:0] = $instr[19:15];
         
         $funct3_valid = $is_r_instr  || $is_s_instr || $is_b_instr || $is_i_instr;
         ?$funct3_valid
            $funct3[2:0] = $instr[14:12];
           
         $funct7_valid = $is_r_instr ;
         ?$funct7_valid
            $funct7[6:0] = $instr[31:25];
           
         $rd_valid = $is_r_instr  || $is_u_instr || $is_j_instr || $is_i_instr;
         ?$rd_valid
            $rd[4:0] = $instr[11:7];
         
         
      @2
         //INSTRUCTION DECODE
         $dec_bits[10:0] = {$funct7[5],$funct3,$opcode};
         $is_beq = $dec_bits ==? 11'bx_000_1100011;
         $is_bne = $dec_bits ==? 11'bx_001_1100011;
         $is_blt = $dec_bits ==? 11'bx_100_1100011;
         $is_bge = $dec_bits ==? 11'bx_101_1100011;
         $is_bltu = $dec_bits ==? 11'bx_110_1100011;
         $is_bgeu = $dec_bits ==? 11'bx_111_1100011;
         $is_addi = $dec_bits ==? 11'bx_000_0010011;
         $is_add = $dec_bits ==? 11'b0_000_0110011;
         $is_lui = $dec_bits ==? 11'bx_xxx_0110111;
         $is_auipc = $dec_bits ==? 11'bx_xxx_0010111;
         $is_jal = $dec_bits ==? 11'bx_xxx_1101111;
         $is_jalr = $dec_bits ==? 11'bx_000_1100111;
         $is_load = $opcode == 7'b0000011;
         $is_sb = $dec_bits ==? 11'bx_000_0100011;
         $is_sh = $dec_bits ==? 11'bx_001_0100011;
         $is_sw = $dec_bits ==? 11'bx_010_0100011;
         $is_slti = $dec_bits ==? 11'bx_010_0010011;
         $is_sltiu = $dec_bits ==? 11'bx_011_0100011;
         $is_xori = $dec_bits ==? 11'bx_100_0100011;
         $is_ori = $dec_bits ==? 11'bx_110_0100011;
         $is_andi = $dec_bits ==? 11'bx_111_0100011;
         $is_slli = $dec_bits ==? 11'b0_001_0100011;
         $is_srli = $dec_bits ==? 11'b0_101_0100011;
         $is_srai = $dec_bits ==? 11'b1_101_0100011;
         $is_sub = $dec_bits ==? 11'b1_000_0110011;
         $is_sll = $dec_bits ==? 11'b0_001_0110011;
         $is_slt = $dec_bits ==? 11'b0_010_0110011;
         $is_sltu = $dec_bits ==? 11'b0_011_0110011;
         $is_xor = $dec_bits ==? 11'b0_100_0110011;
         $is_srl = $dec_bits ==? 11'b0_101_0110011;
         $is_sra = $dec_bits ==? 11'b1_101_0110011;
         $is_or = $dec_bits ==? 11'b0_110_0110011;
         $is_and = $dec_bits ==? 11'b0_111_0110011;
         
         $jalr_target_pc[31:0] = $src1_value +$imm ;
      @3
         $is_jump = $is_jal || $is_jalr ;   
         `BOGUS_USE($is_beq $is_bne $is_blt $is_bge $is_bltu $is_bgeu $is_addi $is_add
                    $is_lui $is_auipc $is_jal $is_jalr $is_load $is_sb $is_sh $is_sw $is_slti
                    $is_sltiu $is_xori $is_ori $is_andi $is_slli $is_srli $is_srai $is_sub $is_sll
                    $is_slt $is_sltu $is_xor $is_srl $is_sra $is_or $is_and)
         
      @2  
         //REGISTER FILE READ
         //$rf_wr_en = 1'b0;
         //$rf_wr_index[4:0] = 5'b0;
         //$rf_wr_data[31:0] = 32'b0;
         $rf_rd_en1 = $rs1_valid;
         $rf_rd_index1[4:0] = $rs1;
         $rf_rd_en2 = $rs2_valid;
         $rf_rd_index2[4:0] = $rs2;
         
         $src1_value[31:0] = >>1$rf_wr_en && (>>1$rf_wr_index == $rf_rd_index1) ? >>1$result : $rf_rd_data1;
         $src2_value[31:0] = >>1$rf_wr_en && (>>1$rf_wr_index == $rf_rd_index2) ? >>1$result : $rf_rd_data2;
         $br_target_pc[31:0] = $pc +$imm;
         
      @3  
         //ARITHMETIC AND LOGIC UNIT (ALU)
         
         $sltu_rslt[31:0] = $src1_value < $src2_value;
         $sltiu_rslt[31:0] = $src1_value < $imm;
         $result[31:0] = $is_addi ? $src1_value + $imm :
                         $is_add ? $src1_value + $src2_value :
                         $is_andi ? $src1_value & $imm :
                         $is_ori ? $src1_value | $imm :
                         $is_xori ? $src1_value ^ $imm :
                         $is_slli ? $src1_value << $imm[5:0] :
                         ($is_addi || $is_load || $is_s_instr) ? $src1_value + $imm :
                         $is_srli ? $src1_value >> $imm[5:0] :
                         $is_and ? $src1_value & $src2_value :
                         $is_or ? $src1_value | $src2_value :
                         $is_xor ? $src1_value ^ $src2_value :
                         $is_sub ? $src1_value - $src2_value :
                         $is_sll ? $src1_value << $src2_value[4:0] :
                         $is_srl ? $src1_value >> $src2_value[4:0] :
                         $is_sltu ? $sltu_rslt :
                         $is_sltiu ? $sltiu_rslt :
                         $is_lui ? {$imm[31:12],12'b0} :
                         $is_auipc ? $pc + $imm :
                         $is_jal ? $pc + 4 :
                         $is_jalr ? $pc + 4 :
                         $is_srai ? { {32{$src1_value[31]}},$src1_value} >> $imm[4:0] :
                         $is_slt ? ($src1_value[31] == $src2_value[31]) ? $sltu_rslt : {31'b0,$src1_value[31]} :
                         $is_slti ? ($src1_value[31] == $imm[31]) ? $sltiu_rslt : {31'b0,$src1_value[31]} :
                         $is_sra ? { {32{$src1_value[31]}},$src1_value} >> $src2_value[4:0] :
                         32'bx;
         
         
         //REGISTER FILE WRITE
         $rf_wr_en = ($rd_valid && $rd != 5'b0 && $valid) || >>2$valid_load;
         $rf_wr_index[4:0] = >>2$valid_load ? >>2$rd : $rd;
         $rf_wr_data[31:0] = >>2$valid_load ? >>2$ld_data : $result;
         
         
         //BRANCH INSTRUCTIONS 1
         $taken_branch = $is_beq ? ($src1_value == $src2_value):
                         $is_bne ? ($src1_value != $src2_value):
                         $is_blt ? (($src1_value < $src2_value) ^ ($src1_value[31] != $src2_value[31])):
                         $is_bge ? (($src1_value >= $src2_value) ^ ($src1_value[31] != $src2_value[31])):
                         $is_bltu ? ($src1_value < $src2_value):
                         $is_bgeu ? ($src1_value >= $src2_value):
                         1'b0;
          //CYCLE VALID INSTRUCTIONS
         $valid = !(>>1$valid_taken_branch || >>2$valid_taken_branch ||
                    >>1$valid_load || >>2$valid_load) ;
         
         $valid_load = $valid && $is_load ;
         //$valid = !(>>1$valid_taken_branch || >>2$valid_taken_branch);
         $valid_taken_branch = $valid && $taken_branch;
         $valid_jump = $is_jump && $valid ;
         `BOGUS_USE($taken_branch)
      @4
         //MINI 1-R/W MEMORY
         $dmem_wr_en = $is_s_instr && $valid ;
         $dmem_addr[3:0] = $result[5:2] ;
         $dmem_wr_data[31:0] = $src2_value ;
         $dmem_rd_en = $is_load ;
         
      @5
         //LOAD DATA
         $ld_data[31:0] = $dmem_rd_data ;   
         
         
         

      // Note: Because of the magic we are using for visualisation, if visualisation is enabled below,
      //       be sure to avoid having unassigned signals (which you might be using for random inputs)
      //       other than those specifically expected in the labs. You'll get strange errors for these.

   
   // Assert these to end simulation (before Makerchip cycle limit).
   //*passed = *cyc_cnt > 40;
   *passed = |cpu/xreg[15]>>5$value == (1+2+3+4+5+6+7+8+9) ;
   *failed = 1'b0;
   
   // Macro instantiations for:
   //  o instruction memory
   //  o register file
   //  o data memory
   //  o CPU visualization
   |cpu
      m4+imem(@1)    // Args: (read stage)
      m4+rf(@2, @3)  // Args: (read stage, write stage) - if equal, no register bypass is required
      m4+dmem(@4)    // Args: (read/write stage)
   
   m4+viz(@4)    // For visualisation, argument should be at least equal to the last stage of CPU logic
   //@4 would work for all lab
\SV
   endmodule
```

* The Makerchip output is as shown below:
  
![final](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6e9537e6-78f2-48fd-b54b-7bf5fea99c59)


</details>
</details>
</details>

## ACKNOWLEDGEMENT
<details>
 <summary>ACKNOWLEDGEMENT</summary>

* Kunal Ghosh, VSD Corp. Pvt. Ltd.
* Chatgpt
* Kanish R,Colleague,IIIT B
* Pruthvi Parate,Colleague,IIIT B
* Emil Jayanth Lal,Colleague,IIIT B
* Bhargav Dv,Colleague,IIIT B
* Geetima Kachari,Assistant professor
* Shivani Shah,IIIT B Senior
* Bala Dhinesh,Engineer,Testorrent
* Steve Hoover,Redwood Eda

</details>

## REFERENCES 
<details>
 <summary>REFERENCES</summary>

* https://www.vsdiat.com
* https://github.com/kunalg123/riscv_workshop_collaterals
* https://github.com/RISCV-MYTH-WORKSHOP/RISC-V-CPU-Core-using-TL-Verilog.git
* https://github.com/riscv/riscv-gnu-toolchain
* https://steveicarus.github.io/iverilog/
* https://github.com/kunalg123/
* https://github.com/stevehoover/RISC-V_MYTH_Workshop
* https://makerchip.com/sandbox/
* https://redwoodeda.com

</details>
</details>
</details>
</details>
</details>
