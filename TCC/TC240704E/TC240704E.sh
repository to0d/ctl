#/bin/sh

/usr/lib/llvm-17/bin/opt -passes=print-callgraph-sccs hello2.ll -o /dev/null -debug-pass-manager
echo ""

/usr/lib/llvm-17/bin/opt -passes=print-cfg-sccs hello2.ll -o /dev/null -debug-pass-manager
echo ""

echo "output: done!"