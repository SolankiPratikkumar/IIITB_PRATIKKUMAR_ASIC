[](url) Physical Design of ASICs PART2 


## DAY 1
<details>
<summary>DAY-1</summary>
<br>

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
 
 <details>
  <summary>Detailed Discription of Course</summary>
 </details>
</details>
</details>
