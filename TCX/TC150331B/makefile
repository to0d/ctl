CFLAGS= -I ../include -g -std=c99 -D_XOPEN_SOURCE
a.out: TC150331B.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out