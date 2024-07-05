#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=licm input.ll -o output.ll -S -debug-pass-manager

echo "output: done!"