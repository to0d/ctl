#TEST: LLVM Pass Unittest - test AAResultsWrapperPass

main: hello.ll mypass.so

hello.ll: hello.c
	clang hello.c -S -o hello.ll -emit-llvm -g

mypass.so: TC231212A.cpp
	clang -shared -fPIC -o mypass.so TC231212A.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.bc
	rm -f *.ll

