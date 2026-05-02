%{
#include "ast.h"
#include "SemanticAnalyzer.h"
#include <iostream>
#include <string>

extern int yylex();
extern int yylineno;
void yyerror(const char *s);

Node* root; // Raíz del AST
%}

%union {
    int ival;
    double fval;
    char* sval;
    class Node* nptr;
}
%define parse.error verbose

/* Tokens */
%token <ival> TRUE_LIT FALSE_LIT INT_LIT 
%token <fval> FLOAT_LIT
%token <sval> ID STRING_LIT
%token INT FLOAT STRING ARRAY BOOL FUNCTION RETURN
%token GT LT PLUS MINUS MULT DIV MOD
%token IF ELSIF ELSE WHILE FOR
%token PRINT READ
%token EQ NEQ GEQ LEQ
%token ASSIGN LBRACE RBRACE LPAREN RPAREN
%token LBRACK RBRACK COMMA SEMI

/* Tipos de nodos */
%type <nptr> program mixed_list mixed_item function_definition 
%type <nptr> parameter_list parameter type declaration statement_list 
%type <nptr> statement expression if_statement block 
%type <nptr> elsif_list argument_list for_loop assignment

/* Precedencia */
%left EQ NEQ
%left GEQ LEQ GT LT
%left PLUS MINUS
%left MULT DIV MOD  

%%

/* Operaciones relacionadas con el AST */
// Inicio del programa
program:
    mixed_list { root = $1; }
    ;


mixed_list:
    mixed_item { 
        $$ = new Node("Program"); 
        $$->add_child($1); 
    }
    | mixed_list mixed_item { 
        $1->add_child($2); 
        $$ = $1; 
    }
    ;

mixed_item:
    function_definition { $$ = $1; }
    | statement { $$ = $1; }
    ;

function_definition:
    FUNCTION ID LPAREN parameter_list RPAREN block {
        $$ = new Node("Function", "fn " + std::string($2), yylineno);
        if ($4) $$->add_child($4);
        $$->add_child($6);
    }
    ;

parameter_list:
    %empty { $$ = nullptr; }
    | parameter { 
        $$ = new Node("Parameters");
        $$->add_child($1); 
    }
    | parameter_list COMMA parameter {
        if ($1) {
            $1->add_child($3);
            $$ = $1;
        } else {
            $$ = new Node("Parameters");
            $$->add_child($3);
        }
    }
    ;

parameter:
    type ID {
        $$ = new Node("Parameter", std::string($2), yylineno);
        $$->add_child($1);
    }
    ;

type:
    INT { $$ = new Node("Type", "int"); }
    | FLOAT { $$ = new Node("Type", "flt"); }
    | STRING  { $$ = new Node("Type", "str"); }
    | BOOL { $$ = new Node("Type", "bl"); }
    | ARRAY { $$ = new Node("Type", "arr");}
    ;

statement_list:
    statement { 
        $$ = new Node("Statement List"); 
        $$->add_child($1); 
    }
    | statement_list statement { 
        $1->add_child($2); 
        $$ = $1; 
    }
    ;

statement:
    declaration SEMI { $$ = $1; }
    | assignment SEMI { $$ = $1; }
    | expression SEMI { $$ = $1; }
    | if_statement { $$ = $1; }
    | WHILE LPAREN expression RPAREN block {
        $$ = new Node("Loop", "wh", yylineno);
        $$->add_child($3);
        $$->add_child($5);
    }
    | for_loop { $$ = $1; }
    | RETURN expression SEMI {
        $$ = new Node("Return", "rt", yylineno);
        $$->add_child($2);
    }
    ;

declaration:
    type ID ASSIGN expression {
        $$ = new Node("Declaration", std::string($2), yylineno);
        $$->add_child($1);
        $$->add_child($4);
    }
    | type ID {
        $$ = new Node("Declaration", std::string($2), yylineno); 
        $$->add_child($1);
    }
    ;

assignment:
    ID ASSIGN expression {
        $$ = new Node("Assignment", std::string($1), yylineno); 
        $$->add_child($3);
    }
    ;

