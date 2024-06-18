#TEST: LLVM Pass Optimize - test InstructionCombiningPass

output.ll: test_instcombine.ll
	`llvm-config --bindir`/opt -instcombine -S test_instcombine.ll -o output.ll -enable-new-pm=0 --debug-pass=Structure

clean:
	rm -f output.ll
