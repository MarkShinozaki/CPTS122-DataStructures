# Lab 3: Data Structures and Dynamic Linked Stacks in C

## I. Learner Objectives
- At the conclusion of this programming assignment, participants should be able to:
  - Design, implement and test a dynamic stack in C
  - Compare and contrast dynamic linked lists and dynamic stacks
  - Summarize the advantages of applying a stack within certain applications
  - Describe the operations applied to a stack including:
    1. `push()`
    2. `pop()`
    3. `top() or peek()`
    4. `isEmpty()`

## II. Prerequisites

**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose a small C language program
- Create test cases for a program
- Apply and implement structs in C
- Apply and implement pointers in C
- Apply and implement dynamic memory in C
- Design and implement a dynamic singly linked list
  
## III. Overview & Requirements

- This lab, along with your TA, will help you navigate through designing, implementing, and testing a dynamic stack. Recall, a stack data structure is a restricted linked list, where only the top node in the stack may be accessed at any given time. A stack is referred to as a last-in, first-out (LIFO) structure as a result of this constraint. Furthermore, the operation of a stack must adhere to this restriction. A `push()` operation adds a node to the top of the stack, a `pop()` operation removes a node from the top of the stack, and a `top()` or `peek()` operation returns the data in the node at the top of the stack. We will visualize a stack in the following way:

```csharp
Copy code
    [top]
    [Item 3]
    [Item 2]
    [Item 1]
     NULL
```

**Tasks:**
1. For the following problem define a stackNode struct with data of type double. Implement the following operations for your stack data structure:

  - `isEmpty()` - a predicate function which checks to see if the stack is empty; returns true if the stack is empty; false otherwise
  - `push()` - inserts a node, with a double precision value, to the top of the stack; the node is allocated dynamically; the double precision value should be passed in as an argument, along with a double pointer to the top of the stack
  - `pop()` - deletes a node from the top of the stack; accepts a double pointer to the top of the stack; does not return a value; this function should only be called after isEmpty() is called
  - `top()` or peek() - returns the data in the node at the top of the stack; does not modify the stack

2. Test your application. In the same project, create one more header file `testStack.h` and source file `testStack.c` (for a total of at least five files). The `testStack.h` file should contain function prototypes for test functions you will use on your stack functions. The testStack.c source file should contain the implementations for these test functions. You will be designing and implementing unit tests. You will have at least one test function per application function. For example, you will have an application function called `push()` (or a function very similar) that is used to insert a node on the top of the stack. In this task, you will need to create a test function called `testPush()` that passes in various double precision data directly into `push()` to see if it works correctly. Your test should check to see that the top node has the correct value. Does the top pointer change?

3. Tower of Hanoi: A very popular mathematical game or puzzle is referred to as the Tower of Hanoi. The idea behind the game is to find an efficient method for moving disks between three posts. Each disk has a different diameter, but all of them can be placed on the available posts.

   **The goal of the game is to move all of the disks from one post to another according to the following rules:**
   
     - Only one disk may be transferred at a time
     - Only the top disk on any post may be accessed at a given time
     - No disk may be placed on top of a smaller disk at any point

At the start of the game, all of the disks must originally be placed such that the largest disk is on the bottom of the stack of one post, and the smallest is on the top of the stack on the same post. The disks should form a cone shape. Write a program to simulate the Tower of Hanoi game. For each move print the post number (1 - 3) from which the disk is taken, the diameter of the disk, and the resulting post on which the disk is placed. Also, show the current diameter of the disks on each post. You must use stacks to solve this problem! Initially start with three disks in your game. Note: if you visit Tower of Hanoi Animation, you will find an animation of how Tower of Hanoi should run.

4. Maze: Generate a maze with a start to end path. The maze may be represented by a two-dimensional array of integers, where a wall may be represented by a 0 and a door may be represented by a 1. Find a path in your maze by using a stack. Modify your `stackNode` to store `Point` data for a path in a maze. A `Point` should be defined as a struct with `row` and `column` fields. Whenever a fork in the maze is encountered, store the coordinates of the fork on the stack. If the current path does not provide a path to the end of the maze, then the last forking point can be popped and a different path may be taken. This is called backtracking.

## Solution Implementation 
### Stack Data Structure

**stack.h**
```c
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    double data;
    struct stackNode *next;
} StackNode;

typedef struct point {
    int row;
    int column;
} Point;

// Stack function prototypes
int isEmpty(StackNode *top);
void push(StackNode **top, double value);
void pop(StackNode **top);
double top(StackNode *top);

#endif
```

