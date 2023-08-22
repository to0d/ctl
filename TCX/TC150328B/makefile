CFLAGS= -I ../include/ctl -g -std=c99
a.out: TC150328B.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out