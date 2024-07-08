#/bin/sh

/usr/lib/llvm-14/bin/clang -c test.c -S -emit-llvm -o test_14.ll
echo ""

/usr/lib/llvm-14/bin/clang -c test.c -S -emit-llvm -o test_14_2.ll -Xclang -no-opaque-pointers
echo ""


/usr/lib/llvm-17/bin/clang -c test.c -S -emit-llvm -o test_17.ll
echo ""

/usr/lib/llvm-17/bin/clang -c test.c -S -emit-llvm -o output.ll -Xclang -no-opaque-pointers
echo ""

/usr/lib/llvm-15/bin/clang -c test.c -S -emit-llvm -o output.ll -Xclang -no-opaque-pointers
echo ""

/usr/lib/llvm-15/bin/opt test_17.ll -S -o output.ll --opaque-pointers
echo ""

echo "output: done!"