CFLAGS=-I ../include -g -std=c99

a.out: TC150326A.o
	gcc -o $@ $^
..c.o:
	gcc -c $< -std=c99 
clean:
	rm -f *.o
	rm -f a.out