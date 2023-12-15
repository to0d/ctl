a.out: TC231215A.cpp
	`llvm-config --bindir`/clang++ -o a.out TC231215A.cpp `llvm-config --cxxflags --ldflags --libs`
 
clean:
	rm -f *.out
	rm -f *.ll

