#!/bin/bash

# Directory Navigation: Create a shell script that navigates to a specified directory and lists all files and directories within it.

dir=$1

lsout=$(cd $dir && ls)

echo $lsout
