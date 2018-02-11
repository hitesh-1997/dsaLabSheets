
CC = gcc
FLAGS = -Wall -g -c -lm -pg

compileQ: driverq.o mem.o que.o 
	$(CC) driverq.o mem.o que.o -o test

compileMQ: drivermq.o mem.o que.o MultiQ.o
	$(CC) drivermq.o mem.o que.o MultiQ.o -o test
	
driverq.o: driverq.c mem.h que.h
	$(CC) $(FLAGS) driverq.c

mem.o: mem.c mem.h
	$(CC) $(FLAGS) mem.c

que.o: que.c que.h mem.h
	$(CC) $(FLAGS) que.c

MultiQ.o: MultiQ.c MultiQ.h mem.h que.h
	$(CC) $(FLAGS) MultiQ.c
	
run:
	./test
	
clean:
	rm -rf *o test
