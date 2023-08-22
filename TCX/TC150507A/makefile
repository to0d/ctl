CFLAGS= -I ../include -g -std=c99
a.out: TC150507A.o
	gcc -o $@ $^  -std=c99 -lpthread
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out