CFLAGS=-I ../ -g -std=c99

hello.a: hello.o
	gcc -o $@ $^ -g
    
hello.o:
	gcc -c hello.c -g

clean:
	rm -f *.o
	rm -f hello.a
