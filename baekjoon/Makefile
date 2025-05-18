
RAW_GOALS := $(MAKECMDGOALS)
dir := $(word 1, $(RAW_GOALS))
target_test_number := $(test)
test_count := $(shell ls $(dir)/test-output-*.txt 2>/dev/null | wc -l)

IGNORED_TARGETS := all clean run

SRCS=$(wildcard $(dir)/*.cpp)

override MAKECMDGOALS := $(word 1, $(RAW_GOALS))

.PHONY: all clean $(filter-out $(IGNORED_TARGETS), $(MAKECMDGOALS))

all:
	@echo "Default build"

$(filter-out $(IGNORED_TARGETS), $(MAKECMDGOALS)):
	@if [ -d "$(dir)" ]; then \
		echo "addr - https://boj.kr/$(dir)"; \
		if ls $(dir)/*.cpp >/dev/null 2>&1; then \
			g++ -std=c++20 -Wall -Wextra -Werror -o $(dir)/$(dir).out $(dir)/*.cpp; \
			$(dir)/$(dir).out $(dir) $(test_count) $(target_test_number); \
			./check.sh $(dir) $(test_count) $(target_test_number); \
			python3 extract.py $(dir); \
		else \
			echo "No C++ source files found in $(dir)"; \
		fi \
	else \
		echo "addr - https://boj.kr/$(dir)"; \
		mkdir -p $(dir);\
		cp template.cpp $(dir)/$(dir).cpp; \
		cp template.md $(dir)/$(dir).md; \
		./get-test-answer.sh $(dir) true;\
		code $(dir)/$(dir).cpp;\
		code $(dir)/$(dir).md;\
	fi
