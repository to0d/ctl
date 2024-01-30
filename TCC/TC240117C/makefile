main: impl.o mypass.so

impl.o: impl.c
	clang -c impl.c -o impl.o -I ./include_2

mypass.so: TC240117C.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC240117C.cpp `llvm-config --cxxflags --ldflags --libs`

clean:
	rm -f *.ll
	rm -f *.o
	rm -f *.out
	rm -f *.so
