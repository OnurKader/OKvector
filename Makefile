CC=g++
CFLAGS= -std=c++2a -Wall -Wextra -Wpedantic -Wshadow -g

.PHONY: clean build all

all: build

clean:
	@rm -f main *.o

vector.o: vector.cpp vector.hpp
	$(CC) $(CFLAGS) -c $<

main.o: main.cpp
	$(CC) $(CFLAGS) -c $<

build: vector.o main.o
	$(CC) $(CFLAGS) $^ -o main
