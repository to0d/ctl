#/bin/sh

/usr/lib/llvm-17/bin/opt -passes=view-dom input.ll -o /dev/null -S -debug-pass-manager
/usr/lib/llvm-17/bin/opt -passes=view-dom-only input.ll -o /dev/null -S -debug-pass-manager

echo "output: done!"