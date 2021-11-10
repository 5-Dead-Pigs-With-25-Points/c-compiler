grammar.o: grammar.y lexical.l
	bison -d bison -d grammar.y
	flex lexical.l
	g++ -o $@ grammar.tab.c lex.yy.c -lfl
