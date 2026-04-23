# Zap

Minimalist programming language with keywords of at most 3 characters. Implemented with Flex + Bison in C++.

Developed as Practice 6 for the Compilers Lab — UNAM Faculty of Sciences, 2026-2.

---

## Project structure

```
.
├── lexer.l          # Lexical analyzer (Flex)
├── parser.y         # Syntactic and semantic analyzer (Bison)
├── ast.h            # AST definition and NodeKind enum
├── ast.cpp          # AST implementation
└── test.zap         # Sample program
```

---

## Build

```bash
bison -d parser.y
flex lexer.l
g++ -o zap ast.cpp lex.yy.c parser.tab.c
```

---

## Usage

```bash
./zap < test.zap
```

On success, prints the AST to stdout and generates `ast.dot`.  
On error, reports the line where it occurred.

To visualize the AST:

```bash
dot -Tpng ast.dot -o ast.png
```

---

## The language

### Primitive types

| Keyword | Type    |
|---------|---------|
| `int`   | integer |
| `flt`   | float   |
| `str`   | string  |
| `bl`    | boolean |

### Reserved keywords

| Keyword | Meaning  |
|---------|----------|
| `fn`    | function |
| `rt`    | return   |
| `if`    | if       |
| `ei`    | else if  |
| `el`    | else     |
| `wh`    | while    |
| `fo`    | for      |
| `pr`    | print    |
| `rd`    | read     |
| `T`     | true     |
| `F`     | false    |

### Example

```zap
# Computes the factorial of n
fn factorial(int n) {
    if (n <= 1) {
        rt 1;
    } el {
        rt n * factorial(n - 1);
    }
}

int x = 5;
pr(factorial(x));
```

---

## Errors

The lexer reports errors with color and line number:

```
Lexic Error: unknown character '@' at line 7
```

The parser reports syntax errors:

```
Syntax error: unexpected ASSIGN, expecting ID at line 40
```