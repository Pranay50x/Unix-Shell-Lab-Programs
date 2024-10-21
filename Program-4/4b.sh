#!/bin/bash 

count_text_stats() {

	input_text="$1"
	char_count=$(echo -n "$input_text" | wc -m)
	word_count=$(echo "$input_text" | wc -w)
	space_count=$(echo "$input_text" | tr -cd '' | wc -c)
	special_count=$(echo s"$input_text" | tr -cd '[:punct:]' | wc -c)

	echo "Text Analysis Report: "
	echo "Character COunt: $char_count"
	echo "Word Count: $word_count"
	echo "White Space Count: $space_count"
	echo "Special Character count: $special_count"
	echo "  "
}


text_to_analyse="This is a sample text!, I feel great to be working @Google"

count_text_stats "$text_to_analyse"
