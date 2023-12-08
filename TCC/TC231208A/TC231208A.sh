#/bin/sh

OPT_VER_STR=`opt --version | grep version | awk '{print $4}' | awk -F . '{print $1}'`
OPT_VER=`expr $OPT_VER_STR`
OPT_ARG=

if [ $OPT_VER -gt 10 ] 
then
    OPT_ARG=$OPT_ARG" -enable-new-pm=0"
fi

opt -load ./mypass.so -mypass hello.ll -o /dev/null $OPT_ARG

echo "output: done!"