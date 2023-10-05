test.a: mymalloc.o 
	gcc -I. -o test.a TC231005B.c mymalloc.o -g 

mymalloc.o:
	gcc -DCOMPILETIME -c mymalloc.c
    
clean:
	rm -f *.o
	rm -f *.a
