#TEST: LLVM Pass Unittest - test BranchProbabilityInfoWrapperPass

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -g -o hello.ll

mypass.so: TC231213A.cpp
	clang -shared -fPIC -o mypass.so TC231213A.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.bc
	rm -f *.ll