**stack.c**
```c
#include "stack.h"

int isEmpty(StackNode *top) {
    return top == NULL;
}

void push(StackNode **top, double value) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = *top;
        *top = newNode;
    } else {
        printf("No memory available to push data\n");
    }
}

void pop(StackNode **top) {
    if (isEmpty(*top)) {
        printf("Stack is empty, cannot pop\n");
    } else {
        StackNode *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

double top(StackNode *top) {
    if (isEmpty(top)) {
        printf("Stack is empty, no top element\n");
        return -1; // Assuming all data is non-negative; change accordingly if data can be negative
    } else {
        return top->data;
    }
}
```
### Testing the Stack 

**testStack.h**
```c
#ifndef TESTSTACK_H
#define TESTSTACK_H

void testPush();
void testPop();
void testTop();

#endif
```
**testStack.h**
```c
#include "stack.h"
#include "testStack.h"

void testPush() {
    StackNode *stack = NULL;
    push(&stack, 10.0);
    if (top(stack) == 10.0) {
        printf("Test Push 1 Passed\n");
    } else {
        printf("Test Push 1 Failed\n");
    }

    push(&stack, 20.0);
    if (top(stack) == 20.0) {
        printf("Test Push 2 Passed\n");
    } else {
        printf("Test Push 2 Failed\n");
    }
}

void testPop() {
    StackNode *stack = NULL;
    push(&stack, 10.0);
    push(&stack, 20.0);
    pop(&stack);
    if (top(stack) == 10.0) {
        printf("Test Pop 1 Passed\n");
    } else {
        printf("Test Pop 1 Failed\n");
    }

    pop(&stack);
    if (isEmpty(stack)) {
        printf("Test Pop 2 Passed\n");
    } else {
        printf("Test Pop 2 Failed\n");
    }
}

void testTop() {
    StackNode *stack = NULL;
    if (top(stack) == -1) {
        printf("Test Top 1 Passed\n");
    } else {
        printf("Test Top 1 Failed\n");
    }

    push(&stack, 10.0);
    if (top(stack) == 10.0) {
        printf("Test Top 2 Passed\n");
    } else {
        printf("Test Top 2 Failed\n");
    }
}

int main() {
    testPush();
    testPop();
    testTop();
    return 0;
}
```
### Tower of Hanoi 
**hanoi.c**
```c
#include <stdio.h>

void moveDisk(int n, char fromPeg, char toPeg) {
    printf("Move disk %d from %c to %c\n", n, fromPeg, toPeg);
}

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    if (n == 1) {
        moveDisk(n, fromPeg, toPeg);
        return;
    }
    towerOfHanoi(n - 1, fromPeg, auxPeg, toPeg);
    moveDisk(n, fromPeg, toPeg);
    towerOfHanoi(n - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
```
### Maze Solver 
**maze.h**
```c
#ifndef MAZE_H
#define MAZE_H

typedef struct point {
    int row;
    int column;
} Point;

typedef struct stackNode {
    Point data;
    struct stackNode *next;
} StackNode;

int isEmpty(StackNode *top);
void push(StackNode **top, Point value);
void pop(StackNode **top);
Point top(StackNode *top);
int findPath(int maze[5][5], int rows, int columns);

#endif
```
**maze.c**

```c
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(StackNode *top) {
    return top == NULL;
}

void push(StackNode **top, Point value) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = *top;
        *top = newNode;
    } else {
        printf("No memory available to push data\n");
    }
}

void pop(StackNode **top) {
    if (isEmpty(*top)) {
        printf("Stack is empty, cannot pop\n");
    } else {
        StackNode *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

Point top(StackNode *top) {
    if (isEmpty(top)) {
        Point errorPoint = {-1, -1};
        return errorPoint;
    } else {
        return top->data;
    }
}

int findPath(int maze[5][5], int rows, int columns) {
    StackNode *stack = NULL;
    Point start = {0, 0};
    Point end = {rows - 1, columns - 1};
    Point current = start;
    push(&stack, current);

    while (!isEmpty(stack)) {
        current = top(stack);
        pop(&stack);

        int r = current.row;
        int c = current.column;

        if (r == end.row && c == end.column) {
            printf("Path found\n");
            return 1;
        }

        // Mark current point as part of the path
        maze[r][c] = 2;

        // Move right
        if (c + 1 < columns && maze[r][c + 1] == 1) {
            Point next = {r, c + 1};
            push(&stack, next);
        }

        // Move down
        if (r + 1 < rows && maze[r + 1][c] == 1) {
            Point next = {r + 1, c};
            push(&stack, next);
        }

        // Move left
        if (c - 1 >= 0 && maze[r][c - 1] == 1) {
            Point next = {r, c - 1};
            push(&stack, next);
        }

        // Move up
        if (r - 1 >= 0 && maze[r - 1][c] == 1) {
            Point next = {r - 1, c};
            push(&stack, next);
        }
    }

    printf("No path found\n");
    return 0;
}

int main() {
    int maze[5][5] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1}
    };
    findPath(maze, 5, 5);
    return 0;
}
```

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%204">Lab 4</a>
</p>

















