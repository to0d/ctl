CPPFLAGS=-std=c++11 -I ../include -g
a.out: TC170310C.o
	g++ -o $@ $^  -lstdc++
..c.o:
	g++ -c $<
clean:
	rm -f *.o
	rm -f a.out