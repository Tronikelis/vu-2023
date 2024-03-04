#!/bin/bash
PATH=.

filename=$1

contents=$(<$filename)

pairs=()

i=0

getChar() {
    echo "${contents:$i:1}"
}

getNextChar() {
    echo "${contents:$(($i + 1)):1}"
}

expression=""

parseExpression() {
    char="$(getChar)"
    nextChar="$(getNextChar)"

    expression=""

    while [[ $char != "\"" ]]; do
        if [[ $char == "\\" ]]; then
            expression+="$nextChar"
            ((i++))
        else
            expression+="$char"
        fi

        ((i++))

        char="$(getChar)"
        nextChar="$(getNextChar)"
    done
}

eatWhitespace() {
    while [[ "$(getChar)" == " " || "$(getChar)" == "\n" || "$(getChar)" == "\t" || "$(getChar)" == "," || $(getChar) == ":" ]]; do
        ((i++))
    done
}

for (( ; i < ${#contents}; i++)); do
    eatWhitespace
    char="$(getChar)"

    if [[ $char == "\"" ]]; then
        ((i++))
        parseExpression
        pairs+=("$expression")
    fi

    if [[ $char == "[" ]]; then
        ((i++))

        combined=""

        while [[ "$(getChar)" != "]" ]]; do
            eatWhitespace
            parseExpression

            if [[ ! -z $expression ]]; then
                combined+="::$expression"
            fi

            ((i++))
        done

        pairs+=("$combined")
    fi
done

keyOrData=$2

for ((i = 1; i < ${#pairs[@]}; i += 2)); do
    key="${pairs[$((i - 1))]}"
    value="${pairs[$i]}"

    if [[ "$keyOrData" == "$key" ]] || [[ "$value" == *"$keyOrData"* ]] || [[ -z $keyOrData ]]; then
        echo "$key: $value"
    fi
done
