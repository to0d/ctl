CPPFLAGS= -g
a.out: TC161102A.o
	g++ -o $@ $^  -lstdc++
..c.o:
	g++ -c $<
clean:
	rm -f *.o
	rm -f a.out