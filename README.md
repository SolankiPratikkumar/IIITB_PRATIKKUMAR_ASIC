[](url) Physical Design of ASICs


## DAY 0
<details>
<summary>DAY-0</summary>
<br>

<details>
<summary>Summary</summary>
 
Here we are installing Yosys, Iverilog, GTKWave, MAGIC, OpenLane, OPENSTA which are needed tools for ahead coursework. 
</details>

<details>
<summary>Yosys</summary>
    
**Key Features of Yosys:**
    
(1) RTL Synthesis: Yosys takes RTL descriptions written in the Verilog hardware description language (HDL) as input and performs synthesis to generate gate-level netlists. This process involves converting the RTL code into a network of logic gates, flip-flops, and other basic digital components.

(2) Technology Mapping: Yosys supports various technology mapping algorithms to map the synthesized logic to specific target libraries, which are collections of predefined gates and flip-flops available in a specific technology or manufacturing process.

(3) Optimization: Yosys includes a range of optimization passes that aim to improve the quality of the synthesized design. These optimizations can target various aspects such as area, power consumption, and timing performance.

(4) Formal Verification: Yosys supports formal verification techniques to ensure that the synthesized design behaves correctly based on formal mathematical proofs rather than relying solely on simulation.

(5) Support for FPGA and ASIC: Yosys is versatile and can be used for both field-programmable gate array (FPGA) designs and application-specific integrated circuit (ASIC) designs. It supports a variety of FPGA architectures and ASIC libraries.

Overall, Yosys plays a significant role in the digital design and hardware development process, providing an open-source and flexible platform for RTL synthesis and related tasks.

**Steps to install Yosys**

```
git clone https://github.com/YosysHQ/yosys.git
cd yosys 
sudo apt install make (If make is not installed please install it) 
sudo apt-get install build-essential clang bison flex \
    libreadline-dev gawk tcl-dev libffi-dev git \
    graphviz xdot pkg-config python3 libboost-system-dev \
    libboost-python-dev libboost-filesystem-dev zlib1g-dev
make config-gcc
make 
sudo make install
```
![Screenshot from 2023-08-01 23-07-31](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3f208d14-c0b1-4c0e-a30a-74e02a0dbdcc)
Yosys installed
</details>


<details>
<summary>IVerilog</summary>
    
**Key Features of Icarus Verilog:**

(1) Verilog Simulation: IVERILOG primarily focuses on Verilog simulation. It can simulate the behavior of digital circuits described in Verilog, allowing designers to verify their designs' functionality and behavior before synthesis.

(2) Support for Verilog Standards: IVERILOG supports various versions of the Verilog HDL standard, including IEEE 1364-2005 (Verilog 2005) and parts of IEEE 1364-2001 (Verilog 2001).

(3) Command-Line Interface: IVERILOG is primarily used through the command-line interface, where users provide input files, simulation parameters, and other options. This makes it suitable for integration into automated testing and scripting environments.

(4) Waveform Generation: IVERILOG can generate VCD (Value Change Dump) and other waveform formats that allow users to visualize the behavior of their designs over time using waveform viewer tools.

(5) Support for Different Simulation Levels: IVERILOG supports various simulation levels, including behavioral, RTL (Register Transfer Level), and gate-level simulations. This enables designers to simulate different levels of abstraction.

**Steps to install Icarus Verilog**
```
sudo apt-get install iverilog
```
![Screenshot from 2023-08-01 23-08-24](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/83636fdd-673d-4c39-bace-eb66ece762d2)
iverilog installed
</details>


<details>
    <summary>GTKWave</summary>

**Key Features of GTKWave:**

(1) Waveform Visualization: GTKWave provides a graphical interface for viewing digital waveforms. It allows users to see how signal values change over simulation time, helping to debug and analyze digital designs.

(2) Support for Various Formats: GTKWave supports various waveform file formats, including VCD (Value Change Dump), FST (Fast Signal Trace), LXT (LXT2), and more. This flexibility allows it to work with output files from different simulation tools.

(3) Hierarchical Views: Users can navigate through hierarchical designs, inspecting signals and modules at different levels of abstraction. This is especially useful for analyzing complex designs with multiple levels of hierarchy.

