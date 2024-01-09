main: mypass.so

mypass.so: TC240109A.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC240109A.cpp `llvm-config --cxxflags --ldflags --libs` -g
 
clean:
	rm -f *.so

