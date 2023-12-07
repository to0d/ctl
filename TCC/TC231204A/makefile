main: hello.bc loop_pass.so

hello.bc: hello.c
	clang -emit-llvm hello.c -c -o hello.bc

loop_pass.so: TC231204A.cpp
	`llvm-config --bindir`/clang  -shared  -fPIC `llvm-config --cxxflags` `llvm-config --ldflags` TC231204A.cpp -o loop_pass.so
 
clean:
	rm -f *.so
	rm -f *.bc

