#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=partial-inliner partial-inline-act.ll -o output.ll -S -debug-pass-manager
echo ""

echo "output: done!"