main: mypass.so hello.ll

hello.ll: hello.c
	clang -emit-llvm hello.c -S -o hello.ll -g -O0 -Wno-extern-initializer -I ./

mypass.so: TC231221B.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC231221B.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.ll

