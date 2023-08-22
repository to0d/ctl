CFLAGS= -I ../include -g
a.out: TC150327D.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out