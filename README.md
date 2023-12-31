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
yosys> read_verilog multiple_modules.v
yosys> synth -top multiple_modules
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
	
**Step followed for Flat Synthesis:**

```
$ yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog multiple_modules.v
yosys> synth -top multiple_modules
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr multiple_modules_hier.v
yosys> !gvim multiple_modules_hier.v
yosys> flatten
yosys> write_verilog -noattr multiple_modules_flat.v
yosys> !gvim multiple_modules_flat.v
inside Netlist type for other hier module
:vsp multiple_modules_hier.v
yosys> show
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> synth -top sub_module1
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```

* Here, the flatten command remove the submodule and make the direct connection in the Netlist
* 2nd Netlist we directly see the instantiation of AND gate and OR gate we don't see u1 and u2 submodule anymore
* By using show Firstly we see here flatten multiple module layout
* And secondly time using show command we synthesize submodule1,so we see submodule1 last time

**Comparing both Netlist:**

![Screenshot from 2023-08-15 15-58-18](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9bf9bdaf-2ead-4452-bf07-4938812f942b)

**Viewing Synthesis of flatten multiple module**

![Screenshot from 2023-08-15 16-12-19](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/abdf111d-b109-46dc-9ac2-e6871e87fdb2)

**Viewing Synthesis of submodule1**

![Screenshot from 2023-08-15 16-01-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9d025b56-ce82-4c47-8415-4e8067d8bf6d)

</details>
</details>

<details>
<summary>Various Flop Coding style and Simulation</summary>

**Why to use Flop:**

![1aflopWhatsApp Image 2023-08-15 at 5 23 49 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/53967184-e01d-423a-9f30-b84a0f8eb5d1)

![1b WhatsApp Image 2023-08-15 at 5 23 50 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f7791b70-a7b8-4052-8ade-ce68808c73bb)

**Different Types of Flop Synthesis:**

![Screenshot from 2023-08-15 17-16-14](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/401de78c-b73c-4135-be97-2aef6de099bd)


![2aWhatsApp Image 2023-08-15 at 5 23 50 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/944a2e19-a8de-49ec-b157-26806f42682a)

![2bWhatsApp Image 2023-08-15 at 5 23 50 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/07700076-5034-4264-92dc-bad3d04b20af)

**Waveform Analysis by IVerilog and GTKWave**

* Steps for synthesize of  Asynchronous reset D FlipFlop which is dff_asyncres.v

```
$ iverilog dff_asyncres.v tb_dff_asyncres.v
$ ./a.out
$ gtkwave tb_dff_asyncres.vcd
```

![Screenshot from 2023-08-15 18-47-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e82466e9-8955-4930-9031-2b6b4eb6fdf7)

![Screenshot from 2023-08-15 18-46-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/52facee6-685e-447e-a9ed-dfb2137634dd)


* Steps for synthesis of Asynchronous Set D FlipFlop which is dff_async_set.v

```
$ iverilog dff_async_set.v tb_dff_async_set.v
$ ./a.out
$ gtkwave ./tb_dff_async_set.vcd
 ```


![Screenshot from 2023-08-15 18-52-49](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cc375ef4-88ae-411c-8594-b2c014ad93f6)


![Screenshot from 2023-08-15 18-52-16](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/869a713f-3f12-4fba-b49f-cc19fded9852)


* Steps for synthesis of Synchronous Reset D FlipFlop which is dff_syncres.v in GTKWave

```
$ iverilog dff_syncres.v tb_dff_syncres.v
$ ./a.out
$ gtkwave ./tb_dff_syncres.vcd
```

![Screenshot from 2023-08-15 18-54-44](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3b341256-c6b3-451c-bae8-7c842c6c8d70)

![Screenshot from 2023-08-15 18-56-34](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a2ae5e75-1ffa-477a-bae2-0973b938659f)

**Layout of D FlipFlop Synthesis by Yosys**

* Steps for synthesis of ASynchronous Reset D FlipFlop which is dff_asyncres.v in Yosys

  ```
  $yosys
   yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> read_verilog dff_asyncres.v
   yosys> synth -top dff_asyncres
   yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> show
  ```

  ![Screenshot from 2023-08-15 19-32-35](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/40e63612-3cb7-44fe-95de-f27e8dab1f6f)

* Steps for synthesis of ASynchronous Set D FlipFlop which is dff_async_set.v in Yosys

  ```
  $yosys
   yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> read_verilog dff_async_set.v
   yosys> synth -top dff_async_set
   yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> show
  ```

