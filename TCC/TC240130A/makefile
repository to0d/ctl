
CPPFLAGS =-g -gdwarf-4 -shared -fPIC `llvm-config --cxxflags --ldflags --libs` -Wno-unused-command-line-argument

mypass.so: TC240130A.o hpcc_dfg_util.o hpcc_dot_util.o
	`llvm-config --bindir`/clang++ $(CPPFLAGS) -o mypass.so TC240130A.o hpcc_dfg_util.o hpcc_dot_util.o

hpcc_dfg_util.o: hpcc_dfg_util.cpp 
	`llvm-config --bindir`/clang++ $(CPPFLAGS) -o hpcc_dfg_util.o -c hpcc_dfg_util.cpp 

hpcc_dot_util.o: hpcc_dot_util.cpp 
	`llvm-config --bindir`/clang++ $(CPPFLAGS) -o hpcc_dot_util.o -c hpcc_dot_util.cpp 

TC240130A.o: TC240130A.cpp
	`llvm-config --bindir`/clang++ $(CPPFLAGS) -o TC240130A.o -c TC240130A.cpp 

clean:
	rm -f *.so
	rm -f *.o
	rm -f *.dot