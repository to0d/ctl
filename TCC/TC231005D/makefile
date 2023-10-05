test.a: mymalloc.o
	gcc TC231005D.c -o test.a -g

mymalloc.o:
	gcc -DRUNTIME -shared -fpic -g  -o mymalloc.so mymalloc.c -ldl

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.so
