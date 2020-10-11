#!/bin/bash

echo "Начинаем" > infa
i=0
while read LINE
    do 
    	i=$((i+1))
    	echo "$i $LINE" >> infa
    	rosservice info $LINE >> infa
	done < servises