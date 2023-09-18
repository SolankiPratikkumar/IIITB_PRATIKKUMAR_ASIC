[](url) Physical Design of ASICs - Advanced Physical Design using OpenLANE


## DAY 1: Inception of Open Source EDA, OpenLANE and Sky130PDK

 <details>
  <summary>How to Talk to Computer</summary>
  
## Introduction to QFN-48 Package, Chip, Pad, Core, Die, IPs

* The Arduino or any other board block structure looks as below
 ![Screenshot from 2023-09-09 12-12-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/15592065-db6f-48ca-9107-c93d7b5f153d)

* Below there is an IC or processor which is now called as Package QFN 48(Quad Flat No Lead) which is 7mm*7mm area and inside it will communicate with a chip
![Screenshot from 2023-09-09 12-15-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8104fbde-5b38-4994-a06a-4709cf2c4842)

* This chip is manufactured on a silicon chip called DIE; PADS makes communication with input and output signals and CORE contains all digital logic inside it
![Screenshot from 2023-09-09 12-18-11](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/16af2006-ff48-4cb2-97e5-549918ba5d72)

* Below is the vital terminology "Foundry IPs" which means a foundry is a factory which manufactures the chip using big machines and IPs an Intellectual Property which is done by communication with the help of files with an organisation. The term "MACROS" performs Digital Operation and consists of pure Digital Logic inside the chip.

![Screenshot from 2023-09-09 12-24-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/69a59fac-f04a-4a43-8ec8-752b4d09e309)

 **Introduction to RISC-V**
   
   * C-Program is run by the compile to assembly language of RISC V and that makes Hardware Layout operation (qflow); that Hardware can be RISC-V

***WHAT IS RISC-V***

* RISC-V is an open-source instruction set architecture used to develop custom processors for a variety of applications, from embedded designs to supercomputers.
* RISC-V is an open-source instruction set architecture (ISA) for designing computer processors. 
* An instruction set architecture defines the instructions a processor can execute, the formats for those instructions, and the corresponding hardware behaviour. 
* RISC-V is designed to be versatile, customizable, and open, making it well-suited for a wide range of applications, from embedded systems to high-performance computing.
* Briefly the architecture can be understood below:
* RISC-V Architecture --->  Implementation (picorv32 cpu core) ---> Hardware Layout(qflow)

 ![Screenshot from 2023-09-09 18-22-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/15f88da2-a69a-4521-aee6-a0bf3c358902)

## RISC-V Characteristics

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

# From Software Applications to Hardware

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
 
  <details>
  <summary>SOC Design and OpenLANE</summary>
   
# Introduction to all components of Open source Digital ASIC Design
  

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

**Simplified RTL to GDS II Flow**

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

* Place the cells on the floorplan rows, aligned with the sites
* Usually placement is done in two Steps: Global Placement and Detailed Placement
* In Global Placement decide the optimal position for the old cell; such positions are not certainly legal so the cell may overlay or go for a toss
* In Detailed Placement the position obtained is minimally altered to be legal
  
* STEP 4: Clock Tree Synthesis(CLock Routing)

* Create a clock-distributed network
* To deliver the clock to all sequential element flipflop
* With minimum clock Skew
* And in a good shape as Tree(H,X,etc)
  
![Screenshot from 2023-09-11 00-46-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4630998a-eb62-4033-99cd-53da13c0a514)

* STEP 5: Routing of Signal

* Metal nets are connected self together
* Implement the interconnect using the available metal layer as defined by PDKs
* The Sky130PDK defines routing layers, the lowest layer is directly connected and it's a Titanium metal layer while the Interconnects are an Aluminium layer
* Metal tracks form a routing grid
* The routing grid is huge
* Divide and Conquer
   * Global Routing: Generates routing guides
   * Detailed Routing: Uses the routing guides to implement the actual wiring
     
![Screenshot from 2023-09-11 00-48-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/18ebe876-93c4-4161-8c6e-c64be226e5e7)


* STEP 6: Sign Off

* Physical Verification
   * Design Rules Checking(DRC): Make sure that the final layout owns all design rules
   * Layout vs Schematics(LVS): Final layout matches the GATE Layout netlist that is started

* Timing Verification
  * Static Timing Analysis(STA): To make sure all timing constraints are met and circuits will run at a designated clock frequency
  
## Introduction to OpenLANE and Strive Chipset

**OpenLANE**

* Started as an open source flow for a True Open Source Tape out Experiment
* Strive is a family of open-everything SOCS like Open PDKs, Open EDA, Open RTL

**Main Goal of OpenLANE**

* Produce a clean GDS II with no human intervention (no-human-in-loop)
  * Clean means:
   * No LVS Violation
   * No DRC Violation
   * No Timing Violation still it is a work in progress
* Tuned for SkyWater130 Open PDK
* Containerized that its instruction is built & run natively will follow
* Can be used to harden Macros and Chips design
* Two modes of Operation:
 * Autonomous: Push pattern wait for some time base GDS Tool
 * Interactive: Run command and steps one by one
* Design Space Exploration finds the best set of flow configuration
* Large number of Design Examples; there were 43 designs with their best configuration available and still increasing

![Screenshot from 2023-09-11 15-01-04](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/eeb80cf1-cc3d-4f24-8bd3-84f3dc787ede)
  
# Introduction to OpenLANE detailed ASIC Design Flow

* Flow Diagram of OpenLANE ASIC Flow is shown below:

![Screenshot from 2023-09-11 15-11-34](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5e330038-60fe-4c30-a0db-ab35ab1caed8)

* OpenLANE is based on several OpenLANE projects like below
* OpenROAD, Magic VLSI Layout Tool, KLayout, Fault, Yosys, Fault, QFlow, ABC

Step 1: Flow starts with Design RTL to RTL Synthesis using tools of Yosys+ABC
* RTL to the Logic circuit can be optimised and used by ABC script for further use

Step 2: STA uses OpenSTA Tool
* Here Synthesis Exploration shows "Delay vs. Area" affected by different explore strategy
* Here Design Exploration is used to find the best configuration for a particular design
* Design Exploration utility is also used for Regression Testing(CI)
* OpenLANE design already runs these 70 designs to compare the result to the best-known ones

Step 3: Design for Test(DFT) uses the Fault tool for the Testing phase; The functionality and image are shown below and 

![Screenshot from 2023-09-11 16-31-45](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c39252d7-c213-44fd-b520-7dba86749497)

Step 4: Physical Implementation 
* This step is also called as PnR (Place & Route)
* All done by the OpenROAD app
* Floor/Power Planning
* End Decoupling Capacitors and Tap Cell Insertion
* Placement are two types Global and Detailed
* Post placement Optimization
* Clock Tree Synthesis(CTS)
* Routing is also done in two ways Global and Detailed

Step 5: Logic Equivalent Checking (LEC) uses Yosys tool
* Here, we compare the Netlist resulting from optimisation done during Physical Implementation
* Every time the netlist is modified and verification must be performed
   * CTS modifies the netlist
   * Post placement optimisation modifies the netlist
* LEC is used to formally confirm that the function did not change after modifying the netlist

Step 6: Dealing with Antenna Rules Violation 

* Its described below image with the definition,

![Screenshot from 2023-09-11 21-01-32](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/068d8ee9-1cc0-4f49-8df2-c77be86a5e26)

* There are two solutions for this violation issue
  * Firstly, Bridging attaches a higher layer intermediary
  * Secondly, Add an Antenna diode cell to leak away charges

* With OpenLANE we create a Fake Antenna Diode  and if netlist creates an issue then we change by original antenna diode as shown below:
![Screenshot from 2023-09-11 21-04-08](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3114e73a-dd8b-48c3-bb82-2c730cd5f264)

Step 7: Sign Off
* It involves the following process
* RC Extraction
* STA(Open STA)
* Physical Verification DRC and LVS 
    * By using Magic for Design Rules Checking(DRC) and Spice Extraction from Layout
    * Magic and Netgen are used for LVS

 </details>

  <details>
  <summary>Get Familiar to open source EDA Tools</summary>  
  

**Required Installation** 
```
sudo apt-get update
sudo apt-get install \
   ca-certificates \
   curl \
   gnupg \
   lsb-release

sudo apt-get update
sudo apt-get upgrade
sudo apt install -y build-essential python3 python3-venv python3-pip make git
```

**Docker Installation**

```
# Remove old installations
sudo apt-get remove docker docker-engine docker.io containerd runc
# Installation of requirements
sudo apt-get update
sudo apt-get install \
   ca-certificates \
   curl \
   gnupg \
   lsb-release
# Add the keyrings of docker
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
# Add the package repository
echo \
   "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
# Update the package repository
sudo apt-get update

# Install Docker
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin

# Check for installation
sudo docker run hello-world
```

**Installing OpenLANE**
```
git clone https://github.com/The-OpenROAD-Project/OpenLane
cd OpenLane
make
make test
```

**Check for installation**
```
sudo docker run hello-world
```

* Below are Images of the OpenLANE tool Installed:
```
//open OpenLane directory and type below command
~/OpenLane$ make mount
/openlane$ ./flow.tcl -interactive
% package require openlane 0.9
% prep -design picorv32a
% run_synthesis
```

![Screenshot from 2023-09-16 21-52-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c5f56af3-84fa-4171-9c74-d41e0d6d649a)

![Screenshot from 2023-09-16 22-44-12](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/da9df512-45aa-4421-a717-c6f15a2d0f83)

* Below is dff_synthesis report:

![Screenshot from 2023-09-18 11-56-21](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/402643a7-ba2d-49ba-a276-10e8a3a62596)


* Below is synthesis_pre report:
  
![Screenshot from 2023-09-18 11-56-51](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d56978e2-ea61-46e0-a8c2-7f73ea8684a0)

![Screenshot from 2023-09-18 11-57-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/13225f83-175f-4eb8-9592-44a1930ca0c4)
  
**Flops ratio:**

* The flop ratio is defined as the ratio of the number of flops to the total number of cells
* Here flop ratio is 1240/8116 = 0.1528 (i.e: 15.3%) [From the synthesis statistics]
  
 </details>
 </details>
 
 ## DAY 2: Good Floorplan vs Bad Floorplan and Library Cell

 <details>
  <summary>Chip Floorplaning Consideration</summary>  
  
