# Arduino Serial Mouse

The project is a demo that emulate a serial mouse by Arduino.


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

```
inputattach --sunmouse <board port>
```

## Reference

1. linux/driver/input/mouse/sermouse.c
2. linuxconsoletools
