# Real-Time vehicle message monitoring

### Prerequisites

#### AURIX Development Studio & GCC Compiler

Ensure you have AURIX Development Studio available (we need compiler toolsets from it): [Here](https://www.infineon.com/design-resources/platforms/aurix-software-tools/aurix-tools/aurix-development-studio)

Add compiler toolsets to your PATH environment variable. I added these:
- C:\Infineon\AURIX-Studio-1.10.2\tools\Compilers\tricore-gcc11\bin
- C:\Infineon\AURIX-Studio-1.10.2\tools\make
- C:\Infineon\AURIX-Studio-1.10.2\tools\AurixFlasherSoftwareTool_v1.0.8
- C:\Infineon\AURIX-Studio-1.10.2\tools\Compilers\Tasking_1.1r8\ctc\bin
- C:\Infineon\AURIX-Studio-1.10.2\tools\Compilers\sdcc_421\bin

#### CMake & Ninja (better C++ experience)

(On Windows) Make sure you have the following paths in your PATH environment variable
- C:\Users<Your-Local-User>\AppData\Local\Programs\Python\Python312\Scripts\
- C:\Users\<Your-Local-User>\AppData\Roaming\Python\Python312\Scripts
- C:\Users\<Your-Local-User>\AppData\Local\Programs\Python\Python312\

You need CMake and Ninja. You can install those with Python.
```
$ pip3 install cmake ninja
```
### Compile & Build

You can view available presets like this.
```
$ cmake --list-presets
```

You can execute the whole build pipeline (workflow) like this:
```
$ cmake --workflow --preset tricore-debug
```

Or, you can run each stage individually. Normally a CMake stage consist of
1. configure: analyze the project and environment & produce native build files  `cmake -S . -B build`
2. build: compile & link targets `cmake --build build`
3. test: execute & verify unit tests `ctest --test-dir build --output-on-failure`
4. package: deploy outputs `cmake --install build --prefix /opt/my_project`

In this case, test and packaging was not implemented on purpose.

Why? CMake doesn't have flash implemented in the workflow (it is not a standard procedure), which would have required manual twiggling and scripting. It was not worth it... You can do this later on, if you want.

1. Configuration (generates platform-agnostic build files)
```
$ cmake --preset tricore-debug
```

2. Build
```
$ cmake --build --preset tricore-debug
```

### How to Flash

Compile the project and navigate to bin folder.
$ cd <project-root>/build/<preset>/bin

```
$ AurixFlasher -hex ./aurix-sec-gtw-http-server.hex
```

### Terminal (View UART logs)

1. Install PuTTY
2. Check the name of your COM serial line in device manager (usually COM4)
3. Setup in your PuTTY: Connection type: Serial, Speed: 9600 (for stability)

### Documentation

Hardware specification and documentation is available at docs folder.
