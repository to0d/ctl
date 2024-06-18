#TEST: LLVM Pass Optimize - test GVNLegacyPass

output.ll: test_gvn_pass.ll
	`llvm-config --bindir`/opt -gvn -S test_gvn_pass.ll -o output.ll -enable-new-pm=0 --debug-pass=Structure

clean:
	rm -f output.ll
