CPPFLAGS= -g
a.out: TC161101A.o
	g++ -o $@ $^  -lstdc++
..c.o:
	g++ -c $<
clean:
	rm -f *.o
	rm -f a.out