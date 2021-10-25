# makefile for Assign1
FILE=Assign1
CC = gcc
CFLAGS = -ansi -pedantic -Wall -w

$(FILE) : Assign1.o
	$(CC) $(CFLAGS) -o $(FILE) Assign1.o
	./$(FILE)

lab3.o : Assign1.c
	$(CC) $(CFLAGS) -c -o Assign1.o Assign1.c

clean:
	rm *.o 