![Screenshot from 2023-08-15 19-48-40](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a2e177d0-2a13-4a24-8985-f8ddd46a5855)

 * Steps for synthesis of Synchronous Reset D FlipFlop which is dff_syncres.v in Yosys

  ```
  $yosys
   yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> read_verilog dff_syncres.v
   yosys> synth -top dff_syncres
   yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
   yosys> show
  ```
  
  ![Screenshot from 2023-08-15 19-53-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7f868ff3-a2ca-433b-b4ea-4648ec648a4f)


**Interesting Optimisation Part1**

![2laWhatsApp Image 2023-08-15 at 10 13 19 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1f7ad944-1836-451b-be99-eccce06ecd05)

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog mult_2.v
yosys> synth -top mul2
yosys> show
yosys> write_verilog -noattr mul2_net.v
yosys> !gvim mul2_net.v
```


![Screenshot from 2023-08-15 22-20-00](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/64701c9c-840f-4ef0-92b5-bc5bfecb17f7)

![Screenshot from 2023-08-15 21-33-53](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4c0e7bfd-5f3f-464f-89af-f94d49be0241)

![Screenshot from 2023-08-15 21-39-27](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ad8d5a93-8f36-40d9-bac7-8f432f58700b)

![Screenshot from 2023-08-15 22-24-40](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/29ace6e2-b850-49e6-a305-a90c9463b063)


**Interesting Optimisation Part2**

![2lbWhatsApp Image 2023-08-15 at 10 14 38 PM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/dd341eee-c55f-40b2-a666-d040d63fa7b0)

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog mult_8.v
yosys> synth -top mult8
yosys> show
yosys> write_verilog -noattr mult8_net.v
yosys> !gvim mult8_net.v
```

![Screenshot from 2023-08-15 22-43-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f7be9db8-41c5-4df0-917d-1e4272f9fe0f)

![Screenshot from 2023-08-15 22-45-00](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4578affa-5d78-463b-a733-6228a588916c)


</details>
</details>


## DAY 3
<details>
<summary>DAY-3</summary>
<br>

<details>
<summary>Introduction to Optimisation</summary>

**Combinational Logic Optimisation:**

![3a WhatsApp Image 2023-08-16 at 12 12 58 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/75cdf6b4-5981-449d-89a5-9440ed37141a)

**With MOS Transistor:**

![3cWhatsApp Image 2023-08-16 at 12 14 14 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/74afc925-e28e-4037-bbe6-289b71b3ce95)


**Boolean Logic Optimisation:**

![3bWhatsApp Image 2023-08-16 at 12 13 44 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b4d5b435-3bc3-40e9-9ca5-0967baeb47e5)

**Sequential Logic Optimisation:**

* Sequential Constant:

  ![3dWhatsApp Image 2023-08-16 at 12 14 45 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/acd5ab4a-0bbc-41bc-bf10-439c01722af3)

* Sequential Non-Constant:

![3eWhatsApp Image 2023-08-16 at 12 15 47 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d8e556b7-f806-41b3-851c-c223e4e34680)

**State Optimisation and Cloning**

![3fWhatsApp Image 2023-08-16 at 12 16 23 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/87fa84fa-bc42-425f-a18e-5e62acee10cb)

**Retiming:**

![3gWhatsApp Image 2023-08-16 at 12 16 52 AM](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/72da6a13-73fe-4970-90ae-f417ffefca23)

* Performance of circuit is increased to 250MHz with Slack and Delay balancing

</details>
  
<details>
<summary> Combination Logic Optimisation</summary>


<details>
<summary>optcheck_1</summary>
	
* Following steps has been executed for output synthesis of optcheck_1.v

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog opt_check.v
yosys> synth -top opt_check
yosys> opt_clean -purge
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```


  ![Screenshot from 2023-08-16 00-38-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/bf9dff37-357f-480e-a04b-7829b8fb43ab)

</details>

<details>
<summary>optcheck_2</summary>
	
* Following steps has been executed for output synthesis of optcheck_2.v
  
```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog opt_check2.v
yosys> synth -top opt_check2
yosys> opt_clean -purge
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```

![Screenshot from 2023-08-16 00-55-29](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7eaa514e-bfaf-44f0-9d5d-324a9d87a051)

</details>

<details>
<summary>optcheck_3</summary>
			   
* Following steps has been executed for output synthesis of optcheck_3.v

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog opt_check3.v
yosys> synth -top opt_check3
yosys> opt_clean -purge
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```

