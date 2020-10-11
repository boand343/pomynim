#!/bin/bash

echo "Начинаем" 
i=0
while read LINE
    do 
    	i=$((i+1))
    	echo "$i $LINE" 
    	rosservice call $LINE 1
	done < servises