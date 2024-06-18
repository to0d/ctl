#TEST: LLVM Pass Unittest - Print CallInst's source line number

main: mypass.so hello_g.ll hello_r.ll

hello_g.ll: hello.c
	clang -emit-llvm hello.c -S -o hello_g.ll -g

hello_r.ll: hello.c
	clang -emit-llvm hello.c -S -o hello_r.ll

mypass.so: TC231221A.cpp
	clang -shared -fPIC -o mypass.so TC231221A.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.ll

