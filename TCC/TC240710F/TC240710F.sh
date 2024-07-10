#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=transform-warning input.ll -o /dev/null -S -debug-pass-manager

echo "output: done!"