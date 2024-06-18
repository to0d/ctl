#TEST: LLVM IR Compile_ - Create IR manually

a.out: TC231215A.cpp
	clang -o a.out TC231215A.cpp `llvm-config --cxxflags --ldflags --libs` -lstdc++
 
clean:
	rm -f *.out
	rm -f *.ll

