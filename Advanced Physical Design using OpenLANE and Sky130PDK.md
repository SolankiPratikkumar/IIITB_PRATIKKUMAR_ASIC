[](url) Physical Design of ASICs - Advanced Physical Design using OpenLANE


## DAY 1: Inception of Open Source EDA, OpenLANE and Sky130PDK

 <details>
  <summary>How to Talk to Computer</summary>
  
# Introduction to QFN-48 Package, Chip, Pad, Core, Die, IPs

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
  
# Introduction to OpenLANE and Strive Chipset

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

![Screenshot from 2023-09-16 22-44-12](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/53cc5335-6be7-423a-935a-bac5f5130f5)  
* Below is dff_synthesis report:
![266792079-c4d04351-021f-4c56-9327-c88d52a8cd8f](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ec38cdee-a0c4-4ab4-8547-8cd6b87f10ed)

![266792086-ac2cc982-f792-4251-9b1b-b337f8bdba4b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1ddbaba6-48c0-43a4-90d9-42bcf57f5b31)

![265791982-686d8a71-a016-4b77-83b2-2b3625f4cf91](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/8d4a495a-eac3-432b-9283-683d302bead0)

* Below is synthesis_pre report:
![265792337-f73e82ad-a3bd-4a95-aa71-8542b4f47ebd](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7af25fb0-d7c2-4a2c-af28-3a0d069c8d61)

**Flops ratio:**
* The flop ratio is defined as the ratio of the number of flops to the total number of cells
* Here flop ratio is 1596/10104 = 0.1579 (i.e: 15.8%) [From the synthesis statistics]
 </details>
 </details>
 
 ## DAY 2: Good Floorplan vs Bad Floorplan and Library Cell

 <details>
  <summary>Chip Floorplaning Consideration</summary>  
  
# Utilization Factor and Aspect Ratio

* Core: The term "core width" generally pertains to the physical dimensions or size of the central processing unit (CPU) or processor core within a microchip. Typically quantified in nanometers (nm) or micrometers (µm), it is denoted as, for instance, a "14nm core" or a "7nm core," representing the transistor feature size within the core. Conversely, the "core height" isn't typically expressed in a similar manner to the width. Instead, the core's dimensions are usually communicated in relation to its overall area, calculated by multiplying its width and height.

* Die: The term "die width" typically denotes the physical measurement of the semiconductor wafer after all the individual integrated circuits (ICs) have been constructed on it, just prior to their separation. The widths of dies can vary considerably based on the particular manufacturing process and the design of the chips being manufactured, ranging from a few millimeters to several centimeters or even more.

* Comparable to the core, discussions about the "die height" are infrequent. Instead, the size of the die is commonly conveyed in relation to its area, which is calculated by multiplying its width and height.
 
* Here we are creating a netlist using 1 AND gate,1 OR gate,2 FlipFlop and all the logic gates for physical design are considered as square dimension same as Flipflop as shown in below image

![Screenshot from 2023-09-16 16-31-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/0f3a0d1f-2679-4abf-831f-f7ad6da9c939)

* We can observe the netlist connection and all standard cell and flipflops are taken as 1*1 sq unit as shown below
![Screenshot from 2023-09-16 16-34-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6745e69c-2425-40dc-b2f2-b63df8774f2f)

* Below image we observe that the complete netlist is with dimension 4 sq unit and the core dimension is 4*2 sq unit hence by Utilisation formula as mention it will be 0.5 or 50% and the aspect ratio as per formula will be also 0.5 as per fromula mention image.
* If the total dimension area of netlist is equal area of core then Utilisation factor and Aspect Ratio equals 1 which means core is square in shape
  
* Utlisation Factor == Total area occupied by the netlist / Total area of the core.
* Aspect ratio = Height of core / Width of core

![Screenshot from 2023-09-16 16-44-28](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/03d73c1c-e816-40e0-80fb-ba299cf6dc88)

# Concept of Pre- Placed Cell


* Pre-placed cells (or pre-placed blocks) in ASIC (Application-Specific Integrated Circuit) design refer to predefined and fixed blocks of logic or circuitry that are manually placed in specific locations on the semiconductor chip's layout before the automated placement and routing process.These cells are placed manually by the chip designer or through automated tools. Since these IP's are placed before automated Placement and Routing, these are reffered to as Pre-placed cells.
* Pre-Placed cells- There are few IP's/blocks have user defined locations, and hence placed in chip before automated placement and routing and are called preplaced cells.

![Screenshot from 2023-09-16 18-22-00](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3d35eedc-f41e-4677-b166-87df1c6406a9)

![Screenshot from 2023-09-16 18-26-07](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3b11a626-c2a5-4d8f-aae2-7d41c3517254)

  
# Decoupling Capacitor

* Decoupling capacitors play a vital role in electronic circuit design by ensuring a steady power supply, filtering out unwanted noise, and enhancing the overall performance and reliability of electronic systems, especially in digital and mixed-signal applications. It's crucial to carefully choose, position, and size decoupling capacitors to maximize their efficiency in noise reduction and voltage stability, thus optimizing circuit functionality.

