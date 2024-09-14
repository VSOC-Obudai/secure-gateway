# Aurix Sec GTW HTTP Server Example (Alternative Take)

### Prerequisites

You need CMake and Ninja. You can install those with Python.
```
$ pip3 install cmake ninja
```
Make sure you have the following paths in your PATH environment variable
C:\Users<Your-Local-User>\AppData\Local\Programs\Python\Python312\Scripts\
C:\Users\<Your-Local-User>\AppData\Roaming\Python\Python312\Scripts
C:\Users\<Your-Local-User>\AppData\Local\Programs\Python\Python312\

Ensure you have AURIX Development Studio available (we need compiler toolsets from it)

Add compiler toolsets to your PATH environment variable.
I added these:
C:\Infineon\AURIX-Studio-1.10.2\tools\Compilers\tricore-gcc11\bin
C:\Infineon\AURIX-Studio-1.10.2\tools\make
C:\Infineon\AURIX-Studio-1.10.2\tools\AurixFlasherSoftwareTool_v1.0.8
C:\Infineon\AURIX-Studio-1.10.2\tools\Compilers\Tasking_1.1r8\ctc\bin
C:\Infineon\AURIX-Studio-1.10.2\tools\Compilers\sdcc_421\bin

### Building

You can execute each stage like this

1. configuration
```
$ cmake --preset tricore-debug
```

2. build
```
$ cmake --build --preset tricore-debug
```

Or alternatively, you can execute the whole workflow like this:
```
$ cmake --workflow --preset tricore-debug
```

### Flashing

You can flash simply from console. Step in your bin path after building:
$ cd <project-root>/build/<preset>/bin

```
$ AurixFlasher -hex ./aurix-sec-gtw-http-server.hex
```

### Serial Communication

1. Install PuTTY
2. Check the name of your COM serial line in device manager (usually COM4)
3. Setup in your PuTTY: Connection type: Serial, Speed: 9600
