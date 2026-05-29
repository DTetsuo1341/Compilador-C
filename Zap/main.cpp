#include "ast.h"
#include "SemanticAnalyzer.h"
#include "tac_generator.h"
#include <cstdio>
#include <cstring>
#include <iostream>

// Declaraciones externas del parser/lexer generados por Bison/Flex
extern int   yyparse();
extern FILE* yyin;
extern Node* root;

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <input.zap> [-o output.fis25]\n", argv[0]);
        return 1;
    }

    //  Argumentos 
    const char* infile  = argv[1];
    const char* outfile = "output.fis25";

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            outfile = argv[i + 1];
            i++;
        }
    }

    //  1. Abrir archivo fuente 
    FILE* in = fopen(infile, "r");
    if (!in) {
        perror("Error al abrir el archivo de entrada");
        return 2;
    }
    yyin = in;

    //  2. Análisis léxico + sintáctico 
    if (yyparse() != 0) {
        fprintf(stderr, "Fallo en el analisis sintactico.\n");
        fclose(in);
        return 3;
    }
    fclose(in);

    if (!root) {
        fprintf(stderr, "No se genero AST.\n");
        return 4;
    }

    //  3. Análisis semántico 
    SemanticAnalyzer analyzer;
    analyzer.analyze(root);
    analyzer.print_results();

    if (analyzer.has_errors()) {
        fprintf(stderr, "Fallo en el analisis semantico.\n");
        delete root;
        return 5;
    }

    //  4. Generación de código intermedio FIS-25 
    TACGenerator tac;
    tac.generate(root);
    tac.optimize();

    try {
        tac.write(outfile);
        fprintf(stderr, "Codigo intermedio generado: %s\n", outfile);
    } catch (const std::exception& e) {
        fprintf(stderr, "Error al escribir la salida: %s\n", e.what());
        delete root;
        return 6;
    }

    delete root;
    return 0;
}