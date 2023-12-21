main: mypass.so hello.ll

hello.ll: hello.c
	clang -emit-llvm hello.c -S -o hello.ll

mypass.so: TC231221C.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC231221C.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.ll

