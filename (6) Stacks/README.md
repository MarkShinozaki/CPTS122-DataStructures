# Basics of a Stack

## What is a Stack?
- A finite sequence of nodes, where only the top node may be accessed.
- Insertions (PUSHes) may only be made at the top and deletions (POPs) may only be made at the top.
  - A stack is referred to as a last-in, first out or LIFO data structure.
  - Consider a pile or "stack" of plates; as you unload your dishwasher, the most recent plate is placed on top of the last plate, etc. as you need a plate, you grab one from the top of the stack.
- A stack is a restricted or constrained list.
- Focus on linked list implementations of stacks.

## The Function-Call Stack
### The Function-Call Stack (1)
- We are aware of the function call stack; it is LIFO.
- Also known as the program-execution stack, run-time stack, program stack, or simply "the stack".
- Works behind the scenes - supports the function call/return mechanism - LIFO.
  - Necessary to track sequence of called functions.

### The Function-Call Stack (2)
- Supports the creation, maintenance, and destruction of each called function's local variables.
- Call stack memory is placed in RAM; monitored closely by CPU.

### The Function-Call Stack (3)
- When a function declares a variable, it is "pushed" onto the stack (dynamic memory is not though).
- Parameters are also passed using the call stack.

## Stack Frames
### Stack Frames (1)
- **Each called function must eventually return control to the calling function**:
```c
void function1(void) // calling function
{
    function2(); // called function
    // after executing function2(),
    // control returns back to function1()
}
```
- The system must track the return address that each called function needs to return control to the calling function - the function-call stack handles this info.

### Stack Frames (2) 
- Each time a function  calls another function, an entry is pushed to the stack.
- THe entry is called the stack frame or activation record, which contains the return address required for the called function to return to the calling function.
- The entry also contains some other information discussed later.

### Stack Frames (3)
- If called function returns, instead of calling another function before returning, then the stack frame for the function call is popped, and control transfers to the return address in the stack frame.
- The information required for the caleld function to return to its caller is always at the rop of the call stack!

### Stack Frames (4) 
- If a called function makes a call to another function, then the stack frame for the new function is pushed to the top of the stack.

## Stack Frames and Local Variables 
### Stack Frames and Local Variables (1)
- Local variables including parameters and variables declared by the function are reserved in the stack frame.
  - These variables need to remain active if a function makes a call to another function and "go away" when the function returns to its caller.
 
### Stack Frames and Local Variables (2)
- Stack Overflow
  - If more function calls occur than can be handled by the finite amount of memeory for the function call-stack, then an error called stack overflow occurs.
  - High potential for this occuring with recursion, on problems that require a lor of recursive steps!
 
## The Heap 
- A region of memory that is not managed for you (unlike with the stack)
- Explicitly deallocate `free()` the memory.

## Struct StackNode 
- **Definition for StackNode**:
```c
typedef struct stackNode {
    char data;
    // self-referential
    struct stackNode *pNext;
} StackNode;
```
## Initializing a Stack 
### Initializing a Stack (1) 
- `InitStack(S)`: Procedure to initialize the stack S to empty.
**Implementation**:
```c
void initStack(StackNode **pStack) {
    // Recall: we must dereference a pointer to retain changes
    *pStack = NULL;
}
```
### Initializing a Stack (2)
- The `intStack()` function is elementary and is not always implemented.
- **We may instead initialize the pointer to the top of the stack with NULL within `main()`**:
```c
int main(void) {
    StackNode *pStack = NULL; // points to stack top
    …
}
```
## Checking for Empty Stack 
### Checking for Empty Stack (1)
- `StackIsEmpty(S) -> b`: Boolean function to return TRUE is S is empty.
**Implementation**:
```c
int isEmpty(StackNode *pStack) {
    int status = 0; // False initially
    if (pStack == NULL) { // The stack is empty
        status = 1; // True
    }
    return status;
}
```
### Checking for Empty Stack (2)
- **Substitute the `int` return type with an enumerated type such as Boolean**:
```c
typedef enum boolean {
    FALSE, TRUE
} Boolean;
```
### Checking for Empty Stack (3)
- **Implementation with Boolean defined**:
```c
Boolean isEmpty(StackNode *pStack) {
    Boolean status = FALSE;
    if (pStack == NULL) {
        status = TRUE;
    }
    return status;
}
```

