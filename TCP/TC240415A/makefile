#TEST: LLVM Pass Optimize - test StackProtector

output.ll: test_ssp.ll
	`llvm-config --bindir`/opt -stack-protector -S test_ssp.ll -o output.ll -enable-new-pm=0

test_ssp.ll: input.c
	clang -emit-llvm input.c -S -o test_ssp.ll

clean:
	rm -f test_ssp.ll
	rm -f output.ll
