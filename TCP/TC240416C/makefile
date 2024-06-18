#TEST: LLVM Pass Unittest - test domtree

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -g -o hello.ll

mypass.so: TC240416C.cpp
	clang -shared -fPIC -o mypass.so TC240416C.cpp `llvm-config --cxxflags --ldflags --libs` 
 
clean:
	rm -f *.so
	rm -f *.bc
	rm -f *.ll

