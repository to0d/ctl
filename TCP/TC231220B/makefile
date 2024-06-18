#TEST: LLVM Pass Unittest - Print module source path

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -g -o hello.ll

mypass.so: TC231220B.cpp
	clang -shared -fPIC -o mypass.so TC231220B.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.ll