(4) Zooming and Scrolling: GTKWave enables users to zoom in and out of the waveform display and scroll through time, allowing them to focus on specific sections of the simulation and analyze signal transitions in detail.

(5) Search and Highlight: Users can search for specific signal names or values within the waveform display and highlight instances where those values match the search criteria.

**Steps to install GTKWave**
```
sudo apt update
sudo apt install gtkwave
```
![Screenshot from 2023-08-01 23-07-31](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c87362a8-7618-462f-a9d0-f967a049f0e1)
GTKWave installed
</details>

<details>
    <summary>NGSPICE</summary>

**Key Features of NGSPICE:**

(1) SPICE Compatibility: NGSPICE aims to be compatible with the original SPICE syntax and functionality. This allows users familiar with SPICE to transition to NGSPICE with minimal effort.

(2) Wide Range of Circuit Simulations: NGSPICE supports the simulation of various types of electronic circuits, including analog, digital, and mixed-signal designs. It can handle both linear and non-linear circuit elements.

(3) Various Component Models: NGSPICE includes a wide range of built-in component models such as resistors, capacitors, inductors, transistors, diodes, operational amplifiers, and more. Users can also define custom models.

(4) Interactive and Batch Modes: NGSPICE can be used interactively through a command-line interface or in batch mode where simulations are defined in a script or input file.

(5) Transient Analysis: NGSPICE can perform transient analysis, which involves simulating the behavior of a circuit over a specified time period. This is useful for studying how circuit components respond to changes over time.

**Steps to install NGSPICE**

Download the tarball from https://sourceforge.net/projects/ngspice/files/ to a local directory and then follow the commands given below :
```
# Dependency for ngspice:
sudo apt-get install libxaw7-dev

# ngspice installation:
tar -zxvf ngspice-40.tar.gz
cd ngspice-40
mkdir release
cd release
../configure  --with-x --with-readline=yes --disable-debug
make
sudo make install
```


![Screenshot from 2023-08-02 10-22-47](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4bbe9b3b-05d9-448f-a4b9-3c8bf8868d7f)
NGSPICE installed
</details>

<details>
    <summary>OPENSTA</summary>

**Key Features of OPENSTA:**

(1) Static Timing Analysis: OpenSTA performs static timing analysis, which involves analyzing the timing paths and delays in a digital circuit based on its netlist and libraries. This analysis helps identify timing violations and ensures that the design meets its performance specifications.

(2) Hierarchical Analysis: OpenSTA can analyze designs with hierarchical structures, allowing it to handle large and complex designs with multiple levels of hierarchy.

(3) Liberty File Support: OpenSTA uses Liberty (.lib) files, which contain information about the delay characteristics of standard cells in a technology library. These files are essential for accurately modeling the delays in the design during analysis.

(4) Path Analysis: OpenSTA identifies critical timing paths in the design and calculates their worst-case delay. This helps designers focus their optimization efforts on paths that are most likely to cause timing violations.

(5) Setup and Hold Checks: OpenSTA performs setup and hold time checks, ensuring that signals arrive at their destination flip-flops within a specified time window.

(6) Clock Skew Analysis: OpenSTA can analyze clock skew, which is the difference in arrival times of the clock signal at different flip-flops. Skew analysis is critical for synchronous designs to maintain proper synchronization.

**Steps to install OPENSTA**

Prior to the installation of the OpenSTA install the dependencies using the command shown below :
```
sudo apt-get install cmake clang gcc tcl swig bison flex 
```
**After installing the dependencies use the following command to install OpenSTA:**
```
git clone https://github.com/The-OpenROAD-Project/OpenSTA.git
cd OpenSTA
mkdir build
cd build
cmake ..
make
sudo make install
```
![Screenshot from 2023-08-02 10-51-11](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/fbd58818-1234-4e36-8611-29a0509f6864)
Installed OpenSTA
</details>


<details>
    <summary>MAGIC</summary>

**Key Features of MAGIC:**

(1) Layout Editing: MAGIC provides a comprehensive environment for creating and editing mask layouts for integrated circuits. It allows users to design individual cells, full custom layouts, and more complex chip designs.

(2) Hierarchical Layout: MAGIC supports hierarchical design, enabling designers to create complex designs composed of multiple reusable cells and blocks.

