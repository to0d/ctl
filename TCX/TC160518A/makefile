CFLAGS= -I ../include -g -std=c99
a.out: TC160518A.o
	gcc -o $@ $^
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out