#TEST: LLVM Pass Unittest - Print Class member function info

main: test.ll my_pass.so

test.ll: test.cpp
	clang -emit-llvm test.cpp -S -o test.ll

my_pass.so: TC231211C.cpp
	clang TC231211C.cpp -o my_pass.so -shared -fPIC `llvm-config --cxxflags --ldflags`
 
clean:
	rm -f *.so
	rm -f *.ll