(3) Grid-Based Editing: MAGIC employs a grid-based editing system that simplifies the alignment of components and connections, ensuring proper design alignment and manufacturability.

(4) Design Rule Checking (DRC): MAGIC includes basic design rule-checking capabilities to help identify potential layout violations, ensuring that the design adheres to the foundry's design rules.

(5) Layer-Based Approach: MAGIC works with multiple layers that represent different aspects of the layout, such as metal layers, diffusion layers, and more. This layer-based approach allows designers to work with complex process technologies.

**Steps to install MAGIC**
```
sudo apt-get install m4
sudo apt-get install tcsh
sudo apt-get install csh
sudo apt-get install libx11-dev
sudo apt-get install tcl-dev tk-dev
sudo apt-get install libcairo2-dev
sudo apapt-gett-get install mesa-common-dev libglu1-mesa-dev
sudo apt-get install libncurses-dev
git clone https://github.com/RTimothyEdwards/magic
cd magic
./configure
make
sudo make install
```
![Screenshot from 2023-08-02 11-00-19](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9cd6d438-6b91-423d-af2e-0b2301dc4941)
    MAGIC Installed
</details>

<details>
    <summary>OPENLANE</summary>

**Key Features of OPENLANE:**

(1) Floorplanning and Placement: OpenLANE performs floorplanning and placement, determining the physical locations of various logic blocks on the chip.

(2) Clock Tree Synthesis: OpenLANE generates clock distribution networks to ensure proper clocking across the chip.

(3) Routing: OpenLANE handles the routing of interconnects between logic blocks, ensuring proper signal connectivity and adhering to design rules.

(4) Design Rule Checking (DRC): OpenLANE performs DRC to identify violations of the manufacturing process's design rules.

(5) Timing Analysis: OpenLANE includes static timing analysis to ensure that the design meets timing requirements.

(6) Power Analysis: OpenLANE provides power estimation and analysis tools to assess the power consumption of the design.

* Prior to the installation of the OpenLane install the dependencies and packages using the command shown below : 
```
sudo apt-get update
sudo apt-gEDA Tool Integration: OpenLANE integrates various open-source Electronic Design Automation (EDA) tools, such as Yosys for synthesis and OpenROAD for place and route.

IP Integration: OpenLANE supports the integration of intellectual property (IP) blocks, allowing designers to incorporate pre-designed modules into their chips.

Hierarchical Design: OpenLANE supports hierarchical design methodologies, enabling the creation of complex chips composed of reusable sub-blocks.

Scripting and Customization: OpenLANE allows users to customize various aspects of the design flow using Tcl scripting, facilitating automation and the application of custom design strategies.

Regular Standard Cell Libraries: OpenLANE typically uses regular standard cell libraries, which are designed to facilitate easier placement and routing.

OpenROAD Integration: OpenLANE collaborates with the OpenROAD project, which focuses on a complete RTL-to-GDSII design flow using various open-source tools.

Community and Development: OpenLANE is actively maintained by a community of developers and users who contribute to its development, documentation, and support.

In summary, OpenLANE is a powerful open-source tool that streamlines the process of designing digital integrated circuits from RTL descriptions to GDSII layouts. Its automation capabilities, integration with various EDA tools, and community support make it a valuable choice for digital design projects.

et upgrade
sudo apt install -y build-essential python3 python3-venv python3-pip make git
```

* Docker Installation :
```
sudo apt install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg

echo "deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

sudo apt update
sudo apt install docker-ce docker-ce-cli containerd.io
sudo docker run hello-world

sudo groupadd docker
sudo usermod -aG docker $USER
sudo reboot 
```
* Check for installation
```
sudo docker run hello-world
```
* Steps to install OpenLane, PDKs and Tools
```
cd $HOME
git clone https://github.com/The-OpenROAD-Project/OpenLane
cd OpenLane
make
make test
```
![image](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/076d9dc4-2553-4dcf-8b43-6bfed56a86df)
OPENLANE installed
</details>
    
<details>
    <summary>REFERENCES</summary>

(1) https://yosyshq.net/yosys/

(2) https://steveicarus.github.io/iverilog/

(3) https://gtkwave.sourceforge.net/

