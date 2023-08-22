CPPFLAGS=-I ../include/ctl -g -lfl
x.main.ctl.x: y.tab.o lex.yy.o 
	gcc -o $@ $^ -lstdc++ -lfl	
	mv lex.yy.c lex.yy.c.tmp
	mv y.tab.c  y.tab.c.tmp
	mv y.tab.h  y.tab.h.tmp

lex.yy.o:
	flex example.l
	gcc -g -c lex.yy.c    

y.tab.o:
	byacc -d  example.y
	gcc -g -c y.tab.c
    
clean:
	rm -f *.o
	rm -f *.tmp
	rm -f *.x

