CPPFLAGS=-std=c++0x -I ../include -g
a.out: TC160118A.o
	g++ -o $@ $^ -std=c++11 -pthread
..c.o:
	g++ -c $< 
clean:
	rm -f *.o
	rm -f a.out