(4) https://ngspice.sourceforge.io/

(5) https://github.com/The-OpenROAD-Project/OpenSTA/

(6) http://opencircuitdesign.com/magic/

(7) https://github.com/The-OpenROAD-Project/OpenLane/

</details>

</details>
</details>
</details>

## DAY 1


<details>

<summary>DAY-1</summary>
<br>

	
<details>
<summary>IVerilog and GTKWave </summary>

**-->Introduction to open source simulator Iverilog**

* RTL Design checked for adherence to the spec by simulating the design, Here we use the simulation tools for simulating the Design as Iverilog

**Design:**

* Design is actual Verilog code or set of Verilog code which has the intended functionality to meet with required specification

**TestBench:**

* TestBench is the setup to apply simulation(test_vectors) to the design to check its functionality.

**How Simulator Works:**

* Simulator looks for changes in the input signals.
* Upon change to the input the output is evaluated.
* If no change to the input, no change to the output!
  
**Important Point**
* Simulator is looking for changes in the values of input!

![Screenshot from 2023-08-12 10-57-20](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/81b9df2e-b4c1-46ba-bded-43181cedb7c0)

**NOTE**
* Design may have one or more primary inputs and one or more primary outputs.
* TestBench doesn't have a Primary input or Primary outputs.

**Iverilog Based Simulation Flow:**

![Screenshot from 2023-08-09 11-04-08](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/43742cda-2eb7-47d8-9cdc-daac26f3ac1f)

</details>


 
<details>
 <summary> Introduction to LAB 1</summary>
 Open the terminal from VLSI Directory created on the desktop and git clone the library from the link by following the steps:

![Screenshot from 2023-08-12 12-32-19](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ab5c525f-432e-4aec-99ad-2097670cbfa7)

Following is the link to the GitHub repository used for git clone in Ubuntu:
```
	#git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git
```
 type the following command to view all directories and enter the directory:

  ```
         #ls
         #cd @directory name
```
![Screenshot from 2023-08-12 12-45-48](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7a98cdd8-271b-4184-bb07-1dbbdb839ebb)

* Directory named sky130RTLDesignAndSynthesisWorkshop contains an inside directory named verilog files that has all the standard cells with main .v files and tb_.v files inside it, as shown in the above screenshot.

</details>

<details>
 <summary> Introduction to IVerilog and GTKWave part1</summary>

* Open the directory verilog files in the terminal of sky130RTLDesignAndSynthesisWorkshop
* Use the file good_mux.v and tb_good_mux.v in IVerilog which has one to one correspondence
* Then a.out file is created and it will dump the tb_good_mux.vcd file
* Open tb_good_mux.vcd file in GTKWave 
* Observe the output in GTKWave

**Command Written in Ubuntu**
```
#cd verilog_files
#iverilog good_mux.v tb_good_mux.v
#./a.out
#gtkwave tb_good_mux.vcd
```
![Screenshot from 2023-08-12 13-14-20](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/37d11677-9821-4d19-b75d-133ae8803816)

**Observing GTKWave Functionality**

![Screenshot from 2023-08-12 13-17-24](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cf6e946c-7ff3-4cff-b072-b0d6bb92975e)

* We can observe the waveform after dragging and dropping all input and output on Time
* Click to zoom fit because the simulator is showing the waveform at a very small scale
* By selecting + & - we can zoom in and out respectively after selecting the waveform
* This icon > and < trace the forward transition and backward transition respectively of the waveform after selecting a particular waveform  

</details>

<details>
 <summary> Simulation: IVerilog and GTKWave Part2 </summary>

* Below is gvim steps image and verilog testbench and code:

```
gvim tb_good_mux.v -o good_mux.v
```

![Screenshot from 2023-08-09 12-41-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/648dc393-2030-4945-bfcd-82db6cbe692a)

* By the above step we have obtained the main verilog code and testbench code of good_mux.v and tb_good_mux.v file
* And it can be observed as below:

  ![Screenshot from 2023-08-12 17-42-08](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/deacf04d-4c43-4282-a51a-cd9553721293)

  ![Screenshot from 2023-08-12 17-42-50](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9a8b28fc-17e6-4158-9704-a3c5275aebaa)


