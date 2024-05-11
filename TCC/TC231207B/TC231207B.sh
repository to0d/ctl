#/bin/sh

/usr/lib/llvm-17/bin/opt -passes=dot-cfg hello.ll
dot -Tpng -o hello_cfg.png .foo.dot

/usr/lib/llvm-17/bin/opt -passes=dot-callgraph hello.ll
dot -Tpng -o hello_callgraph.png hello.ll.callgraph.dot

echo "output: done!"