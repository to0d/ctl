main: hello.ll

hello.ll: hello.c
	clang -emit-llvm hello.c -S -o hello.ll

clean:
	rm -f *.ll
	rm -f *.dump.txt

