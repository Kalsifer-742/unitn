#!/bin/bash +x
#oppure -x ?

mode=$1;
path=$2;

make
./app $mode $path