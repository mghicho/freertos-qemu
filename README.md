# freertos-qemu
Using qemu to run freertos on cortex-m3


## Build:

 make


## Run

qemu-system-arm -M lm3s811evb -nographic -kernel gcc/RTOSDemo.bin

use Ctrl-A+X to exit.
