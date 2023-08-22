CPPFLAGS=-I ../include/ctl -g -lfl
x.main.ctl.x: y.tab.o lex.yy.o 
	gcc -o $@ $^ -lstdc++ -lfl	
	mv lex.yy.c lex.yy.c.tmp
	mv y.tab.c  y.tab.c.tmp
	mv y.tab.h  y.tab.h.tmp
	mv y.tab.o  y.tab.o.tmp
	mv lex.yy.o lex.yy.o.tmp

lex.yy.o:
	flex example.flex
	gcc -g -c lex.yy.c    

y.tab.o:
	byacc -d  example.yacc
	gcc -g -c y.tab.c

clean:
	rm -f *.o
	rm -f *.tmp
	rm -f *.x