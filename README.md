# Zap Compiler

Compiler for the **Zap** programming language that generates intermediate code for the **FIS-25** architecture. Built in C++ with Flex and Bison, covering lexical analysis, parsing, semantic analysis, and three-address code generation.

---

## Pipeline

```
source.zap  →  Lexer (Flex)  →  Parser (Bison)  →  AST
                                                      ↓
output.fis25  ←  TAC Generator  ←  Semantic Analyzer
```

---

## Requirements

- g++ with C++17 support
- flex
- bison

---

## Build

```bash
make
```

## Usage

```bash
# Outputs to output.fis25
./zap program.zap

# Custom output name
./zap program.zap -o result.fis25

# Clean build artifacts
make clean
```

---

## Project Structure

```
.
├── main.cpp               # Pipeline orchestrator
├── lexer.l                # Lexical analyzer (Flex)
├── parser.y               # Parser (Bison)
├── ast.h / ast.cpp        # Abstract Syntax Tree
├── SemanticAnalyzer.h     # Semantic analyzer + symbol table
├── SemanticAnalyzer.cpp
├── tac.h                  # TAC instruction struct + FIS-25 opcodes
├── tac_generator.h        # Intermediate code generator
├── tac_generator.cpp
├── Makefile
└── examples/
    ├── collatz.zap        # Collatz Conjecture
    ├── primo.zap          # N-th Prime Number
    ├── monte_carlo.zap    # Pi approximation (Monte Carlo)
    ├── kaprekar.zap       # Kaprekar Routine
    └── euclides.zap       # Extended Euclidean Algorithm
```

---

## Examples

| Program | Description | Input | Expected output |
|---|---|---|---|
| `collatz.zap` | Steps to reach 1 | Any positive integer | e.g. `27` → `111` |
| `primo.zap` | N-th prime number | N | e.g. `10` → `29` |
| `monte_carlo.zap` | Pi × 1000 via Monte Carlo | Iteration count | e.g. `5000` → `~3141` |
| `kaprekar.zap` | Steps to reach 6174 | Any 4-digit number | e.g. `1234` → `3087, 8352, 6174` |
| `euclides.zap` | GCD and Bézout coefficients | Two integers a, b | e.g. `35 15` → `gcd=5, x=1, y=-2` |

### Minimal Zap example

```
# Factorial of 5
fn factorial(int n) {
    if (n < 2) {
        rt 1;
    }
    rt n * factorial(n - 1);
}

int resultado = factorial(5);
pr("5! =");
pr(resultado);
```

---

## Compiler Phases

| Phase | Tool | File |
|---|---|---|
| Lexical analysis | Flex | `lexer.l` |
| Parsing | Bison (LALR) | `parser.y` |
| Semantic analysis | C++ | `SemanticAnalyzer.cpp` |
| Code generation | C++ | `tac_generator.cpp` |

---

## Exit Codes

| Code | Meaning |
|---|---|
| `0` | Success |
| `1` | Incorrect usage |
| `2` | Could not open input file |
| `3` | Syntax error |
| `4` | No AST produced |
| `5` | Semantic error |
| `6` | Could not write output file |