![Screenshot from 2023-08-16 01-01-26](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/55f71b37-8db0-4b39-915e-b5fc66775567)

</details>

<details>
<summary>optcheck_4</summary>
	
* Following steps has been executed for output synthesis of optcheck_4.v

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog opt_check4.v
yosys> synth -top opt_check4
yosys> opt_clean -purge
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```

![Screenshot from 2023-08-16 01-04-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4fc56872-6cff-4d14-8471-a8d3d7bfebbe)

</details>
</details>

<details>
<summary> Sequential Logic Optimisation</summary>
	
<details>
<summary>dff_const1</summary>

* Iverilog and GTKWave Simulation:

* Steps to follow in Verilog Files Terminal:
```
iverilog dff_const1.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const1.vdc
```

  ![Screenshot from 2023-08-16 01-30-28](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9ccfb601-94b4-4af3-a68f-9ca09c899f51)

* Yosys Synthesis:
  
* Steps to follow in Verilog Files Terminal:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog dff_const1.v
yosys> synth -top dff_const1
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
```

![Screenshot from 2023-08-16 01-47-46](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2a73eb7c-bcaa-4356-88f9-04fccbd66527)

</details>


<details>
<summary>dff_const2</summary>

* Iverilog and GTKWave Simulation:

* Steps to follow in Verilog Files Terminal:
  
```
iverilog dff_const2.v tb_dff_const2.v
./a.out
gtkwave tb_dff_const2.vdc
```

![Screenshot from 2023-08-16 02-24-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cb39dd6a-087c-4257-a888-bbd94a051a5a)

  
* Yosys Synthesis:

* Steps to follow in Verilog Files Terminal

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog dff_const2.v
yosys> synth -top dff_const2
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
``` 

![Screenshot from 2023-08-16 02-30-43](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d6e0f9a2-40d6-417a-82e4-1227e9166d0c)

</details>


<details>
<summary>dff_const3</summary>


* Iverilog and GTKWave Simulation:

* Steps to follow in Verilog Files Terminal:
  
```
iverilog dff_const3.v tb_dff_const3.v
./a.out
gtkwave tb_dff_const3.vdc
```

![Screenshot from 2023-08-16 02-24-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cb39dd6a-087c-4257-a888-bbd94a051a5a)

  
* Yosys Synthesis:

* Steps to follow in Verilog Files Terminal

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog dff_const3.v
yosys> synth -top dff_const3
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
``` 

![Screenshot from 2023-08-16 02-36-03](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9018b9a9-3d2b-4470-9e0a-5b17d847536a)

</details>


<details>
<summary>dff_const4</summary>


* Iverilog and GTKWave Simulation:

* Steps to follow in Verilog Files Terminal:
  
```
iverilog dff_const4.v tb_dff_const4.v
./a.out
gtkwave tb_dff_const4.vdc
```

![Screenshot from 2023-08-16 02-38-59](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/681864bc-f048-4d2e-af4c-1f85bcdd7db8)


  
* Yosys Synthesis:

* Steps to follow in Verilog Files Terminal

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog dff_const4.v
yosys> synth -top dff_const4
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
``` 

![Screenshot from 2023-08-16 02-41-30](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e5ebab2a-4a0f-4072-b499-5e894d5b3b60)

</details>

<details>
<summary>dff_const5</summary>


* Iverilog and GTKWave Simulation:

* Steps to follow in Verilog Files Terminal:
  
```
iverilog dff_const5.v tb_dff_const5.v
./a.out
gtkwave tb_dff_const5.vdc
```

![Screenshot from 2023-08-16 02-43-48](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/fb1db17e-4b23-4913-a5b5-99558b34ff16)

  
* Yosys Synthesis:

* Steps to follow in Verilog Files Terminal

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog dff_const5.v
yosys> synth -top dff_const5
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
``` 

![Screenshot from 2023-08-16 02-46-40](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9950d2d2-9607-482b-b9d3-744b352fd4bc)

![Screenshot from 2023-08-16 02-46-55](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2be0ff31-aae6-4fd2-aca5-a3a0791fb64f)

</details>

<details>
<summary>counter_opt</summary>

* Iverilog and GTKWave Simulation:

* Steps to follow in Verilog Files Terminal:
  
