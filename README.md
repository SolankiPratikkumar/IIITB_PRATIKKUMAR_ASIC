[](url) Physical Design of ASICs

<details>
<summary>DAY-0</summary>
<br>

## CLASS 1
<details>
<summary>Yosys</summary>
    YoSys Installation

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
Icarus Verilog Installation

**Steps to install Icarus Verilog**
```
sudo apt-get install iverilog
```
![Screenshot from 2023-08-01 23-08-24](https://github.com/SolankiPratikkumar/IIITB_PRATIKKUMAR_ASIC/assets/140999250/83636fdd-673d-4c39-bace-eb66ece762d2)
iverilog installed
</details>


<details>
    <summary>GTKWave</summary>
GTKWave Installation

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
NGSPICE Installation


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
OPENSTA Installation
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
    MAGIC Installation
    
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
    OPENLANE Installation

Prior to the installation of the OpenLane install the dependencies and packages using the command shown below :
```
sudo apt-get update
sudo apt-get upgrade
sudo apt install -y build-essential python3 python3-venv python3-pip make git
```

Docker Installation :
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
# Check for installation
```
sudo docker run hello-world
```
# Steps to install OpenLane, PDKs and Tools
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
