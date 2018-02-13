
# run:
#	./test $(INT)
#  ./test 1

CC = gcc
FLAGS = -c -Wall -g


compare: compileRecMS compileiterMS runiterMS runRecMS

compileRecMS : merge.o test.o recms.o
	$(CC) merge.o test.o recms.o -o test1

compileiterMS:	merge.o test.o iterms.o
	$(CC) merge.o test.o iterms.o -o test2

runRecMS:
	./test1	
	
runiterMS:
	./test2
	
merge.o: merge.c merge.h def.h
	$(CC) $(FLAGS) merge.c
	
test.o: test.c merge.h def.h
	$(CC) $(FLAGS) test.c

recms.o: recms.c def.h merge.h
	$(CC) $(FLAGS) recms.c

iterms.o: iterms.c def.h merge.h
	$(CC) $(FLAGS) iterms.c

clean:
	rm -rf *o test


