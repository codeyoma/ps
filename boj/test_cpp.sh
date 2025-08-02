#!/bin/bash

dir=$1
test_count=$2
target_test_number=$3


if ls $dir/*.cpp >/dev/null 2>&1; then \
  echo ""
  echo "[cpp]"
  g++ -std=c++20 -Wall -Wextra -Werror -o $dir/$dir.out $dir/*.cpp; \
  $dir/$dir.out $dir $test_count $target_test_number; \
  ./check.sh $dir $test_count $target_test_number; \
else \
  cp template.cpp $dir/$dir.cpp; \
fi

echo
