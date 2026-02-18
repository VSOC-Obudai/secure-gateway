# Automotive CAN Bus Security Gateway Firmware

Bare-metal security gateway firmware for the Infineon AURIX TC37x (TriCore) microcontroller, targeting real-time CAN bus monitoring in automotive environments.

The firmware runs across three TriCore CPU cores with synchronized startup via hardware events. Core 0 owns the application loop, while cores 1 and 2 are reserved for future parallel workloads. The CAN subsystem implements interrupt-driven TX/RX pipelines using FIFO queuing, hardware message filtering with configurable ID range acceptance, and ISR-safe spinlock synchronization for cross-core serial output. Four distinct interrupt priorities handle message transmission, reception, loss detection, and protocol error classification independently — each mapped to a dedicated interrupt line and CPU0 service.

Serial I/O is implemented over ASCLIN at 115200 baud with direct register-level TX control for deterministic character output, bypassing the standard FIFO path to ensure log visibility during early initialization. The build system uses CMake with Ninja and a custom tricore-elf-gcc toolchain file, supporting Debug, Profile, and Release presets. Firmware deployment is done via AurixFlasher from the generated Intel HEX output.

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
3. Setup in your PuTTY: Connection type: Serial, Speed: 115200

### Documentation

Hardware specification and documentation is available at docs folder.
