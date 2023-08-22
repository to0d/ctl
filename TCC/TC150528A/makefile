CPPFLAGS=-I ../include/ctl -g -lfl

x.main.ctl.x: main.ctl.o
	gcc -o $@ $^  -lstdc++ -lfl 

main.ctl.o:
	flex example.l
	gcc -g -c lex.yy.c
	mv lex.yy.o main.ctl.o
	mv lex.yy.c lex.yy.c.tmp
    
clean:
	rm -f *.o
	rm -f *.tmp
	rm -f *.x



