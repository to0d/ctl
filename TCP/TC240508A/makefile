#TEST: LLVM Pass Unittest - test LoopPass

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -c -S -o hello.ll

mypass.so: TC240508A.cpp
	clang  -shared  -fPIC `llvm-config --cxxflags --ldflags` TC240508A.cpp -o mypass.so
 
clean:
	rm -f *.so
	rm -f *.bc

