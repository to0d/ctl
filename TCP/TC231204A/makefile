#TEST: LLVM Pass Unittest - test LoopInfoWrapperPass

main: hello.bc test_pass.so

hello.bc: hello.c
	clang -emit-llvm hello.c -c -o hello.bc

test_pass.so: TC231204A.cpp
	clang -shared  -fPIC `llvm-config --cxxflags --ldflags` TC231204A.cpp -o test_pass.so
 
clean:
	rm -f *.so
	rm -f *.bc

