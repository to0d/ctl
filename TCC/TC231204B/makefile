main: hello.bc loop_pass.so

hello.bc: hello.c
	clang -emit-llvm hello.c -c -o hello.bc -O3 -fno-vectorize -fno-slp-vectorize -fno-unroll-loops

loop_pass.so: TC231204B.cpp
	`llvm-config --bindir`/clang  -shared  -fPIC `llvm-config --cxxflags` `llvm-config --ldflags` TC231204B.cpp -o loop_pass.so
 
clean:
	rm -f *.so
	rm -f *.bc

