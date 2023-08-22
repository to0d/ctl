CPPFLAGS=-I ../include/ctl -g
x.main.ctl.x: TC160722A.o
	gcc -o $@ $^
..c.o:
	gcc -c $<
clean:
	rm -f *.o
	rm -f *.x