#!/bin/bash
PATH=.

traverse() {
    path="$1"
    searchPattern="$2"

    for i in "$path"/*; do
        if [[ -d "$i" ]]; then
            traverse "$i" "$searchPattern"
        elif [[ -f "$i" ]] && [[ "$i" == *"$searchPattern"* ]]; then
            readarray contents <$i

            echo -e "${contents[0]}\n${contents[1]}"
            echo "!!: $i"
            echo ""
        fi
    done
}

traverse "$1" "$2"
