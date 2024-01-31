#/bin/sh

script_abs=$(readlink -f $0)
script_dir=$(dirname $script_abs)

OPT_CMD=`llvm-config --bindir`/opt
OPT_VER_STR=`$OPT_CMD --version | grep version | awk '{print $4}' | awk -F . '{print $1}'`
OPT_VER=`expr $OPT_VER_STR`
OPT_ARG=

if [ $OPT_VER -gt 10 ] ; 
then
    OPT_ARG=$OPT_ARG" -enable-new-pm=0"
fi


echo "************ test_3 ************"
$OPT_CMD -load ./mypass.so -mypass test_3.ll --dot-path $script_dir/ -o /dev/null $OPT_ARG
echo ""
echo ""

echo "************ test_3 - test_3.simd_gemm ************"
$OPT_CMD -load ./mypass.so -mypass test_3.ll --dot-path $script_dir/ --dot-node simd_gemm -o /dev/null $OPT_ARG
echo ""
echo ""

#dot -Tpng -o test_3.png test_3.dot


echo "output: done!"