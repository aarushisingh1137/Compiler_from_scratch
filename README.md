The following instructions should be followed to run the compiler.
Modify tes.aaru to give own inputs.
g++ src/main.cpp src/lexer.cpp src/parser.cpp src/ast_printer.cpp src/evaluator.cpp src/codegen.cpp -Iinclude -o compiler
./compiler test.aaru
./program
echo $?

<img width="1432" height="601" alt="image" src="https://github.com/user-attachments/assets/511055aa-8afe-4ad6-950b-f9f4b383c7c3" />



# AaruLang Compiler

AaruLang is a simple compiler built from scratch in C++ that translates a custom programming language into x86-64 assembly and produces executable programs.

The project was developed as a learning exercise to understand how compilers work internally, including lexical analysis, parsing, abstract syntax trees, interpretation, symbol tables, and code generation.

---

## Features

### Language Features

* Integer literals
* Arithmetic expressions

  * `+`
  * `-`
  * `*`
  * `/`
* Parentheses
* Variables
* Assignment statements
* Multiple statements separated by semicolons

Example:

```text
x = 5;
y = x * 2;
y + 1;
```

---

## Compiler Pipeline

```text
Source Code
     ↓
Lexer
     ↓
Tokens
     ↓
Parser
     ↓
Abstract Syntax Tree (AST)
     ↓
Code Generator
     ↓
x86-64 Assembly
     ↓
Executable Program
```

---

## Project Structure

```text
include/
│
├── token.hpp
├── lexer.hpp
├── parser.hpp
├── ast.hpp
├── ast_printer.hpp
├── evaluator.hpp
└── codegen.hpp

src/
│
├── main.cpp
├── lexer.cpp
├── parser.cpp
├── ast_printer.cpp
├── evaluator.cpp
└── codegen.cpp
```

---

## Implemented Components

### Lexer

Converts source code into tokens.

Supported tokens:

* Numbers
* Identifiers
* Assignment operator (`=`)
* Arithmetic operators (`+ - * /`)
* Parentheses
* Semicolons

Example:

Input:

```text
x = 5 + 3;
```

Output:

```text
Identifier(x)
Assign
Number(5)
Plus
Number(3)
Semicolon
```

---

### Parser

Implemented using Recursive Descent Parsing.

Supports operator precedence:

```text
Parentheses
    ↓
* /
    ↓
+ -
    ↓
Assignment
```

Example:

```text
(2 + 3) * 4
```

AST:

```text
      *
     / \
    +   4
   / \
  2   3
```

---

### Abstract Syntax Tree

Implemented nodes:

* NumberExpr
* VariableExpr
* BinaryExpr
* AssignmentExpr
* Program

Example:

```text
x = 5;
x + 2;
```

AST:

```text
Program
│
├── AssignmentExpr(x)
│
└── BinaryExpr(+)
```

---

### Evaluator

An interpreter used to execute the AST directly.

Supports:

* Variable storage
* Symbol tables
* Arithmetic evaluation
* Assignment execution

Example:

```text
x = 5;
x + 2;
```

Result:

```text
7
```

---

### Code Generator

Generates x86-64 assembly.

Features:

* Stack-frame based variable storage
* Automatic variable allocation
* Arithmetic code generation
* Assignment code generation
* Variable loading and storing

Example generated assembly:

```asm
mov rax, 5
mov [rbp-8], rax

mov rax, [rbp-8]
push rax

mov rax, 2
pop rbx

add rax, rbx
```

---

## Building

Compile the compiler:

```bash
g++ src/main.cpp \
   src/lexer.cpp \
   src/parser.cpp \
   src/ast_printer.cpp \
   src/evaluator.cpp \
   src/codegen.cpp \
   -Iinclude \
   -o compiler
```

---

## Usage

Create a source file:

```text
test.aaru
```

```text
x = 5;
y = x * 2;
y + 1;
```

Run the compiler:

```bash
./compiler test.aaru
```

The compiler will:

1. Read the source file
2. Generate assembly
3. Write `output.s`
4. Build an executable named `program`

Run the generated executable:

```bash
./program
echo $?
```

Output:

```text
11
```

---

## Example

Source:

```text
x = 5;
x + 2;
```

Generated result:

```text
7
```

Generated assembly:

```asm
mov rax, 5
mov [rbp-8], rax

mov rax, [rbp-8]
push rax
mov rax, 2
pop rbx
add rax, rbx
```

---

## Future Improvements

* Comparison operators (`<`, `>`, `==`, `!=`)
* If statements
* While loops
* Functions
* Better error handling
* Register allocation
* Optimization passes
* Direct machine-code generation

---

## Learning Goals

This project was built to understand:

* Compiler architecture
* Recursive descent parsing
* Abstract syntax trees
* Symbol tables
* Code generation
* x86-64 assembly
* Executable creation on Linux

---

Built in C++ on Ubuntu (WSL) using VS Code.

