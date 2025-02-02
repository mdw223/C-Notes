# A makefile with explicit rules for everything we need to build.

# Rebuild the expecutable if one of the objects changes.
main: main.o helper.o
	gcc main.o helper.o -o main

# Rebuild main.o if there's a change in its source file or
# in the header it includes.
main.o: main.c helper.h
	gcc -Wall -std=c99 -g -c main.c

# Rebuild helper.o if there's a change in its implementation
# file or its header.
helper.o: helper.c helper.h
	gcc -Wall -std=c99 -g -c helper.c