```
iverilog counter_opt.v tb_counter_opt.v
./a.out
gtkwave tb_counter_opt.vdc
```

![Screenshot from 2023-08-16 02-43-48](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/fb1db17e-4b23-4913-a5b5-99558b34ff16)

  
* Yosys Synthesis:

* Steps to follow in Verilog Files Terminal

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog counter_opt.v
yosys> synth -top counter_opt
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
``` 

![Screenshot from 2023-08-16 02-55-17](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4ad2e89a-b65b-496a-b7d4-b1d9695fff16)

![Screenshot from 2023-08-16 02-55-37](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/13eb23a6-8dec-4acb-81c4-eadf2b22001f)

</details>

<details>
<summary>counter_opt2</summary>

  
* Yosys Synthesis:

* Steps to follow in Verilog Files Terminal

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog counter_opt2.v
yosys> synth -top counter_opt2
yosys> dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> show
``` 

![Screenshot from 2023-08-16 03-05-07](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c2330975-aa20-4a0e-ad58-aad8cd3e7ce1)

</details>
</details>
</details>

## DAY 4
<details>
<summary>DAY-4</summary>
<br>
	
<details>
<summary>GLS, Blocking vs NonBlocking & Synthesis Simulation Mismatch</summary>

 <details>
<summary>GLS Concept and Flow Using Iverilog</summary>

![Screenshot from 2023-08-16 10-39-22](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/61c47866-2ee2-4d5e-94f7-053bc846cffc)

![Screenshot from 2023-08-16 10-40-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/13638fa8-14d6-4112-905d-38aeed46257a)

</details>

<details>
<summary>Synthesis-Simulation Mismatch</summary>

![Screenshot from 2023-08-16 10-58-03](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f6bbadba-113e-4bb8-897b-105d023c5f82)



</details>

<details>
<summary>Blocking and NonBlocking and Caveats</summary>

 ![Screenshot from 2023-08-16 10-59-52](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/761c5a6a-eb09-4486-8804-3515cf044776)

![Screenshot from 2023-08-16 11-22-54](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/dbc06a6b-5f2c-480a-8147-eceb3c448e72)

</details>
</details>
<details>
<summary>Caveats with Blocking Statements</summary>

![Screenshot from 2023-08-16 11-22-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/7606c994-8509-4ab3-9204-b70b4703688f)

![Screenshot from 2023-08-16 11-22-18](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cb6dd33a-98e4-4a21-b4e9-3d488e5bf152)

</details>

<details>
<summary>LABS on GLS, Blocking vs NonBlocking & Synthesis Simulation Mismatch</summary>

 <details>
<summary>Labs on GLS Synthesis-Simulation Mismatch Part1</summary>

* Following command used to see Verilog code of  ternary_operator_mux, bad_mux, good_mux:
  
```
$ gvim ternary_operator_mux.v -o bad_mux.v -o good_mux.v
```

![Screenshot from 2023-08-16 12-27-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6831eca7-2bb7-4d27-a5f1-891f3a380224)

**Ternary Operator Mux Simulation and Synthesis in Iverilog, GTKWave, Yosys, GLS:**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog ternary_operator_mux.v tb_ternary_operator_mux.v
  $./a.out
  $gtkwave tb_ternary_operator_mux.vcd
```

![Screenshot from 2023-08-16 12-37-33](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/346e32a9-36c2-4777-9e58-ece0d788a4c9)

* Steps for synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog ternary_operator_mux.v
yosys> synth -top ternary_operator_mux
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr ternary_operator_mux_net.v
yosys> show
```

![Screenshot from 2023-08-16 12-46-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/11774223-153d-41bb-8c07-d12553085767)

* Below are Command to simulate in GLS:

```
$ iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v ternary_operator_mux_net.v tb_ternary_operator_mux.v
$./a.out
$ gtkwave tb_ternary_operator_mux.vcd
```

![Screenshot from 2023-08-16 13-06-55](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/4b561be5-9d7c-4d23-beb9-4584dd1003d8)
  
</details>

<details>
<summary>Labs on GLS Synthesis-Simulation Mismatch Part2</summary>

**Bad Mux Simulation and Synthesis in Iverilog, GTKWave, Yosys, GLS:**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog bad_mux.v tb_bad_mux.v
  $./a.out
  $gtkwave tb_bad_mux.vcd
