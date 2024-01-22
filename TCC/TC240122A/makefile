myplugin.so: TC240122A.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o myplugin.so TC240122A.cpp `llvm-config --cxxflags --ldflags --libs`

clean:
	rm -f *.ll
	rm -f *.o
	rm -f *.out
	rm -f *.so