## Utilization Factor and Aspect Ratio

* Core: The term "core width" generally pertains to the physical dimensions or size of the central processing unit (CPU) or processor core within a microchip. Typically quantified in nanometers (nm) or micrometers (µm), it is denoted as, for instance, a "14nm core" or a "7nm core," representing the transistor feature size within the core. Conversely, the "core height" isn't typically expressed in a similar manner to the width. Instead, the core's dimensions are usually communicated in relation to its overall area, calculated by multiplying its width and height.

* Die: The term "die width" typically denotes the physical measurement of the semiconductor wafer after all the individual integrated circuits (ICs) have been constructed on it, just prior to their separation. The widths of dies can vary considerably based on the particular manufacturing process and the design of the chips being manufactured, ranging from a few millimetres to several centimetres or even more.

* Comparable to the core, discussions about the "die height" are infrequent. Instead, the size of the die is commonly conveyed in relation to its area, which is calculated by multiplying its width and height.
 
* Here we are creating a netlist using 1 AND gate,1 OR gate,2 FlipFlop and all the logic gates for physical design are considered as square dimensions same as Flipflop as shown in below image

![Screenshot from 2023-09-16 16-31-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0f3a0d1f-2679-4abf-831f-f7ad6da9c939)

* We can observe the netlist connection and all standard cell and flipflops are taken as 1*1 sq unit as shown below
  
![Screenshot from 2023-09-16 16-34-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6745e69c-2425-40dc-b2f2-b63df8774f2f)

* Below image we observe that the complete netlist is with dimension 4 sq unit and the core dimension is 4*2 sq unit hence by the Utilisation formula as mention it will be 0.5 or 50% and the aspect ratio as per formula will be also 0.5 as per fromula mention image.
* If the total dimension area of netlist is equal area of core then Utilisation factor and Aspect Ratio equals 1 which means core is square in shape
  
* Utlisation Factor == Total area occupied by the netlist / Total area of the core.
* Aspect ratio = Height of core / Width of core

![Screenshot from 2023-09-16 16-44-28](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/03d73c1c-e816-40e0-80fb-ba299cf6dc88)

## Concept of Pre-Placed Cell

* Pre-placed cells (or pre-placed blocks) in ASIC (Application-Specific Integrated Circuit) design refer to predefined and fixed blocks of logic or circuitry that are manually placed in specific locations on the semiconductor chip's layout before the automated placement and routing process. These cells are placed manually by the chip designer or through automated tools. Since these IPs are placed before automated Placement and Routing, these are referred to as Pre-placed cells.
* The arrangement of these IPs in a chip is referred as Floorplanning
* These IPs/blocks have user-defined locations, and hence are placed in the chip before automated placement and routing and are called pre-placed cells.
* Automated placement and routing tools place the remaining logical cells in the design onto the chip
* If this netlist is repeated multiple times in layout and is reused that's why we converted it block

![Screenshot from 2023-09-16 18-22-00](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3d35eedc-f41e-4677-b166-87df1c6406a9)

![Screenshot from 2023-09-18 12-09-47](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3e741167-1470-4cb7-9352-7b7baaea77aa)


## Decoupling Capacitor

* Decoupling capacitors play a vital role in electronic circuit design by ensuring a steady power supply, filtering out unwanted noise, and enhancing the overall performance and reliability of electronic systems, especially in digital and mixed-signal applications. It's crucial to carefully choose, position, and size decoupling capacitors to maximize their efficiency in noise reduction and voltage stability, thus optimizing circuit functionality.

* Pre-placed cells must then be surrounded with decoupling capacitors (decaps). The resistances and capacitances associated with long wire lengths can cause the power supply voltage to drop significantly before reaching the logic circuits. Their role is to decouple the circuit from power supply by supplying the necessary amount of current to the circuit. They prevent crosstalk and enable local communication.

![Screenshot from 2023-09-18 12-29-35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/20c68397-3bec-46fa-ae60-23fe4e6c0c0b)

![Screenshot from 2023-09-18 12-31-49](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5f88a6e3-3aa3-4e29-99f3-fe156ecc8f29)

![Screenshot from 2023-09-18 12-35-30](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8f7fffd8-4fda-4892-b3ca-3e4d90534936)

## Power Placement

* Suppose there are numerous macros on a chip, and when the output switches from '1' to '0,' the excess charge is dissipated into the ground line, resulting in a visible ground bump. Likewise, when it switches from '0' to '1,' there is a voltage drop observed in the power supply. To address this issue, implementing multiple supply lines for both VDD and ground can be a potential solution, as illustrated below:
![267383508-c4702946-dc09-4e1d-b727-87cb66dc3295](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3e27ae61-02a2-4ad4-bc17-8df6ae3c8315)

## Pin Placement

* The netlist outlines the interconnections among logic gates within a chip. The intermediate area between the core and die is allocated for the placement of pins. The connectivity details, expressed in either VHDL or Verilog, guide the positioning of I/O pads for different pins. Specifically, the input, output, and clock pins are strategically placed to minimize routing complexity and optimize for reduced delay
  
![267384870-6defb5df-c7ce-4112-be5f-c90029002da8](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e70c9f71-7646-4ab1-8311-964825f07820)

* The Clock port are bigger than the normal I/O pins because of it's continuous use and larger area offers less resistance. 
![267385070-8d8c13a0-78ab-4664-b9f3-d5a945aa7cb9](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/85d8bcc7-10b7-4bc1-826f-f090cf6a2775)


* To run the picorv32a floorplan in OpenLane:
```
run_floorplan
```
![Screenshot from 2023-09-16 23-19-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3bfad5d8-483a-4569-90d2-181630736acd)

* Post the floorplan run, a .def file will have been created within the results/floorplan directory.
* We may review floorplan files by checking the floorplan.tcl.
* The system defaults will have been overriden by switches set in conifg.tcl and further overriden by switches set in sky130A_sky130_fd_sc_hd_config.tcl.

To view the floorplan, Magic is invoked after moving to the results/floorplan directory:



* Post the floorplan run, a .def file will have been created within the results/floorplan directory. We may review floorplan files by checking the floorplan.tcl. The system defaults will have been overriden by switches set in conifg.tcl and further overriden by switches set in sky130A_sky130_fd_sc_hd_config.tcl.

* To view the floorplan, Magic is invoked after moving to the results/floorplan directory:
![Screenshot from 2023-09-16 23-24-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2ae6c2a1-aa17-40f6-8e8e-8beb055ef97e)

```
magic -T /home/parallels/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read tmp/merged.nom.lef def read results/floorplan/picorv32a.def &
```

<img width="904" alt="266801182-87c3c1e9-eb75-4365-932f-9865b3ef6ffd" src="https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/33b79e85-a977-48e0-ae6a-3160f8ad1c60">


* One can zoom into Magic layout by selecting an area with left and right mouse click followed by pressing "z" key.

* Various components can be identified by using the what command in tkcon window after making a selection on the component.

* Zooming in also provides a view of decaps present in picorv32a chip.

* The standard cell can be found at the bottom left corner.

* You can clearly see I/O pins, Decap cells and Tap cells. Tap cells are placed in a zig zag manner or you can say diagonally

</details>
 </details>

 <details>
  <summary>Library Binding and Placement</summary>  

* Library consists of cells, shapes & sizes of cells, various flavours of the same cell, timing/delay information.
* The netlist or the circuit is made using the component available in library, where each element is represented as a box.

![266786781-4887d41c-a227-47df-b30a-c92b8a800019](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e09f7272-2f3a-45ae-bbea-cc1ee9b115d1)

 * Initially, the netlist is bound to physical cells in the design process. While practice exercises may involve predefined shapes for logical gates like OR, AND, etc., in real-world scenarios, we define physical dimensions using shapes like rectangles or squares, specifying width and height.
 * This data is typically provided in libraries (libs) and layout exchange format (LEF) files. These dimensions and other relevant information are used to place the cells in the design by proper initialization.

![266786781-4887d41c-a227-47df-b30a-c92b8a800019](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/747c1481-ca5d-482e-a30f-95b97bede7c7)

## Optimize Placement

* Placement is the process of placing the cells in the core area of the chip as shown below

![266786781-4887d41c-a227-47df-b30a-c92b8a800019](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/747c1481-ca5d-482e-a30f-95b97bede7c7)

* The next step in the OpenLANE ASIC flow is placement. The synthesized netlist is to be placed on the floorplan. Placement is perfomed in 2 stages:
* 1.Global Placement: It finds optimal position for all cells which may not be legal and cells may overlap. Optimization is done through reduction of half parameter wire length.
* 2.Detailed Placement: It alters the position of cells post global placement so as to legalise them
![2b266786848-e40e5c6c-a71d-454e-8cba-4b24530cc44b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/eba5dcd4-9218-4383-a6e5-8b556c386932)

* Optimization is stage where we estimate the lenght and capictance, based on that we add buffers. Ideally, Optimization is done for better timing

![Screenshot from 2023-09-16 23-50-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/aa4ccb5f-7d53-42c7-8065-2c2a4192ac9b)

 ## Netlist Binding and initial place design

* Library characterization is the procedure of thoroughly analyzing and characterizing electronic components and fundamental elements like logic gates, flip-flops, and related building blocks. 
* The aim is to create accurate models that precisely represent the behavior of these components under a range of conditions and scenarios.
* Through library characterization, vital information is obtained regarding how these components respond to diverse inputs, account for delays, manage power consumption, and exhibit various other operational characteristics.
* Library modeling encompasses the creation of mathematical or algorithmic representations that accurately describe the behavior and characteristics of electronic components.
* These models serve as the foundation for Electronic Design Automation (EDA) tools to simulate, analyze, and optimize digital circuits during the design phase.
* By utilizing these models, designers can efficiently evaluate the performance, power consumption, timing, and other critical aspects of the circuit design, aiding in the development of optimal and functional electronic systems
  
![2c 6824418-98fc611c-0d59-47cb-8869-ef3fca4c9500](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d2f8ec3c-107d-4121-9b85-0c4a19e1f528)

