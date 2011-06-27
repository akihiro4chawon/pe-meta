# Makefile

CC = gcc
CFLAGS = -O2 -std=c++0x -fconstexpr-depth=100000

.SUFFIXES: .cc.s

cppfiles:=$(wildcard *.cc)
asmfiles:=$(cppfiles:.cc=.s)

.PHONY: all
all: $(asmfiles)

.cc.s:
	$(CC) $(CFLAGS) -S $<

.PHONY: test
test: $(asmfiles)
	perl testasm.pl $^

.PHONY: clean
clean:
	$(RM) $(asmfiles)

