#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=strip-dead-prototypes input.ll -o output.ll -S -debug-pass-manager

echo "output: done!"