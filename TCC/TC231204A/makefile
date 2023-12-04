main: hello.bc loop_pass.so

hello.bc: hello.c
	clang -emit-llvm hello.c -c -o hello.bc

loop_pass.so: loop_pass.cpp
	`llvm-config --bindir`/clang  -shared  -fPIC `llvm-config --cxxflags` `llvm-config --ldflags` loop_pass.cpp -o loop_pass.so
 
clean:
	rm -f *.so
	rm -f *.bc

