#!/bin/bash


valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         $*

cat valgrind-out.txt | grep "All heap blocks were freed"
cat valgrind-out.txt | grep "definitely lost:"
