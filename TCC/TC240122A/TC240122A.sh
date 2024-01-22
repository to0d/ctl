#/bin/sh


clang -Xclang -load -Xclang ./myplugin.so -Xclang -add-plugin -Xclang myplugin -emit-llvm -S -c test.c -o test.ll
echo "output: done!"


