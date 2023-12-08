main: hello.ll loop_pass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -o hello.ll

loop_pass.so: TC231208A.cpp
	`llvm-config --bindir`/clang  -shared  -fPIC `llvm-config --cxxflags` `llvm-config --ldflags` TC231208A.cpp -o loop_pass.so
 
clean:
	rm -f *.so
	rm -f *.bc
	rm -f *.ll

