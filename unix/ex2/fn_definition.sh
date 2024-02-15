#!/bin/bash

# Function Definition: Define a function that calculates the factorial of a given number and call it from your script.

target=$1

factorial() {
    number=$1
    output=1

    for ((i = 0; i < $number; i++)); do
        ((output *= (($i + 1))))
    done

    # return only meant for 0-255 exit codes
    echo $output
}

echo $(factorial $target)
