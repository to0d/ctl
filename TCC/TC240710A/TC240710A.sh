#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=extract-blocks input.ll -o /dev/null -S -debug-pass-manager

echo "output: done!"