#/bin/sh

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/todd/mpich/lib
export LIBRARY_PATH=$LIBRARY_PATH:/home/todd/mpich/lib
clang++ -o a.out TC240117A.o -lmpi

mpirun -np 4 ./a.out 

echo "output: done!"