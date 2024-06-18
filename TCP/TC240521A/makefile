#TEST: LLVM IR Optimize -  clang -O3 -Rpass

output.ll: 
	clang -O3 -Rpass-analysis=.* -Rpass=.* -Rpass-missed=.* -c TC240521A.c -S -emit-llvm -o output.ll
	clang -O3 -Rpass-analysis=.* -Rpass=.* -Rpass-missed=.* -c TC240521A2.c -S -emit-llvm -o TC240521A2.ll
	clang -c TC240521A.c -S -emit-llvm

clean:
	rm -f output.ll
	rm -f TC240521A*.ll