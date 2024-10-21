#!/bin/bash 

file_name="temp.txt" 

if [ -e "$file_name" ]; 
then
	echo "'$file_name' exists."
	mv "$file_name" "old_${file_name}"
	echo "Existing file renamed to '${file_name}_old'." 

	echo "New empty file created with the name '$file_name'."

	echo "Both conditions done together." 
else 
	echo 'File '$file_name' does not exist.\nNew empty file created.'
	touch $file_name
fi

