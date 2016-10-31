#!/bin/bash 

export KERNEL=kernel.bin
qemu-system-i386 -kernel  "$KERNEL"

