#/bin/sh

opt -load ./mypass.so -hello hello.bc -o /dev/null
opt -load ./mypass.so -hello2 hello.bc -o /dev/null
echo "output: done!"