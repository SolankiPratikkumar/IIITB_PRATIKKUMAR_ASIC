[](url) Physical Design of ASICs PART2 


## Quick links:


[DAY 1](#day-1)

[DAY 2](#day-2)

[DAY 3](#day-3)

[DAY 4](#day-4)

[DAY 5](#day-5)



[REFERENCES](#References)


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
$ riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
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

* Different Register with their ABI name and their usage are mentioned in above image which will be used in upcoming labs

  </details>
</details>

 <details>
 <summary>Labs works ABI function calls</summary>

<details>
 <summary>Study new ALgorithm for sum 1 to N using ASM</summary>

* 
  
  </details>
</details>
</details>
