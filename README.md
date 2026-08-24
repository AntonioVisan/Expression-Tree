# 🌳 Expression Tree

![C++](https://img.shields.io/badge/C%2B%2B-20-blue)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-2026-purple)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Subject](https://img.shields.io/badge/Subject-Data%20Structures-orange)
![Application](https://img.shields.io/badge/Application-Console%20Application-informational)

> A **C++20 implementation of an expression tree for arithmetic expressions**, originally developed for a university **Data Structures** assignment and later refactored into a standalone project, featuring infix-to-postfix conversion, binary expression tree construction, level-order tree traversal, arithmetic expression evaluation, variable value input, input validation, and repeated evaluation using the same expression tree.

## 📖 Overview

This project was originally developed as part of the **Data Structures** university course as an assignment focused on implementing an **expression tree for arithmetic expressions**.

The project implements an expression tree system that reads an arithmetic expression from an external input file, converts the expression from infix notation to postfix notation, constructs the corresponding binary expression tree, displays the tree level by level, and evaluates the expression using user-provided variable values.

The project was developed to practice and demonstrate fundamental **Data Structures and Algorithms concepts in C++**, including binary trees, stacks, postfix expression processing, recursive tree evaluation, dynamic memory management, expression parsing, and tree traversal.

The program reads an arithmetic expression from the external `input.txt` file, processes the expression using operator precedence and parentheses, constructs the corresponding expression tree, and allows the expression to be evaluated repeatedly using different values for its variables.

The main functionality includes:

- reading an arithmetic expression from an external input file
- supporting numeric operands and lowercase alphabetic variables
- supporting the basic arithmetic operators `+`, `-`, `*`, and `/`
- supporting parentheses in arithmetic expressions
- determining operator precedence
- identifying operands and operators
- converting infix expressions to postfix notation
- using `std::stack` during postfix conversion
- constructing a binary expression tree from the postfix expression
- representing operators as internal tree nodes
- representing operands as leaf nodes
- dynamically allocating expression tree nodes
- displaying the expression tree level by level
- extracting all variables from the original expression
- storing variable values using `std::map`
- requesting `double` values for each variable
- evaluating the expression recursively in a bottom-up manner
- reusing the same expression tree for repeated evaluations
- allowing different variable values to be provided for each evaluation
- validating the expression during expression tree construction
- handling invalid menu options
- releasing the dynamically allocated expression tree from memory

The expression tree is a binary tree in which internal nodes contain arithmetic operators and leaf nodes contain operands. Each internal node represents an arithmetic operation performed between the values obtained from its left and right subtrees.

Before constructing the tree, the input expression is converted from **infix notation to postfix notation** using a stack. Operator precedence and parentheses are taken into account during this conversion.

For example, the expression:

```text
4+x*((5-1+2)*3+2*(y-1))
```

is first converted into postfix notation. The postfix representation can then be processed from left to right to construct the corresponding expression tree.

During expression tree construction, operands are pushed onto a stack as individual nodes. When an operator is encountered, the two most recent nodes are removed from the stack and attached as the left and right children of a new operator node. The newly created node is then pushed back onto the stack.

The construction process continues until the complete expression tree has been created. A valid expression must leave exactly one node in the stack, which becomes the root of the expression tree.

The resulting tree can be displayed using a **level-order traversal**, showing the nodes belonging to each tree level. This makes the hierarchical structure of the arithmetic expression visible and demonstrates the relationship between operators and their operands.

Expression evaluation is performed recursively in a **bottom-up manner**. Leaf nodes representing numeric values directly return their corresponding values, while variable nodes retrieve their values from the `std::map` provided during evaluation.

For an operator node, the left and right subtrees are evaluated first. The operator is then applied to the two resulting values.

The variable values are collected before each evaluation using the set of variables extracted from the original expression. Each variable is requested only once per evaluation, and the resulting values are stored in an `std::map<char, double>`.

This allows the same expression tree to be reused for multiple evaluations without rebuilding the tree. For example, the expression:

```text
4+x*((5-1+2)*3+2*(y-1))
```

can be evaluated repeatedly using different values for `x` and `y` while keeping the same expression tree in memory.

The implementation also performs basic validation during expression tree construction. Invalid expressions that do not provide enough operands for an operator or do not result in exactly one final tree node are rejected.

The project was later **refactored and modernized for GitHub**, including English naming conventions, clearer function responsibilities, simplified operator precedence handling, dedicated helper functions for operand and operator detection, improved input validation, variable extraction, reusable variable-based evaluation, and cleaner separation between postfix conversion, expression tree construction, and evaluation.

The final result is a standalone **C++20 console application** that demonstrates how an arithmetic **expression tree** can be implemented using fundamental data structures such as binary trees, stacks, maps, sets, recursion, and dynamic memory management.

## 📚 Original Assignment

The project was originally developed as part of the university **Data Structures** course as an assignment focused on implementing an **arithmetic expression tree**.

### 1. Assignment Requirements

The original assignment requires reading an arithmetic expression from a file, constructing the corresponding **binary expression tree**, displaying the tree level by level, and evaluating the expression using values provided for its variables.

The expression consists of:

- numbers
- variables
- the basic arithmetic operators `+`, `-`, `*`, and `/`
- parentheses

The assignment can be summarized as follows:

> Read an arithmetic expression from a file. Construct the corresponding expression tree, display the tree by levels, request `double` values for the variables, and evaluate the expression. The evaluation step must be repeatable using different variable values while keeping the same expression tree.

### 2. Expression Tree

An **expression tree** is a binary tree used to represent an arithmetic expression.

The assignment specifies that:

- internal nodes contain arithmetic operators
- leaf nodes contain operands
- each internal node represents an arithmetic operation
- the operation is performed using the values obtained from its left and right subtrees

For example, the expression:

```text
(3+1)*7
```

can be represented by the following expression tree:

```text
        *
       / \
      +   7
     / \
    3   1
```

The root contains the multiplication operator, while the left subtree represents `3+1`.

### 3. Expression Evaluation

The expression tree allows the arithmetic expression to be evaluated in a `bottom-up manner`.

This means that the values of the child subtrees are calculated first, and their results are then used by the parent operator.

For the previous example:

```text
        *
       / \
      +   7
     / \
    3   1
```

the evaluation is performed as:

```text
3 + 1 = 4
4 * 7 = 28
```

The result represented by an operator node is therefore obtained from the results of its two child subtrees.

### 4. Infix and Postfix Notation

The assignment suggests using `postfix (Reverse Polish) notation` to construct the expression tree.

An arithmetic expression is initially given in `infix notation`, where operators appear between their operands.

For example:

```text
3+1
```

can be converted to postfix notation:

```text
31+
```

The postfix representation makes it possible to construct the expression tree using a stack.

### 5. Expression Tree Construction

The expression tree can be constructed from the postfix representation using a stack of tree nodes.

The construction process follows these rules:

1. When an operand is encountered, create a new leaf node and push it onto the stack.
2. When an operator is encountered, remove the two top nodes from the stack.
3. Create a new node containing the operator.
4. Use the two removed nodes as the left and right children of the new node.
5. Push the newly created node back onto the stack.

For an operator, the first node removed from the stack becomes the **right child**, while the second node removed becomes the **left child**.

After processing the complete postfix expression, the stack should contain exactly one node. This node is the root of the expression tree.

### 6. Level-Order Tree Display

The assignment requires displaying the expression tree **by levels**.

A level-order traversal visits the tree from top to bottom, processing all nodes from one level before moving to the next level.

For example:

```text
        +
       / \
      4   *
         / \
        x   +
```

can be displayed as:

```text
Level 0: +
Level 1: 4 *
Level 2: x +
```

This traversal can be implemented using a `queue`, since the nodes are processed in breadth-first order.

### 7. Variable Evaluation

The assignment requires requesting values of type `double` for the variables contained in the expression and then evaluating the complete expression.

For example, for:

```text
x*x+y
```

the program can request:

```text
x = 3
y = 5
```

and evaluate:

```text
3*3+5 = 14
```

Variable values are stored separately from the expression tree so that the same tree can be evaluated multiple times.

The implementation uses:

```cpp
std::map<char, double>
```

to associate each variable with its current value.

### 8. Repeated Evaluation

An important requirement of the assignment is that the evaluation step can be repeated using `different values for the variables without reconstructing the expression tree`.

For example, the same expression:

```text
x*x+y
```

can be evaluated as:

```text
x = 3
y = 5
→ 14
```

and then:

```text
x = 4
y = 2
→ 18
```

The expression tree remains unchanged between the two evaluations. Only the variable values are replaced.

This separation allows the tree to represent the structure of the expression independently from the values used during evaluation.

### 9. Original Example

The assignment provides the following arithmetic expression as an example:

```text
4+x*((5-1+2)*3+2*(y-1))
```

The corresponding expression tree contains operators as internal nodes and numeric values or variables as leaf nodes.

The tree reflects the precedence of the arithmetic operations and the grouping introduced by parentheses.

For example, the multiplication involving `x` is represented below the `+` at the root, while the operations inside the parenthesized subexpressions appear deeper in the tree.

The implementation uses this expression as the original input example in `input.txt`.

### 10. Data Structures Required by the Assignment

The assignment is focused on fundamental `tree data structures` and allows the expression tree to be constructed using postfix notation.

The implementation uses:

```cpp
std::stack<char>
```

for converting the infix expression to postfix notation,

```cpp
std::stack<Node*>
```

for constructing the expression tree from the postfix expression, and

```cpp
std::queue<Node*>
```

for displaying the tree level by level.

The expression tree itself is represented using dynamically allocated binary tree nodes.

Each `Node` contains:

- the value stored in the node
- a pointer to the left child
- a pointer to the right child

Operator nodes represent arithmetic operations, while leaf nodes represent numeric operands or variables.

### 11. Assignment Objectives

The original assignment therefore focuses on the following concepts:

- arithmetic expression parsing
- binary expression trees
- infix notation
- postfix notation
- stack-based expression processing
- tree construction
- level-order tree traversal
- queues
- recursive tree evaluation
- bottom-up expression evaluation
- arithmetic operators
- variables and `double` values
- repeated evaluation using the same tree
- dynamic memory management

The final implementation fulfills the original requirement by reading an arithmetic expression from a file, converting it to postfix notation, constructing the corresponding binary expression tree, displaying the tree by levels, and evaluating the expression using variable values provided by the user.

## ✨ Features

- 🌳 Expression Tree Construction
  - Constructs a binary expression tree from an arithmetic expression
  - Represents arithmetic operators using internal tree nodes
  - Represents numeric values and variables using leaf nodes
  - Uses dynamically allocated `Node` objects
  - Connects each operator node to its left and right child nodes
  - Produces a single root node representing the complete expression

- 🧮 Arithmetic Expression Support
  - Supports numeric operands
  - Supports lowercase alphabetic variables
  - Supports addition `+`
  - Supports subtraction `-`
  - Supports multiplication `*`
  - Supports division `/`
  - Supports parentheses
  - Respects standard arithmetic operator precedence

- 🔄 Infix to Postfix Conversion
  - Reads the arithmetic expression in infix notation
  - Converts the expression to postfix notation before constructing the tree
  - Uses `std::stack<char>` to store operators
  - Handles parentheses during conversion
  - Applies the correct precedence between arithmetic operators
  - Produces a postfix representation suitable for tree construction

- 🏗️ Postfix-Based Tree Construction
  - Processes the postfix expression from left to right
  - Creates a tree node for every operand
  - Uses `std::stack<Node*>` to store partially constructed subtrees
  - Creates an operator node when an arithmetic operator is encountered
  - Assigns the first removed node as the right child
  - Assigns the second removed node as the left child
  - Produces the final expression tree when exactly one node remains

- 📊 Level-Order Tree Display
  - Displays the expression tree level by level
  - Uses `std::queue<Node*>` for breadth-first traversal
  - Displays the level number for each group of nodes
  - Shows the hierarchical structure of the expression tree
  - Makes the relationship between operators and operands visible

- 🔢 Expression Evaluation
  - Evaluates the expression recursively using the expression tree
  - Performs evaluation in a bottom-up manner
  - Evaluates child subtrees before applying the parent operator
  - Supports `+`, `-`, `*`, and `/`
  - Converts numeric character operands to their corresponding numeric values
  - Returns the final arithmetic result as a `double`

- 🔤 Variable Handling
  - Detects lowercase alphabetic variables in the input expression
  - Extracts the set of distinct variables before evaluation
  - Uses `std::set<char>` to store unique variables
  - Requests a `double` value for each variable
  - Ensures each variable is requested only once per evaluation

- 🗺️ Variable Value Storage
  - Uses `std::map<char, double>` to associate variables with their values
  - Separates variable values from the expression tree structure
  - Passes the variable values to the tree during evaluation
  - Allows repeated evaluation with different variable values
  - Keeps the expression tree unchanged between evaluations

- 🔁 Repeated Evaluation
  - Allows the same expression to be evaluated multiple times
  - Requests new variable values for each evaluation
  - Reuses the same expression tree for every evaluation
  - Avoids reconstructing the tree when variable values change
  - Supports different results for the same expression based on the provided values

- 📄 Input File Handling
  - Reads the arithmetic expression from the external `input.txt` file
  - Verifies that the input file can be opened
  - Processes the complete arithmetic expression from the input file
  - Uses standard C++ file stream functionality

- 🛡️ Input Validation
  - Detects when the input file cannot be opened
  - Detects invalid expressions during expression tree construction
  - Verifies that enough operands are available for every operator
  - Verifies that exactly one node remains after processing the postfix expression
  - Prevents evaluation when the expression tree could not be constructed
  - Handles invalid menu options

- 🧹 Dynamic Memory Management
  - Allocates expression tree nodes dynamically
  - Connects nodes using left and right child pointers
  - Uses the `Node` destructor to recursively release child nodes
  - Releases the complete expression tree after program execution
  - Prevents the allocated tree from remaining in memory after the program exits

- 🧪 Test Cases
  - Tested with the original assignment expression
  - Tested with expressions containing variables
  - Tested with repeated occurrences of the same variable
  - Tested repeated evaluation using different variable values
  - Tested expressions without variables
  - Tested operator precedence
  - Tested division and multiplication
  - Tested parentheses and nested expressions
  - Tested invalid menu options
  - Verified correct level-order tree construction and expression evaluation

## 🏗️ Application Architecture

The application follows a simple **functional architecture** centered around the **expression tree** and the data structures required to parse arithmetic expressions, construct the binary tree, display it level by level, and evaluate it using user-provided variable values.

The program is implemented using `main.cpp` and the `Node` class defined in `Node.h` and `Node.cpp`, together with the external `input.txt` file containing the arithmetic expression.

The implementation separates the different responsibilities into dedicated functions, making each stage of the expression tree process independently identifiable and easier to understand.

```text
                              main.cpp
                                 │
                                 ▼
                          Read input.txt
                                 │
                                 ▼
                       Arithmetic Expression
                                 │
                                 ▼
                         toPostfix()
                                 │
                                 ▼
                        Postfix Expression
                                 │
                                 ▼
                   buildExpressionTree()
                                 │
                                 ▼
                         Expression Tree
                                 │
                    ┌────────────┴────────────┐
                    │                         │
                    ▼                         ▼
             printByLevels()          getVariables()
                    │                         │
                    ▼                         ▼
             Level-Order Output       Set of Variables
                                              │
                                              ▼
                                     readVariableValues()
                                              │
                                              ▼
                                      Variable Value Map
                                              │
                                              ▼
                                   expressionTree->evaluate()
                                              │
                                              ▼
                                      Expression Result
```

### 🧩 Main Components

- **`Node`**
  - Represents a node in the binary expression tree.
  - Stores the value contained in the node.
  - Stores pointers to the left and right children.
  - Represents both operator nodes and operand nodes.
  - Uses operator characters for internal nodes.
  - Uses numeric characters or variables for leaf nodes.
  - Recursively releases its children through the destructor.
  - Provides the recursive expression evaluation functionality.

- **`getPrecedence()`**
  - Determines the precedence of an arithmetic operator.
  - Assigns the same precedence to `+` and `-`.
  - Assigns a higher precedence to `*` and `/`.
  - Returns `0` for characters that are not supported operators.

- **`isOperand()`**
  - Determines whether a character represents an operand.
  - Supports numeric characters from `0` to `9`.
  - Supports lowercase variables from `a` to `z`.

- **`isOperator()`**
  - Determines whether a character represents a supported arithmetic operator.
  - Supports `+`, `-`, `*`, and `/`.

- **`toPostfix()`**
  - Converts the input arithmetic expression from infix notation to postfix notation.
  - Uses `std::stack<char>` to temporarily store operators.
  - Handles parentheses during the conversion.
  - Applies the correct arithmetic operator precedence.
  - Produces a postfix representation suitable for expression tree construction.

- **`buildExpressionTree()`**
  - Constructs the binary expression tree from the postfix expression.
  - Uses `std::stack<Node*>` to store partially constructed subtrees.
  - Creates leaf nodes for operands.
  - Creates internal nodes for arithmetic operators.
  - Uses the first removed node as the right child.
  - Uses the second removed node as the left child.
  - Verifies that enough operands are available for every operator.
  - Verifies that exactly one node remains after processing the complete postfix expression.

- **`getVariables()`**
  - Extracts the variables contained in the original arithmetic expression.
  - Uses `std::set<char>` to store distinct variables.
  - Ensures that each variable appears only once in the resulting collection.

- **`readVariableValues()`**
  - Requests a `double` value for each variable.
  - Stores the values in an `std::map<char, double>`.
  - Provides the values required during expression evaluation.
  - Requests each distinct variable only once per evaluation.

- **`printByLevels()`**
  - Displays the expression tree level by level.
  - Uses `std::queue<Node*>` for breadth-first traversal.
  - Displays the level number together with the nodes belonging to that level.
  - Makes the hierarchical structure of the expression tree visible.

- **`Node::evaluate()`**
  - Recursively evaluates the expression tree.
  - Performs evaluation in a bottom-up manner.
  - Returns numeric operands directly.
  - Retrieves variable values from the provided `std::map`.
  - Recursively evaluates the left and right subtrees.
  - Applies the arithmetic operator stored in the current node.
  - Returns the final expression result as a `double`.

- **`main()`**
  - Acts as the application entry point.
  - Opens and reads the external `input.txt` file.
  - Converts the expression to postfix notation.
  - Constructs the expression tree.
  - Displays the tree level by level.
  - Extracts the variables from the expression.
  - Provides the evaluation menu.
  - Reads variable values for each evaluation.
  - Evaluates the expression using the same expression tree.
  - Allows repeated evaluations with different variable values.
  - Releases the dynamically allocated expression tree.

### 📦 Data Structures

The implementation uses several STL and custom data structures to support expression tree construction and evaluation:

- **`Node`**
  - Represents a node in the binary expression tree.
  - Contains the node value and pointers to the left and right children.

- **`std::stack<char>`**
  - Used during infix-to-postfix conversion.
  - Temporarily stores arithmetic operators and parentheses.

- **`std::stack<Node*>`**
  - Used during expression tree construction.
  - Stores operands and partially constructed subtrees.

- **`std::queue<Node*>`**
  - Used for level-order traversal of the expression tree.
  - Ensures that nodes are processed from top to bottom.

- **`std::set<char>`**
  - Stores the distinct variables found in the input expression.
  - Automatically prevents duplicate variable entries.

- **`std::map<char, double>`**
  - Associates each variable with its current numeric value.
  - Provides the values required during expression evaluation.

- **`std::string`**
  - Stores the original arithmetic expression.
  - Stores the generated postfix expression.

### 🌳 Expression Tree Model

Each operand is initially represented as a leaf node, while every arithmetic operator becomes an internal node.

For example:

```text
Expression:
(3+1)*7
```

is represented as:

```text
        *
       / \
      +   7
     / \
    3   1
```

The operator nodes determine how the values of their child subtrees are combined.

For an operator node:

```text
          operator
          /      \
     left value  right value
```

the result is calculated by applying the operator to the values obtained from the two child subtrees.

### 🔄 Infix-to-Postfix Flow

The first processing stage converts the original infix expression into postfix notation.

The conversion follows the standard operator precedence rules:

```text
+  -   → precedence 1
*  /   → precedence 2
```

Parentheses are used to explicitly control the order of operations.

Conceptually:

```text
Infix Expression
       │
       ▼
  Operator Stack
       │
       ▼
Postfix Expression
```

The postfix expression can then be processed from left to right to construct the expression tree.

### 🏗️ Tree Construction Flow

The complete expression tree construction process can be represented as:

```text
Input expression
       │
       ▼
Infix-to-postfix conversion
       │
       ▼
Postfix expression
       │
       ▼
Create operand nodes
       │
       ▼
Push nodes onto stack
       │
       ▼
Encounter operator
       │
       ▼
Pop right subtree
       │
       ▼
Pop left subtree
       │
       ▼
Create operator node
       │
       ▼
Push new subtree
       │
       ├── More postfix elements ──► Repeat
       │
       ▼
Single remaining node
       │
       ▼
Expression tree root
```

### 📊 Level-Order Traversal

After the tree has been constructed, the application displays it using a breadth-first traversal.

For example:

```text
        +
       / \
      4   *
         / \
        x   y
```

is displayed as:

```text
Level 0: +
Level 1: 4 *
Level 2: x y
```

The implementation uses `std::queue<Node*>` to process all nodes belonging to the current level before continuing with the next level.

### 🔢 Expression Evaluation Model

Expression evaluation is performed recursively from the leaves toward the root.

For a numeric leaf:

```text
3 → 3.0
```

For a variable leaf:

```text
x → variables['x']
```

For an operator node:

```text
           +
          / \
         A   B
```

the application first evaluates `A` and `B`, then performs:

```text
result = A + B
```

The same approach is used for subtraction, multiplication, and division.

This implements the `bottom-up evaluation` described in the original assignment.

### 🔤 Variable Handling

Variables are extracted from the original expression before the evaluation loop.

For example:

```text
x*x+y
```

produces:

```text
{x, y}
```

The variables are then assigned values using:

```cpp
std::map<char, double>
```

Conceptually:

```text
variable -> value

x -> 3.0
y -> 5.0
```

During evaluation, a variable node retrieves its corresponding value from this map.

### 🔁 Repeated Evaluation Flow

One of the requirements of the assignment is to allow the same expression tree to be evaluated using different variable values.

The application therefore follows this flow:

```text
                    Expression Tree
                           │
              ┌────────────┴────────────┐
              │                         │
              ▼                         ▼
       Variable values 1         Variable values 2
       x = 1, y = 1              x = 2, y = 3
              │                         │
              ▼                         ▼
          evaluate()                evaluate()
              │                         │
              ▼                         ▼
             22                        48
```

The tree itself is constructed only once.

Only the `std::map<char, double>` containing the variable values changes between evaluations.

### 🛡️ Input Validation

The application performs basic validation during input processing and tree construction.

These checks include:

- input file cannot be opened
- an operator is encountered without enough operands
- the postfix expression does not produce exactly one final tree node
- expression tree construction fails
- invalid menu options are entered

When the input file cannot be opened, the application displays:

```text
Could not open input.txt.
```

When the expression cannot be converted into a valid expression tree, the application displays:

```text
Invalid expression.
```

### 📄 Input File

The arithmetic expression is read from the external:

```text
input.txt
```

The original assignment example used by the project is:

```text
4+x*((5-1+2)*3+2*(y-1))
```

This expression contains:

- numeric operands
- variables
- all four supported arithmetic operators
- nested parentheses
- different operator precedence levels

It therefore provides a representative example for the complete expression tree workflow.

### 🧹 Memory Management

The expression tree uses dynamically allocated `Node` objects.

Each node stores pointers to its left and right children.

The `Node` destructor recursively releases the complete tree:

```text
delete root
    │
    ├── delete left subtree
    │       ├── delete children
    │       └── ...
    │
    └── delete right subtree
            ├── delete children
            └── ...
```

Deleting the root therefore releases all nodes belonging to the expression tree.

### 🔄 Application Flow

The complete execution flow is:

```text
main()
  │
  ▼
Read input.txt
  │
  ▼
Convert infix expression to postfix
  │
  ▼
Build expression tree
  │
  ├── Invalid expression ──► Display error and exit
  │
  ▼
Display tree by levels
  │
  ▼
Extract variables
  │
  ▼
Display evaluation menu
  │
  ▼
Read variable values
  │
  ▼
Evaluate expression
  │
  ├── Evaluate again ──────► Read new variable values
  │                           │
  │                           ▼
  │                       Same tree
  │
  ▼
Delete expression tree
  │
  ▼
End program
```

### 🏁 Final Result

The architecture keeps the project **compact, modular, and focused on the expression tree implementation**.

The implementation directly reflects the requirements of the original university assignment while providing clear separation between:

- arithmetic expression parsing
- infix-to-postfix conversion
- expression tree construction
- level-order tree traversal
- variable extraction
- variable value management
- bottom-up expression evaluation
- input validation
- memory management

The result is a standalone **C++20 console application** that demonstrates how an arithmetic **expression tree** can be implemented using fundamental data structures such as binary trees, stacks, queues, maps, sets, recursion, and dynamic memory management.

## 📂 Project Structure

```text
ExpressionTree/
├── .gitignore
├── ExpressionTree.slnx
│
└── ExpressionTree/
    ├── ExpressionTree.vcxproj
    ├── ExpressionTree.vcxproj.filters
    ├── main.cpp
    ├── Node.cpp
    ├── Node.h
    └── input.txt
```

### 📄 Main Files

- **`main.cpp`**
  - Contains the main expression tree implementation.
  - Reads the arithmetic expression from the input file.
  - Converts the expression from infix notation to postfix notation.
  - Builds the binary expression tree from the postfix expression.
  - Extracts the variables contained in the expression.
  - Displays the expression tree level by level.
  - Reads variable values from the user.
  - Evaluates the expression using the constructed tree.
  - Allows repeated evaluations using different variable values.
  - Performs basic expression validation.

- **`Node.h`**
  - Defines the `Node` class used by the expression tree.
  - Stores the value contained in each node.
  - Provides pointers to the left and right child nodes.
  - Declares constructors, setters, getters, tree traversal, and evaluation functionality.

- **`Node.cpp`**
  - Contains the implementation of the `Node` class.
  - Initializes node data and child pointers.
  - Implements the node setters and getters.
  - Implements level-order tree traversal.
  - Implements recursive bottom-up expression evaluation.
  - Implements the recursive destructor used to release the complete expression tree.

- **`input.txt`**
  - Contains the arithmetic expression used as input.
  - The original assignment example used by the project is:
  
    ```text
    4+x*((5-1+2)*3+2*(y-1))
    ```
  
  - The program reads the expression from this file before constructing the expression tree.

- **`ExpressionTree.slnx`**
  - Visual Studio solution file.

- **`ExpressionTree.vcxproj`**
  - Visual Studio C++ project configuration.

- **`ExpressionTree.vcxproj.filters`**
  - Defines how the source files are organized inside Visual Studio.

### 🛠️ Build Files

Visual Studio generates additional files and directories when the project is compiled, such as:

```text
x64/
└── Debug/
    ├── ExpressionTree.exe
    ├── ExpressionTree.pdb
    └── other intermediate build files
```

These files are **build artifacts** and are not part of the source code.

> Build artifacts, Visual Studio intermediate files, executables, debug databases, logs, `.tlog` directories, and other temporary files are excluded from version control through `.gitignore`.

The repository therefore contains only the source files, project configuration, input file, and other files required to build and understand the application.

## 🛠️ Built With

- **C++20** (ISO C++20)
- **Visual Studio 2026**
- **Microsoft C++ Build Tools v145**
- **64-bit build**
- **Binary Expression Tree** for representing the arithmetic expression
- **`std::stack`** for infix-to-postfix conversion and expression tree construction
- **`std::queue`** for level-order tree traversal
- **`std::set`** for storing distinct variables from the expression
- **`std::map`** for associating variables with their `double` values
- **`std::string`** for the input expression and postfix representation
- **`std::ifstream`** for reading the arithmetic expression from `input.txt`
- **Standard Streams** for console input and output
- **Recursive tree traversal** for expression evaluation
- **Dynamic memory management** for expression tree nodes

## ⭐ Highlights

- 🌳 **Expression Tree Construction**
  - Builds a binary expression tree representing the arithmetic expression
  - Creates a leaf node for every numeric operand and variable
  - Creates internal nodes for arithmetic operators
  - Preserves operator precedence and parentheses through postfix conversion
  - Produces a single root node representing the complete expression

- 🔄 **Infix-to-Postfix Conversion**
  - Converts the original arithmetic expression from infix notation to postfix notation
  - Uses `std::stack<char>` to manage operators
  - Handles parentheses correctly
  - Applies standard arithmetic operator precedence
  - Produces a postfix expression suitable for tree construction

- 🏗️ **Postfix-Based Tree Construction**
  - Processes the postfix expression from left to right
  - Uses `std::stack<Node*>` to store operands and partial subtrees
  - Creates operator nodes by combining the two most recent subtrees
  - Correctly assigns left and right children according to postfix evaluation
  - Validates the final tree structure

- 📊 **Level-Order Tree Display**
  - Displays the expression tree level by level
  - Uses `std::queue<Node*>` for breadth-first traversal
  - Displays the level number together with its nodes
  - Makes the hierarchical structure of the arithmetic expression easy to inspect

- 🔢 **Bottom-Up Expression Evaluation**
  - Evaluates the expression recursively from the leaves toward the root
  - Supports `+`, `-`, `*`, and `/`
  - Calculates child subtree results before applying the parent operator
  - Returns the final expression result as a `double`
  - Directly reflects the bottom-up evaluation described in the assignment

- 🔤 **Variable Support**
  - Detects lowercase alphabetic variables from `a` to `z`
  - Extracts distinct variables using `std::set<char>`
  - Requests a `double` value for every variable
  - Stores variable values using `std::map<char, double>`
  - Keeps variable values separate from the expression tree structure

- 🔁 **Repeated Evaluation**
  - Allows the same expression tree to be evaluated multiple times
  - Requests new variable values for every evaluation
  - Reuses the existing expression tree
  - Avoids rebuilding the tree when variable values change
  - Produces different results for the same expression based on the provided values

- 📄 **Input File Handling**
  - Loads the arithmetic expression from the external `input.txt` file
  - Uses `std::ifstream` for file input
  - Processes the expression before constructing the tree
  - Uses the original assignment expression as the default input

- 🛡️ **Input Validation**
  - Detects when `input.txt` cannot be opened
  - Detects invalid expressions during tree construction
  - Verifies that enough operands are available for every operator
  - Verifies that exactly one node remains after processing the postfix expression
  - Handles invalid menu options

- 🧹 **Dynamic Memory Management**
  - Uses dynamically allocated nodes for the expression tree
  - Connects nodes through left and right child pointers
  - Uses a recursive destructor to release the complete tree
  - Ensures that the expression tree is properly deleted after execution

- 🧪 **Test Cases**
  - Tested with the original assignment expression
  - Tested with expressions containing multiple variables
  - Tested with repeated occurrences of the same variable
  - Tested repeated evaluation using different variable values
  - Tested expressions without variables
  - Tested arithmetic operator precedence
  - Tested multiplication and division
  - Tested nested parentheses
  - Tested invalid menu options
  - Verified correct tree construction, level-order display, and expression evaluation

- 📦 **STL Data Structures**
  - `std::stack` for infix-to-postfix conversion
  - `std::stack<Node*>` for expression tree construction
  - `std::queue<Node*>` for level-order traversal
  - `std::set<char>` for distinct variable extraction
  - `std::map<char, double>` for variable value storage
  - `std::string` for the input and postfix expressions

- 🏗️ **Refactored Implementation**
  - English naming throughout the code
  - Consistent `camelCase` naming convention
  - Dedicated helper functions for operands, operators, and precedence
  - Separate functions for postfix conversion and tree construction
  - Separate variable extraction and value input
  - Reusable expression evaluation
  - Improved input and expression validation
  - Modernized C++20 implementation
  - Prepared as a standalone GitHub project

## 🎯 Concepts Demonstrated

- **Arithmetic Expression Trees**
  - Represents arithmetic expressions using binary trees
  - Stores operators in internal nodes
  - Stores numeric operands and variables in leaf nodes
  - Represents the structure and evaluation order of the expression

- **Infix Notation**
  - Processes arithmetic expressions written in standard infix notation
  - Supports `+`, `-`, `*`, `/`, and parentheses
  - Preserves the intended grouping of arithmetic operations

- **Postfix Notation**
  - Converts infix expressions into postfix notation
  - Uses operator precedence to determine the correct processing order
  - Uses parentheses to control the order of operations
  - Provides a convenient representation for expression tree construction

- **Stack-Based Expression Processing**
  - Uses `std::stack<char>` during infix-to-postfix conversion
  - Uses `std::stack<Node*>` during expression tree construction
  - Processes operators and operands according to postfix notation
  - Builds subtrees incrementally until the complete tree is obtained

- **Binary Tree Representation**
  - Uses dynamically allocated `Node` objects
  - Stores the value represented by each node
  - Maintains left and right child pointers
  - Represents both operator nodes and operand nodes
  - Uses operator characters for internal nodes and numeric or variable characters for leaves

- **Level-Order Tree Traversal**
  - Displays the expression tree level by level
  - Uses `std::queue<Node*>` for breadth-first traversal
  - Processes all nodes from one level before continuing to the next
  - Makes the hierarchical structure of the expression visible

- **Bottom-Up Expression Evaluation**
  - Evaluates the expression recursively from the leaves toward the root
  - Evaluates child subtrees before applying the parent operator
  - Supports `+`, `-`, `*`, and `/`
  - Produces the final arithmetic result as a `double`
  - Directly reflects the bottom-up evaluation described in the assignment

- **Variable Handling**
  - Detects lowercase alphabetic variables from `a` to `z`
  - Extracts distinct variables from the original expression
  - Uses `std::set<char>` to store unique variables
  - Requests a `double` value for every variable
  - Separates variable values from the expression tree structure

- **Variable Value Look-Up**
  - Stores variable values using `std::map<char, double>`
  - Associates every variable with its current numeric value
  - Provides variable values during recursive tree evaluation
  - Avoids requesting the same variable multiple times during one evaluation

- **Repeated Expression Evaluation**
  - Reuses the same expression tree for multiple evaluations
  - Allows different values to be assigned to variables
  - Avoids reconstructing the tree when variable values change
  - Demonstrates the separation between expression structure and runtime values

- **Operator Precedence**
  - Assigns equal precedence to `+` and `-`
  - Assigns higher precedence to `*` and `/`
  - Uses precedence during infix-to-postfix conversion
  - Ensures that the resulting expression tree reflects the correct arithmetic order

- **Parentheses Handling**
  - Supports nested parentheses in arithmetic expressions
  - Uses parentheses to override standard operator precedence
  - Removes matching parentheses during postfix conversion
  - Preserves the intended structure of the original expression

- **Input Handling**
  - Reads the arithmetic expression from the external `input.txt` file
  - Uses `std::ifstream` for file input
  - Processes the expression before constructing the tree
  - Detects when the input file cannot be opened

- **Expression Validation**
  - Verifies that enough operands are available when an operator is encountered
  - Detects invalid postfix expressions during tree construction
  - Verifies that exactly one tree remains after processing the complete expression
  - Prevents evaluation when a valid expression tree cannot be constructed
  - Handles invalid menu options

- **Dynamic Memory Management**
  - Allocates expression tree nodes dynamically
  - Connects nodes through left and right child pointers
  - Uses a recursive destructor to release child subtrees
  - Releases the complete expression tree when the root node is deleted

- **STL Data Structures**
  - `std::stack` for infix-to-postfix conversion
  - `std::stack<Node*>` for expression tree construction
  - `std::queue<Node*>` for level-order traversal
  - `std::set<char>` for distinct variable extraction
  - `std::map<char, double>` for variable value storage
  - `std::string` for the original and postfix expressions

- **Algorithmic Complexity**
  - Infix-to-postfix conversion processes the expression in linear time, with each character pushed to and removed from the operator stack at most once
  - Expression tree construction processes the postfix expression in linear time
  - Level-order traversal visits every tree node once
  - Variable extraction visits every character in the original expression once
  - Expression evaluation visits the relevant expression tree nodes once
  - Stack, queue, set, and map operations provide the required data management for each stage

- **Modern C++ Practices**
  - C++20 language standard
  - Range-based `for` loops
  - `const` references to avoid unnecessary copies
  - `const` member functions for read-only getters and evaluation
  - STL containers for structured data management
  - Dedicated helper functions for individual responsibilities
  - Consistent English naming
  - Consistent `camelCase` function naming
  - Constructor initializer lists
  - Explicit management of dynamically allocated resources
  - Clear separation between parsing, tree construction, traversal, and evaluation

## 📊 Test Results

The **Expression Tree** application was manually tested through the console using multiple arithmetic expressions and variable values.

The tests covered the main functionality of the project, including:

- Infix-to-postfix conversion
- Expression tree construction
- Operator precedence
- Parentheses handling
- Level-order tree traversal
- Expression evaluation
- Variable extraction
- Variable value storage
- Repeated evaluation using different variable values
- Expressions without variables
- Division and multiplication
- Invalid menu input

### ✅ Tested Scenarios

| Test | Scenario | Result |
|---|---|---|
| **Test 1** | Original assignment expression with variables | ✅ Passed |
| **Test 2** | Original expression evaluated with different variable values | ✅ Passed |
| **Test 3** | Invalid menu option followed by a valid evaluation | ✅ Passed |
| **Test 4** | Simple expression without variables | ✅ Passed |
| **Test 5** | Expression containing division and multiplication | ✅ Passed |

### 🌳 Test Case 1 — Original Assignment Expression

Input:

```text
4+x*((5-1+2)*3+2*(y-1))
```

The application generated the following expression tree when displayed level by level:

```text
Level 0: +
Level 1: 4 *
Level 2: x +
Level 3: * *
Level 4: + 3 2 -
Level 5: - 2 y 1
Level 6: 5 1
```

The expression tree correctly represents the structure and precedence of the original arithmetic expression.

The application then requested values for the variables:

```text
Enter a value for variable x: 1
Enter a value for variable y: 1
Expression result: 22
```

A second evaluation was performed using different values without rebuilding the tree:

```text
Enter a value for variable x: 2
Enter a value for variable y: 3
Expression result: 48
```

This verifies the main requirement of the assignment: `the same expression tree can be evaluated repeatedly using different variable values`.

### 🔁 Test Case 2 — Repeated Evaluation

The expression tree was evaluated multiple times with different values for `x` and `y`.

For:

```text
x = 3
y = 5
```

the application produced:

```text
Expression result: 14
```

For:

```text
x = 4
y = 2
```

the application produced:

```text
Expression result: 18
```

The tree remained unchanged between evaluations.

This confirms that variable values are stored separately from the expression tree and that the same tree can be reused for subsequent evaluations.

### 🛡️ Test Case 3 — Invalid Menu Option

The application was tested with an invalid menu option:

```text
Choose an option: 3
Invalid option. Choose 1 or 2.
```

The program then continued normally and allowed the expression to be evaluated:

```text
Choose an option: 1
Enter a value for variable x: 3
Enter a value for variable y: 5
Expression result: 14
```

This verifies that invalid menu input does not terminate the application and that the evaluation loop continues correctly.

### 🔢 Test Case 4 — Expression Without Variables

Input:

```text
3+4*2
```

The generated tree was:

```text
Level 0: +
Level 1: 3 *
Level 2: 4 2
```

The expression was then evaluated without requesting any variable values:

```text
Expression result: 11
```

This verifies that numeric-only expressions are handled correctly and that standard operator precedence is respected:

```text
4 * 2 = 8
3 + 8 = 11
```

### ➗ Test Case 5 — Division and Multiplication

Input:

```text
8/2*3+4
```

The generated tree was:

```text
Level 0: +
Level 1: / *
Level 2: 8 2 3 4
```

The application produced:

```text
Expression result: 16
```

This verifies that division and multiplication are correctly represented in the expression tree and evaluated according to their precedence.

### 📋 Test Summary

| Test | Scenario | Expected Result | Result |
| --- | --- | --- | --- |
| **Test 1** | Original assignment expression | Correct tree and evaluation | ✅ Passed |
| **Test 2** | Repeated evaluation with different `x` and `y` values | Same tree reused with different results | ✅ Passed |
| **Test 3** | Invalid menu option | Display error and continue execution | ✅ Passed |
| **Test 4** | Expression without variables | Correct numerical result | ✅ Passed |
| **Test 5** | Division and multiplication | Correct precedence and result | ✅ Passed |

> **Result:** All tested scenarios passed successfully. The tests verify the core functionality of the Expression Tree application, including infix-to-postfix conversion, binary expression tree construction, level-order traversal, operator precedence, variable handling, bottom-up evaluation, repeated evaluation using the same tree, and basic input validation. 

## 📋 Requirements

- Windows 10 / Windows 11
- Visual Studio 2026
- Microsoft C++ Build Tools v145
- C++20 (ISO C++20)
- 64-bit build environment

> Developed and tested using **Visual Studio 2026** with the **Microsoft C++ Build Tools v145** toolset, **C++20 (ISO C++20)**, and a **64-bit build configuration**.

## 🚀 Running

1. Clone the repository.

```bash
git clone <repository-url>
```

2. Open `ExpressionTree.slnx` in `Visual Studio 2026`.

3. Make sure the project is configured with:

- `Microsoft C++ Build Tools v145`
- `C++20 (ISO C++20)`
- `64-bit`

4. Build the solution.

```text
Build → Build Solution
```

or simply press:

```text
Ctrl + Shift + B
```

5. Run the application.

```text
F5
```

or click **Start** in Visual Studio.

### 📄 Input File

The arithmetic expression used by the application is read automatically from:

```text
ExpressionTree/input.txt
```

The program reads the expression from the file before constructing the expression tree.

The original assignment expression used for testing is:

```text
4+x*((5-1+2)*3+2*(y-1))
```

The expression can contain:

- numeric operands
- lowercase variables
- `+`
- `-`
- `*`
- `/`
- parentheses

### 🔄 Infix-to-Postfix Conversion

When the application starts, the expression is first converted from `infix notation` to `postfix notation`.

For example:

```text
3+4*2
```

is converted to:

```text
342*+
```

The conversion uses a `std::stack<char>` to manage operators and applies the standard arithmetic precedence rules.

### 🌳 Expression Tree Construction

The postfix expression is then used to construct the binary expression tree.

The application uses a stack of node pointers:

```cpp
std::stack<Node*>
```

When an operator is encountered:

1. The right subtree is removed from the stack.
2. The left subtree is removed from the stack.
3. A new operator node is created.
4. The two subtrees are attached to the operator node.
5. The resulting subtree is pushed back onto the stack.

After the complete postfix expression has been processed, the remaining node becomes the root of the expression tree.

### 📊 Display the Expression Tree

The constructed expression tree is displayed **level by level** using breadth-first traversal.

For the original assignment expression:

```text
4+x*((5-1+2)*3+2*(y-1))
```

the application produces:

```text
Level 0: +
Level 1: 4 *
Level 2: x +
Level 3: * *
Level 4: + 3 2 -
Level 5: - 2 y 1
Level 6: 5 1
```

This demonstrates the hierarchical structure of the expression tree and satisfies the level-order display requirement from the assignment.

### 🔤 Variable Handling

Before evaluation, the application extracts all distinct lowercase variables from the original expression.

For example:

```text
4+x*((5-1+2)*3+2*(y-1))
```

contains:

```text
x
y
```

The variables are stored using:

```cpp
std::set<char>
```

During each evaluation, the application requests a `double` value for every variable.

The values are stored using:

```cpp
std::map<char, double>
```

For example:

```text
Enter a value for variable x: 2
Enter a value for variable y: 3
```

### 🧮 Expression Evaluation

The expression tree is evaluated recursively in a `bottom-up` manner.

For every operator node:

1. Evaluate left subtree
2. Evaluate right subtree
3. Apply the operator

The supported operators are:

```text
+   Addition
-   Subtraction
*   Multiplication
/   Division
```

For example:

```text
3+4*2
```

is represented as:

```text
    +
   / \
  3   *
     / \
    4   2
```

and evaluated as:

```text
4 * 2 = 8
3 + 8 = 11
```

### 🔁 Repeated Evaluation

The application allows the same expression tree to be evaluated multiple times using different variable values.

After displaying the tree, the program presents the following menu:

```text
Do you want to evaluate the expression with different variable values?
1) Yes
2) No
Choose an option:
```

Selecting:

```text
1
```

requests new variable values and evaluates the existing tree.

For example:

```text
Enter a value for variable x: 1
Enter a value for variable y: 1
Expression result: 22
```

A subsequent evaluation can use:

```text
Enter a value for variable x: 2
Enter a value for variable y: 3
Expression result: 48
```

The expression tree is `not rebuilt` between evaluations. Only the variable values change.

### 🔢 Expression Without Variables

Expressions containing only numeric operands can also be evaluated.

For example:

```text
3+4*2
```

produces:

```text
Level 0: +
Level 1: 3 *
Level 2: 4 2
```

and:

```text
Expression result: 11
```

No variable values are requested because the expression does not contain any variables.

### ➗ Division and Multiplication

The application supports both multiplication and division while respecting their precedence.

For example:

```text
8/2*3+4
```

produces:

```text
Level 0: +
Level 1: / *
Level 2: 8 2 3 4
```

and evaluates to:

```text
Expression result: 16
```

### 🛡️ Input and Error Handling

The application handles several invalid input cases, including:

- missing `input.txt`
- invalid arithmetic expressions
- insufficient operands during tree construction
- invalid menu options

If the input file cannot be opened:

```text
Could not open input.txt.
```

If an invalid expression is detected during tree construction:

```text
Invalid expression.
```

Invalid menu options do not terminate the application:

```text
Choose an option: 3
Invalid option. Choose 1 or 2.
```

The program then continues waiting for a valid option.

### 🔄 Program Flow

The complete execution flow is:

```text
Read input.txt
      │
      ▼
Convert infix expression to postfix
      │
      ▼
Build binary expression tree
      │
      ▼
Validate expression tree
      │
      ▼
Display tree by levels
      │
      ▼
Extract distinct variables
      │
      ▼
Request variable values
      │
      ▼
Evaluate expression bottom-up
      │
      ├──── Evaluate again with new values
      │
      ▼
Delete expression tree
      │
      ▼
End program
```

The application requires no external libraries or runtime dependencies beyond the specified C++ development environment.

## 📄 License

This project is released under the **MIT License**.

See the [LICENSE](LICENSE) file for more details.
