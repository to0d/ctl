#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=loop-unroll-and-jam input.ll -o output.ll -S -debug-pass-manager
echo ""

echo "output: done!"