# makefile for lab3
FILE=lab3_srs
CC = gcc
CFLAGS = -ansi -pedantic -Wall -w

$(FILE) : lab3_srs.o
	$(CC) $(CFLAGS) -o $(FILE) lab3_srs.o
	./$(FILE)

lab3.o : lab3_srs.c
	$(CC) $(CFLAGS) -c -o lab3_srs.o lab3_srs.c

clean:
	rm *.o 