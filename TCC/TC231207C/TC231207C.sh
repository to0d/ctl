#/bin/sh

clang -cc1 -ast-dump hello.c > hello.dump.txt
echo "output: done!"