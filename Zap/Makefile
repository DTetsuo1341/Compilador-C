CXX    = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LEX    = flex
BISON  = bison
 
TARGET = zap
 
#  Fuentes manuales 
SRCS = ast.cpp SemanticAnalyzer.cpp tac_generator.cpp main.cpp
 
#  Fuentes generadas por flex/bison 
GEN_C = lex.yy.c parser.tab.c
 
#  Objetos 
OBJS  = $(SRCS:.cpp=.o) lex.yy.o parser.tab.o
 
all: $(TARGET)
 
#  1. Bison genera parser.tab.c y parser.tab.h 
parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y
 
#  2. Flex genera lex.yy.c (necesita los tokens de parser.tab.h) 
lex.yy.c: lexer.l parser.tab.h
	$(LEX) lexer.l
 
#  3. Compilar archivos generados (sin -Wall para no spamear warnings) 
lex.yy.o: lex.yy.c
	$(CXX) $(CXXFLAGS) -Wno-unused-function -c lex.yy.c -o lex.yy.o
 
parser.tab.o: parser.tab.c parser.tab.h
	$(CXX) $(CXXFLAGS) -c parser.tab.c -o parser.tab.o
 
#  4. Compilar fuentes propias 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
#  5. Linkear 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) -lfl
 
#  Utilidades 
clean:
	rm -f $(OBJS) lex.yy.c parser.tab.c parser.tab.h $(TARGET) *.fis25
 
.PHONY: all clean
 
