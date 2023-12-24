#/bin/sh

echo "********** hello_old **********"
./hello_old.out

echo "********** hello_new **********"

OPT_CMD=`llvm-config --bindir`/opt
OPT_VER_STR=`$OPT_CMD --version | grep version | awk '{print $4}' | awk -F . '{print $1}'`
OPT_VER=`expr $OPT_VER_STR`
OPT_ARG=

if [ $OPT_VER -gt 10 ] 
then
    OPT_ARG=$OPT_ARG" -enable-new-pm=0"
fi

$OPT_CMD -S -load ./mypass.so -mypass hello_old.ll -o hello_new.ll $OPT_ARG

`llvm-config --bindir`/llc -filetype=obj hello_new.ll -o hello_new.o
`llvm-config --bindir`/clang hello_new.o -o hello_new.out
./hello_new.out

echo "output: done!"