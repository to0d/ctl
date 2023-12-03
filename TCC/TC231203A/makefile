main: hello.bc mypass.so

hello.bc: hello.c
	clang -O3 -emit-llvm hello.c -c -o hello.bc

mypass.so: mypass.cpp
	`llvm-config --bindir`/clang  -shared  -fPIC `llvm-config --cxxflags` `llvm-config --ldflags` mypass.cpp -o mypass.so
 
clean:
	rm -f *.so
	rm -f *.bc

