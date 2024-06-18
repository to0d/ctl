#/bin/sh

OPT_CMD=`llvm-config --bindir`/opt
OPT_VER_STR=`$OPT_CMD --version | grep version | awk '{print $4}' | awk -F . '{print $1}'`
OPT_VER=`expr $OPT_VER_STR`
OPT_ARG=

if [ $OPT_VER -gt 10 ] ; 
then
    OPT_ARG=$OPT_ARG" -enable-new-pm=0"
fi

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../../build

$OPT_CMD -load ./mypass.so -mypass hello.ll -o /dev/null $OPT_ARG

#sopt -s hello.ll -d cfg
#idot .

echo "output: done!"