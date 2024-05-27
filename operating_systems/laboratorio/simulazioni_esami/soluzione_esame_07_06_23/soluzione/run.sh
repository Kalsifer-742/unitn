#!/bin/bash

if [[ $# -lt 10 ]]; then
    echo "troppe poche parole"
elif [[ $# -gt 10 ]]; then
    echo "troppe parole"
else
    parole=($@)
    scambio=true
    while $scambio; do
        scambio=false
        for ((i = 0 ; i < ${#parole[@]}-1 ; i++)); do
            if [[ ${parole[$i]} -gt ${parole[$i+1]} ]]; then
                tmp=${parole[$i]}
                parole[$i]=${parole[$i+1]}
                parole[$i+1]=$tmp
                scambio=true
            fi
        done
    done
    for i in ${!parole[@]}; do
        echo ${parole[$i]}
    done
fi