## Printing Data in Stack 
### Printing Data in Stack (1)
**Implementation**:
```c
void printStackIterative(StackNode *pStack) {
    printf("X -> ");
    while (!isEmpty(pStack)) {
        printf("%c -> ", pStack->data);
        // Get to the next item
        pStack = pStack->pNext;
    }
    printf("NULL\n");
}
```
### Printing Data in Stack (2)
**Recursive Implementation**:
```c
void printStackRecursive(StackNode *pStack) {
    if (!isEmpty(pStack)) { // Recursive step
        printf("| %c |\n", pStack->data);
        printf("   |  \n"); // Trying to imitate link
        printf("   V  \n");
        // Get to the next item
        pStack = pStack->pNext;
        printStackRecursive(pStack);
    } else { // Base case
        printf("NULL\n");
    }
}
```
## Inserting Data into a Stack 
- `Push(S,e)`: Procedure to insert a node with information `e` into `s`; in case `s` is empty, make a node containing `e` the only node in `s` and the current node.
**Consider these basic specifications for stack operations in the future. Here is the code**:
### Inserting Data onto Top of Stack Without Error Checking (1)
```c
void push(StackNode **pStack, char newData) {
    StackNode *pMem = NULL;
    pMem = (StackNode *) malloc(sizeof(StackNode));
    // Initialize the dynamic memory
    pMem->data = newData;
    pMem->pNext = NULL;
    // Insert the new node onto top of stack
    pMem->pNext = *pStack;
    *pStack = pMem;
}
```
- **Does this look similar to `insertAtFront()` for a linked list? The Answer is YES!**

### Inserting Data onto Top of Stack Without Error Checking (2)
- **Define a new function which handles the dynamic allocation and initialization of a node**:
```c
StackNode *makeNode(char newData) {
    StackNode *pMem = NULL;
    pMem = (StackNode *) malloc(sizeof(StackNode));
    // Initialize the dynamic memory
    pMem->data = newData;
    pMem->pNext = NULL;
    return pMem;
}
```
### Inserting Data onto Top of Stack Without Error Checking (3)
- **Reorganize code to use the new function**:
```c
void push(StackNode **pStack, char newData) {
    StackNode *pMem = NULL;
    pMem = makeNode(newData);
    // Insert the new node onto top of stack
    pMem->pNext = *pStack;
    *pStack = pMem;
}
```
### Inserting Data onto Top of Stack With Error Checking (1)
- **Modify code to check for dynamic memory allocation errors, starting with `makeNode()`**:
```c
StackNode *makeNode(char newData) {
    StackNode *pMem = NULL;
    pMem = (StackNode *) malloc(sizeof(StackNode));
    if (pMem != NULL) {
        // Initialize the dynamic memory
        pMem->data = newData;
        pMem->pNext = NULL;
    }
    // Otherwise no memory is available; could use else, but it's not necessary
    return pMem;
}
```
### Inserting Data onto Top of Stack With Error Checking (2)
- **Define a Boolean enumerated type**:
```c
typedef enum boolean {
    FALSE, TRUE
} Boolean; // To be used to indicate success of push()
```
- **Add error checking to `push()`**:
```c
Boolean push(StackNode **pStack, char newData) {
    StackNode *pMem = NULL;
    Boolean status = FALSE; // Assume can’t insert a new node; out of memory
    pMem = makeNode(newData);
    if (pMem != NULL) { // Memory was available
        // Insert the new node onto top of stack
        pMem->pNext = *pStack;
        *pStack = pMem;
        status = TRUE; // Successfully added a node to the stack!
    }
    return status;
}
```
## Removing Data from Top of Stack
### Removing Data from Top of Stack (1)
- Apply defensive design practices and ensure the stack is not empty. If we do not, then the precondition must be that the stack is not empty.
- **This implementation of `pop()` checks for removal errors and doesn't return the data popped from the stack**:
```c
Boolean pop(StackNode **pStack) {
    Boolean status = FALSE;
    StackNode *pTop = NULL;
    if (!isEmpty(*pStack)) { // Stack is not empty; defensive design
        pTop = *pStack; // Temp storage of top of stack
        *pStack = (*pStack)->pNext;
        free(pTop); // Remove the top node
        status = TRUE; // Successfully removed the top node
    }
    return status;
}
```
### Removing Data from Top of Stack (2)
- **This implementation of `pop()` returns the data removed from the top of the stack**:
```c
char pop(StackNode **pStack) {
    StackNode *pTop = NULL;
    char retData = '\0';
    if (!isEmpty(*pStack)) { // Stack is not empty; defensive design
        pTop = *pStack; // Temp storage of top of stack
        retData = (*pStack)->data; // Keep data in top node
        *pStack = (*pStack)->pNext;
        free(pTop); // Remove the top node
    }
    return retData;
}
```

## Retrieving Data from Top of Stack Without Deleting Nodes
- **The `peek()` or `top()` function does not modify the stack; it just returns the data in the top of the stack (it “peeks” at the data)**:
```c
char peek(StackNode *pStack) {
    char retData = '\0';
    if (!isEmpty(pStack)) { // Stack is not empty; defensive design
        retData = pStack->data;
    }
    return retData;
}
```
## Stack Applications 
- Reversing strings
- Checking for palindromes
- Searching for a path in a maze
- Tower of Hanoi
- Evaluating infix expressions
- function call stacks
- Many others...

## Closing Thoughts
- Can you build a driver program to test these functions?
- `push()` for a stack is essentially the same operation as `insertFront()` for a linked list.
- `pop()` is `deleteFront()` for a linked list.
- If you know how to implement a linked list you should be able to implement a stack.
- You can implement a stack without using links; hence, you can use an array as the underlying structure for the stack.
- Continue to discuss why you would use a dynamic linked list instead of a dynamic linked stack and vice versa.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(7)%20Queues">Part 7: Queues</a>
</p>



