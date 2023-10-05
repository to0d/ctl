CFLAGS=-I ../ -g -std=c99


hello.a: hello.o
	gcc -o hello.a hello.o -g
	gcc -o hello_pg.a hello_pg.o -g -pg
    
hello.o:
	gcc -c hello.c -g
	gcc -c hello.c -o hello_pg.o -g -pg

clean:
	rm -f *.o
	rm -f *.a