```

![Screenshot from 2023-08-16 13-19-06](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/639f9ac1-048b-4b1f-a883-43b067ddd0d0)


* Steps for synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog bad_mux.v
yosys> synth -top bad_mux
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr bad_mux_net.v
yosys> show
```

![Screenshot from 2023-08-16 13-21-36](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e2e2911c-37eb-4ac9-8b46-7588614ce530)


* Below are Command to simulate in GLS:

```
$ iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v bad_mux_net.v tb_bad_mux.v
$./a.out
$ gtkwave tb_bad_mux.vcd
```
![Screenshot from 2023-08-16 13-26-32](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6e37e35b-d646-437f-935e-04699571b492)


**Analysis of Mismatch in GLS Waveform:**

![Screenshot from 2023-08-16 12-16-53](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c3aec598-a1c4-499c-8160-d98e7565d0e3)


  
</details>

<details>
<summary>Mismatch in Blocking Statement</summary>

* Following command used to see Verilog code of blocking_caveat.v :
  
```
$ gvim ternary_operator_mux.v -o bad_mux.v -o good_mux.v
```

![Screenshot from 2023-08-16 15-32-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6d0b97d9-af73-4432-b79e-42f3fbf88878)


**Blocking_caveat Simulation and Synthesis in Iverilog, GTKWave, Yosys, GLS:**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog blocking_caveat.v tb_blocking_caveat.v
  $./a.out
  $gtkwave blocking_caveat.vcd
```

![Screenshot from 2023-08-16 15-36-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/d3a629ee-3983-495a-89c0-d486d50940a3)


* Steps for synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog blocking_caveat.v
yosys> synth -top blocking_caveat
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr blocking_caveat_net.v
yosys> show
```

![Screenshot from 2023-08-16 15-53-28](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/cd92339e-1c46-4ea1-bc52-81ad3ef6e7e5)

* Below are Command to simulate in GLS:

```
$ iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v blocking_caveat_net.v tb_blocking_caveat.v
$./a.out
$ gtkwave tb_blocking_caveat.vcd
```

![Screenshot from 2023-08-16 15-58-31](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/153c5b89-0073-4b7d-8dcb-6acd9363aecf)

**Analysis of Mismatch in GLS Waveform:**

![Screenshot from 2023-08-16 15-02-39](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/29a562ba-b154-47dc-a300-5550e556f1c4)

</details>
</details>
</details>



## DAY 5
<details>
<summary>DAY-5</summary>
<br>
	
<details>
<summary>IF Case Construct</summary>


![5a](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c544102c-9ac4-4da1-80c9-2666c57cc278)

![5b](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/62316e67-1d4f-4dbd-bf31-def65f425343)

![5c](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ae916c7f-a146-41b3-874a-716463dc4f2f)

![5d](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/db0587f5-76d7-4ffa-b0ee-9e02b8108980)

</details>


<details>
<summary>Lab Incomplete IF Case</summary>

**Example1: incomp_if**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog incomp_if.v  tb_incomp_if.v 
  $./a.out
  $gtkwave incomp_if.vcd
```

![Screenshot from 2023-08-16 20-44-38](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1f3b32ae-6d7e-4549-8303-c20063eb5202)

* Steps for Synthesis in Yosys:

```  
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
yosys> read_verilog incomp_if.v 
yosys> synth -top incomp_if
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr incomp_if_net.v
yosys> show
```

![Screenshot from 2023-08-16 20-48-31](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/721d7dcd-0d5a-416d-a8f2-34efc720aa85)


**Example2:  incomp_if2**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog incomp_if2.v  tb_incomp_if2.v 
  $./a.out
  $gtkwave incomp_if2.vcd
```

![Screenshot from 2023-08-16 20-55-09](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/675fc26e-38bc-402e-b9f9-92e89b1b04a1)


* Steps for Synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
yosys> read_verilog incomp_if2.v 
yosys> synth -top incomp_if2
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr incomp_if2_net.v
yosys> show
```

![Screenshot from 2023-08-16 20-57-14](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/be7ef686-b758-4a7e-942e-9d54411cdf25)


</details>



<details>
<summary>Lab on Incomplete overlapping Case</summary>


**Example1: incomp_case**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog incomp_case.v  tb_incomp_case.v 
  $./a.out
  $gtkwave incomp_case.vcd
```
![Screenshot from 2023-08-16 21-16-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/85bbdf69-f617-409e-96f1-02e8747c02c4)


* Steps for Synthesis in Yosys:

