#!/bin/bash
# Raymond Mui
# CSE 374 Homework 5
# Makefile



main: t9.o Node.o main.o
	gcc -std=c99 -g -Wall -o main main.o t9.o Node.o
main.o: t9.h
	gcc -std=c99 -g -Wall -c main.c

t9.o: t9.c t9.h
	gcc -std=c99 -g -Wall -c t9.c
Node.o: Node.c Node.h
	gcc -std=c99 -g -Wall -c Node.c

clean:
	rm -f *.o
	rm -f main
	
#t9: t9.o Node.o
#	gcc -Wall -std=c99 -g -o t9 t9.o Node.o

#t9.o: Node.h t9.c
#	gcc -Wall -std=c99 -g -c t9.c

#Node.o: Node.h Node.c
#gcc -Wall -std=c99 -g -c Node.c

