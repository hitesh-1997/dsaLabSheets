
compile : mem.o linkList.o ex3d.o
	gcc mem.o linkList.o ex3d.o -o test

mem.o: mem.c mem.h
	gcc -c -pg mem.c

linkList.o: linkList.c linkList.h 
	gcc -c -pg linkList.c

ex3d.o: ex3d.c linkList.h mem.h
	gcc -c -pg ex3d.c
	
run:
	./test
	
clean:
	rm -rf *o test
