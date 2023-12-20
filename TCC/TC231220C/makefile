main: test_c.ll test_cpp.ll

test_c.ll: test.c
	clang -O3 -emit-llvm test.c -S -o test_c.ll

test_cpp.ll: test.c
	clang++ -O3 -emit-llvm test.c -S -o test_cpp.ll -Wno-deprecated

clean:
	rm -f *.ll

