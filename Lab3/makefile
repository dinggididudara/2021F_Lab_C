# makefile for lab3
FILE=lab3
CC = gcc
CC_FLAGS = -ansi -pedantic -Wall -w

$(FILE) : lab3.o
	$(CC) $(CC_FLAGS) -o $(FILE) lab3.o
	./$(FILE)

lab3.o : lab3.c
	$(CC) $(CC_FLAGS) -c -o lab3.o lab3.c

clean:
	rm *.o 