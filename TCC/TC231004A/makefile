CFLAGS=-I ../ -g -std=c99

hello.a: hello.o fun.o
	gcc -o $@ $^ -g
    
hello.o:
	gcc -c hello.c -g
    
fun.o:
	gcc -c fun.c -g
    
clean:
	rm -f *.o
	rm -f hello.a
