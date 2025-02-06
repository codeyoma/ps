.PHONY: all clean $(MAKECMDGOALS)

dir ?= $(MAKECMDGOALS)
test_count := $(shell ls $(dir)/test-output-*.txt 2>/dev/null | wc -l)
IGNORED_TARGETS := all clean run

SRCS=$(wildcard $(dir)/*.cpp)


all:
	@echo "Default build"

$(filter-out $(IGNORED_TARGETS),$(MAKECMDGOALS)):
	@if [ -d "$(dir)" ]; then \
		echo "addr - https://boj.kr/$(dir)"; \
		if ls $(dir)/*.cpp >/dev/null 2>&1; then \
			g++ -std=c++20 -o $(dir)/$(dir).out $(dir)/*.cpp; \
			$(dir)/$(dir).out $(dir) $(test_count); \
			./check.sh $(dir) $(test_count); \
		else \
			echo "No C++ source files found in $(dir)"; \
		fi \
	else \
		echo "Creating it... '${dir}'"; \
		echo "addr - https://boj.kr/$(dir)"; \
		mkdir -p $(dir);\
		cp template.cpp $(dir)/$(dir).cpp; \
		./get-test-answer.sh $(dir) true;\
	fi
