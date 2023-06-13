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

# We pass values to the program and collect the information in .dat
echo -e "${purple}Execution...${nocolor}"
	echo -e "${green}Solving the 4x4 puzzle${nocolor}"
	$bin/main $data/4x4.txt >> $result/4x4_result.dat
	echo -e "${green}Finalized${nocolor}"
	echo -e "${green}Solving the 5x5 puzzle${nocolor}"
    $bin/main $data/5x5.txt >> $result/5x5_result.dat
	echo -e "${green}Finalized${nocolor}"
	echo -e "${green}Solving the 8x8 puzzle${nocolor}"
    $bin/main $data/8x8.txt >> $result/8x8_result.dat
	echo -e "${green}Finalized${nocolor}"

echo -e "${purple}Execution completed${nocolor}"
