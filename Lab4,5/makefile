# makefile for Assign1
FILE=main
CC = gcc
CFLAGS = -ansi -pedantic -Wall -w

$(FILE) : main.o cardGame.o
	$(CC) $(CFLAGS) -o $(FILE) main.o cardgame.o
	./$(FILE)

lab3.o : Assign1.c
	$(CC) $(CFLAGS) -c -o main.o main.c cardgame.o cardgame.c

clean:
	rm *.o 