* Logic synthesis stands as a pivotal phase in digital integrated circuit (IC) design, acting as a central process in translating a high-level hardware description into a gate-level representation that can be physically fabricated in silicon.

* The Floorplan is a critical step in physical design, wielding substantial influence over the quality of chip or design implementation. An effective floorplan can streamline the implementation process (including placement, clock tree synthesis, routing, and timing closure). Conversely, a poor floorplan can lead to an array of design issues, such as congestion, timing problems, noise, IR (current), and routing complications. A suboptimal floorplan can escalate area, power usage, affect reliability and the IC's lifespan, ultimately increasing the overall IC cost due to extended closure efforts and the need for additional low voltage threshold switches (LVTS) or ultra-low voltage threshold switches (ULVTS).

* Placement involves determining the positions of circuit devices on a die's surface. It is a critical stage in the VLSI design flow, impacting routability, performance, heat distribution, and to a lesser extent, power consumption of a design.

* Clock Tree Synthesis (CTS) is a technique used to evenly distribute the clock among all sequential parts of a VLSI design, aiming to minimize skew and delay.

* Routing in VLSI entails physically establishing connections between signal pins using metal layers. Following Clock Tree Synthesis (CTS) and optimization, the routing step defines precise pathways for interconnecting standard cells, macros, and I/O pins.

* Optimizing placement involves utilizing estimated wire length and capacitance to achieve an efficient layout.

* Repeaters, essential components in the core area, are introduced to maintain signal integrity. The arrangement and placement of repeaters within the core play a crucial role, as illustrated in the provided image.

![2c6817886-5a2f396e-9ac9-4fb4-b407-14480a4b468e](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ff9e5503-132f-4c7b-8517-b4791aa01a91)

* Below is the image when we ran Placement command in OpenLane
![Screenshot from 2023-09-16 23-50-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/706457b3-fe32-430d-b4d6-4e1e80b4bc1f)

**Congestion aware Placement**

* Post placement, the design can be viewed on magic within results/placement directory:
```
magic -T /home/parallels/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read tmp/merged.nom.lef def read results/floorplan/picorv32a.def &
```

![266819534-98701b8a-a575-4553-a661-15e2af78884d](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/782c21bf-cb26-4ee3-b890-c24a8a2e3ca0)

**Note:** Power distribution network generation is usually a part of the floorplan step. However, in the openLANE flow, floorplan does not generate PDN. It is created after post CTS. The steps are - floorplan, placement, CTS, Post CTS and then PDN

**Need for libraries and characterization** 

* As we know that, logic gates or logic cells are a shared element in every stage of the design process, encompassing logic synthesis, routing, and STA (Static Timing Analysis).
* To enable the tools to comprehend these gates and their timing, it's imperative to conduct a thorough characterization of these cells

</details>

 <details>
  <summary>Cell Design and Characterization Flow</summary> 

* Below is the representation of cell design flow
  
![266851161-481e207c-bff3-44dc-a1da-e9b060c0b096](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/843fb9a0-3d6c-491a-b438-1a843a3dbd4a)

* The design flow for cells, also recognized as the standard cell design flow, involves the process of crafting and refining standard cell libraries essential for digital integrated circuit design. These libraries constitute foundational elements like logic gates and flip-flops, crucial for the creation of intricate digital circuits.

* Initiation involves specifying the standard cell library's requirements and specifications, encompassing factors like technology node, voltage levels, speed requisites, and power constraints.

* Following this, the appropriate architecture and topology for the standard cells are selected, entailing decisions on the logical functions each cell will undertake, alongside determining the number of input and output pins.

* Subsequently, schematic designs for each standard cell are created, delineating the logical function using gates and interconnections. Specialized tools like schematic capture software are employed for this stage.

* After the schematic design, the cells are simulated to ascertain compliance with stipulated functionality and timing requisites. This phase may encompass functional simulation, static timing analysis (STA), and power analysis.

* Physical layouts for the cells are then generated based on the schematic designs, entailing specifications of dimensions, transistor placements, and metal layer routing.

* Crucial checks such as Design Rule Check (DRC) and Layout vs. Schematic (LVS) are performed to ensure adherence to manufacturing rules and coherence with the schematic.

* Next, parasitic components, including resistances and capacitances, are extracted from the layout, significantly influencing timing and power characteristics. The cells are thoroughly characterized by evaluating their performance under various conditions, such as varying input vectors and operating voltages.

* A detailed timing analysis follows to determine critical parameters like propagation delay, setup time, hold time, and clock-to-Q delay for flip-flops.

* The standard cell library is ultimately validated by integrating it into a test chip or designing test cases, ensuring alignment with performance and functionality requirements.
  
![266851584-58dabbee-bdc0-4259-8af8-577835d7803d](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b32359d4-3868-4eff-bce6-9dfcea894a5a)

![2aa266a851870-e750f943-c0c8-4117-bfb2-6e9ad56c68c5](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0ebb5c99-fa9a-4d08-ba37-61d88e2cffb8)

* Stick diagram of the layout representation is shown below:
  
![2bb266852695-7d81050a-6039-4fed-bea9-1a094ac6dcf6](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6eb2b0d2-8874-46ed-aeb0-053e219c87b6)

## Standard Cell Characterization Flow

* A typical standard cell characterization flow that is followed in the industry includes the following steps:

1. Read in the models and tech files
2. Read extracted spice Netlist
3. Recognise the behaviour of the cells
4. Read the subcircuits
5. Attach power sources
6. Apply stimulus to characterization setup
7. Provide necessary output capacitance loads
8. Provide necessary simulation commands

* Now, all these 8 steps are fed in together as a configuration file to a characterization software called GUNA. This software generates timing, noise, and power models. These .libs are classified as Timing characterization, power characterization and noise characterization

![242526685-87348350-fa25-4ef8-99f4-1cdddf070f10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/31f0760b-24ca-46e9-aa7f-c66b214e8942)

![266853817-34bb2182-24c1-40b7-b06b-faccf1959727](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/383e0f2f-b9fe-4f0a-b3e6-7730f389aba8)

![266853809-bef80248-0189-495b-9579-f1bbb9444096](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/24de945b-887b-4f78-8808-bc9009475c66)

</details>

 <details>
  <summary>General Timing Characterisation Parameters</summary> 

* The can understoodthis Parameter by taking a circuit as a reference
  
![2ba 266782039-b9f3b27d-3cd0-48d4-bbc5-848b18c63045](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a96da9ac-8c14-458a-baaf-67d854723080)

* slew_low_rise_thr : Its generally taken as a point in the rising waveform, the point is at the rising edge generally at 20% value from the initial point.

* slew_high_rise_thr : Its generally taken as a point in the rising waveform, the point is at the rising edge generally at 20% value from the final point of the waveform, it can also be considered as 80% from initial point of the waveform.

* slew_low_fall_thr : Its generally taken as a point in the falling waveform, the point is at the rising edge generally at 20% value from the initial point.

* slew_high_fall_thr : Its generally taken as a point in the falling waveform, the point is at the rising edge generally at 20% value from the final point of the waveform, it can also be considered as 80% from initial point of the waveform.

![2bb_266782248-24922247-a8b7-42c7-8f19-3315f8be5f8b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/258822ac-0913-46f1-b2b7-82f28fb5b081)


* in_rise_thr : It is generally taken the 50% value point in the input rise waveform.

* in_fall_thr : It is generally taken the 50% value point in the input fall waveform.

* out_rise_thr : It is generally taken the 50% value point in the output rise waveform.

* out_fall_thr :  It is generally taken the 50% value point in the output fall waveform

* The above concept is shown in below image:

![2bc_266782346-7794cd40-f580-4443-ab91-134d111c4fdf](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a0a7cad0-58de-48d1-a665-709347127aab)


* **Propagation Delay** refers to the time interval between when the input, in the process of transitioning, reaches 50% of its ultimate value, and the moment the output also achieves 50% of its final value. Inadequate selection of threshold values can result in negative delay values. Even with appropriate threshold choices, variations in slew rate can sometimes cause the delay to be either positive or negative.
* Propagation delay = time(out_thr) - time(in_thr)

* **Transition Time** is the time it takes the signal to move between states is the transition time , where the time is measured between 10% and 90% or 20% to 80% of the signal levels.
* Rise transition time = time(slew_high_rise_thr) - time (slew_low_rise_thr)
* Low transition time = time(slew_high_fall_thr) - time (slew_low_fall_thr)
  
 </details>
 </details>
 
 ## DAY 3: Design Library Cell Using Magic Layout and NGSpice Characterization

 <details>
  <summary>Labs for CMOS Inverter NGSpice Simulations</summary>  

**Inverter**

* A CMOS inverter, or Complementary Metal-Oxide-Semiconductor inverter, is a fundamental digital electronic circuit designed to perform the basic logical operation of inversion.
* Essentially, it takes an input signal and generates an output signal that represents the logical opposite of the input.
* When the input is high (logic 1), the output will be low (logic 0), and conversely, when the input is low (logic 0), the output will be high (logic 1)
* Below image shows the nodes of inverter:
![268231402-be2807d2-e912-4beb-bd29-fd137c278f97](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/652327ff-ded7-43e7-a991-741532081f9a)

* The spice deck simulation shown below:
![268254662-af257b8b-e995-45a0-8abc-e7c19515cc91](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a86f435c-b714-434c-ad4e-408e07c649cb)

* The cir file is shown below
![268257826-b944f013-ba10-4926-9efa-1c3814d477dd](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/956942fd-396e-41fb-8744-be3878754147)

* To run it open ngspice and in command give
``source cmos.cir``

![268258504-e79c82b2-9054-41da-8314-d448fb0ddf17](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/79a846c9-ac4e-46cf-8ea9-936418da40e5)

* Below is the model file :

