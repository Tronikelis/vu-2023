#!/bin/bash
PATH=.

filename=$1
contents=$(<$filename)

word=""
words=()
word_count=()

calc_word_stats() {
    local word=$1
    declare -A count=()

    for ((i = 0; i < ${#word}; i++)); do
        local char=${word:$i:1}
        local curr_count=${count[$char]}

        if [[ -z $curr_count ]]; then
            count[$char]=0
            continue
        fi

        count[$char]=$(($curr_count + 1))
    done
}

calc_sentence_word_stats() {
    local words=$1

    for word in $words; do
        calc_word_stats $word
    done
}

for ((i = 0; i < ${#contents}; i++)); do
    char=${contents:$i:1}

    if [[ $char == "." ]] || [[ $char == "?" ]] || [[ $char == "!" ]]; then
        calc_sentence_word_stats $words
        words=()
        word=""
        break
    fi

    if [[ $char != " " ]]; then
        word+=$char
    else
        words+=($word)
        word=""
    fi
done
