CPPFLAGS=-std=c++11 -I ../include -g -gstabs+
a.out: TC150325A.o head.ctl.o
	g++ -g -o $@ $^  -lstdc++
..c.o:
	g++ -g -c $<
clean:
	rm -f *.o
	rm -f a.out