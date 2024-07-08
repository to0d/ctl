#/bin/sh

/usr/lib/llvm-14/bin/clang -c test.c -S -emit-llvm -o test_14.ll
echo ""

/usr/lib/llvm-17/bin/clang -c test.c -S -emit-llvm -o test_17.ll
echo ""

/usr/lib/llvm-17/bin/clang -c test.c -S -emit-llvm -o output.ll --no-opaque-pointer
echo ""

echo "output: done!"