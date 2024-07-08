#/bin/sh

/usr/lib/llvm-17/bin/opt -passes=lower-global-dtors input.ll -o output.ll -S -debug-pass-manager
echo ""

echo "output: done!"