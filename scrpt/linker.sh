#!/bin/bash

COLORSCRPT=$PWD/../scrpt/color.sh
if [ -e $COLORSCRPT ] ; then
    source $COLORSCRPT
    print=print
else
    echo "Can't find colors, just using echo"
    print=echo    
fi


#
# remove old lib
#
LINK=./lib/_PYAPI.so
if [ -e $LINK ] ; then 
    rm $LINK
fi


#
# remove link
#
LINK=./bin/_PYAPI.so
if [ -e $LINK ] ; then 
    rm $LINK
fi


#
# make sure pony is installed
#
PONY_LIB_PATH=`pkg-config --variable=libdir ponyc`
if [ "$PONY_LIB_PATH" == "" ] ; then
    $print ERR "Cannot find location for PONYC"
    exit 1
fi



#
# make sure WallarooCppApi is installed
#
WALL_LIB_PATH=`pkg-config --variable=libdir wallaroocppapi`
if [ "$WALL_LIB_PATH" == "" ] ; then
    $print ERR "Cannot find location for WallarooCppApi"
    exit 1
fi




PYTHON_FLAGS=`python-config --cflags --ldflags`
PONYC_FLAGS=`pkg-config --libs ponyc`
BIN=palindrome
/usr/bin/c++    \
    -std=c++11 \
    -g \
    -g \
    -O0 \
    -fPIC \
    CMakeFiles/palindrome.dir/src/PalindromeIO.cpp.o \
    CMakeFiles/palindrome.dir/src/Palindrome.cpp.o \
    CMakeFiles/palindrome.dir/src/main.cpp.o \
    -o \
    bin/$BIN \
    ./lib/src.o \
    $PYTHON_FLAGS \
    $PONYC_FLAGS \
    -ldl \
    -lpthread \
    -lwallaroo -L$WALL_LIB_PATH
    
    


if [ -e $PWD/../src/WallarooHooks.py ] ; then 
	cp $PWD/../src/WallarooHooks.py ./bin/
fi
