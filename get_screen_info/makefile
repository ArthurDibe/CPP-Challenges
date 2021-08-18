#/////////////////////////////////////////////////////
#// DEVELOPER: Dibe
#//
#// FILE: makefile
#/////////////////////////////////////////////////////

CC=g++
FLAGS=-std=c++11
FLAGS+=-I
FLAGS=-Wall
FILES=main.cpp
OBJECTS=main.o

output: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o output

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.o output

all: output
