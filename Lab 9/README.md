# Lab 9: Developing a Stack Class Template in C++

## I. Learner Objectives

At the conclusion of this programming assignment, participants should be able to:

  - Design, implement and test a Stack class template in C++
  - Apply an array implementation for a Stack
  - Compare and contrast value classes versus container classes
  - Apply and implement overloaded functions and operators

## II. Prerequisites

- Before starting this programming assignment, participants should be able to:

- Analyze a basic set of requirements for a problem
- Create test cases for a program
- Design, implement and test classes in C++
- Declare and define constructors
- Declare and define destructors
- Compare and contrast public and private access specifiers in C++
- Describe what is an attribute or data member of a class
- Describe what is a method of a class
- Apply and implement overloaded functions
- Distinguish between pass-by-value and pass-by-reference
- Discuss classes versus objects

## III. Overview & Requirements

This lab, along with your TA, will help you navigate through designing, implementing, and testing a Stack class template in C++. It will also help you with understanding how to apply a stack object to an application.

Labs are held in a “closed” environment such that you may ask your TA questions. Please use your TAs knowledge to your advantage. You are required to move at the pace set forth by your TA. Have a great time! Labs are a vital part to your education in Cpts 122 so work diligently.

**Tasks:**

**Part 1: Review Stack Class Template Code in C++**

1. Define what is a stack: What is the purpose of using stacks?

2. Review and discuss the skeleton code with your teammates: Notice that all of the template code is located only in the header (.h) files, sometimes you will see the use of (.hpp) files instead. For this lab, please use the template code in .h files. You will encounter stub functions; these are functions that are partly implemented. You will write the code for the “stubs” in task 2. Are there any questions about the provided code? Make sure you understand the existing implementation before proceeding.

**Part 2: Implement Stack Code in C++**

1. Complete the implementation for each of the "stub" functions (found in the Stack class) and answer the following questions:

- `isEmpty()` - what is the Big-O of this algorithm?
- `push()` - what is the Big-O of this algorithm?
- `pop()` - what is the Big-O of this algorithm?

2. As you complete each function, test it. As part of the project, you will notice that a test class has been provided. Please use this to check your functions work!

**Part 3: Postfix Evaluation with a Stack**

1. Build a function that will complete a postfix evaluation of an expression given input strings using your stack implementation. You will pop elements from the stack and perform the required operations.

2. Algorithm for Evaluating Postfix Expressions

- What is the Big-O of the following algorithm?
  - Let S be an empty stack.
  - If there is no character to read, then the postfix expression is malformed. This error in the input string should be reported and the program should give up on that string.
  - Read the next character and call it c.
  - If c is the symbol '-':
    - If S is empty, the postfix expression is malformed. This error in the input string should be reported and the program should give up on that string.
    - If it has more than one element, then the postfix expression is malformed. This error in the input string should be reported and the program should give up on that string.
    - If it has exactly one element, call it e. The value of the postfix expression is e. Return e.
- If c is a binary operator, call S1 and S2 the top two elements of S:
    - If S does not have at least two elements, the postfix expression is malformed. This error in the input string should be reported and the program should give up on that string.
    - Otherwise, pop elements S1 and S2 from the stack. Then perform the required operation on S2 and S1 (i.e., S1 values below S2 in the prior to the popping).
    - Push the result onto S.

- If c is an operand, push c onto S and go to Step 2.

**Part 4: Convert infix to postfix** 
- Implement the following algorithm: Using your stack class template implementation, create a function that will convert a given infix expression (string) to a postfix expression (string). Assume the input string represents a well-formed infix expression. The stack operator (operator<<) will be helpful.

- See Infix to Postfix for an explanation and example of the algorithm.

---

## Solution 

### Stack Class Template 

**Stack.h**

```c++
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
public:
    Stack();
    bool isEmpty() const;
    void push(const T &value);
    T pop();
    T top() const;

private:
    std::vector<T> mData;
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
bool Stack<T>::isEmpty() const {
    return mData.empty();
}

template <typename T>
void Stack<T>::push(const T &value) {
    mData.push_back(value);
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    T value = mData.back();
    mData.pop_back();
    return value;
}

template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return mData.back();
}

#endif
```

### Postfix Evaluation with Stack 

**PostfixEvaluator.h**

```c++
#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include "Stack.h"
#include <string>

class PostfixEvaluator {
public:
    double evaluate(const std::string &expression);

private:
    bool isOperator(char c) const;
    double applyOperation(char operation, double operand1, double operand2) const;
};

#endif
```

**PostfixEvauluator.cpp**
```c++
#include "PostfixEvaluator.h"
#include <sstream>
#include <stdexcept>

double PostfixEvaluator::evaluate(const std::string &expression) {
    Stack<double> stack;
    std::istringstream tokens(expression);

    std::string token;
    while (tokens >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
            double operand2 = stack.pop();
            if (stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
            double operand1 = stack.pop();
            double result = applyOperation(token[0], operand1, operand2);
            stack.push(result);
        } else {
            std::istringstream value(token);
            double operand;
            value >> operand;
            stack.push(operand);
        }
    }

    if (stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
    double result = stack.pop();
    if (!stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
    return result;
}

bool PostfixEvaluator::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double PostfixEvaluator::applyOperation(char operation, double operand1, double operand2) const {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: throw std::runtime_error("Invalid operator");
    }
}
```

### Test Driver

**main.cpp**

```c++
#include "PostfixEvaluator.h"
#include <iostream>
#include <string>

void testPostfixEvaluation(const std::string &expression) {
    PostfixEvaluator evaluator;
    try {
        double result = evaluator.evaluate(expression);
        std::cout << "The result of evaluating the postfix expression \"" << expression << "\" is: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error evaluating postfix expression \"" << expression << "\": " << e.what() << std::endl;
    }
}

int main() {
    std::string expressions[] = {
        "6 2 + 5 * 8 4 / -",
        "2 3 +",
        "7 8 + 3 2 + /"
    };

    for (const std::string &expression : expressions) {
        testPostfixEvaluation(expression);
    }

    return 0;
}
```








--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%202">Lab 2</a>
</p>
