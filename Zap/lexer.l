%{
#include "ast.h"
#include "parser.tab.h"
#include <string.h>

#define LEX_ERROR(msg) fprintf(stderr, "\033[1;31mLexic Error:\033[0m " msg " '%s' at linea %d\n", yytext, yylineno)

extern int yylineno;
void yyerror(const char *s);
%}

%option noyywrap
%option yylineno


DIGIT      [0-9]
LETTER     [a-zA-Z_]
ALNUM      [a-zA-Z0-9_]

%%
"#"[^\n]*           { /* comentario, ignorar*/}
[ \t\n\r]+          { /* espacios, ignorar*/}

"int"               { return INT; }
"flt"               { return FLOAT; }
"str"               { return STRING; }
"bl"                { return BOOL;}
"arr"               { return ARRAY; }

"if"                { return IF; }
"ei"                { return ELSIF; }
"el"                { return ELSE; }
"wh"                { return WHILE; }
"fo"                { return FOR; }

"fn"                { return FUNCTION; }
"rt"                { return RETURN; }

"pr"                { return PRINT; }
"rd"                { return READ; }

"T"                 { yylval.ival =  1; return TRUE_LIT;}
"F"                 { yylval.ival =  0; return FALSE_LIT;}

{DIGIT}+\.{DIGIT}+  { yylval.fval = atof(yytext); return FLOAT_LIT;}
{DIGIT}+            { yylval.ival = atoi(yytext); return INT_LIT;}

\"[^\"]*\"          { yylval.sval = strdup(yytext); return STRING_LIT;}

"=="                { return EQ; }
"!="                { return NEQ; }
">="                { return GEQ; }
"<="                { return LEQ; }
">"                 { return GT; }
"<"                 { return LT; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }
"="                 { return ASSIGN; }

"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACK; }
"]"                 { return RBRACK; }
","                 { return COMMA; }
";"                 { return SEMI; }

{LETTER}{ALNUM}*    { yylval.sval = strdup(yytext); return ID;}


.  { LEX_ERROR("unknown character"); }
%%