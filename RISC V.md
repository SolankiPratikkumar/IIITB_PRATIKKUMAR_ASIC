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
  <summary>RISCV GCC compile And Disassemble</summary>

  ```

 sqwdq
```


![Screenshot from 2023-08-20 20-37-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1871dbe3-2333-436c-ae3e-c0b7fd01cab8)



  </details>
 </details>
</details>
</details>