```  
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
yosys> read_verilog incomp_case.v 
yosys> synth -top incomp_case
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr incomp_case_net.v
yosys> show
```

![Screenshot from 2023-08-16 21-18-10](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6f85781a-844d-4974-a9bb-e2e0520d1dbd)


![Screenshot from 2023-08-16 21-18-36](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f795eba4-ab56-4b7f-aa02-0b8556bb3826)


**Example2: comp_case**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog comp_case.v  tb_comp_case.v 
  $./a.out
  $gtkwave comp_case.vcd
```

![Screenshot from 2023-08-16 21-27-52](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a64ce227-d94b-4ace-ba1a-49e90508d3dc)


* Steps for Synthesis in Yosys:

```  
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
yosys> read_verilog comp_case.v 
yosys> synth -top comp_case
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr comp_case_net.v
yosys> show
```

![Screenshot from 2023-08-16 21-29-20](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1bbbd582-04ce-4c87-87a7-6540251cd9ec)


![Screenshot from 2023-08-16 21-29-57](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/a5026b7f-2aac-4e69-a462-cbe7f45715a5)


**Example3: partial_case_assign**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog partial_case_assign.v  tb_partial_case_assign.v 
  $./a.out
  $gtkwave partial_case_assign.vcd
```
![gtkwave0773282-771ffa67-f694-409d-9bbe-c25037372d6d](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9d0cf927-1cba-4f90-b9ab-1d86fd1f3eac)

* Steps for Synthesis in Yosys:

```  
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
yosys> read_verilog partial_case_assign.v 
yosys> synth -top partial_case_assign
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr partial_case_assign_net.v
yosys> show
```

![Screenshot from 2023-08-16 21-43-03](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b13d0913-6866-4475-8fd9-fc114f44b182)

![Screenshot from 2023-08-16 21-43-29](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/693207d9-4e25-4904-beb2-ec90892e3ea5)


**Example4: bad_case**

* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog bad_case.v  tb_bad_case.v 
  $./a.out
  $gtkwave bad_case.vcd
```
![Screenshot from 2023-08-16 21-52-55](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f240a338-b306-479b-a9f0-902d74232f85)


* Steps for Synthesis in Yosys:

```  
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
yosys> read_verilog bad_case.v 
yosys> synth -top bad_case
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr bad_case_net.v
yosys> show
```

![Screenshot from 2023-08-16 21-54-16](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b350d8fd-0000-4714-aadd-d035402864ab)

![Screenshot from 2023-08-16 21-54-54](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/823a6b59-6b73-40f3-8021-88017fab3084)

</details>

<details>
<summary>For loop and For generate</summary>

**For Loop:**

* Procedural 'for' loops are runtime evaluated as often as necessary when the procedural block is activated. They can be fully dynamic.
* They must have appeared in a procedural block - thus have more limited use.
* It is used in the "always" block. It is used for evaluating expressions multiple times.
* Syntax is as follows:
  
```
for (<initiaization>, <condition>, <update>)begin
 \\ expression to be evaluated
end
```

**For generate:**

* Generate loops are evaluated at compile / elaboration time. NOT at runtime.
* So the limits of the loop must be fully "known" at elaboration time.
* We are just about unlimited as to what can go inside a generate loop.
* It is used outside the "always" block. It is used for instantiating hardware multiple times.
* Syntax is as follows:
```
genvar k;
generate 
    for (k = 0; k < 4; k++) begin
       \\ statements to be executed
       end
   end
endgenerate
```

</details>

<details>
<summary>Labs on 'For Loop and For Generate'</summary>

**Example1: mux_generate**

* We will here Write Verilog code, Simulation on GTKWave, Synthesis on Yosys, as well we will do a Simulation on GLS:
  
* Verilog Code of mux_generate.v
  
```
gvim mux_generate.v
```

![Screenshot from 2023-08-17 00-27-48](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/b3a1fc05-2426-431f-8045-fa06a80ec499)


* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog mux_generate.v tb_mux_generate.v
  $./a.out
  $gtkwave mux_generate.vcd
```

![Screenshot from 2023-08-17 00-31-04](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/1d5d8bef-64e4-4c55-ad24-dffcad69f499)



