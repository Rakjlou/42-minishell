#!/bin/bash

test_file()
{
	local file=$1

	bash --posix < $file > $file.ref
	local ref_exit_value=$?

	./minishell < $file | sed --expression '1d;$d' > $file.ours
	local our_exit_value=$?

	diff $file.ref $file.ours > $file.diff

	if [ $? -ne 0 ]; then
		echo "DIFF FAILED" $file;
		cat file.diff;
		return 1;
	elif [ $ref_exit_value -ne $our_exit_value ]; then
		echo "EXIT VALUE FAILED" $file
		echo "Ref" $ref_exit_value
		echo "Ours" $our_exit_value
		return 1;
	else
		echo "OK" $file;
		return 0;
	fi
}

test_file "tests/pipe_simple"
