#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=dot-dom hello2.ll -o /dev/null -debug-pass-manager
/usr/lib/llvm-14/bin/opt -passes=dot-dom-only hello2.ll -o /dev/null -debug-pass-manager

/usr/lib/llvm-17/bin/opt -passes=dot-post-dom hello2.ll -o /dev/null -debug-pass-manager
/usr/lib/llvm-17/bin/opt -passes=dot-post-dom-only hello2.ll -o /dev/null -debug-pass-manager

idot .

echo "output: done!"