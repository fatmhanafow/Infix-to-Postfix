# Infix to Postfix Converter and Evaluator

## Description
This program converts an infix mathematical expression to a postfix expression and evaluates it based on user-provided variable values.

## Features
- Converts infix expressions (e.g., `a+b*(c^d-e)^(f+g*h)-i`) to postfix notation.
- Evaluates the resulting postfix expression.
- Supports basic arithmetic operators: `+`, `-`, `*`, `/`, `^`.
- Allows user input for variable values.

## How to Use
1. Compile the program using a C++ compiler:
   ```sh
   g++ -o infix_to_postfix infix_to_postfix.cpp -std=c++11
   ```
2. Run the executable:
   ```sh
   ./infix_to_postfix
   ```
3. Enter an infix expression when prompted.
4. Provide values for the variables in the expression.
5. View the converted postfix expression and the evaluated result.

## Example Usage
**Input:**
```
Please enter an infix mathematical expression: a+b*c
Please enter the values of the variables:
a: 2
b: 3
c: 4
```

**Output:**
```
Equivalent postfix expression: abc*+
Final result: 14
```

## Requirements
- C++ compiler (e.g., GCC, Clang, MSVC)

## License
This project is open-source and available under the MIT License.

