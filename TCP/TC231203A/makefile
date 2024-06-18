#TEST: LLVM Pass Unittest - test FunctionPass

main: hello.bc mypass.so

hello.bc: hello.c
	clang -O3 -emit-llvm hello.c -c -o hello.bc

mypass.so: TC231203A.cpp
	clang  -shared  -fPIC `llvm-config --cxxflags --ldflags` TC231203A.cpp -o mypass.so
 
clean:
	rm -f *.so
	rm -f *.bc