* Steps for synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog mux_generate.v
yosys> synth -top mux_generate
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr mux_generate_net.v
yosys> show
```

![Screenshot from 2023-08-17 00-33-15](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/c54ef5c5-07ef-4c3b-8dc6-cd539bcc12dd)

![Screenshot from 2023-08-17 00-33-42](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/3994f53e-8c3a-482c-b3c6-95432d77fefc)

* Below are Command to simulate in GLS:

```
$ iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v mux_generate_net.v tb_mux_generate.v
$./a.out
$ gtkwave tb_mux_generate.vcd
```
![Screenshot from 2023-08-17 00-37-45](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/6120bab8-c7c6-47bf-af9b-4ea2edc49a58)


**Example2: demux_case**

* We will here Write Verilog code, Simulation on GTKWave, Synthesis on Yosys, as well we will do a Simulation on GLS:
  
* Verilog Code of demux_case.v
  
```
gvim demux_case.v -o tb_demux_case.v
```

![Screenshot from 2023-08-17 00-47-58](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/ce889511-1061-4e44-b754-31eeb5808e46)



* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog demux_case.v tb_demux_case.v
  $./a.out
  $gtkwave demux_case.vcd
```

![Screenshot from 2023-08-17 00-52-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/35d3ec5b-039c-4e58-84ce-8d03e0ada5dc)


* Steps for synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog demux_case.v
yosys> synth -top demux_case
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr demux_case_net.v
yosys> show
```

![Screenshot from 2023-08-17 00-55-41](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/98328efe-0913-4d92-bb11-9f2e16d431e9)

![Screenshot from 2023-08-17 00-56-11](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/22026aba-e938-4d03-9ecf-4c2d1af3f520)


* Below are Command to simulate in GLS:

```
$ iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v demux_case_net.v tb_demux_case.v
$./a.out
$ gtkwave tb_demux_case.vcd
```
![Screenshot from 2023-08-17 00-58-15](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/21da462b-26cd-443c-b5ca-853d5282ce9b)


**Example3: demux_generate**

* We will here Write Verilog code, Simulation on GTKWave, Synthesis on Yosys, as well we will do a Simulation on GLS:
  
* Verilog Code of demux_generate.v
  
```
gvim demux_generate.v -o tb_demux_generate.v
```

![Screenshot from 2023-08-17 01-02-09](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2ef8e19d-58cd-4ed6-9b00-b5fb6b29eedd)


* Steps to execute iverilog and GTKWave Simulation are mentioned below:

```
  $iverilog demux_generate.v tb_demux_generate.v
  $./a.out
  $gtkwave demux_generate.vcd
```

![Screenshot from 2023-08-17 01-04-24](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/f12c6541-8fde-4254-83d4-c800c5194272)


* Steps for synthesis in Yosys:

```
$yosys
yosys> read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> read_verilog demux_generate.v
yosys> synth -top demux_generate
yosys> abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
yosys> write_verilog -noattr demux_generate_net.v
yosys> show
```

![Screenshot from 2023-08-17 01-06-01](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9e1f35a7-b446-407c-b3c2-1157aab891f0)

![Screenshot from 2023-08-17 01-07-20](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/2f773edb-4b60-48ec-8a73-28b7b15f0db5)


* Below are Command to simulate in GLS:

```
$ iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v demux_generate_net.v tb_demux_generate.v
$./a.out
$ gtkwave tb_demux_generate.vcd
```

![Screenshot from 2023-08-17 01-10-53](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/73bae9a9-9ba0-422e-9d92-c5f5d9da9a99)

</details>
</details>

## ACKNOWLEDGEMENT
<details>
    <summary>ACKNOWLEDGEMENT</summary>

* Kunal Ghosh, VSD Corp. Pvt. Ltd.
* Nanditha Rao, Professor, IIITB
* Madhav Rao, Professor, IIITB
* Manikandan,Professor,IIITB
* Mariam Rakka
* Skywater Foundry
* Chatgpt
* Pruthvi Parate Collegue, IIITB
* Alwin Shaju Collegue, IIITB
* Shivangi Collegue, IIITB 

</details>

## REFERENCES
<details>
    <summary>REFERENCES</summary>

(1) https://yosyshq.net/yosys/

(2) https://steveicarus.github.io/iverilog/

(3) https://gtkwave.sourceforge.net/

(4) https://ngspice.sourceforge.io/

(5) https://github.com/The-OpenROAD-Project/OpenSTA/

(6) http://opencircuitdesign.com/magic/

(7) https://github.com/The-OpenROAD-Project/OpenLane/

(8) https://www.vsdiat.com/

(9) https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git

</details>
 
</details>
</details>
</details>
