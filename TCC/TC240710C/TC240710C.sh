#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=view-cfg input.ll -cfg-func-name=foo -o /dev/null -S -debug-pass-manager
/usr/lib/llvm-14/bin/opt -passes=view-cfg-only input.ll -cfg-func-name=foo -o /dev/null -S -debug-pass-manager

echo "output: done!"