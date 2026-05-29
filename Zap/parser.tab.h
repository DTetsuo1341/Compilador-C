/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TRUE_LIT = 258,                /* TRUE_LIT  */
    FALSE_LIT = 259,               /* FALSE_LIT  */
    INT_LIT = 260,                 /* INT_LIT  */
    FLOAT_LIT = 261,               /* FLOAT_LIT  */
    ID = 262,                      /* ID  */
    STRING_LIT = 263,              /* STRING_LIT  */
    INT = 264,                     /* INT  */
    FLOAT = 265,                   /* FLOAT  */
    STRING = 266,                  /* STRING  */
    ARRAY = 267,                   /* ARRAY  */
    BOOL = 268,                    /* BOOL  */
    FUNCTION = 269,                /* FUNCTION  */
    RETURN = 270,                  /* RETURN  */
    GT = 271,                      /* GT  */
    LT = 272,                      /* LT  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    MULT = 275,                    /* MULT  */
    DIV = 276,                     /* DIV  */
    MOD = 277,                     /* MOD  */
    IF = 278,                      /* IF  */
    ELSIF = 279,                   /* ELSIF  */
    ELSE = 280,                    /* ELSE  */
    WHILE = 281,                   /* WHILE  */
    FOR = 282,                     /* FOR  */
    PRINT = 283,                   /* PRINT  */
    READ = 284,                    /* READ  */
    EQ = 285,                      /* EQ  */
    NEQ = 286,                     /* NEQ  */
    GEQ = 287,                     /* GEQ  */
    LEQ = 288,                     /* LEQ  */
    ASSIGN = 289,                  /* ASSIGN  */
    LBRACE = 290,                  /* LBRACE  */
    RBRACE = 291,                  /* RBRACE  */
    LPAREN = 292,                  /* LPAREN  */
    RPAREN = 293,                  /* RPAREN  */
    LBRACK = 294,                  /* LBRACK  */
    RBRACK = 295,                  /* RBRACK  */
    COMMA = 296,                   /* COMMA  */
    SEMI = 297                     /* SEMI  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    int ival;
    double fval;
    char* sval;
    class Node* nptr;

#line 113 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
