#!/bin/sh

for i in $(seq 1 10); do
    mkdir "$i"
done

for dir in $(find . -maxdepth 1 -type d); do
    for j in $(seq -f "%03g" 1 10); do
        touch "$dir/name_date.txt-$j"
    done
done