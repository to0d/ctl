#/bin/sh

clang -emit-llvm hello.c -mllvm -print-after-all -S -o - &> hello.pass_dump.1.txt
cat hello.pass.txt | grep "IR Dump"
echo "output: done!"