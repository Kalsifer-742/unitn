#!/bin/bash

(( i = 0 ))
cat $1 | while read line; do
    if [ $((i%2)) -eq 0 ]; then
        echo "$line"
    else
        1>&2 echo "$line"
    fi

    (( i++ ))
done