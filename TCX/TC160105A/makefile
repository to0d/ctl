CFLAGS=-g -std=c99 -D_GNU_SOURCE
a.out: TC160105A.o
	gcc -o $@ $^  -std=c99  -lpthread
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out