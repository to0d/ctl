#/bin/sh

clang -emit-llvm -S -c test.c -o test.ll -I ./include_1 

# sed  "s/@func/@func_wrap/g" test.ll > test2.ll
echo "update ir"
OPT_CMD=`llvm-config --bindir`/opt
OPT_VER_STR=`$OPT_CMD --version | grep version | awk '{print $4}' | awk -F . '{print $1}'`
OPT_VER=`expr $OPT_VER_STR`
OPT_ARG=

if [ $OPT_VER -gt 10 ] ; 
then
    OPT_ARG=$OPT_ARG" -enable-new-pm=0"
fi

$OPT_CMD -S -load ./mypass.so -mypass test.ll -o test2.ll $OPT_ARG

clang -c test2.ll -o test.o
clang test.o impl.o -o test.out
./test.out
echo "output: done!"