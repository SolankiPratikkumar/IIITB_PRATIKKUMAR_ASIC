[](url) Physical Design of ASICs - Advanced Physical Design using OpenLANE


## DAY 1
<details>
<summary>DAY-1</summary>
<br>
 <details>
 <summary>Inception of Open Source EDA, OpenLANE and Sky130PDK</summary>
 <details>
  <summary>SK1_How to Talk to Computer</summary>
 <details>
  <summary>L1_Introduction to QFN-48 Package, Chip, Pad, Core, Die, IPs</summary>

* The Arduino or any other board block structure looks as below
 ![Screenshot from 2023-09-09 12-12-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/15592065-db6f-48ca-9107-c93d7b5f153d)

* Below there is an IC or processor which is now called as Package QFN 48(Quad Flat No Lead) which is 7mm*7mm area and inside it will communicate with a chip
![Screenshot from 2023-09-09 12-15-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8104fbde-5b38-4994-a06a-4709cf2c4842)

* This chip is manufactured on a silicon chip called DIE; PADS makes communication with input and output signals and CORE contains all digital logic inside it
![Screenshot from 2023-09-09 12-18-11](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/16af2006-ff48-4cb2-97e5-549918ba5d72)

* Below is the vital terminology "Foundry IPs" which means a foundry is a factory which manufactures the chip using big machines and IPs an Intellectual Property which is done by communication with the help of files with an organisation. The term "MACROS" performs Digital Operation and consists of pure Digital Logic inside the chip.

![Screenshot from 2023-09-09 12-24-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/69a59fac-f04a-4a43-8ec8-752b4d09e309)

 </details>

  <details>
  <summary>L2_Introduction to RISC-V</summary>
   
   * C-Program is run by the compile to assembly language of RISC V and that makes Hardware Layout operation (qflow); that Hardware can be RISC-V

***WHAT IS RISC-V***

* RISC-V is an open-source instruction set architecture used to develop custom processors for a variety of applications, from embedded designs to supercomputers.
* RISC-V is an open-source instruction set architecture (ISA) for designing computer processors. 
* An instruction set architecture defines the instructions a processor can execute, the formats for those instructions, and the corresponding hardware behaviour. 
* RISC-V is designed to be versatile, customizable, and open, making it well-suited for a wide range of applications, from embedded systems to high-performance computing.
* Briefly the architecture can be understood below:
* RISC-V Architecture --->  Implementation (picorv32 cpu core) ---> Hardware Layout(qflow)

 ![Screenshot from 2023-09-09 18-22-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/15f88da2-a69a-4521-aee6-a0bf3c358902)

# RISC-V Characteristics

* Is a proven ISA and follows established RISC design principles
* Has single-cycle instructions
* Uses a load-store architecture
* Features a simple, stable, software-centric design (small, fixed base with modular fixed-standard extensions)
* Is modular, layered and extensible, allowing for software and hardware freedom in architecture
* Flexible and scalable (i.e., suitable for microcontrollers to personal computers to supercomputers)
* Has 32- and 64-bit variants and extensions to support floating point instructions
* Is supported by various language compilers (e.g., GNU Compiler Collection and Linux operating system)
* Offers a range of hardware support from microcontrollers to systems on module, systems on chip and field programmable gate arrays
* Accelerates the design-to-market timeline through collaboration and open-source IP reuse
  
</details>

 <details>
  <summary>From App to Hardware</summary>

* The Flow of the RISC-V is explained in the below image:
   
 ![Screenshot from 2023-08-20 14-48-36](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8415bef2-9de6-494e-95dd-d00528000659)

* "Application Software" (like Mozilla Firefox, Stopwatch app) is input to the "System Software" which then passes through the compiler and generated to RISC-V in an instruction.exe file and the exe file is passed to the Assembler which converts to Machine Binary language and Finally that is executed to "Hardware" Chip layout

 * The example of the RISC-V flow can be understood by below StopWatch application:
   
![Screenshot from 2023-08-20 14-47-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9ccf5217-418a-4c1d-95f2-5ea503bc70dd)

* Same way it works for other Application Software:

  ![Screenshot from 2023-08-20 14-55-09](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c0679442-3926-4659-b170-e361fe0fb134)

* Works in the following way, the C-program is created by an application and provided it to input to the compiler to which the output is RISC-V instruction and that is input to the assembler and the output of the assembler is Machine language code which is in binary format and that machine level code is input for the Hardware that is here Chip layout. Here the Compiler and assembler together form a System Software block.
  
![r1aWhatsApp Image 2023-08-20 at 4 11 34 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/50799b6e-38b9-437b-a360-963def94357e)

 </details>
 </details>
 
  <details>
  <summary>SK2_SOC Design and OpenLANE</summary>
 <details>
  <summary>L1_Introduction to all components of Open source digital ASIC Design </summary>
*
  
 </details>
 </details>
 </details>
  </details>
