#/bin/sh

/usr/lib/llvm-14/bin/clang -c test.c -S -emit-llvm -o test_14.ll
echo ""

/usr/lib/llvm-15/bin/clang -c test.c -S -emit-llvm -o test_15_with_ptr.ll
echo ""

/usr/lib/llvm-15/bin/clang -c test.c -S -emit-llvm -o test_15_without_ptr.ll -Xclang -no-opaque-pointers
echo ""

/usr/lib/llvm-15/bin/opt test_15_without_ptr.ll -S -o test_15_opt_remove_pointer_type_.ll --opaque-pointers
echo ""

echo "output: done!"