[](url) Physical Design of ASICs


## DAY 0
<details>
<summary>DAY-0</summary>
<br>


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

(4) Design Rule Checking (DRC): MAGIC includes basic design rule checking capabilities to help identify potential layout violations, ensuring that the design adheres to the foundry's design rules.

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



  ## DAY 1
<summary>DAY-1</summary>
<br>

<details>
<summary>IVerilog and GTKWave </summary>

**Summary:**

This section shows how I simulated and synthesized a 2x1 mux using iverilog and yosys respectively. iverilog generates from the RTL design and its testbench a value changing dump file (vcd). gtkwave is the tool used to plot the simulation results of the design. Yosys is a tool which synthesizes RTL designs into a netlist. It is also used to test the synthesized netlist when we provide it with a testbench.


*Introduction to open source simulator IVerilog Flowchat* 
![Screenshot from 2023-08-09 11-04-08](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/43742cda-2eb7-47d8-9cdc-daac26f3ac1f)

	
<details>
 <summary> Library Installation of Verilog Files</summary>
![Screenshot from 2023-08-09 11-01-24](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/e883bed6-4b73-466f-a520-4406c484e1a2)
</details>

<details>
 <summary> Verilog Codes</summary>
    
The verilog codes of the 2x1 mux (good_mux.v) and its testbench (tb_good_mux.v) are taken from https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git




<details>
 <summary> Simulation: iverilog and gtkwave </summary>
 
 I used the following commands to simulate and view the plots of the RTL design:
 Firstly open terminal from Verilog Files directory from sky130RTLDesignAndSynthesisWorkshop and then 
	
 ```
 iverilog <name verilog: good_mux.v> <name testbench: tb_good_mux.v>
 ./a.out
 gtkwave tb_good_mux.vcd
 ```
![Screenshot from 2023-08-09 12-14-32](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/77c2cad0-1fc4-4560-bdcc-b5c68aaf6e78)

	
 Below is the screenshot of the gtkwave plots:
 
![Screenshot from 2023-08-09 12-16-00](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/995d38f6-f006-423c-add8-30e866be19df)

Below is gvim steps image and verilog testbench and code:
![Screenshot from 2023-08-09 12-41-13](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/648dc393-2030-4945-bfcd-82db6cbe692a)
![Screenshot from 2023-08-09 12-40-33](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/9072bbd4-f6a3-4cb7-9f39-53aefbb46768)


 </details>





</details>


