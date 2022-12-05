# makefile for lab4
FILE=Lab04_100
CC = gcc
CC_FLAGS = -ansi -pedantic -Wall -w

$(FILE) : Lab04_100.o
	$(CC) $(CC_FLAGS) -o $(FILE) Lab04_100.o
	./$(FILE)

Lab04_100.o : Lab04_100.c
	$(CC) $(CC_FLAGS) -c -o Lab04_100.o Lab04_100.c

clean:
	rm *.o 