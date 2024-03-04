#!/bin/bash
PATH=.

contents=$(<$1)
len=${#contents}

nth=1

if [[ ! -z $2 ]]; then
    nth=$2
fi

for ((i = 0; i < $len; i += $nth)); do
    curr="${contents:$i:1}"
    prev="${contents:$((i - 1)):1}"

    if [[ $i == 0 ]]; then
        el="${contents:1:$len}"
        contents="${curr^}${el,,}"
        continue
    fi

    if [[ $prev == " " ]]; then
        el="${contents:$((i + 1)):$len}"
        contents="${contents:0:$i}${curr^}${el,,}"
    fi
done

str=""

for ((i = $len; i >= 0; i--)); do
    str+="${contents:$i:1}"
done

echo "$str"
