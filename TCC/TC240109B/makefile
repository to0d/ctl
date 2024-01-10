CPPFLAGS= -I ../include -I ~/openmp/include -g -fopenmp

CXX:=clang++

TC240109B.o: TC240109B.cpp
	${CXX}  -I ../include -I ~/openmp/include -g -fopenmp  -c -o TC240109B.o TC240109B.cpp
	clang -emit-llvm -S -I ../include -I ~/openmp/include -c TC240109B.cpp -o TC240109B_none.ll 
	clang -emit-llvm -S -I ../include -I ~/openmp/include -fopenmp -c TC240109B.cpp -o TC240109B_openmp.ll 
clean:
	rm -f *.o
	rm -f a.out
	rm -f *.ll