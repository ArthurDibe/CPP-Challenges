#/////////////////////////////////////////////////////
#// DEVELOPER: Dibe
#//
#// FILE: makefile
#/////////////////////////////////////////////////////

CC=g++
FLAGS=-std=c++11
FLAGS+=-I
FLAGS=-Wall
FILES=lab2.cpp
OBJECTS=lab2.o

output: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o output

lab2.o: lab2.cpp
	$(CC) -c lab2.cpp

clean:
	rm -f *.o output

all: output
