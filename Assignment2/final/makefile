# makefile for Assignment 2
FILE=main
CC = gcc
CC_FLAGS = -ansi -pedantic -Wall -w

$(FILE) : main.o
	$(CC) $(CC_FLAGS) -o $(FILE) main.o
	./$(FILE)

main.o : main.c
	$(CC) $(CC_FLAGS) -c -o main.o main.c

clean:
	rm *.o 