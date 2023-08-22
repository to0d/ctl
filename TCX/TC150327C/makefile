CFLAGS= -I ../include -g -std=c99
a.out: TC150327C.o
	gcc -o $@ $^
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out