main: mypass.so hello_old.out hello_old.ll

hello_old.ll: hello.c
	`llvm-config --bindir`/clang -emit-llvm hello.c -S -o hello_old.ll

hello_old.o: hello_old.ll
	`llvm-config --bindir`/llc -filetype=obj hello_old.ll -o hello_old.o

hello_old.out: hello_old.o
	`llvm-config --bindir`/clang hello_old.o -o hello_old.out

mypass.so: TC231224B.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC231224B.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.out
	rm -f *.so
	rm -f *.ll

