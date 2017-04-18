#!/bin/bash

COLORS=~/bin/color.sh
if [ -e $COLORS ] ; then
    source $COLORS
    print=print
else
    print=echo
fi

name="start"
while [ "$name" != "quit" ] ; 
do
    read -p "input>" name
    $print DBG "typed:$name"
    echo $name | nc 127.0.0.1 7000
done


