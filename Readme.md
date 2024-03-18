# WVMC-Server

> ***<mark>Warning</mark>:*** *Feature incomplete and work in progress! Use at your own risk!*

### <u>What is the WVMC?</u>

The Windows-Virtual-Machine-Communicator *(short WVMC)* is a Toolset for sending pre-defined commands from a qemu-based 
Windows-VM to a Linux Host. It consists of a Guest-side Client and a Host-side Server which communicate via a virtual Serial-port.

Link to the [Client Repository](https://github.com/Solek798/WVMC-Client).

### <u>How will the WVMC-Server operate?</u>

> *As mentioned above this is still work in progress. So I will describe how I plan it to work when it's done.*

The WVMC-Server defines how many commands exist and what they do. It is started with the machine on startup and immediately
connects to the socket that represents the virtual serial-port.

> *Name and location of all files will be hard-coded to begin with, but I plan to make this a proper daemon-process
> with config-file at some point.*

> *Note that the WVMC as a whole needs a virtual serial-port defined in the vm.xml to operate.*


The Server will wait for the Client to send a start message and then send the number of available commands. The commands 
are defined in a JSON file and only the Server knows which number belongs to which command. When the client sends a 
message with a command number it will execute the associated command via system call.

When the guest shuts down the client will send a stop message which causes the server to disconnect and shutdown as well.

### <u>Missing Features</u>

- [ ] Listening to Client 'Start' and 'Stop' message
- [ ] Ability to execute system commands
- [ ] Configurability of commands via JSON file
- [ ] Configurability of file locations and names via .conf file
- [ ] Ability to run as background daemon-process

___

### <u>How to build</u>

This project is developed with cmake version 3.27.8

``` 
cmake <path to project>
make <path to project>
```
