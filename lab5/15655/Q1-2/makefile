
# run:
#	./test $(INT)
#  ./test 1

CC = gcc
FLAGS = -c -Wall -g -pg


compare: compileRecMS compileiterMS runiterMS runRecMS

compileRecMS : merge.o driver.o recms.o mem.o
	$(CC) merge.o driver.o recms.o mem.o -o test

compileiterMS:	merge.o driver.o iterms.o mem.o
	$(CC) merge.o driver.o iterms.o mem.o -o test

runRecMS:
	./test
	
runiterMS:
	./test
	
merge.o: merge.c merge.h def.h
	$(CC) $(FLAGS) merge.c
	
driver.o: driver.c merge.h def.h mem.h
	$(CC) $(FLAGS) driver.c

recms.o: recms.c def.h merge.h
	$(CC) $(FLAGS) recms.c

iterms.o: iterms.c def.h merge.h
	$(CC) $(FLAGS) iterms.c

mem.o: mem.c mem.h
	$(CC) $(FLAGS) mem.c
	 
clean:
	rm -rf *o test


