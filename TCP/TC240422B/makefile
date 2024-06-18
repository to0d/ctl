#TEST: LLVM IR Compile_ - Create IR manually

a.out: TC240422B.cpp
	clang -o a.out TC240422B.cpp `llvm-config --cxxflags --ldflags --libs` -lstdc++
 
clean:
	rm -f *.out
	rm -f *.ll

