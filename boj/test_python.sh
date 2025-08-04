#!/bin/bash

dir=$1
test_count=$2
target_test_number=$3

if ls $dir/$dir.py >/dev/null 2>&1; then \
  echo "[python]"
  python3 $dir/$dir.py $dir $test_count $target_test_number; \
  ./check.sh $dir $test_count $target_test_number; \
else \
  cp template.py $dir/$dir.py; \
sed -i '' "1i\\
# https://www.acmicpc.net/problem/$dir
" $dir/$dir.py

sed -i '' "2i\\
# https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/$dir/$dir
" $dir/$dir.py

fi
