#TEST: LLVM Pass Unittest - test LazyValueInfoWrapperPass

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -o hello.ll

mypass.so: TC240422C.cpp
	clang -shared -fPIC -o mypass.so TC240422C.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.bc
	rm -f *.ll