* There are multiples ways to write verilog code
* Note that Testbench doesn't have primary input and primary output
* Here Initialize input there the stimulus is given to the system
* #300 is the delay after which the output will be obtained and changeable according to our need
* Command always #75 sel=~sel here the select line will toggle after every 75 sec delay
* Here, there is no stimulus in the tb file; we are dumping the vcd file and observing output in GTKWave

 
</details>

<details>
<summary>Introduction to Yosys & Logic Synthesis</summary>

 **Overview Of Yosys Synthesizer:**
* Tool used for converting RTL to Netlist AND Yosys is the synthesizer used here
* **NOTE:** The Netlist is the representation of this design in the form of Standard Cells present in .lib file

**Yosys Synthesizer:**
![Screenshot from 2023-08-12 21-39-39](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c9b89be4-01e8-4156-8dee-c5615b8eb4a4)

**How to Verify the Synthesis:** 
* Solution: We run the Netlist and Testbench in iVerilog and get output .vcd file and the generated output must be the same as that observed in RTL Simulation.
And also, the Testbench is the same used here as that of RTL Design Testbench.

![Screenshot from 2023-08-12 21-44-33](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e96392b7-79ea-4a00-8c3e-45617461275f)

</details>


<details>
<summary>Introduction to  Logic Synthesis Part1</summary>

**Logic Synthesis:**

* RTL To GATE level translation is called Synthesis 
* The design is converted into gates and the connection is made between the gates
* This is given out as a file called netlist

![Screenshot from 2023-08-09 17-51-26](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/795ca21c-a5bb-4dcc-82bd-78a4d85d150b)

**What is .lib**
* It's the collection of logical modules or standard cells
* It includes AND, OR, NOT many other standard cells with a different flavor in their speed operation and Different inputs terminal
* Example:
*  2 Input NAND with slow NAND, Medium NAND, Fast NAND
*  3 Input NAND with slow NAND, Medium NAND, Fast NAND
* While we can execute any Boolean Expression by NAND and NOR Universal gate that are also available.

![Screenshot from 2023-08-13 11-47-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d4da883b-268a-4058-a3b7-47d3c149ff51)


**Why different Flavours of GATE**

![Screenshot from 2023-08-13 11-29-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f73685a9-1af8-4f96-8a19-ef06559ccb73)

* Combinational delay in logic path determines the maximum speed of operation of digital logic circuits
* Tclk > Tcq_A+ Tcomb + Tsetup_B
* Tcq_A: propagation delay of Flop A
* Tcombi: propagation delay of Combinational circuit
* Tsetup_B: before the clock arrives at Flop B, the time duration to avail the data earlier to input of Flop_B
* The Tclk must be such that data from DFF A to DFF B reaches in one clock cycle
* fclk max =1/Tclk min
* So, the clock Time must be less as possible to make fmax high; we need Cell that works fast to make Tclk small as possible
* Then, Are Faster cells Sufficient?

</details>


<details>
<summary>Introduction to  Logic Synthesis Part2</summary>

**Why we need slow cells?**

![Screenshot from 2023-08-13 12-37-43](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cc19a38e-f162-408f-a5e7-34a1def76de3)

* In the clock waveform, Flip flop B must capture the clock after one cycle completion of clock A or it must capture after a minimum delay after clock of A starts,for reliable collection of data at the input of DFF_B, which can be understood by waveform above
* Here, we want clock to work fast but it should not be ultrafast otherwise data will be missed at DFF_B
* So, the system must be optimally Fast
* To ensure that there are no "HOLD" issue at DFF_B, we need cells that work slowly!!!
* Hence,we need cells that work fast to meet the required performance and we also need cells that work slow to meet HOLD
* This collection is formed by .lib

**Faster Cells vs Slower Cells**

* Load in digital circuits is capacitance
* Faster the charging/discharging of capacitance then there is lesser cell delay
* To charge/discharge the capacitance fast, we need transistors capable of sourcing more currentthat is Wide Transistor
* Wider Transistor gives Low Delay consequently leads to more Area, more Current and more Power
* Narrow Transistor gives More Delay consequently leads to less Area, less Current and less Power
* **NOTE:** Faster cell do not come free, they come at penalty of more Area and more Power

**Selection of Cells:**

