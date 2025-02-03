#!/bin/bash

space_usage=$(df -h / | awk 'NR==2 {print$5}' | sed 's/%//')
echo "System space used: $space_usage%"

if [ $space_usage -gt 80 ];
then
    echo "Low system space left"
    echo "Large files are: "
    find / -type f -size +1G -exec ls -lh {} \; 2</dev/null

    if [ $? -ne 0 ];
    then
        echo "no files greater than 1gb or insufficient perms"
    fi
else
    echo "System space under control"
fi
