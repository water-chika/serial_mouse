# Arduino Serial Mouse

The project is a demo that emulate some input devices by Arduino.

## Emulated Devices

1. sunmouse
2. stinger

## Build & Program

Use below command to get board fqbn and port.
```
arduino-cli board list
```

Compile source code and upload it to the board:
```
arduino-cli compile --fqbn <board fqbn>
arduino-cli upload --fqbn <board fqbn> --port <board port>
```

## Usage

Connect A0,A1 with x and y axis, also connect 5V and GND pins.

```
inputattach --sunmouse <board port>
```

or if stinger device is emulated:

```
inputattach --stinger <board port>
```

## Reference

1. linux/driver/input/mouse/sermouse.c
2. linuxconsoletools
