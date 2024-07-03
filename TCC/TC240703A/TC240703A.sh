#/bin/sh

echo "test hello.ll"
/usr/lib/llvm-14/bin/opt -passes=aa-eval hello.ll -o /dev/null -debug-pass-manager
echo ""
echo ""

echo "test hello2.ll"
/usr/lib/llvm-14/bin/opt -passes=aa-eval hello2.ll -o /dev/null -debug-pass-manager
echo ""
echo ""

echo "output: done!"