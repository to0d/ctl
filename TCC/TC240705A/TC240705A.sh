#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=indvars input.ll -o output.ll -S -debug-pass-manager
echo ""

echo "output: done!"