#!/bin/bash

# User Input Validation: Create a script that prompts the user for a username and validates if it meets certain criteria (e.g., length, contains only alphanumeric characters).

echo "username:"

read username

if [[ $(echo $username | wc --chars) -le 8 ]]; then
    echo "username must contain 8 char"
    exit 1
fi

if [[ $username =~ [^a-zA-Z0-9] ]]; then
    echo "username contains non alphanumeric chars"
    exit 1
fi
