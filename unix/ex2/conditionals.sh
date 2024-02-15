#!/bin/bash

# Conditionals: Create a script that takes a number as input and checks if it's even or odd, then prints the result.

number=$1

if [ $(($number % 2)) == 0 ]; then
    echo "Even"
else
    echo "Odd"
fi
