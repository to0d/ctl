#/bin/sh

clang -emit-llvm -S -c test.c -o test.ll -I ./include_1 
sed  "s/@func/@func_wrap/g" test.ll > test2.ll
clang -c test2.ll -o test.o
clang test.o impl.o -o test.out
./test.out
echo "output: done!"