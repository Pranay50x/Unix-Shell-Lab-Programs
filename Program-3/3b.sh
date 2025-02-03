#!/bin/bash

file_name="source.txt"

if [ -e $file_name ];
then
    echo "File '$file_name' exists"
    mv "$file_name" "old_$file_name"
    echo "Renames '$file_name' to 'old_$file_name'"

    touch "$file_name"
    echo "new empty '$file_name' created"
    echo "Both conditions done together"
else
    echo 'File '$file_name' doesnt exist\nNew File created'
    touch "$file_name"
fi
