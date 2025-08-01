#!/bin/bash

problem_number=$1
test_case=$2
test_target=$3

correct_count=0

if [ -n "$test_target" ]; then
    if diff -b "$problem_number/test-output-$test_target.txt" "$problem_number/my-output-$test_target.txt" >/dev/null; then
        echo -e "Test case $test_target: \033[32mO\033[0m"
    else
        echo -e "Test case $test_target: \033[31mX\033[0m"
    fi
else
    for i in $(seq 1 $test_case); do
        if diff -b "$problem_number/test-output-$i.txt" "$problem_number/my-output-$i.txt" >/dev/null; then
            echo -e "Test case $i: \033[32mO\033[0m"
            ((correct_count++))
        else
            echo -e "Test case $i: \033[31mX\033[0m"
        fi
    done
    echo "- $correct_count/$test_case"
fi
