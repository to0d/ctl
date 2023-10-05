test.a: mymalloc.o
	gcc -c TC231005C.c
	gcc -Wl,--wrap,malloc -Wl,--wrap,free -o test.a TC231005C.o mymalloc.o

mymalloc.o:
	gcc -DLINKTIME -c mymalloc.c
    
clean:
	rm -f *.o
	rm -f *.a