* We need to guide the Synthesizer to select the flovour of cells that is optimum for the implementation of logic circuit
* More use of faster cells: make bad circuits in terms of Area and Power and also HOLD TIme Violation
* More use of slower cells: make sluggish circuit which may not meet the performance
* **NOTE:** The guidance offered to the Synthesizer to pick correct set of cells is called as "Constraints"

**Synthesis(Illustration):**

![Screenshot from 2023-08-13 12-28-50](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/198065bb-a632-4c8a-9d59-af34d48a22c6)
* The circuit on the right is created from RTL using the Gates available in the .lib and given out as Netlist

</details>

<details>
<summary>Yosys1 good mux part1</summary>

**Invoke the Yosys:**
* Following code is been written for getting graphical version of Logic 
* Firstly open terminals from verilog files in sky130RTLDesignAndSynthesisWorkshop and follow the code:

```
# ls
# yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog good_mux.v
yosys> synth -top good_mux
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```

* Here abc_liberty .. command convert RTL file to gate & which gate it has to link here is of good mux.v
* ABC Result into Input signal: 3 & output signal: 1
* yosys>show  command will allow us to see graphical version of logic which is realize
  
* The screenshot synthesis of the above code can be observe below:
  
  ![1 Screenshot from 2023-08-13 15-35-29](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/583f5e64-686b-45bd-8b9f-94ec2326f167)

![2 Screenshot from 2023-08-13 16-56-46](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/85761ef9-f945-4210-8e15-94431728e00d)

![3 Screenshot from 2023-08-13 16-57-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/fd9df2fb-c470-4b51-9194-479963fdcc92)

 ![4 Screenshot from 2023-08-13 17-04-35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/74256570-4177-4738-8e2d-bf833512ac7a)
 
![5 Screenshot from 2023-08-13 17-14-05](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c7e88283-bde2-4a1e-a2e2-cd48086f0fa1)

 ![6 Screenshot from 2023-08-13 17-13-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9203cb29-c3ed-427b-90b7-26e6c6e6ed6b)

</details>



<details>
<summary>Yosys1 good mux part2</summary>

* The synthesis graphical waveform is shown below:

  ![7 Screenshot from 2023-08-13 17-14-45](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ad183dab-9df6-4aad-b944-5ce9b75f4a1d)

* It's simple 2x1 mux as seen in the figure


* The Graph obtain in Kunal sir waveform is as follow:

![Screenshot from 2023-08-13 18-12-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/5756aaac-ba3d-4c0d-b69f-b755ae9fa7d1)

* The Understanding of the logical circuit is given below:

  ![WhatsApp Image 2023-08-13 at 6 25 42 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6d3f6af3-3f80-47c9-8d52-32622b0a7f48)

* Hence, 2x1 good mux is been synthesized using Yosys

 </details>


 
<details>
<summary>Yosys1 good mux part3</summary>
	
**How to write a Netlist:**

* Continuation to above Lab code in ubuntu
* Commands are as follows:
  
```
yosys> write_verilog -noattr good_mux_netlist.v
yosys> !gvim good_mux_netlist.v
```
* We obtain here simplified Netlist over here as shown below:
  
  ![Screenshot from 2023-08-14 10-30-04](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e16d5f95-565d-45cd-8a3e-07bdb64aad9e)

* Here, the wire is i0 is assign with _0_ and i1 assign by _1_ similarly for sel line as _2_
* A1 is instantiated by _1_ ; similarly  S is instantiated by _2_
* Output is obtained by X(_3_)

* The Kunal sir Netlist is shown below:

  ![Screenshot from 2023-08-14 10-44-45](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d151cdc6-976f-4a30-ab46-a95b45e8439f)

* Here, the select line is assigned _2_ which is wire _2_ in module; and instantiated in nand2.1 by .B(_2_) and also instantiated by 021ai-0 by .A1(_2_)
* Similarly i0 is assigned as _0_ and instantiated by variable in (_0_); and same goes for i1
  
 </details>

 
<details>
 <summary>Summary</summary>

* This section shows how we simulated and synthesized a good mux using iVerilog. GTKWave is the tool used to plot the simulation results of any design. And Understand briefly about Yosys and Logic Synthesis; also how we can deal with different types of gates. Finally synthesized good mux with the Yosys tool with a simulation circuit and its Netlist.

