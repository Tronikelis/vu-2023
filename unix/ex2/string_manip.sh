#!/bin/bash

echo "Please enter a string: "

read string

chars=$(echo $string | wc --chars)

# -1 because newline? or \0 someshit like that?
echo $(($chars - 1))
