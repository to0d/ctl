#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=simple-loop-unswitch input.ll -o output.ll -S -debug-pass-manager

echo "output: done!"