```
* SPICE 3f5 Level 8, Star-HSPICE Level 49, UTMOST Level 8

.lib cmos_models 
* DATE: Feb 23/01
* LOT: T0BM                  WAF: 07
* Temperature_parameters=Default
.MODEL nmos  NMOS (                                LEVEL   = 49
+VERSION = 3.1            TNOM    = 27             TOX     = 5.8E-9
+XJ      = 1E-7           NCH     = 2.3549E17      VTH0    = 0.3907535
+K1      = 0.4376003      K2      = 8.265151E-3    K3      = 4.214601E-3
+K3B     = -3.7220937     W0      = 2.517345E-6    NLX     = 2.310668E-7
+DVT0W   = 0              DVT1W   = 0              DVT2W   = 0
+DVT0    = 0.2411602      DVT1    = 0.3707226      DVT2    = -0.5
+U0      = 316.5922683    UA      = -9.89493E-10   UB      = 2.154013E-18
+UC      = 2.474632E-11   VSAT    = 1.254499E5     A0      = 1.2735648
+AGS     = 0.2428704      B0      = 2.579719E-8    B1      = -1E-7
+KETA    = 4.87168E-4     A1      = 0              A2      = 0.5196633
+RDSW    = 120            PRWG    = 0.5            PRWB    = -0.2
+WR      = 1              WINT    = 2.357855E-8    LINT    = 1.210018E-9
+DWG     = 2.292632E-9
+DWB     = -9.94921E-10   VOFF    = -0.1039771     NFACTOR = 1.3905578
+CIT     = 0              CDSC    = 2.4E-4         CDSCD   = 0
+CDSCB   = 0              ETA0    = 3.894977E-3    ETAB    = 7.800632E-4
+DSUB    = 0.0307944      PCLM    = 1.7312397      PDIBLC1 = 0.999135
+PDIBLC2 = 4.850036E-3    PDIBLCB = -0.0866866     DROUT   = 0.8612131
+PSCBE1  = 7.995844E10    PSCBE2  = 1.457011E-8    PVAG    = 0.0099984
+DELTA   = 0.01           RSH     = 5              MOBMOD  = 1
+PRT     = 0              UTE     = -1.5           KT1     = -0.11
+KT1L    = 0              KT2     = 0.022          UA1     = 4.31E-9
+UB1     = -7.61E-18      UC1     = -5.6E-11       AT      = 3.3E4
+WL      = 0              WLN     = 1              WW      = -1.22182E-16
+WWN     = 1.2127         WWL     = 0              LL      = 0
+LLN     = 1              LW      = 0              LWN     = 1
+LWL     = 0              CAPMOD  = 2              XPART   = 0.4
+CGDO    = 3.11E-10       CGSO    = 3.11E-10       CGBO    = 1E-12
+CJ      = 1.741905E-3    PB      = 0.9876681      MJ      = 0.4679558
+CJSW    = 3.653429E-10   PBSW    = 0.99           MJSW    = 0.2943558
+CF      = 0              PVTH0   = -0.01          PRDSW   = 0
+PK2     = 2.589681E-3    WKETA   = -1.866069E-3   LKETA   = -0.0166961      )
*
.MODEL pmos  PMOS (                                LEVEL   = 49
+VERSION = 3.1            TNOM    = 27             TOX     = 5.8E-9
+XJ      = 1E-7           NCH     = 4.1589E17      VTH0    = -0.583228
+K1      = 0.5999865      K2      = 6.150203E-3    K3      = 0
+K3B     = 3.6314079      W0      = 1E-6           NLX     = 1E-9
+DVT0W   = 0              DVT1W   = 0              DVT2W   = 0
+DVT0    = 2.8749516      DVT1    = 0.7488605      DVT2    = -0.0917408
+U0      = 136.076212     UA      = 2.023988E-9    UB      = 1E-21
+UC      = -9.26638E-11   VSAT    = 2E5            A0      = 0.951197
+AGS     = 0.20963        B0      = 1.345599E-6    B1      = 5E-6
+KETA    = 0.0114727      A1      = 3.851541E-4    A2      = 0.614676
+RDSW    = 1.496983E3     PRWG    = -0.0440632     PRWB    = -0.2945454
+WR      = 1              WINT    = 7.879211E-9    LINT    = 2.894523E-8
+DWG     = -1.112097E-8
+DWB     = 9.815716E-9    VOFF    = -0.1204623     NFACTOR = 1.2259401
+CIT     = 0              CDSC    = 2.4E-4         CDSCD   = 0
+CDSCB   = 0              ETA0    = 0.3325261      ETAB    = -0.0623452
+DSUB    = 0.9206875      PCLM    = 0.833903       PDIBLC1 = 9.948506E-4
+PDIBLC2 = 0.0191187      PDIBLCB = -1E-3          DROUT   = 0.9938581
+PSCBE1  = 2.887413E10    PSCBE2  = 8.325891E-9    PVAG    = 0.8478443
+DELTA   = 0.01           RSH     = 3.6            MOBMOD  = 1
+PRT     = 0              UTE     = -1.5           KT1     = -0.11
+KT1L    = 0              KT2     = 0.022          UA1     = 4.31E-9
+UB1     = -7.61E-18      UC1     = -5.6E-11       AT      = 3.3E4
+WL      = 0              WLN     = 1              WW      = 0
+WWN     = 1              WWL     = 0              LL      = 0
+LLN     = 1              LW      = 0              LWN     = 1
+LWL     = 0              CAPMOD  = 2              XPART   = 0.4
+CGDO    = 2.68E-10       CGSO    = 2.68E-10       CGBO    = 1E-12
+CJ      = 1.864957E-3    PB      = 0.976468       MJ      = 0.4614408
+CJSW    = 3.118281E-10   PBSW    = 0.6870843      MJSW    = 0.3021929
+CF      = 0              PVTH0   = 6.397941E-3    PRDSW   = 30.410214
+PK2     = 2.100359E-3    WKETA   = 5.428923E-3    LKETA   = -0.0111599      )
*
.endl
```

**For execution:**

* Run Then using setplot you can set the dc plot. Also you can see by assign display and we can see plot Output vs Input
  
![Screenshot from 2023-09-17 01-39-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/00b9aa6f-9091-420a-b47f-45ec2e777c3f)

* Here we are representing the switching threshold, including the relationship and calculate between Wp/Lp and xWn/Ln

![268261711-7f9b0787-45cc-4e45-9edc-28918f2bff76](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b57fa46d-03fe-415f-87e9-cb80d4a24b7f)

* We have now updated CMOS file:
![268262032-4b39d6f4-5165-4a1e-96f9-46fa827b82cd](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e0b077e2-64b6-4725-925d-82d739224698)
 
* Below is the graph of out vs time:
![268263752-778eca09-2747-40b6-86e2-1c6b0f2233f9](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/84020417-7e5e-4094-86e2-b47852b9f561)

## Lab steps to gitclone vsdstdcell design

* First, clone the required mag files and spicemodels of inverter,pmos and nmos sky130. The command to clone files from github link is:
``git clone https://github.com/nickson-jose/vsdstdcelldesign.git``
* Once we run this command, it will create vsdstdcelldesign folder in openlane directory.
* In order to open the mag file and run magic go to the directory
* For layout we run magic command
``magic -T sky130A.tech sky130_inv.mag &``
* After running Magic command we get the layout of the inverter in the Magic window

![Screenshot from 2023-09-18 14-13-05](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/64b7daf5-bca2-4a29-abeb-c99048eaa33e)

   </details>
   </details>
   
 <details>
  <summary>Inception of CMOS fabrication Process</summary>
  
* Here's an explanation of the 16-mask CMOS fabrication process:
  
* Substrate Selection: In the initial stage, the appropriate semiconductor substrate is carefully chosen.

* Creation of Active Regions: To isolate the active regions for transistors, the process begins with the deposition of SiO2 and Si3N4 layers, followed by photolithography and silicon nitride etching. This process, known as LOCOS (Local Oxidation of Silicon), involves growing oxide in specific regions. Subsequently, Si3N4 is removed using hot phosphoric acid.

* Formation of N-Well and P-Well: The N-well and P-well regions are created separately. P-well formation involves photolithography and ion implantation of p-type Boron material into the p-substrate. Similarly, N-well is formed using n-type Phosphorus material. High-temperature furnace processes drive-in diffusion to determine well depths, a process known as the tub process.

* Gate Formation: The gate is a critical terminal in CMOS transistors, controlling threshold voltages for transistor switching. A polysilicon layer is deposited, and photolithography techniques are applied to create NMOS and PMOS gates. Important parameters in gate formation include oxide capacitance and doping concentration.

* Lightly Doped Drain (LDD) Formation: LDD is created to mitigate hot electron and short channel effects.

* Formation of Source & Drain: Thin oxide layers are added to prevent channel effects during ion implantation. N+ and P+ implants are performed using Arsenic implantation and high-temperature annealing.

* Local Interconnect Formation: Thin screen oxide is removed through etching in an HF solution. Titanium deposition through sputtering is initiated. Heat treatment results in chemical reactions, producing low-resistant titanium silicon dioxide for interconnect contacts and titanium nitride for top-level connections, enabling local communication.

* Higher Level Metal Formation: Achieving suitable metal interconnects involves addressing non-planar surface topography. Chemical Mechanical Polishing (CMP) is employed by doping silicon oxide with Boron or Phosphorus to achieve surface planarization. TiN and blanket Tungsten layers are deposited and subjected to CMP. An aluminium (Al) layer is added and subjected to photolithography and CMP. This constitutes the first level of interconnects, with additional interconnect layers added to reach higher-level metal layers.

![266960128-11e88b98-aaa3-4077-b46b-abff9b3f38c3](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6fe3466b-4f3e-4520-bf25-ebb789b64166)

* Addition of Dielectric Layer: Finally, a dielectric layer, typically Si3N4, is applied to protect the chip.

* This intricate process leads to the creation of advanced integrated circuits with multiple layers of interconnects, playing a vital role in modern electronic devices.
  
![3b268265887-2fe79a8e-8560-408f-9eba-e2da7131f424](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8cd94767-4f9d-4a07-9baf-cedfdbbd410e)

* First, clone the required mag files and spice models of inverter,pmos and nmos sky130. The command to clone files from github link is:
``
git clone https://github.com/nickson-jose/vsdstdcelldesign.git
``
* For layout we will run a Magic command
```
magic -T sky130A.tech sky130_inv.mag &
```
![Screenshot from 2023-09-17 02-10-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/290c85f0-d607-4988-90c1-b32db4ad3e1d)

