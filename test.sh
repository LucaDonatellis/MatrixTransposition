#!/bin/bash

PROGRAM=$1

for P in {4..12}; do
    N=$((2**P))
    echo "Executing $PROGRAM with n = $N"
    ./$PROGRAM $N
done