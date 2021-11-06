# makefile for Assign1
FILE=main
CC = gcc
CFLAGS = -ansi -pedantic -Wall -w

$(FILE) : main.o playGame.o betMoney.o
	$(CC) $(CFLAGS) -o $(FILE) main.o playGame.o betMoney.o
	./$(FILE)

lab3.o : Assign1.c
	$(CC) $(CFLAGS) -c -o main.o main.c playGame.o playGame.c betMoney.o

clean:
	rm *.o 