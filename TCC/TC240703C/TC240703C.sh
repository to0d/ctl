#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=instcount hello2.ll -o /dev/null -debug-pass-manager
/usr/lib/llvm-17/bin/opt -passes=instcount hello2.ll -o /dev/null -debug-pass-manager

echo "output: done!"