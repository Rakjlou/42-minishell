#!/bin/bash

test_file_exit()
{
	rm -rf $1.ref;
	rm -rf $1.diff;
	rm -rf $1.ours;
	return $2;
}

test_file()
{
	local file=$1

	bash --posix < $file > $file.ref
	local ref_exit_value=$?

	./minishell < $file | grep -v minishell > $file.ours
	local our_exit_value=$?

	diff $file.ref $file.ours > $file.diff

	if [ $? -ne 0 ]; then
		echo "DIFF FAILED" $file;
		cat $file.diff;
		test_file_exit $file 1;
	elif [ $ref_exit_value -ne $our_exit_value ]; then
		echo "EXIT VALUE FAILED" $file
		echo "Ref" $ref_exit_value
		echo "Ours" $our_exit_value
		test_file_exit $file 1;
	else
		echo "OK" $file;
		test_file_exit $file 0;
	fi
}

test_file "tests/pipe_simple" 2>/dev/null
test_file "tests/pipe_double" 2>/dev/null
test_file "tests/pipe_triple" 2>/dev/null
test_file "tests/logical_simple" 2>/dev/null
test_file "tests/logical_mix" 2>/dev/null

