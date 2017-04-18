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
    len=${#name}
    if [ $len -le 9 ] ; then 
	    $print DBG "typed:$name, len:$len"
	    echo -ne "\x0$len$name" | hexdump -C
	    echo -ne "\x0$len$name" | nc 127.0.0.1 7000
	else
		$print ERR "To long, max char count is 9"
	fi
done


