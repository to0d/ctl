#/bin/sh

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/todd/openmp/lib
export LIBRARY_PATH=$LIBRARY_PATH:/home/todd/openmp/lib
clang++ -o a.out TC240109B.o -lomp

echo -n "openmp lib:"
ldd a.out | grep openmp
./a.out

echo "output: done!"