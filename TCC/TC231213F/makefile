main: mypass.so test_cpp.ll

test_cpp.ll: test_cpp.cpp
	clang++ -emit-llvm test_cpp.cpp -S -o test_cpp.ll
    
mypass.so: TC231213F.cpp
	`llvm-config --bindir`/clang++ -shared -fPIC -o mypass.so TC231213F.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.so
	rm -f *.bc
	rm -f *.ll

