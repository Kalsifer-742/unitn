#!/usr/bin/env bash

i=$(($#-1))
arr=($@)

while [[ $i -ge 0 ]]; do
	echo ${arr[$i]}; 
	(( i-- ))
done
