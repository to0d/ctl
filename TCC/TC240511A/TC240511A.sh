#/bin/sh

/usr/lib/llvm-14/bin/opt -passes=dot-cfg-only hello.ll
dot -Tpng -o hello_cfg.png .foo.dot


echo "output: done!"