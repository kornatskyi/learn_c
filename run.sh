#!/bin/bash

filename=$1

gcc -g -Wall -Wextra -Wpedantic $filename


if [ $? -eq 0 ]; then
  ./a.out
else 
  echo "Compilation failed!"
fi