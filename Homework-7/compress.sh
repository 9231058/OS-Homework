#!/bin/bash
HW_NO=7

rm os_assigment$[HW_NO]_group20.tgz
tar cvfz os_assigment$[HW_NO]_group20.tgz main.c fifo.h Makefile note.txt
