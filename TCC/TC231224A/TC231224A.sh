#/bin/sh

echo "****** test test_c.ll ******"
clang -emit-llvm test.c -S -o test_c.ll -Wno-undefined-inline
cat test_c.ll | grep -e define -e call
echo ""

echo "****** test test_cpp.ll ******"
clang++ -emit-llvm test.c -S -o test_cpp.ll -Wno-undefined-inline -Wno-deprecated
cat test_cpp.ll | grep -e define -e call
echo ""

echo "output: done!"