![Screenshot from 2023-09-17 02-12-15](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/325be9f4-40a9-45e9-8413-1795d8ab4efd)

## SKY130 Basic Layer layout and LEF using inverter

* When inspecting the layout, we can observe the specific layers necessary for constructing a CMOS inverter. The inverter consists of a PMOS and NMOS transistor connected together.

* The gates of both the PMOS and NMOS transistors are interconnected and directed to the input, denoted as 'A'.
* The NMOS source is linked to the ground, represented as 'VGND'.
* The PMOS source is connected to VDD, indicated as 'VPWR'.
* The drains of both PMOS and NMOS transistors are connected, ultimately leading to the output, labeled as 'Y'.
* Within the Skywater130 technology, the initial layer is the local interconnect layer, referred to as 'locali'. * * Above this layer, we have metal 1, identifiable by its purple color, and above that is metal 2, characterized by a pink color.
* To explore connections between various segments, position the cursor over the area of interest and press 'S' once. The tkson window will display the corresponding component name, providing valuable insights into the layout
* For confidentiality of layout companies use Abstact LEF from Layout
* The Abstract LEF will provide us only the metal contacts of the complete layout
    
![Screenshot from 2023-09-18 14-37-03](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9e77ab19-ea3c-4146-8dc6-82caaa8e645d)

![Screenshot from 2023-09-18 14-34-31](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/aa034870-6cd1-445e-a347-d398b2413cca)

**Library exchange format(.lef)**
* The layout of a design is defined in a specific file called LEF.
* It includes design rules (tech LEF) and abstract information about the cells.
  * Tech LEF - Technology LEF file contains information about the Metal layer, Via Definition and DRCs.
  * Macro LEF - Contains physical information of the cell such as its Size, Pin, their direction.

## Designing Standard Cell and SPICE extraction in MAGIC

* Following commands were used in the magic command window to generate the spice file.
```
extract all
ext2spice cthresh 0 rthresh 0
ex2spice
```

* First we need to provide bounding box width and height in tkson window. lets say that width of BBOX is 1.38u and height is 2.72u. The command to give these values to magic is property Fixed BBOX (0 0 1.32 2.72) 

* After this, Vdd, GND segments which are in metal 1 layer, their respective contacts and atlast logic gates layout is defined Inorder to know the logical functioning of the inverter, we extract the spice and then we do simulation on the spice. To extract it on spice we open TKCON window, the steps are

* Know the present directory - ``pwd ``

* Create an extraction file - the command is`` extract all``and sky130_inv.ext files has been created
create spice file using .ext file to be used with our ngspice tool - the commands are
``ext2spice cthresh 0 rthresh 0`` - extracts parasatic capcitances also since these are actual layers - nothing is created in the folder ext2spice - a file`` sky130_inv.spice ``has been created.

![Screenshot from 2023-09-17 11-45-09](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e2cd1a53-bd70-4ae8-b56a-bbb9bdff7b64)

</details>
   </details>
 <details>
  <summary>SKY130 Tech File Labs</summary>  
  
## Create Final SPICE Deck
  
* Under this section, we will go over how to infer the spice deck file and how to run the transient analysis using NGspice. Once the simulation is done, we will characterise the simulation plot.

**Spice Deck** 

* The design is scaled to 0.01u
* The NMOS and PMOS are defined as
  * cell_name drain_node gate_node source_node model_file_name
```
M1000 Y A VGND VGND nshort_model.0 w=35 l=23
M1001 Y A VPWR VPWR pshort_model.0 w=37 l=23
```
* Here,we will include the model files for NMOS and PMOS from the libs directory
```
.include ./libs/nshort.lib
 .include ./libs/pshort.lib
```
* Now, we set up the connections to the nodes with ground, Vdd and input pulses.
  * VGND to VSS 0V
  * Supply voltage VPWR to GND.
  * Sweeping a pulse input.
* So, the set the transient analysis code is as below

```
VDD VPWR 0 3.3V
VSS VGND 0 0V
Va A VGND PULSE(0V 3.3V 0 0.1ns 0.1ns 2ns 4ns)
.tran 1n 20n
.control
run
.endc
.end
```
* Final Spice Deck for simulation is as below:
  
![268432458-572ba693-3394-4c69-aa60-0623757747ff](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/90b0e309-0235-4e19-8e6f-94ffcf064c9c)

**NGSpice Simulation and Characterization**  

* we would run this code for simulation:
```
ngspice sky130_inv.spice
```

![Screenshot from 2023-09-17 14-53-14](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c13cdf7e-0b96-402e-9334-eb201383f081)

* The plot of output vs time can be shown below:
![Screenshot from 2023-09-17 14-55-50](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/fbdf7978-1ee1-486b-bb37-14b95780ec5b)

![Screenshot from 2023-09-17 15-09-15](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c86c64b4-d0e6-4e72-b2e5-b5307a30b9dc)

* We can zoom the graph and obtain in new plot also we can get plot value in terminal by just clicking the graph point as shown in the above image
  
* By observing the plot we can conclude,
* Here, there are four timing parameters used for characterizing the inverter standard cell:
  * Rise transition - Time taken for the output to rise from 20% to 80% of max value = 2.240 - 2.143 = 0.067ns
  * Fall Transition - Time taken for the output to fall from 80% to 20% of max value = 4.0921 - 4.049 = 0.0431ns
  * Cell Rise delay - Difference in time(50% output rise) to time(50% input fall) = 2.17333 - 2.13 = 0.0433ns
  * Cell Fall delay - Difference in time(50% output fall) to time(50% input rise) = 4.076 - 4.0501 = 0.0259ns

**DRC Challenges**

Under this section, we will go over

* In-depth overview of Magic's DRC engine
* Introduction to Google/Skywater DRC rules
* Lab : Warm-up exercise : Fixing a simple rule error
* Lab : Main exercise is Fixing or create a complex error
  
**Introduction to Magic and Skywater PDK**

For running the DRC we need to have an understanding of the technology node we are working on. For this one can refer the following

* Magic link 
```
http://opencircuitdesign.com/magic/
```

![266835049-56354c85-f2f1-4dd8-a305-567ad241c664](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0d4715d7-e35c-4a87-a155-0e4a9b509ed1)

* Github Repo for Skywater PDK 
```
https://github.com/google/skywater-pdk
```

* To use the lab contents below is the command:
```
 wget http://opencircuitdesign.com/open_pdks/archive/drc_tests.tgz
```
* To extract the .tgz use below command: 
```
tar xfz drc_tests.tgz 
```
* Now,in that extracted folder there are files like this :
![266835282-a1f1c8b8-82ef-4a51-ae2d-5930579cd82c](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2ce5ab8f-a736-42f5-bfff-4845c06ccb9e)

* Now,open the terminal to open the file give below commands:
```
magic -d XR met3.mag
```

