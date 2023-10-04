CFLAGS=-I ../ -g

all: x.main.ctl.x hello.a

x.main.ctl.x: TC170514C.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<
    
hello.a: hello.o
	gcc -o $@ $^ -std=c99 -static -lpthread
    
clean:
	rm -f *.o
	rm -f x.main.ctl.x
	rm -f hello.a
