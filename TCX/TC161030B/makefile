CPPFLAGS=-std=c++11 -I ../include -g
a.out: TC161030B.o new_1.o new_2.o
	g++ -o $@ $^  -lstdc++
..c.o:
	g++ -c $<

clean:
	rm -f *.o
	rm -f a.out