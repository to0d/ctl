main: mypass.so hello.ll

hello.ll: hello.cpp
	clang++ -emit-llvm hello.cpp -S -o hello.ll -g

mypass.so: TC231222B.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC231222B.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.ll

