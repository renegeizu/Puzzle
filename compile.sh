#!/bin/bash

# Use: ./Script.sh

# Colors for messages per terminal
nocolor='\033[0m'
red='\033[0;31m'
green='\033[0;32m'
orange='\033[0;33m'
blue='\033[0;34m'
purple='\033[0;35m'
gray='\033[1;30m'
yellow='\033[1;33m'

# We save the necessary directories
bin=$(pwd)/bin
data=$(pwd)/data
lib=$(pwd)/lib
obj=$(pwd)/obj
result=$(pwd)/result
main=$(pwd)/bin/main

# Create necessary directories
if [ -d $bin ];
then
	echo -e "${blue}'Bin' directory ready${nocolor}"
	rm -Rf $bin/*
else
	mkdir $bin
	echo -e "${blue}'bin' directory created${nocolor}"
fi

if [ -d $lib ];
then
	echo -e "${blue}Directory 'lib' ready${nocolor}"
	rm -Rf $lib/*
else
	mkdir $lib
	echo -e "${blue}'lib' directory created${nocolor}"
fi

if [ -d $obj ];
then
	echo -e "${blue}Directory 'obj' ready${nocolor}"
	rm -Rf $obj/*
else
	mkdir $obj
	echo -e "${blue}'obj' directory created${nocolor}"
fi

if [ -d $result ];
then
	echo -e "${blue}Directory 'result' ready${nocolor}"
	rm -Rf $result/*
else
	mkdir $obj
	echo -e "${blue}'result' directory created${nocolor}"
fi

# Code Compilation
echo -e "${orange}Compiling codes ...${nocolor}"
make
echo -e "${orange}End of compilation${nocolor}"
