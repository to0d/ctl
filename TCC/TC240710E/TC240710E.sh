#/bin/sh

/usr/lib/llvm-17/bin/opt -passes=view-post-dom input.ll -o /dev/null -S -debug-pass-manager
/usr/lib/llvm-17/bin/opt -passes=view-post-dom-only input.ll -o /dev/null -S -debug-pass-manager

echo "output: done!"