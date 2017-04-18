#!/bin/bash

# my dirs
BUILD_DIR=$PWD/bin
BIN=palindrome
if [ ! -e $BUILD_DIR/$BIN ] ; then
    echo "No binary: $BUILD_DIR/$BIN"
    exit 1
fi
pushd $BUILD_DIR


read -r -d '' CMD <<- EOM
    $BUILD_DIR/$BIN \
    -i 127.0.0.1:7000 \
    -o 127.0.0.1:5555 \
    -m 127.0.0.1:5001 \
    --ponythreads 4 \
    --ponypinasio \
    --ponynoblock \
    -c 127.0.0.1:12500 \
    -d 127.0.0.1:12501
EOM

echo $CMD
#exit 1

$CMD;



#reset