if_statement:
    IF LPAREN expression RPAREN block elsif_list {
        $$ = new Node("Conditional", "if", $3->linea);
        $$->add_child($3);
        $$->add_child($5);
        if ($6) $$->add_child($6);
    }
    | IF LPAREN expression RPAREN block elsif_list ELSE block {
        $$ = new Node("Conditional", "if", $3->linea);
        $$->add_child($3);
        $$->add_child($5);
        if ($6) $$->add_child($6);
        Node* else_node = new Node("Else", "el");
        else_node->add_child($8);
        $$->add_child(else_node);
    }
    ;

elsif_list:
    %empty { $$ = nullptr; }
    | elsif_list ELSIF LPAREN expression RPAREN block {
        Node* elsif_node = new Node("Else-If", "ei", yylineno);
        elsif_node->add_child($4);
        elsif_node->add_child($6);
        if ($1) {
            $1->add_child(elsif_node);
            $$ = $1;
        } else {
            $$ = new Node("Else-If Branches");
            $$->add_child(elsif_node);
        }
    }
    ;

for_loop:
    FOR LPAREN assignment SEMI expression SEMI assignment RPAREN block {
        $$ = new Node("Loop", "for", yylineno);
        Node* header = new Node("FOR Header");
        header->add_child($3);
        header->add_child($5);
        header->add_child($7);
        $$->add_child(header);
        $$->add_child($9);
    }
    ;

block:
    LBRACE statement_list RBRACE { $$ = $2; }
    | LBRACE RBRACE { $$ = new Node("Empty Block"); }
    ;

expression:
    TRUE_LIT { $$ = new Node("True", std::to_string($1)); }
    | FALSE_LIT { $$ = new Node("False", std::to_string($1)); }
    | INT_LIT  { $$ = new Node("Integer", std::to_string($1)); }
    | FLOAT_LIT { $$ = new Node("Float",  std::to_string($1)); }
    | STRING_LIT { $$ = new Node("String", $1); }
    | ID { $$ = new Node("Identifier", $1, yylineno); }
    | ID LPAREN argument_list RPAREN {
        $$ = new Node("Call", std::string($1), yylineno); 
        if ($3) $$->add_child($3);
    }
    | PRINT LPAREN argument_list RPAREN {
        $$ = new Node("Print", "", yylineno);
        if ($3) $$->add_child($3);
    }
    | READ LPAREN expression RPAREN {
        $$ = new Node("Read", "", yylineno);
        $$ -> add_child($3);
    }
    | expression PLUS expression {
        $$ = new Node("Operation", "+", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression MINUS expression {
        $$ = new Node("Operation", "-", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression MULT expression {
        $$ = new Node("Operation", "*", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression DIV expression {
        $$ = new Node("Operation", "/", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression MOD expression {
        $$ = new Node("Operation", "%", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression EQ expression {
        $$ = new Node("Comparison", "==", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression NEQ expression {
        $$ = new Node("Comparison", "!=", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression GEQ expression {
        $$ = new Node("Comparison", ">=", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression LEQ expression {
        $$ = new Node("Comparison", "<=", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression GT expression {
        $$ = new Node("Comparison", ">", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | expression LT expression {
        $$ = new Node("Comparison", "<", yylineno);
        $$->add_child($1);
        $$->add_child($3);
    }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

argument_list:
    %empty { $$ = nullptr; }
    | expression { 
        $$ = new Node("Arguments");
        $$->add_child($1); 
    }
    | argument_list COMMA expression {
        if ($1) {
            $1->add_child($3);
            $$ = $1;
        } else {
            $$ = new Node("Arguments");
            $$->add_child($3);
        }
    }
    ;

%%

void yyerror(const char *s) {
    std::string msg(s);
    const std::string prefix = "syntax error, ";
    if (msg.rfind(prefix, 0) == 0)
        msg = msg.substr(prefix.size());

    std::cerr << "\033[1;31mSyntax error:\033[0m "
              << msg
              << " at linea " << yylineno
              << std::endl;
}

int main() {
    std::cout << "--- Iniciando Zap Parser ---" << std::endl;
    if (yyparse() == 0) {
        if (root) {
            std::cout << "\n--- Analisis Sintactico Exitoso. Iniciando Analisis Semnatico... ---" << std::endl;
            
            SemanticAnalyzer analyzer;
            analyzer.analyze(root);
            
            analyzer.print_results();
            
            if (!analyzer.has_errors()) { 
                std::cout << "\n--- Decorado AST: ---" << std::endl;
                root->print();
                root->gen_dot("ast.dot");
            }
        }
    }
    return 0;
}