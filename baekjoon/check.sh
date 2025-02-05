#!/bin/bash

problem_number=$1
test_case=$2

for i in $(seq 1 $test_case); do
    if diff -b "$problem_number/test-answer-$i.txt" "$problem_number/my-answer-$i.txt" > /dev/null; then \
        echo -e "Test case $i: \033[32mO\033[0m"; \
    else \
        echo -e "Test case $i: \033[31mX\033[0m"; \
    fi
done
