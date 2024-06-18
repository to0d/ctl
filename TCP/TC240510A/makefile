#TEST: LLVM Pass Unittest - test IntervalPartition

main: hello.ll mypass.so

hello.ll: hello.c
	clang -emit-llvm hello.c -S -o hello.ll

mypass.so: TC240510A.cpp
	clang -shared -fPIC -o mypass.so TC240510A.cpp `llvm-config --cxxflags --ldflags --libs` 
 
clean:
	rm -f *.so
	rm -f *.ll
	rm -f *.png

