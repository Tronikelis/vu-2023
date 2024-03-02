#!/bin/bash
PATH=.

filename=$1
contents=$(<$filename)

calc_word_stats() {
    local word=$@
    declare -A count=()

    local i=0
    for ((i = 0; i < ${#word}; i++)); do
        declare -l char=${word:$i:1}

        if [[ ! -v count[$char] ]]; then
            count[$char]=1
            continue
        fi

        local curr_count=${count[$char]}
        count[$char]=$(($curr_count + 1))
    done

    echo $word
    local to_print=""

    local i
    for ((i = 0; i < ${#word}; i++)); do
        local char=${word:$i:1}
        to_print+="${count[$char]},"
    done

    echo $to_print

    return 0
}

calc_sentence_word_stats() {
    local words=("$@")

    local word
    for word in "${words[@]}"; do
        calc_word_stats $word
    done

    return 0
}

word=""
words=()

for ((i = 0; i < ${#contents}; i++)); do
    char=${contents:$i:1}

    if [[ $char != " " ]] &&
        [[ $char != "." ]] &&
        [[ $char != "?" ]] &&
        [[ $char != "!" ]]; then
        word+=$char
    else
        words+=($word)
        word=""
    fi

    if [[ $char == "." ]] ||
        [[ $char == "?" ]] ||
        [[ $char == "?" ]] ||
        [[ $(($i + 1)) == ${#contents} ]]; then
        words+=($word)
        calc_sentence_word_stats "${words[@]}"

        word=""
        words=()

        continue
    fi

done
