
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
		./test_cpp.sh $(dir) $(test_count) $(target_test_number); \
		./test_python.sh $(dir) $(test_count) $(target_test_number); \
		./make-md.sh $(dir); \
	else \
		echo "addr - https://boj.kr/$(dir)"; \
		mkdir -p $(dir);\
		cp template.cpp $(dir)/$(dir).cpp; \
		cp template.py $(dir)/$(dir).py; \
		./make-md.sh $(dir); \
		./get-test-answer.sh $(dir) true;\
		code $(dir)/$(dir).md;\
		code $(dir)/$(dir).py;\
		code $(dir)/$(dir).cpp;\
	fi
