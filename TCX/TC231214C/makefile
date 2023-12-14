a.out: test.o main.o
	gcc -o $@ $^ -std=c99
test.o:
	g++ -c TC231214C.c -o test.o
main.o:
	gcc -c main.c

clean:
	rm -f *.o
	rm -f a.out