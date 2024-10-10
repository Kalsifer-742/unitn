#!/bin/bash -x

read_and_print_file() {
    (( i = 0 ))
    cat $1 | while read line; do
        echo "$line"
        (( i++ ))
    done
}

target=$1; #non ci possono essre spazi perchè boh
n=$2;

if [[ -e $target ]]; then
    rm $target
fi

make
./program $target $n
read_and_print_file $target
if [[ $# -eq 4 ]]; then
    cat $target > $4
fi