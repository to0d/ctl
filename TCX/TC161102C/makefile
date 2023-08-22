CPPFLAGS= -g
a.out: TC161102C.o other.ctl.o
	g++ -o $@ $^  -lstdc++
..c.o:
	g++ -c $<
clean:
	rm -f *.o
	rm -f a.out