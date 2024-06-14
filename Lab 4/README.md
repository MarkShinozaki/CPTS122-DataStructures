# Lab 4: More Practice with Pointers, Lists, and Stacks in C



## I. Learner Objectives

**At the conclusion of this programming assignment, participants should be able to:**

- Compare and contrast dynamic linked lists and dynamic stacks
- Distinguish between various types of pointers
- Dive deeper into the `<string.h>` library and describe the purpose of `memset()`, `memcpy()`, `memcmp()`, and `memchr()`

## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose a small C language program
- Create test cases for a program
- Apply and implement structs in C
- Apply and implement pointers in C
- Apply and implement dynamic memory in C
- Design and implement a dynamic singly linked list
- Design and implement a dynamic linked stack

## III. Overview & Requirements
**This lab will allow you to further explore pointers and memory, linked lists, and stacks.**

**Tasks:**
1. Given the following fragment of C code, answer the provided questions. If necessary, you could copy and paste the code into Visual Studio to answer the questions.

```c
int n1 = 10, n2 = 42, list[] = {6, 8, 42, 3, 2, 2, -6};

int * const p1 = &n1;
const int *p2 = &n1;
int * p3 = list;
const int * const p4 = NULL;

n1 = 15;
*p1 = 25;
p1 = &n2;
p2 = &n2;
*p2 = 15;
p3[4] = 67;
p4 = &n2;
list = p4;
```

**a. Is there any discernible difference between the declared types for p1 and p2 on lines 2 and 3?**

**Answer:** `Yes, p1 is a constant pointer to an integer, meaning the pointer itself cannot change but the value it points to can be changed. p2 is a pointer to a constant integer, meaning the pointer can change but the value it points to cannot be changed.`

**b. Is the assignment operation on line 6 legal?**

**Answer:** `Yes, assigning a new value to n1 is legal.`

**c. Is the assignment operation on line 7 legal?**

**Answer:** `Yes, *p1 = 25 is legal because p1 is a constant pointer to an integer, so the value it points to can be modified.`

**d. Is the assignment operation on line 8 legal?**

**Answer:** `No, p1 = &n2 is illegal because p1 is a constant pointer and its address cannot be changed.`

**e. Is the assignment operation on line 9 legal?**

**Answer:** `Yes, p2 = &n2 is legal because p2 is a pointer to a constant integer and its address can be changed.`

**f. Is the assignment operation on line 10 legal?**

**Answer:** `No, *p2 = 15 is illegal because p2 points to a constant integer and its value cannot be changed.`

**g. Is the assignment operation on line 11 legal?**

**Answer:** `Yes, p3[4] = 67 is legal because p3 is a pointer to an integer array and the array elements can be modified.`

**h. Is the assignment operation on line 12 legal?**

**Answer:** `No, p4 = &n2 is illegal because p4 is a constant pointer to a constant integer and its address cannot be changed.`

**i. Is the assignment operation on line 13 legal?**

**Answer:** `No, list = p4 is illegal because list is an array and arrays cannot be assigned new addresses.`

2. Complete the implementation for the following function. The function should allocate space on the heap for the given string parameter, and copy (use strncpy()) the string (pStr), including the null character to the heap. The function should return NULL if memory could not be allocated; otherwise it should return a pointer to the beginning of the allocated block of memory on the heap.

```c
char *copyStrToHeap(char *pStr) {
    if (pStr == NULL) {
        return NULL;
    }
    size_t len = strlen(pStr) + 1;
    char *heapStr = (char *)malloc(len);
    if (heapStr == NULL) {
        return NULL;
    }
    strncpy(heapStr, pStr, len);
    return heapStr;
}
```
3. Examine the following standard library functions, which are located in `<string.h>`. As you examine each one at the provided URL, please run the code examples in the C++ shell (click on the gear next to the example code).
- `memset()` - [memset](http://www.cplusplus.com/reference/cstring/memset/)
- `memcpy()` - [memcpy](http://www.cplusplus.com/reference/cstring/memcpy/)
- `memcmp()` - [memcmp](http://www.cplusplus.com/reference/cstring/memcmp/)
- `memchr()` - [memchr](http://www.cplusplus.com/reference/cstring/memchr/)
  
Could you apply each one, independent of the provided code examples? Could you replace the `strncpy()` operation in Task 2 with `memcpy()`? Could you use `memcpy()` to copy structs?

**Answer:**

- `memset()` is used to fill a block of memory with a particular value.
- `memcpy()` is used to copy a block of memory from one location to another.
- `memcmp()` is used to compare two blocks of memory.
- `memchr()` is used to locate the first occurrence of a value in a block of memory.

Yes, you could replace the `strncpy()` operation in Task 2 with `memcpy()` since both functions copy memory, and yes, `memcpy()` can be used to copy structs.

4. Implement the following problems:

### Merging Two Linked Lists

```c
typedef struct node {
    int data;
    struct node *next;
} Node;

Node* mergeLists(Node *list1, Node *list2) {
    Node *mergedList = NULL, **lastPtrRef = &mergedList;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            *lastPtrRef = list1;
            list1 = list1->next;
        } else {
            *lastPtrRef = list2;
            list2 = list2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    *lastPtrRef = (list1 == NULL) ? list2 : list1;
    return mergedList;
}
```
### Detecting a Loop in a Linked List

```c
int detectLoop(Node *head) {
    Node *slowPtr = head, *fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            return 1;
        }
    }
    return 0;
}
```

### Reversing a Linked List 

```c
Node* reverseList(Node *head) {
    Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
```

### Array vs. Linked Implementation of Lists

**Discuss with your team members:**

- Is it more efficient to delete the last node in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because you can traverse directly to the last node without shifting all elements.

- Is it more efficient to delete the first node in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because only the head pointer needs to be updated without shifting all elements.

- Is it more efficient to delete a node, in general, in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because only the pointers need to be updated.

- Is it more efficient to insert a node at the end, in general, in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because you can directly append the node without shifting elements.

- Is it more efficient to insert a node at the front, in general, in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because you only need to update the head pointer.

- Is it more efficient to insert a node at the end, in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because no shifting is required.

- Is it more efficient to insert a node in the front, in an array or linked implementation of a list?

**Answer:** It is more efficient in a linked list because only the head pointer needs to be updated.

- Is it more efficient to access a node, in general, in an array or linked implementation of a list?

**Answer:** It is more efficient in an array because random access is possible with constant time complexity.

### Solving a Maze

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int row;
    int column;
} Point;

typedef struct stackNode {
    Point data;
    struct stackNode *next;
} StackNode;

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
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%205">Lab 5</a>
</p>


































































