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


#LIBNAME=_PYAPI.so
#c++ \
#    -O0 -mcx16 \
#    -o lib/$LIBNAME \
#    -fPIC \
#    -fpermissive \
#    -g3 \
#    -ggdb \
#    -O0 \
#    -march=native \
#    -mcx16 \
#    -shared \
#    -lpython2.7 \
#    -lpthread \
#    -ldl \
#    -lutil \
#    -lm \
#    -std=c++11 \
#    -DDEBUG \
#    -I. \
#    -I/usr/local/include/WallarooCppApi \
#    -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions -std=c++11 -DDEBUG \
#    $WALL_LIB_PATH/libwallaroo.a \
#    $PONY_LIB_PATH/lib/libponyrt-pic.a \
#    ./CMakeFiles/_PYAPI.dir/src/main.cpp.o \
#    ./CMakeFiles/_PYAPI.dir/src/PyModule.cpp.o \
#    ./CMakeFiles/_PYAPI.dir/src/PyApplication.cpp.o \
#    ./CMakeFiles/_PYAPI.dir/libpyapiPYTHON_wrap.cxx.o \
#    -Wl,--whole-archive $WALL_LIB_PATH/libwallaroo.a -Wl,--no-whole-archive \
#    -Wl,--whole-archive ./lib/src.o -Wl,--no-whole-archive \
#    -Wl,-Bstatic -L $WALL_LIB_PATH -lwallaroo -Wl,-Bdynamic \
#    -Wl,--start-group -lwallaroo -lstdc++ -lrt -Wl,--end-group -lpthread -ldl -lm -lpython2.7 -lstdc++ -lponyrt-pic -lssl
#if [ $? -gt 0 ] ; then
#    $print ERR "DID NOT COMPILE $LIBNAME CORRECTLY"
#    exit 1
#else
#    $print INF "LIBRARY finished: $LIBNAME"
#fi

#
# create link
#
#if [ ! -e ./bin/_PYAPI.so ] ; then
#    pushd bin >> /dev/null 2>&1
#    ln -s ../lib/_PYAPI.so
#    popd >> /dev/null 2>&1
#    $print INF "Linked $LIBNAME"
#fi



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
