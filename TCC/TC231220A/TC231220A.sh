#/bin/sh

OPT_VER_STR=`opt --version | grep version | awk '{print $4}' | awk -F . '{print $1}'`
OPT_VER=`expr $OPT_VER_STR`
OPT_ARG=


opt -load ./mypass.so -mypass hello.ll -o /dev/null -enable-new-pm=1
opt -load ./mypass.so -passes=mypass hello.ll -o /dev/null -enable-new-pm=1

echo "output: done!"