* Pre-placed cells must then be surrounded with decoupling capacitors (decaps). The resistances and capacitances associated with long wire lengths can cause the power supply
voltage to drop significantly before reaching the logic circuits.Their role is to decouple the circuit from power supply by supplying the necessary amount of current to the circuit. They pervent crosstalk and enable local communication.

![266765647-8eaf2eea-3251-4869-bd19-09346d7c9f12](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1ce2773b-fa92-488f-9f63-5bb93080a136)

# Power Placement

* Suppose there are numerous macros on a chip, and when the output switches from '1' to '0,' the excess charge is dissipated into the ground line, resulting in a visible ground bump. Likewise, when it switches from '0' to '1,' there is a voltage drop observed in the power supply. To address this issue, implementing multiple supply lines for both VDD and ground can be a potential solution, as illustrated below:
![267383508-c4702946-dc09-4e1d-b727-87cb66dc3295](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3e27ae61-02a2-4ad4-bc17-8df6ae3c8315)

# Pin Placement

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

# Optimize Placement

* Placement is the process of placing the cells in the core area of the chip as shown below

![266786781-4887d41c-a227-47df-b30a-c92b8a800019](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/747c1481-ca5d-482e-a30f-95b97bede7c7)

* The next step in the OpenLANE ASIC flow is placement. The synthesized netlist is to be placed on the floorplan. Placement is perfomed in 2 stages:
* 1.Global Placement: It finds optimal position for all cells which may not be legal and cells may overlap. Optimization is done through reduction of half parameter wire length.
* 2.Detailed Placement: It alters the position of cells post global placement so as to legalise them
![2b266786848-e40e5c6c-a71d-454e-8cba-4b24530cc44b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/eba5dcd4-9218-4383-a6e5-8b556c386932)

* Optimization is stage where we estimate the lenght and capictance, based on that we add buffers. Ideally, Optimization is done for better timing

![Screenshot from 2023-09-16 23-50-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/aa4ccb5f-7d53-42c7-8065-2c2a4192ac9b)

 # Netlist Binding and initial place design

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

# Standard Cell Characterization Flow

* A typical standard cell characterization flow that is followed in the industry includes the following steps:

1. Read in the models and tech files
2. Read extracted spice Netlist
3. Recognise behavior of the cells
4. Read the subcircuits
5. Attach power sources
6. Apply stimulus to characterization setup
7. Provide neccesary output capacitance loads
8. Provide neccesary simulation commands

* Now,all these 8 steps are fed in together as a configuration file to a characterization software called GUNA. This software generates timing, noise, power models. These .libs are classified as Timing characterization, power characterization and noise characterization

![242526685-87348350-fa25-4ef8-99f4-1cdddf070f10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/31f0760b-24ca-46e9-aa7f-c66b214e8942)

![266853817-34bb2182-24c1-40b7-b06b-faccf1959727](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/383e0f2f-b9fe-4f0a-b3e6-7730f389aba8)

![266853809-bef80248-0189-495b-9579-f1bbb9444096](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/24de945b-887b-4f78-8808-bc9009475c66)

</details>

 <details>
  <summary>General Timing Characterisation Parameters</summary> 

* The can understoodthis Parameter by taking a circuit as a reference
  
![2ba 266782039-b9f3b27d-3cd0-48d4-bbc5-848b18c63045](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a96da9ac-8c14-458a-baaf-67d854723080)

* slew_low_rise_thr : Its generally taken as a point in the rising wavform, the point is at rising edge generally at 20% value from the initial point.

* slew_high_rise_thr : Its generally taken as a point in the rising wavform, the point is at rising edge generally at 20% value from the final point of the waveform, also it can also be considered as 80% from initial point of the waveform.

* slew_low_fall_thr : Its generally taken as a point in the falling wavform, the point is at rising edge generally at 20% value from the initial point.

* slew_high_fall_thr : Its generally taken as a point in the falling wavform, the point is at rising edge generally at 20% value from the final point of the waveform, also it can also be considered as 80% from initial point of the waveform.

![2bb_266782248-24922247-a8b7-42c7-8f19-3315f8be5f8b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/715e0393-d660-490c-ae72-5d9cb5384404)
  
* in_rise_thr : It is generally taken the 50% value point in the input rise waveform.

* in_fall_thr : It is generally taken the 50% value point in the input fall waveform.

* out_rise_thr : It is generally taken the 50% value point in the output rise waveform.

* out_fall_thr :  It is generally taken the 50% value point in the output fall waveform

* The above concept is shown in below image:
  
[2bc_266782346-7794cd40-f580-4443-ab91-134d111c4fdf](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a74870c6-5b5c-4841-881e-7f989e287195)


* **Propagation Delay** refers to the time interval between when the input, in the process of transitioning, reaches 50% of its ultimate value, and the moment the output also achieves 50% of its final value. Inadequate selection of threshold values can result in negative delay values. Even with appropriate threshold choices, variations in slew rate can sometimes cause the delay to be either positive or negative.
* Propagation delay = time(out_thr) - time(in_thr)

* Transition Time is the time it takes the signal to move between states is the transition time , where the time is measured between 10% and 90% or 20% to 80% of the signal levels.
* Rise transition time = time(slew_high_rise_thr) - time (slew_low_rise_thr)
* Low transition time = time(slew_high_fall_thr) - time (slew_low_fall_thr)
  
 </details>
 </details>

