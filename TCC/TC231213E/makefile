main: mypass.so

mypass.so: TC231213E.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC231213E.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so