* Below is the periphery rules for m3: (which can be found on https://skywaterpdk.readthedocs.io/en/main/rules/periphery.html#m3)

![266835873-7d65c0c6-8bef-450e-8420-810376d593e4](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6e04ca8b-f91c-4644-a1e0-adfa962217f5)

* Representation is shown below:

![Screenshot from 2023-09-17 15-37-26](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/683cdc28-cb26-402a-87fc-00cc9e4c9a8e)

* Representation of m1 is shown below:
  
![Screenshot from 2023-09-17 15-33-07](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9a52bbd7-dc1d-4861-8de3-4e727e04324d)

* We use the following commands to see metal cut as shown.
```
cif see VIA2
```

![Screenshot from 2023-09-17 15-55-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ccd545d9-c4f3-4571-919b-9073630b5ff8)


## Load SKY130 tech rules for DRC Challenges

* First load the poly file by load poly.mag on tkcon window.
* Finding the error by mouse cursor and find the box area, Poly.9 is violated due to spacing between polyres and poly.

![Screenshot from 2023-09-17 15-56-44](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a8e7dfc9-e455-44a3-befe-269c223d8066)


* We find that the distance between regular polysilicon & poly resistor should be 22um but it is showing 17um and still no errors . We should go to sky130A.tech file and modify as follows to detect this error.

![266859841-0d199111-ded8-4193-a024-544227ab142c](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d11dfb0d-3e65-4b9d-a812-a53c2d508a8c)

* In the line
```
spacing npres *nsd 480 touching_illegal \
	"poly.resistor spacing to N-tap < %d (poly.9)"
```
change to
```
spacing npres allpolynonres 480 touching_illegal \
	"poly.resistor spacing to N-tap < %d (poly.9)"
```
* Now it should be like this :
![266837095-29b5038f-2a70-432b-b15a-5dfff7f2daf5](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/95c92908-0db6-4a28-8438-4361f5db768e)

* Also, update the other
```
spacing xhrpoly,uhrpoly,xpc alldiff 480 touching_illegal \

	"xhrpoly/uhrpoly resistor spacing to diffusion < %d (poly.9)"
```
modify it to
```
spacing xhrpoly,uhrpoly,xpc allpolynonres 480 touching_illegal \

	"xhrpoly/uhrpoly resistor spacing to diffusion < %d (poly.9)"
```
* Now it should be like this :
![266837203-eed19458-b52a-4cac-8a58-cf9a0d2a92b6](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5fda5caa-e6e9-4131-a6b2-ca2e93c4459c)

* Below is the modified final layout:

![Screenshot from 2023-09-17 15-57-35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2134a808-c5d8-4896-840d-173d36760266)


**Implementation of poly resistor Spacing**

* Copy the three resistors by selecting (Edit > select area) and then press 'c' on keyboard.
* You can move the copied resistors by pressing 'm' key and arrow key.

* Now create n diffusion and p diffusion by creating box and selecting the ndiff and pdiff from the sidebar(by clicking the middle button of the mouse).

* Then modify the sky130A.tech file by just modifying the ``*nsd to alldiff``
Now type below command in magic's terminal and all the rules will correctly identify :
```
drc check
```
* Below is the representation:  

![Screenshot from 2023-09-17 15-51-35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1f74d4ff-c523-43c0-8900-27f124c2c8de)

   </details>
   </details>
   
## Day 4: Pre Layout Timing Analysis and Importance of Good Clock Tree
 <details>
  <summary>Timing Modelling Using Delay Tables</summary>  

## Standard Cell LEF generation

* When performing placement, we don't need the entire Magic (MAG) information. Only essential details such as the PR boundary, I/O ports, and power and ground rails of the cell are required.
* This crucial information is outlined in the LEF (Library Exchange Format) file.
* The primary goal is to extract the necessary LEF information from the Magic file and integrate it into our design flow for seamless incorporation into the layout.

**Grid into Track info** 

* Track:A path or a line on which metal layers are drawn for routing. Track is used to define the height of the standard cell.
* To implement our own standard cell, few guidelines must be followed
* I/O ports must lie on the intersection on Horizontal and vertical tracks
* Width and Height of standard cell are odd multiples of Horizontal track pitch and Vertical track pitch
* This information is defined in tracks.info
```
li1 X 0.23 0.46 
li1 Y 0.17 0.34
```
![266860789-660cc8a6-ea06-4d2f-af65-d03e73789b86](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d50985c8-9da5-49df-b341-45e3c54a6046)

* To ensure that ports lie on the intersection point, the grid spacing in Magic (tkcon) must be changed to the li1 X and li1 Y values. After providing the command, we have following:
```
grid 0.46um 0.34um 0.23um 0.17um
```
* Before Conversion representation:
  
![266975000-b6ecccfe-6031-451c-a14a-2144ca3bd6db](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a4fef3c9-1a0c-4282-974d-b91aea5a5e3c)

* After Conversion representation:
  
![266974996-0c2794f2-1d4e-494a-ade5-edbf54899dbb](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a17e87c3-61f2-4106-8a1c-8da0a711a026)

**Lab steps to convert magic layout to standard cell LEF**
* Port defining in the magic, as shown in below image, the steps involved in defining the port:

![266978432-bf0874fe-c853-438e-b9ae-02af19967bab](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/454ab374-b6e8-4c05-8603-42fcf11b8700)

## Create Port Definition:

* However, it's important to define specific attributes and descriptions for the pins associated with a cell. In the context of LEF files, a cell that encompasses ports is scripted as a macro cell, where these ports are formally designated as the PINs of the macro.

* To articulate a port, the process entails utilizing the Magic console, and the steps are as follows:
* Open the Magic Layout window and load the relevant .mag file for the particular design, such as an inverter.
* Navigate to "Edit" and select "Text," initiating a dialogue box for further editing.
* Upon encountering I/O labels, pressing "S" twice swiftly captures the string name and size automatically.
* Confirm that the "Port enable" checkbox is marked to signify this as a port. Additionally, ensure the "Default" checkbox remains unchecked, enabling customization of port characteristics. This is illustrated in the provided figure.

![266978432-bf0874fe-c853-438e-b9ae-02af19967bab](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/454ab374-b6e8-4c05-8603-42fcf11b8700)

* In the depicted figure, the number displayed in the text area adjacent to the "enable" checkbox signifies the sequence in which the ports will be documented in the LEF file. The numbering begins at 0 for the first port.

* Regarding power and ground layers, their definitions can either be similar or distinct from the signal layer. In this scenario, connectivity for ground and power is established utilizing the metal1 layer.

## Set Port Class and Port use Attributes for Layout

* After defining ports, the next step is setting port class and port use attributes.

* Select port A in Magic:
```
port class input
port use signal
```
* Select Y area
```
port class output
port use signal
```
* Select VPWR area
```
port class inout
port use power
```
* Now, select Select VGND area
```
port class inout
port use ground
```

## Custom cell naming and lef extraction.
* Name the custom cell through tkcon window as sky130_vsdinv.mag.
* We generate lef file by command:
```
lef write
```
* This generates sky130_vsdinv.lef file.
![Screenshot from 2023-09-17 17-33-16](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b24fba6d-3a98-4dae-a699-deb0e4669802)

## Steps to include custom cell in ASIC design

* We have created a custom standard cell in previous steps of an inverter. Copy lef file, sky130_fd_sc_hd_typical.lib, sky130_fd_sc_hd_slow.lib & sky130_fd_sc_hd_fast.lib to src folder of picorv32a from libs folder vsdstdcelldesign. Then modify the config.tcl as follows.

```

# Design
set ::env(DESIGN_NAME) "picorv32a"

set ::env(VERILOG_FILES) "$::env(DESIGN_DIR)/src/picorv32a.v"

set ::env(CLOCK_PORT) "clk"
set ::env(CLOCK_NET) $::env(CLOCK_PORT)

set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) {1}

set ::env(LIB_SYNTH) "$::env(OPENLANE_ROOT)/designs/picorv32a/src/sky130_fd_sc_hd__typical.lib"
set ::env(LIB_SLOWEST) "$::env(OPENLANE_ROOT)/designs/picorv32a/src/sky130_fd_sc_hd__slow.lib"
set ::env(LIB_FASTEST) "$::env(OPENLANE_ROOT)/designs/picorv32a/src/sky130_fd_sc_hd__fast.lib"
set ::env(LIB_TYPICAL) "$::env(OPENLANE_ROOT)/designs/picorv32a/src/sky130_fd_sc_hd__typical.lib"

set ::env(EXTRA_LEFS) [glob $::env(OPENLANE_ROOT)/designs/$::env(DESIGN_NAME)/src/*.lef]

set filename $::env(DESIGN_DIR)/$::env(PDK)_$::env(STD_CELL_LIBRARY)_config.tcl
if { [file exists $filename] == 1} {
	source $filename
}
```

* To integrate standard cell in OpenLane flow after make mount , perform following commands:
```
prep -design picorv32a -tag RUN_2023.09.09_20.37.18 -overwrite 
set lefs [glob $::env(DESIGN_DIR)/src/*.lef]
add_lefs -src $lefs
run_synthesis
```
* Synthesis Report :
![4a266902322-2b9b8757-17cc-41f5-b6a8-52a5285698f5](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4c942f71-928f-4d35-91c7-1720dcd862c3)

* STA Report:
![4b266902327-e63e74da-2c40-47e7-90d0-0c17f61758e7](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8cb4c887-da33-408d-adaa-959eb4e5fe7b)

## Delay Tables

* Delay is a critical parameter with significant implications for the behaviour of cells in a design. It essentially governs various aspects of timing within the circuit.
* When dealing with cells of different sizes and threshold voltages, a delay model table, often referred to as a timing table, is established. This table is fundamental for understanding how the delay of a cell depends on input transitions and output loads.
* Consider two scenarios: one where a cell (let's call it X1) is positioned at the end of a long wire and another where the same cell is at the end of a short wire. In the first scenario, the delay of the cell is impacted by the less favourable transition due to the resistance and capacitance effects along the lengthy wire.
* Conversely, the delay is less affected in the second scenario because the wire's characteristics are more favourable. Despite the cells being identical, their delays change based on input transitions and the output loads they encounter.
* VLSI engineers have recognized specific constraints when inserting buffers to maintain signal integrity. They've observed that each buffer level should keep consistent sizing, but their delays can vary depending on the loads they drive. To address this, they introduced the concept of "delay tables."
* These tables are essentially two-dimensional arrays containing values for input slew and load capacitance, associated with different buffer sizes. These tables serve as timing models for the design.
* When algorithms work with these delay tables, they utilize the provided input slew and load capacitance values to calculate corresponding delay values for the buffers.
* In situations where precise delay data isn't available, the algorithm employs interpolation techniques to determine the nearest available data points and extrapolates from them to estimate the required delay values.

<img width="1281" alt="4c266907930-7f23c990-215b-4fd3-a581-448967c046ae" src="https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0dea61c7-d464-42a1-a206-1a32910b637e">

**OpenLane Steps with Custom Standard Cell**

* We performed the synthesis and found that it has positive slack and met timing constraints.
* During Floorplan,504 endcaps, and 6731 tapcells got placed. The design has 275 original rows
* Now  run_placement
* After placement, we check for legality & To check the layout invoke magic from the results/placement directory:
```
magic -T /home/parallels/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read tmp/merged.nom.lef def read results/floorplan/picorv32a.def &
```
![4D266914101-4344be1e-881b-492e-910f-e3a27b052eda](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7044ab51-2463-4106-bb42-a9e00270ad32)


   </details>
   </details>
   
<details>
  <summary>Post-Synthesis Timing Analysis Using OpenSTA</summary>  

## Setup and Hold Time 

* This is where the concepts of SETUP and HOLD time come into play.
* SETUP time is defined as the minimum duration before the active edge of the clock during which the data must remain stable for proper latching. Any deviation from this timing requirement can result in incorrect data being captured, a scenario known as a setup violation.
![4E268226239-2df7daed-20a6-4329-b377-ea3af416ff81](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d89c131a-521f-4f0c-be70-c7b8eac8def0)


* HOLD time is defined as the minimum duration after the active edge of the clock during which the data must remain stable. Violation of this timing requirement can lead to incorrect data being captured, referred to as a hold violation. It's important to note that both setup and hold times are measured specifically with respect to the active clock edge.
![4F268226594-53d2547a-206b-4228-b215-0c3b6aeea644](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b4c7c391-5d5f-4e3a-907e-8d25c5e81473)

## Clock Jitter 

* Clock jitter can arise due to various factors within the clock generator circuitry, environmental noise, power supply fluctuations, and interference from neighbouring circuitry. In the process of timing closure specification, the design margin accounts for jitter as a significant factor.
* Period jitter is the discrepancy between a clock signal's cycle time and the ideal period observed over a substantial number of randomly selected cycles, often around 10,000 cycles. This deviation in the clock period can be represented as an average value (RMS value) across these cycles or as the difference between the maximum and minimum deviations within the selected cycle group (peak-to-peak period jitter).
* Cycle-to-cycle jitter (C2C) is defined as the difference between two consecutive clock cycles within a random selection of clock cycles, typically again around 10,000 cycles. This is usually expressed as the peak value within the randomly selected group, providing insight into the high-frequency jitter.
* In the frequency domain, the phenomenon being measured is referred to as phase noise. Phase noise represents rapid, fleeting, and random phase variations in the waveform. These variations can be converted into jitter values, which are crucial considerations in digital design.

![4G268441195-65b0b057-5260-454b-805b-4da1e332be88](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ca2481e8-d2da-4d20-8047-b662affdd59b)

**Causes of Clock Jitter**

* Clock jitter, characterized by timing uncertainties in a clock signal, can be influenced by various factors:

* Noise: Electronic circuits can introduce noise into the system, causing fluctuations in the clock signal. Sources of noise include power supply fluctuations and electromagnetic interference, both of which can contribute to jitter.

* Component Variations: Variations in electronic component characteristics, such as resistors, capacitors, and transistors, can introduce discrepancies in the clock signal, leading to jitter.

* Temperature Fluctuations: Changes in temperature can affect the behavior of electronic components, causing variations in clock timings and contributing to clock jitter.

* Phase-Locked Loops (PLLs): Phase-Locked Loops (PLLs) are commonly utilized for generating stable clock signals. However, improper design or configuration of PLLs can introduce jitter into the clock signal, impacting timing precision.

* Clock Distribution: Clock signals travel through various paths such as PCB traces or cables during distribution. These paths may introduce delays, reflections, or other irregularities in the clock signal, resulting in jitter.

* Addressing and mitigating these sources of jitter is crucial in maintaining timing accuracy and reliability in electronic circuits and systems.

* Timing analysis is carried out outside the openLANE flow using OpenSTA tool. For this,`` pre_sta.conf `` is required to carry out the STA analysis. Invoke OpenSTA outside the OpenLANE flow as follows:
```
sta pre_sta.conf
```
sdc file for OpenSTA is modified like this:

base.sdc is located in vsdstdcelldesigns/extras directory. So, I copied it into our design folder using
```
cp my_base.sdc /home/parallels/OpenLane/designs/picorv32a/src/
```

* While I didn't encounter any violations, I have practical experience in timing analysis using OpenSTA.
* During the placement stage, the clock is presumed to be ideal since it propagates only once the clock tree synthesis (CTS) is performed. Consequently, only setup slack is considered before CTS, assuming an ideal clock in the placement stage.
* In timing analysis, "setup time" refers to the minimum duration required for the data to stabilize before the active edge of the clock to ensure accurate capture.
* "Setup slack" is computed as the difference between the data required time and the actual data arrival time.
* The clock is generated from a Phase-Locked Loop (PLL) that includes built-in circuits and logic cells. Clock generation can exhibit variations depending on the circuit, collectively referred to as clock uncertainty. Clock uncertainty encompasses parameters like skew, jitter, and margin.
* "Clock Jitter" is defined as the deviation of a clock edge from its original position, representing a form of uncertainty in the timing of the clock signal.
* From the timing report, we can improve slack by upsizing the cells i.e., by replacing the cells with high drive strength and we can see significant changes in the slack.
  
   </details>
   </details>
   
<details>
<summary>Clock Tree Synthesis TritonCTS and Signal Integrity</summary>  

## Clock Tree Synthesis
* The primary objective of constructing a clock tree is to ensure that the clock input effectively reaches all elements in a design without any significant clock skew. A commonly employed method for achieving this is the H-tree structure in Clock Tree Synthesis (CTS).
* When attempting to reduce slack in a prior run, you may have observed modifications in the netlist due to cell replacement techniques before initiating the CTS process using a tool like TritonCTS.
* In Clock Tree Synthesis, the aims include minimizing the routing resources for the clock signal and reducing the area occupied by clock repeaters. Simultaneously, it's essential to maintain acceptable levels of clock skew, clock latency, clock transition time, pulse width, and duty cycle for all sequential elements within the design.
* Additionally, the goal is to ensure the clock power remains within specified limits. Clock skew, a critical parameter, pertains to the variance in clock arrival times between different registers within the design
* Clock Tree Synthesis (CTS) encompasses several methods, each suited for specific design requirements and constraints. Here are various approaches to CTS:
* Balanced Tree CTS: Clock signals are distributed in a balanced manner, resembling a binary tree. The aim is to ensure nearly equal path lengths to all clock sinks (flip-flops), minimizing clock skew. While relatively simple to implement and analyze, it may not be the most power-efficient solution.
* H-tree CTS: Utilizes a hierarchical tree structure resembling the letter "H." Effective for distributing clock signals across large chip areas, reducing clock skew, and optimizing power consumption.
* Star CTS: Clock signal is distributed from a single central point (star-like) to all flip-flops. Simplifies clock distribution and minimizes clock skew but may require more buffers near the source.
* Global-Local CTS: A hybrid approach combining elements of star and tree topologies. Global clock tree distributes the clock signal to major clock domains, while local trees handle further distribution within each domain. Balances global and local optimizations.
* Mesh CTS: Clock wires are organized in a mesh-like grid pattern, with each flip-flop connected to the nearest available clock wire. Often used in structured designs like memory arrays, striking a balance between simplicity and skew minimization.
* Adaptive CTS: Dynamic adjustment of the clock tree structure based on timing and congestion constraints in the design. Offers greater flexibility and adaptability in meeting design goals but may be more complex to implement.

* Below is an example of a Bad Tree

![4M268228489-ec506293-59a4-4a69-a7e9-8876d0cf79d1](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e75da380-488a-44ea-a645-99a0ec05129d)

## Cross Talk & Cross Net Shielding
* Crosstalk noise represents an undesirable disturbance on the clock network induced by adjacent aggressive nets. This interference can either delay or accelerate the clock signal, or even introduce unwanted transitions referred to as glitches.
* Impact: The issue of crosstalk looms large in VLSI design due to the tightly packed components on a chip. Unchecked crosstalk has the potential to cause data corruption, timing breaches, and escalate power usage.
* Mitigation: VLSI designers utilize an array of methods to address and alleviate crosstalk. These include optimizing layout and routing, employing suitable shielding, enacting effective clock distribution strategies, and utilizing clock gating to curtail dynamic power consumption during logic inactivity.
* To preserve the signal integrity of the clock, physical designers shield the clock wires by utilizing a power net. Additionally, they may implement Non-Default Rules (NDR) to route the clock signal while leaving an empty track beside the clock route.
*  This strategic routing minimizes the impact of noise on the clock network. The primary role of the clock signal is to manage and synchronize triggering events in a synchronous design. Therefore, ensuring signal integrity is crucial in meeting the functional specifications of the design.

* In the domain of VLSI circuits, establishing synchronous operation hinges on a well-structured clock distribution network. The primary objective is to facilitate the effective dissemination of clock signals across every sector of the chip while minimizing skew and upholding signal integrity.

* Implementation of Shielding Methods: To uphold the clock network's integrity and mitigate interference risks, VLSI designers frequently implement shielding techniques. These encompass the integration of dedicated clock routing layers, the application of clock tree synthesis algorithms, and strategic buffer insertion—all aimed at enhancing clock distribution efficiency.

* Separation of Clock Domains: VLSI designs commonly encompass multiple clock domains. The strategic use of shielding and precise clock gating is paramount to ensuring that clock signals remain confined within their designated domains. By preventing unwarranted propagation between domains, this measure effectively mitigates metastability issues and maintains synchronization.
![4g268228943-bdc9c311-15e5-4d70-99b4-c2cf1dd1adbd](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/95e42c95-6597-4815-8892-016002e4ad86)

**Clock Tree Synthesis Lab**

* In this stage clock is propagated and make sure that clock reaches each and every clock pin from clock source with mininimum skew and insertion delay.
* Inorder to do this, we implement H-tree using mid point strategy. For balancing the skews, we use clock invteres or bufferes in the clock path. Before attempting to run CTS in TritonCTS tool, if the slack was attempted to be reduced in previous run, the netlist may have gotten modified by cell replacement techniques.
* Therefore, the verilog file needs to be modified using the write_verilog command. Then, the synthesis, floorplan and placement is run again. To run CTS use the below command:
```
run_cts
```

![268460626-334fd5f3-db94-4484-a822-eb73d9ec0b73](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c3fda4d9-3232-41ba-bf1b-78688828b633)

* Since, the clock is propagated, from this stage, we do timing analysis with real clocks. From now post cts analysis is performed by Openroad within the OpenLane flow
* We use the following command to execute CTS within OpenLane:
```
openroad
read_lef <path of merge.nom.lef>
read_def <path of def>
write_db pico_cts.db
read_db pico_cts.db
read_verilog /home/parallels/OpenLane/designs/picorv32a/runs/RUN_09-09_11-20/results/synthesis/picorv32a.v
link_design picorv32a
read_liberty $::env(LIB_SYNTH_COMPLETE)
read_sdc /home/parallels/OpenLane/designs/picorv32a/src/my_base.sdc
set_propagated_clock (all_clocks)
report_checks -path_delay min_max -format full_clock_expanded -digits 4
```
![l268460756-8f40f6de-4c0c-401d-986a-48969ab38278 (1)](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d76e1b3f-dc8c-46d0-a5cf-9518c614495a)

* Running picorv32a command in OpenLane image is below:
```
run_cts
```  
![Screenshot from 2023-09-17 22-25-02](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a66df7bd-69c4-454a-8ca0-fa9a983b313c)

  
 </details>
   </details>

## Day 5: Final Steps for RTL2GDS using TritonRoute and OpenSTA
 <details>
  <summary>Routing and Design Rule Check(DRC)</summary>  
	 
## Maze Routing and Lee's algorithm

* Routing Definition: Routing is the act of establishing a physical link between two pins. Routing algorithms are designed to consider source and target pins, aiming to discover the most efficient path between them, ensuring a valid connection.

* Maze Routing Algorithm: An approach to solve routing challenges is the Maze Routing algorithm, like the Lee algorithm. This technique employs a grid resembling the one used in cell customization for routing. Starting from specified source and target points, the Lee algorithm utilizes this routing grid to find the shortest or most efficient route between them.

* The algorithm applies labels to neighbouring grid cells around the source, incrementing them from 1 until reaching the target (e.g., from 1 to 7). This process may yield various paths, including L-shaped and zigzag-shaped routes. The Lee algorithm emphasizes selecting the optimal path, usually favouring L-shaped routes over zigzags. In the absence of L-shaped paths, it may opt for zigzag routes. This method proves particularly beneficial for global routing tasks.

* However, it's important to acknowledge the limitations of the Lee algorithm. It effectively constructs a maze and labels its cells from the source to the target. While efficient for routing between two pins, it can become time-consuming when dealing with a vast number of pins. There are alternative algorithms designed to address similar routing challenges.

![Screenshot from 2023-09-17 19-50-29](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/67a1ac8c-f3fe-41e0-93b9-867a03264e2b)

## Design Rule Check (DRC)

* DRC Definition: Design Rule Checking (DRC) is a validation process that assesses whether a design conforms to the predetermined process technology regulations specified by the foundry for its fabrication. DRC validation is a crucial step within the physical design workflow, ensuring the design complies with manufacturing prerequisites and mitigates the risk of chip failure. It essentially outlines the chip's quality.

* Various DRCs: DRC encompasses an array of checks, including but not limited to the following:

* Design rules governing physical wires, encompassing aspects like:
  * Minimum wire width
  * Minimum wire-to-wire spacing
  * Minimum wire pitch
  
* To address signal short violations, a common strategy involves employing an upper metal layer by placing it over the metal layer in question. The DRC checks related to this strategy typically involve:

* Via rules, including:
    * Via width
    * Via spacing
 
![5a268349811-6e06f298-9772-45ca-954d-3ec34b755766](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1d2e3816-f26a-4387-860f-8be197882bc5)

 </details>
   </details>

 <details>
  <summary>Power Distribution Network and Routing</summary>

* Unlike the general ASIC flow, Power Distribution Network generation is not a part of the floorplan run in OpenLANE. PDN must be generated after CTS and post-CTS STA analyses:
* We can check whether PDN has been created or not by checking the current def environment variable: ``echo $::env(CURRENT_DEF)``

```
prep -design picorv32a -tag Run 12.07.10.11
gen_pdn
```
![Screenshot from 2023-09-17 22-31-16](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b2219e4a-28cc-4291-9269-164362b00071)

![5b268378589-d4308ba0-8ba9-4b2c-9e45-25f4f0c07b31](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/85d3d7d5-2606-4699-8e18-2e3dbdd381a3)

* After initiating the command, a power distribution network is established. This network is built using the design_cts.def file as its input definition.
* The PDN process involves the creation of power rings, straps, and rails. These components play critical roles in facilitating power flow. Initially, power is drawn from VDD and VSS pads to the power rings.
* Following this, both horizontal and vertical straps connected to the rings serve as conduits for drawing power from the straps. The rings are interconnected with standard cells, and power is then supplied to the standard cells through the rails.
* The standard cells are meticulously designed to have heights that are multiples of the vertical tracks, with a track pitch of 2.72. Adhering to these conditions is essential for effectively powering the standard cells.
* Definitions and specifications for the straps and rails are present in the design. In this specific design, the straps are positioned at metal layers 4 and 5, while the standard cell rails are situated at metal layer 1. Vias are utilized to establish connections across these layers as needed.
  
![Screenshot from 2023-09-17 19-55-27](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/83714db0-76cc-421a-86e5-a8d7b7973b3d)
  
 </details>
   </details>   

<details>
  <summary>TritonRoute Feature</summary>
	
## Routing

* In the domain of routing within Electronic Design Automation (EDA) tools, encompassing both OpenLANE and commercial EDA tools, the routing process is highly intricate given the expansive design space. To streamline this complexity, routing is typically segmented into two primary stages: Global Routing and Detailed Routing.

* These stages are managed by two distinct routing engines:
* Global Routing: At this stage, the routing region is partitioned into rectangular grid cells, forming a coarse 3D routing graph. This task is accomplished by the "FASTE ROUTE" engine.
* Detailed Routing: In this phase, a finer grid granularity and routing guides are utilized to execute the physical wiring. The "tritonRoute" engine is activated during this stage. "Fast Route" generates initial routing guides, and "Triton Route" then refines the routing using the Global Route information. It employs various strategies and optimizations to determine the most efficient path for connecting the pins.

## Key Features of TritonRoute

* Initial Detailed Routing: TritonRoute commences the intricately detailed routing process, laying the initial groundwork for subsequent routing steps.
* Adherence to Pre-Processed Route Guides: TritonRoute prioritizes strict adherence to pre-processed route guides, involving several key actions:
  * Analysis of Initial Route Guides: TritonRoute scrutinizes the directions specified in the preferred route guides. In cases where non-directional routing guides are detected, they are divided into unit widths.
  * Guide Splitting: When non-directional routing guides are encountered, TritonRoute segments them into unit widths to facilitate the routing process.
  * Guide Merging: TritonRoute consolidates guides that are orthogonal (touching guides) to the preferred guides, streamlining the routing trajectory.
  * Guide Bridging: In the presence of guides running parallel to the preferred routing guides, TritonRoute introduces an additional layer to bridge them. This ensures efficient routing within the preprocessed guides.
  * The procedure assumes that each net has a route guide satisfying inter-guide connectivity. This includes sharing the same metal layer with touching guides or neighbouring metal layers with a nonzero vertically overlapped area (where vias are placed). Additionally, every unconnected terminal, i.e., the pin of a standard cell instance, should have its pin shape overlapped by a routing guide, depicted as a black dot (pin) within a purple box (metal1 layer).
    
<img width="1281" alt="5d268355720-b047856c-d799-4d96-bcf9-46ad4e9bba4c" src="https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c3ea4355-21c9-4145-bef3-c82ffb571e3f">

* We can summarise it, TritonRoute stands as a sophisticated tool that not only initiates the initial detailed routing but also places significant importance on enhancing routing within pre-processed route guides. This is achieved through meticulous actions such as breaking down, merging, and bridging these guides as necessary, ultimately aiming for highly efficient and effective routing outcomes.
  
<img width="1290" alt="5e268355662-b8d2a78d-abb2-411d-a609-afc486ca808e" src="https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/94a9e05b-e9d7-4573-9ac1-cebd313eb488">

* Works on MILP(Mixed Integer linear programming) based panel routing scheme with Intra-layer parallel and Inter-layer sequential routing framework

## TritonRoute Problem Statement
```
Inputs : LEF, DEF, Preprocessed route guides
Output : Detailed routing solution with optimized wire length and via count
Constraints : Route guide honoring, connectivity constraints and design rules.
```
* The space where the detailed route takes place has been defined. Now TritonRoute handles the connectivity in two ways.
* Access Point (AP): An Access Point (AP) refers to a specific point on the metal of the route guide, positioned on the grid. It serves the purpose of connecting to various components such as lower-layer segments, pins, IO ports, or upper-layer segments.
* Access Point Cluster (APC): An Access Point Cluster (APC) encompasses all the Access Points (APs) derived from the same lower-layer segment, pin, IO port, or upper-layer guide. It represents a union or grouping of these access points, providing a collective entity for efficient routing.
* TritonRoute run for routing,make sure the CURRENT_DEF is set to pdn.def
* Start routing by using
```
run_routing
```
* The options for routing can be set in the config.tcl file. The optimisations in routing can also be done by specifying the routing strategy to use different versions of the TritonRoute Engine. There is a trade-off between the optimised route and the runtime for routing.
* For the default setting picorv32a takes approximately 30 minutes according to the current version of TritonRoute.
* Here drc violation is zero:

![5g268378251-b77dda43-8564-4a47-89c9-853f35c7878e](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2619d8a7-b35e-4a29-8519-200ae8b9d0ab)


## Layout in Magic tool post Routing:

* The design can be viewed on magic within the results/routing directory. Run the following command in that directory:
```
magic -T /home/parallels/OpenLane/vsdstdcelldesign/libs/sky130A.tech lef read tmp/merged.nom.lef def read results/routing/picorv32a.def &
```
![5e268383481-cdc9252e-4e65-4319-bcbc-ef1dec3a87f3](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/42c3930f-19d2-4be4-b4f9-6814eaa6fa75)

## Identifying Custom Made SKY130_vsdinv
* In tkcon type the following command to check whether sky130_vsdinv exist or not
```
getcell sky130_vsdinv
what
expand
```
![5f268466018-a14cf4e4-c4f7-401f-8d8e-975943492557](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f69e3a25-87bd-415e-b17e-fec2e6651908)

## Slack Report Post Routing:
![265P8386394-efd5e673-af98-45b8-a833-9bfb81d198b1](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cbd5939d-6df1-4e76-ada8-85a342b16643)

## Post-synthesis Flip Flop to Standard Cell Ratio:
![5Q268467051-59abe810-16eb-4bad-8067-18adc7c47fc6](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/00d9d4aa-450f-44c8-85e6-66c480405ecd)

* The Flip-Flop to standard cell Ratio = 1613/18508 = 0.0871
  
## OpenLANE Interactive Flow:
```
cd /home/solanki-pratikkumar/OpenLane
./flow.tcl -interactive
package require openlane 0.9
prep -design picorv32a
run_synthesis
run_floorplan
detailed_placement
run_cts
run_routing
```
![Screenshot from 2023-09-17 22-32-16](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/515633ca-f79e-4b7c-8315-340059aea739)

![Screenshot from 2023-09-17 22-33-02](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/09059e03-99a8-4e57-823d-f55565f32bc4)

 </details>
   </details>   

## Acknowledgement

* Prof. Kunal Ghosh, VSD Corp. Pvt. Ltd.
* Pruthvi Parate, Colleague,IIIT B
* Alwin Shaju, Colleague,IIIT B
* Divyam Satle, Colleague,IIIT B
* Chatgpt

## References

* https://www.vsdiat.com
* https://github.com/The-OpenROAD-Project/OpenLane
* https://github.com/nickson-jose/vsdstdcelldesign
* http://opencircuitdesign.com/magic/
* https://github.com/google/skywater-pdk
* https://www.researchgate.net/
* https://github.com/Devipriya1921/Physical_Design_Using_OpenLANE_Sky130
* https://github.com/kunalg123/
* https://github.com/google/skywater-pdk
