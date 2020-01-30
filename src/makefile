#Jeff Austin
#Makefile for the ovens directory.

# set up for use in gdb and display warnings
# compile for a 32-bit architecture rather than 64-bit. -standard optimizations
CC=g++
CFLAGS=-g -Wall

clean:
	rm -f plugin *~
run: plugin.cpp constructors.cpp implementation_files.cpp
	$(CC) *.cpp -o plugin $(CFLAGS) && ./plugin

# extras

# OBJECTS=*.o
# EXECUTABLE=run
# all: plugin

# RN=./a.out
#run:
#	$(RN)

# all: implementation files plugin
# implementation_files: implementation_files.cpp
#	$(CC) implementation_files.cpp -o implementation_files

#.cpp.o:
#	$(CC) $(CFLAGS) $<-o$@	

#%: %.cpp
#	$(CC) $(CFLAGS) $(DFLAGS) $< oven $@ -lm
