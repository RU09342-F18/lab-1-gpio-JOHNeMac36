# Lab 1: Blink an LED and you can control the world!
## 3 LED Blinking programs for MSP430x processors

### Author
John McAvoy

### Last Updated
19 Sep 2018

### Programs

#### Simple Blink
Blinks an LED on and off. [demo](./demos/simple_blink.gif)

##### Pinouts

|Processor   |LED+|
|------------|----|
|MSP430G2553 |P1.0|
|MSP430FR2311|P1.0|
|MSP430F5529 |P6.0|

[schematic](./schematics/simple_blink.png)

#### Multiple Blink
Blinks 3 LEDs on and off at different frequencies. [demo](./demos/multiple_blink_demo.gif)

[off-board demo](./demos/off_board_blink.gif)

##### Pinouts

|Processor   |LED0+|LED1+|LED2+|
|------------|-----|-----|-----|
|MSP430G2553 |P1.0 |P1.1 |P1.2 |
|MSP430FR2311|P1.0 |P1.1 |P1.2 |
|MSP430F5529 |P6.0 |P6.1 |P6.2 |

[schematic](./schematics/multiple_blink.png)

#### Button Blink
Controls an LED using a button input. [demo](./demos/button_blink.gif)

##### Pinouts

|Processor   |LED+|BTN_out|
|------------|----|-------|
|MSP430G2553 |P1.0|P1.1   |
|MSP430FR2311|P1.0|P1.1   |
|MSP430F5529 |P6.0|P6.1   |

[schematic](./schematics/button_blink.png)

### Building

`$ cd <project_directory>/<msp430xxx>`

(example: `$ cd "Simple Blink/msp430g2553/`)

Compile processor-specific binary

`$ make`

### Running
After building, upload `bin/msp430xxx_<project_name>.elf` to your processor.

Optionally, if [mspdebug](https://github.com/dlbeer/mspdebug) is installed, you can run
`$ make run`
to automatically upload the binary to your processor.
