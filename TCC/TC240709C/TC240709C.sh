#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=simplifycfg input.ll -o output.ll -S -debug-pass-manager
echo ""

/usr/lib/llvm-14/bin/opt -passes=dot-cfg-only input.ll  -o /dev/null
mv ._Z9is_sortedPii.dot input.dot

/usr/lib/llvm-14/bin/opt -passes=dot-cfg-only output.ll  -o /dev/null
mv ._Z9is_sortedPii.dot output.dot


echo "output: done!"