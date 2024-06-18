#TEST: LLVM Pass Unittest - test DominanceFrontierWrapperPass

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -g -o hello.ll

mypass.so: TC240508B.cpp
	clang -shared -fPIC -o mypass.so TC240508B.cpp `llvm-config --cxxflags --ldflags --libs` 
 
clean:
	rm -f *.so
	rm -f *.ll
	rm -f *.png

