#!/bin/bash



red=$(tput setaf 1)
blue=$(tput setaf 4)
yellow=$(tput setaf 3)
normal=$(tput sgr0)

function print()
{
    lvl=$(echo $1 | tr a-z A-Z)
    color=""
    level=""
    if [ "$lvl" == "DBG" ] ; then
	color=$blue
	level="DBG"
    elif [ "$lvl" == "INF" ] ; then
	color=$yellow
	level="INF"
    elif [ "$lvl" == "ERR" ] ; then
	color=$red
	level="ERR"
    else
	color=$normal
	level="NRM"
    fi
    shift
    dt=$(date "+%H:%M:%S")
    printf '%s\n' $color$dt"-"$level" - $*"$normal
}
