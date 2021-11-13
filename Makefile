PROGRAM = parser
GRAMMARDIR = ./CompiledParser
GRAMMAREXIST = $(shell if [ -d $(GRAMMARDIR) ]; then echo "exist"; else echo "notexist"; fi;)

DEPS = $(shell find ./ -name "*.h")
SRC = $(shell find ./ -name "*.cpp")
OBJS = $(SRC:%.cpp=%.o)
CXX = g++
FLEX = flex
BISON = bison
CXXVER = c++11

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) -std=$(CXXVER) -g
	
run: ./lexical.l ./parser.y

ifeq ($(GRAMMAREXIST), notexist)
	mkdir $(GRAMMARDIR)
endif
	$(BISON) --output="./CompiledParser/parser.tab.cpp" --defines="./CompiledParser/parser.tab.h" ./parser.y
	$(FLEX) --outfile="./CompiledParser/lexer.flex.cpp" ./lexical.l
	sed -i "1i\#include \"../grammar/Nodes.h\"" ./CompiledParser/parser.tab.h

%.o: %.cpp $(DEPS)
	$(CXX) -c $< -o $@ -std=$(CXXVER) -g

clean:
	rm -rf $(GRAMMARDIR) $(OBJS) $(PROGRAM)
