CPPFLAGS= -I ../include -g
a.out: TC240109B.o
	clang++ -o $@ $^  -lstdc++
..c.o:
	clang++ -fopenmp -c $< 
clean:
	rm -f *.o
	rm -f a.out