CFLAGS=-I ../ -g

all: x.main.ctl.x hello.a

x.main.ctl.x: TC170514B.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<
    
hello.a: hello.o
	gcc -o $@ $^ -std=c99 -static
    
clean:
	rm -f *.o
	rm -f x.main.ctl.x
	rm -f hello.a
