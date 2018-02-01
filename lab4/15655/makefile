
CC = gcc
FLAGS = -c -Wall -g

compile : q1.o
	$(CC) q1.o -o test

q1.o : q1.c
	$(CC) $(FLAGS) q1.c

run:
	./test $(INT)

clean:
	rm -rf *o test