</details>

</details>


</details>



## DAY 2


<details>

<summary>DAY-2</summary>
<br>

	
<details>
<summary>Introduction to timing.libs:</summary>

<details>
<summary>Introduction to Dot Lib Part1</summary>

* Open Terminal in Verilog files and type the following commands to view the gvim file:
```
 $ gvim ../lib/sky130_fd_dc_hd__tt_025C_1v80.lib
open vim  and type there  :syn off
```
![Screenshot from 2023-08-14 11-40-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3ba25cf5-2b35-482a-8ee3-197dac1fa56b)

* Here in gvim,  library (sky130_fd_sc_hd__tt_025C_1v80) has a meaning attached to it
* There are three parameters very important over here is P-Process, V- Voltage, T- Temperature
* Process variation due to fabrication like every time building 100% accurate design as that of previous is not possible
* There would be a change in voltage across the globe
* And Semiconductor is very sensitive to changes in Temperature
* The CD Player is selling in  Switzerland, Dubai, India there will be a lot of change in Temperature across each place and it should operate completely fine across all places
* Hence, a change in any of 3 parameters of P V T silicon design must work perfectly same at all
  
</details>

<details>
<summary>Introduction to Dot Lib Part2</summary>

**Units in VIM File:**

* Units of Time, Voltage, Power, Current, Capacitance 
* Operating conditions tells what is tt typical process then 025c temperature and 1v80 voltage
   
  ![Screenshot from 2023-08-14 14-40-44](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ef3e360d-2178-4211-8aef-b3a92a9346d6)

* In gvim type the below command for detailed info on standard cells like Power, Delay Timing, etc
* a2110 : 2-input AND into the first input of 4-input OR
```
 :sp ../my_lib/verilog_model/sky130_fd_sc_hd_a2110.behavioral.v
```
 ![Screenshot from 2023-08-14 15-11-46](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/fa056b04-6f66-4c0e-8617-abfe8279091d)

</details>


<details>
<summary>Introduction to Dot Lib Part3</summary>

**Comparing 2 input 3 AND Gates:**

* Vim command used here is as follow to search for AND gate
  
```
:sp ../my_lib/verilog_model/sky130_fd_sc_hd__and2.behavioral.v
```

![Screenshot from 2023-08-14 15-54-49](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4225546a-100f-4899-a35b-b1cf310a4040)

* Following things can be observed from the above comparison:

  ![WhatsApp Image 2023-08-14 at 4 05 16 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/12bf89cb-2ba1-4974-b943-0c549547bd71)


  
</details>

</details>

<details>
<summary>Hierarchical vs Flat Synthesis</summary>
	
<details>
<summary>Hier Synthesis Flat synthesis part1</summary>

![WhatsApp Image 2023-08-14 at 5 25 03 PM (1)](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/16fcaf9c-2c4e-4fef-9ed2-e44ef26b05db)

**Steps followed to synthesize multiple modules:**
```
$ gvim multiple_modules.v
$ yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog good_mux.v
yosys> synth -top good_mux
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show multiple_modules
yosys> write_verilog -noattr multiple_modules_hier.v
yosys> !gvim multiple_modules_hier.v
```
* The output synthesis is as follows:
  
![Screenshot from 2023-08-14 17-39-25](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/126f2b7b-8323-42e1-bfe6-ef118be9c878)

* The generated the Netlist of above design is as follows:
  
![Screenshot from 2023-08-14 18-03-43](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/abe87e33-25a9-4f43-91fa-efb0f7e068c2)
![Screenshot from 2023-08-14 18-04-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/149eb479-d2c0-4546-bfd1-90fd0957088d)

* Here, Firstly u1 and u2 Sub Module are generated and Instantiated both modules
* And u1 Sub Module is a AND gate; u2 Sub Module is OR gate but U2 is generated as Bubbled NAND= OR but not as NOR+NOT
* Because NOR+NOT results in stacked PMOS which is BAD; the reason behind this is the poor Mobility of PMOS & to improve it requires wide cells to get good logical effort

</details>
<details>
<summary>Hier Synthesis Flat synthesis part2</summary>


 
</details>
</details>
</details>

