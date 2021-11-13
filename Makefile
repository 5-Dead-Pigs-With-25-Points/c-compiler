PROGRAM = parser

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
	rm -rf $(OBJS) $(PROGRAM) *.tab.cpp *.flex.cpp *.tab.h
