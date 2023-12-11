main: test.ll my_pass.so

test.ll: test.cpp
	clang++ -emit-llvm test.cpp -S -o test.ll

my_pass.so: TC231211C.cpp
	`llvm-config --bindir`/clang  -shared  -fPIC `llvm-config --cxxflags` `llvm-config --ldflags` TC231211C.cpp -o my_pass.so
 
clean:
	rm -f *.so
	rm -f *.ll

