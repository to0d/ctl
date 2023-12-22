#/bin/sh

clang -E test.c -o expand_clang_1.c
gcc -E test.c -o expand_gcc_1.c

echo "output: done!"