CFLAGS= -g
a.out: TC140725B.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<

clean:
	rm -f *.o
	rm -f a.out