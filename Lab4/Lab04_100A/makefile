# makefile for lab4
FILE=Lab04_100A
CC = gcc
CC_FLAGS = -ansi -pedantic -Wall -w

$(FILE) : Lab04_100A.o
	$(CC) $(CC_FLAGS) -o $(FILE) Lab04_100A.o
	./$(FILE)

Lab04_100.o : Lab04_100A.c
	$(CC) $(CC_FLAGS) -c -o Lab04_100A.o Lab04_100A.c

clean:
	rm *.o 