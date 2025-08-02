#!/bin/bash

dir=$1
test_count=$2
target_test_number=$3

if ls $dir/*.py >/dev/null 2>&1; then \
  echo "[python]"
  python3 $dir/$dir.py $dir $test_count $target_test_number; \
  ./check.sh $dir $test_count $target_test_number; \
else \
  cp template.py $dir/$dir.py; \
fi
