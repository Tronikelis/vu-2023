#!/bin/bash
PATH=.

filename=$1

contents=$(<$filename)

IFS=$'\n'

index=0

get_col_count() {
    local IFS=$' '

    local line=$1
    local cols=()

    for c in $line; do
        cols+=($c)
    done

    local count=${#cols[@]}

    for i in ${!cols[@]}; do
        # echo $i

        # if cols[i] starts with "
        # and if cols[i + 1] ends with "
        # count - 1

        curr=${cols[$i]}
        next=${cols[$(($i + 1))]}

        if [[ ${curr:0:1} == '"' ]] && [[ ${next:(-1)} == '"' ]]; then
            count=$(($count - 1))
        fi
    done

    return $count
}

column_count=0
row_count=0
row_item_count=0

for line in $contents; do
    row_count=$(($row_count + 1))
done

row_count=$(($row_count - 1))
echo "Row count: $row_count"

for line in $contents; do
    get_col_count $line
    count=$?

    if [[ $index == 0 ]]; then
        echo "Column count: $count"
        column_count=$count
    else
        if [[ $count != $column_count ]]; then
            echo "Items in a row do not match column count"
        else
            row_item_count=$(($row_item_count + $count))
        fi
    fi

    index=$(($index + 1))
done

echo "Row item count: $row_item_count"
