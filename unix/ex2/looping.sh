#!/bin/bash

# Looping: Write a script that generates a multiplication table for a given number, up to a specified range, using loops

targetNum=$1

upTo=$2

for ((i = 1; i < $upTo; i++)); do
    echo "$i * $targetNum = $((i * $targetNum))"
done
