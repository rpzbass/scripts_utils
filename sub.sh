#!/bin/bash

echo -e "EXEMPLO:: ./sub.sh lista.txt dominio \n"

dom=$2

for list in $(cat $1); do

host $list.$dom | grep -v NXDOMAIN;

done