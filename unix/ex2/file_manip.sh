#!/bin/bash

# File Manipulation: Write a shell script that takes a filename as an argument and checks if the file exists. If it does, print out its contents; if not, create the file.

filename=$1

if [ -a $filename ]; then
    cat $filename
else
    touch $filename
fi
