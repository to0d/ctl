CFLAGS= -I ../include -g -std=gnu99 -lpthread
a.out: TC150513A.o
	gcc -o $@ $^ 
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f a.out