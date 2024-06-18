#TEST: LLVM IR Optimize - llvm opt -inline -always-inline (all)

output.ll:
	`llvm-config --bindir`/opt TC240521B.ll -o output.ll -S -inline -always-inline

clean:
	rm -f output.ll
    