#/bin/sh

/usr/lib/llvm-17/bin/opt -passes=argpromotion hello2.ll -o /dev/null -debug-pass-manager
echo ""

/usr/lib/llvm-17/bin/opt -passes=argpromotion hello2.ll -o /dev/null -debug-pass-manager
echo ""

echo "output: done!"