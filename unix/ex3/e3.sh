#!/bin/bash
PATH=.

filename=$1

contents=$(<$filename)

pairs=()

for ((i = 0; i < ${#contents}; i++)); do
    char="${contents:$i:1}"

    if [[ $i != 0 ]] && [[ $(($i + 1)) != ${#contents} ]]; then
        if [[ $char == "}" ]] || [[ $char == "{" ]]; then
            echo "nested json not supported without jq usage :))"
            exit 1
        fi
    fi

    if [[ $char == "\"" ]]; then
        key=""
        ((i++))
        char="${contents:$i:1}"
        nextChar="${contents:$(($i + 1)):1}"

        while [[ $char != "\"" ]]; do
            if [[ $char == "\\" ]]; then
                key+="$nextChar"
                ((i++))
            else
                key+="$char"
            fi

            ((i++))
            char="${contents:$i:1}"
            nextChar="${contents:$(($i + 1)):1}"
        done

        pairs+=("$key")
        continue
    fi

    if [[ $char == "[" ]]; then
        key=""
        ((i++))
        char="${contents:$i:1}"
        nextChar="${contents:$(($i + 1)):1}"

        while [[ $char != "]" ]]; do
            if [[ $char == "\\" ]]; then
                key+="$nextChar"
                ((i++))
            else
                key+="$char"
            fi

            ((i++))
            char="${contents:$i:1}"
            nextChar="${contents:$(($i + 1)):1}"
        done

        pairs+=("$key")
        continue
    fi
done

keyOrData=$2

for ((i = 1; i < ${#pairs[@]}; i += 2)); do
    key="${pairs[$((i - 1))]}"
    value="${pairs[$i]}"

    if [[ $keyOrData == $key ]] || [[ $keyOrData == $value ]] || [[ -z $keyOrData ]]; then
        echo "$key: $value"
    fi

done
