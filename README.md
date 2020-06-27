# freertos-qemu
Using qemu to run freertos on cortex-m3



## Build:
    git clone https://github.com/mghicho/freertos-qemu
    cd freertos-qemu
    git submodule init
    git submodule update --recursiv
    cd CORTEX_LM3S811_GCC
    make


## Run

    qemu-system-arm -M lm3s811evb -nographic -kernel gcc/RTOSDemo.bin

use Ctrl-A+X to exit.
