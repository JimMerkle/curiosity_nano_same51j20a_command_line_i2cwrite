# i2cwrite - SAM E51 I2C Write Project

Based on the command_line project for SAM E51 Curiosity Nano.

## Development Board
SAM E51 CURIOSITY NANO
![Curiosity Nano (SAM E51)](CuriosityNanoBoard.jpg)

### KIT-INFO.TXT
```
Debugger firmware:     01.1F.0027 (hex)
Kit name:              SAM E51 Curiosity Nano                                      
Kit USB serial number: MCHP3360023000003716
Device:                ATSAME51J20A                    
Drag and drop:         No 
```
### Evaluation Board Details
```
Part Number: EV76S68A
https://www.microchip.com/en-us/development-tool/ev76s68a

ARM® Cortex®-M4 processor - ATSAME51J20A
One user LED (yellow), active low,  PA14 (pin 31)
One user switch, active low,        PA15 (pin 32)
32,768Hz crystal                    PA00 XIN32, PA01 XOUT32
On-board debugger
Board identification in MPLAB X IDE
One power/status LED (green)
Virtual COM port (CDC)
One logic analyzer (DGI GPIO)
USB powered
Adjustable target voltage
MIC5353 LDO regulator controlled by the on-board debugger
1.8-3.6v output voltage
500 mA maximum output current (limited by ambient temperature and output voltage)
```
## Build Environment
```
MPLAB X IDE v6.25
Microchip XC32 Compiler v4.60
```

### SERCOM5 - Serial/CDC Port - Prewired for USB Serial Communication
```
SERCOM5 TX - PAD0 - PB16 (pin 39)
SERCOM5 RX - PAD1 - PB17 (pin 40)
```
![Configuration](SERCOM5_Configuration.jpg)
![Pins](SERCOM5_Pins.jpg)

### System Diagram
![System Diagram](System_Diagram.jpg)
```
TC0 - 32-bit counter, incrementing every 1us  - Optional, supports microsecond timing
```

### Directory Structure
```
 The build environment for Printf consists of the command_line repository cloned into a
 folder structure as follows:
    
+-- command_line
|   +-- command_line.X                        | mplab X project directory
|   +-- src                                   | source directory
|       +-- main.c                            | application
|       +-- config                            | mcc generated configuration
|       +-- packs                             | processor CMSIS and peripheral
|       +-- logger.c                          | implements printf() functionality, writing to SERCOM TX FIFO
|       +-- logger.h                          | int log_msg(const char *fmt, ...);
|       +-- command_line.c                    | implements the interactive Command Line functionality
|       +-- command_line.h                    | function prototypes
|       +-- version.h                         | version string definition
|   +-- README.md                             | This Readme.md file
|   +-- CuriosityNanoBoard.jpg                | Curiosity Nano picture
|   +-- System_Diagram.jpg                    | MHC "Project Graph" - system diagram
|   +-- SERCOM5_Configuration.jpg             | SERCOM5 configuration screenshot from MHC
|   +-- SERCOM5_Pins.jpg                      | SERCOM5 pinout screenshot from MHC
```

### What is this repository for?
```
SAM E5x/D5x (curiosity nano development board)
Demonstrate creating a Command Line project
```
   
### Help - Getting Started
```
https://www.microchip.com/en-us/tools-resources/configure/mplab-harmony
https://developerhelp.microchip.com/xwiki/bin/view/software-tools/harmony/archive/same54-getting-started-training-module/

```

### YouTube Videos
```
https://www.youtube.com/watch?v=wZlUVmyrH54

```

### Version History
```
00.05.11 - Add "cls" command to clear terminal screen. Add text_in_box() function.
```