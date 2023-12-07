#/bin/sh

opt -dot-cfg hello.ll
dot -Tpng -o main.png .main.dot
/usr/lib/llvm-17/bin/opt -passes=dot-callgraph hello.ll
dot -Tpng -o hello.callgraph.png hello.ll.callgraph.dot

echo "output: done!"