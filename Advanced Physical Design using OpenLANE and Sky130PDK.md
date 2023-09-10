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
  <summary>L3_From Software Application to Hardware</summary>

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
  <summary>L1_Introduction to all components of Open source Digital ASIC Design </summary>
  

* ASIC consists of main components like RTL IPs, EDA Tools, PDK Data as shown in below image:
![Screenshot from 2023-09-10 21-37-47](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/37da65cc-1014-4d96-8821-8e5d5885e91f)

* Here we are starting to see Pure Play FABs and Fabless design companies.
* PDK = the interface between the FAB and the Designers
      = Process Design Kit
* Google made an agreement with Skywater Technology and then release an opensource PPDK to masses which was FOSS 130nm Production PDK
* 130nm Technology PDK has 6% distribution of pure-play integrated circuit foundry sales in 2019 by feature sizes
* Below image shows us all the main components of RTL IPS, EDA Tools, PDK Data respectively
  
![Screenshot from 2023-09-10 21-47-23](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/22ecff72-8a65-45b2-ad11-c812e9bec802)

* And collection of files are used to model a fabrication process for the EDA tools used to design and IC
* Process Design Rules, Device Models, DIgital Standard Cell Libraries,etc as seen in the below image
![Screenshot from 2023-09-10 21-51-46](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0e42da6c-f518-4419-b125-eed080977982)

(Question) Is 130nm Technology Fast?
* Yes,its Fast Technology
* The Intel P4EE @3.46GHz runs, which is much fast 
* OSU team reported 327 MHz post layout clock frequency for a single cycle RV32i CPU
* A Pipeline version can achieve > 1GHz clock!

* The ASICs design methodology is implemented through flow:
* ASIC Flow Onjective: RTL to GDS II
* Also called Automated PnR and/or Physical Implemetation

</details>

<details>
 <summary>L2_Simplified RTL to GDS II Flow</summary>

* The Flowchart of the Entire Flow is summarise below in image: 
![Screenshot from 2023-09-10 23-14-15](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0c237708-7cf2-4059-aa51-8e2018b72500)


* STEP 1:  Synthesis
  
* Convert RTL to a circuit out of components from the standard cell library(SCL)
* Standard cells have regular layout
* Each cells comes with different views/models utilize by different EDA views of Libraries
  * Electrical HDL & Spice
  * Layout(Abstract & Layout)

![Screenshot from 2023-09-10 23-21-53](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b95836c8-e631-4aaa-a4a0-4a6371d9df58)

* STEP 2: Floor Planning and Power Planning
  
* The objective overhere is to plan silicon area & create robust power distribution of the circuits
* Chip Floor Planning: Partition the chip die between different system building blocks & place the input/output Pads
* Macro Floor Planning: Dimensions, pin location, row definition
* Power Planning: Connected by multiple power straps,power rings, power pads of Vdd and Vss
* Below is the image of Chip Floor Planning and Designs are also shown there:
     
![Screenshot from 2023-09-10 23-21-32](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d433e6a8-ef7c-4f12-a19a-9cfcc0cf2140)

* STEP 3: Placement

* Place the cells on the floorplan rows,aligned with the sites
* Usually placement done in two Steps: Global Placement and Detailed Placement
* In Global Placement decide optimal position for the old cell; such position are not certainly legal so cell may overlay or go for a toss
* In Detailed Placement the position obtain is minimally altered to be legal
  
* STEP 4: Clock Tree Synthesis(CLock Routing)

* Create a clock distributed network
* To deliver the clock to all sequential element flipflop
* With minimum clock Skew
* And in a good shape as Tree(H,X,etc)
  
![Screenshot from 2023-09-11 00-46-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4630998a-eb62-4033-99cd-53da13c0a514)

* STEP 5: Routing of Signal

* Metal nets are connected self together
* Implement the interconnect using the available metal layer as defined by PDKs
* The Sky130PDK defines routing layers,the lowest layer is directly connected and its a Titanium metal layer while the Interconnects are Aluminium layer
* Metal tracks form a routing grid
* Routing grid is huge
* Divide and Conquer
   * Global Routing: Generates routing guides
   * Detailed Routing: Uses the routing guides to implement the actual wiring
     
![Screenshot from 2023-09-11 00-48-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/18ebe876-93c4-4161-8c6e-c64be226e5e7)


* STEP 6: Sign Off

* Physical Verification
   * Design Rules Checking(DRC): Make sure that final layout owns all design rules
   * Layout vs Schematics(LVS): Final layout matches the GATE Layout netlist that is started

* Timing Verification
  * Static Timing Analysis(STA): To make sure all timing constraints are meet and circuits will run at designated clock frequency
  
</details>

<details>
 <summary>L3_Simplified RTL to GDS II Flow</summary>


  
 </details>
 </details>
 </details>
 </details>
