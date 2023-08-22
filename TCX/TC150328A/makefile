CPPFLAGS=-I ../include -g
a.out: TC150328A.o
	g++ -o $@ $^  -lstdc++
..c.o:
	g++ -c $<
clean:
	rm -f *.o
	rm -f a.out