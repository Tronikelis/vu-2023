#!/bin/bash

# Process Management: Create a script that lists all running processes, prompts the user for a process ID, and then kills that process.

filename=$1

withTime="$(basename $filename)_$(date +%s)"

cp $filename $withTime
