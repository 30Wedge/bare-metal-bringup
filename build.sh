#!/bin/bash

msp430-gcc -mmcu=msp430g2452 -g -std=c99 -o blinky.elf main.c

