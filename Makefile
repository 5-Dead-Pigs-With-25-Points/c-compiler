PROGRAM = parser
PROGRAM1 = ./parser
BUILDFOLDER = build/
BUILDIO = build/io
NASM = nasm

DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./ -name "*.cpp")
OBJS = $(SRC:%.cpp=%.o)
CXX = g++
FLEX = flex
BISON = bison
CXXVER = c++11

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) -std=$(CXXVER) -g
	
run: ./lexical.l ./grammar.y

	$(BISON) --output="./parser.tab.cpp" --defines="./parser.tab.h" ./grammar.y
	$(FLEX) --outfile="./lexer.flex.cpp" ./lexical.l
	sed -i "1i\#include \"./grammar/Nodes.h\"" ./parser.tab.h

%.o: %.cpp $(DEPS)
	$(CXX) -c $< -o $@ -std=$(CXXVER) -g

clean:
	rm -rf $(OBJS) $(PROGRAM) $(BUILDFOLDER) *.tab.cpp *.flex.cpp *.tab.h ./test/*.asm

build:
	$(PROGRAM1) ./test/test.c
	mkdir $(BUILDFOLDER)
	mkdir $(BUILDIO)
	$(NASM) -f elf -d ELF_TYPE grammar/InterMediate/asm_io.asm -o grammar/InterMediate/asm_io.o
	cp $(PROGRAM) $(BUILDFOLDER)
	cp grammar/InterMediate/asm_io.o $(BUILDIO)
	cp grammar/InterMediate/asm_io.inc $(BUILDIO)
	cp -r test/ $(BUILDFOLDER)
	cp example/Makefile $(BUILDFOLDER)
	# $(PROGRAM1) ./test.c
	# $(NASM) -f elf test.asm -o test.o
	# $(CXX) -o test test.o grammar/InterMediate/asm_io.o -m32
