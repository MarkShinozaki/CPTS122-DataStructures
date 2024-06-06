# Basics of a Queue

## What is a Queue?
- A linear data structure with a finite sequence of nodes, where nodes are removed from the front (head) and nodes are inserted at the back (tail).
- A queue is referred to as a first-in, first-out (FIFO) data structure.
  - Consider a grocery store line; people enter at the back (tail) and the person at the front (head) is always serviced first.
- A queue is also considered a restricted or constrained list.
- Focus on linked list implementations of queues.

## Implementation of Queues in C

### Struct QueueNode
```c
typedef struct queueNode {
    char data;
    // self-referential
    struct queueNode *pNext;
} QueueNode;
```

### Initializing a Queue in C (1)
```c
void initQueue(QueueNode **pHead, QueueNode **pTail) {
    // Recall: we must dereference a pointer to retain changes
    *pHead = NULL; // points to front of queue
    *pTail = NULL; // points to back of queue
}
```
### Initializing a Queue in C (2)
- The `initQueue()` function is elementary and is not always implemented.
- We may instead initialize the pointers to the front and back of the queue with `NULL` within `main()`.

```c
int main(void) {
    QueueNode *pHead = NULL; // points to front
    QueueNode *pTail = NULL; // points to back
}
```
### Initializing a Queue in C (3)
- Combine the two pointers (`pHeead` and `pTail`) of a queue into a single struct called `Queue`.
```c
typedef struct queue {
    QueueNode *pHead;
    QueueNode *pTail;
} Queue;
```
- Modify `initQueue()` to accept a `Queue` struct type.
```c
void initQueue(Queue *pQueue) {
    pQueue->pHead = NULL;
    pQueue->pTail = NULL;
}
```
### Checking for Empty Queue in C
#### Checking for Empty Queue (1)
- **Only need to check the head pointer to see if the queue is empty.**
```c
int isEmpty(Queue q) {
    // Condensed the code into one statement; returns 1 if pHead is NULL; 0 otherwise
    return (q.pHead == NULL);
}
```
#### Checking for Empty Queue (2)
- **Substitute the `int` return type with an enumerated type such as Boolean.**
```c
typedef enum boolean {
    FALSE, TRUE
} Boolean;
```
#### Checking for Empty Queue (3)
- **Implementation with Boolean defined.**
```c
Boolean isEmpty(Queue q) {
    Boolean status = FALSE;
    if (q.pHead == NULL) { // Queue is empty
        status = TRUE;
    }
    return status;
}
```
### Printing Data in Queue in C
- **Possible implementation using recursion**
```c
void printQueueRecursive(QueueNode *pHead) {
    if (pHead != NULL) { // Recursive step
        printf("%c ->\n", pHead->data);
        // Get to the next item
        pHead = pHead->pNext;
        printQueueRecursive(pHead);
    } else { // Base case
        printf("NULL\n");
    }
}
```

### Inserting Data into Back of Queue with Error Checking in C
#### Inserting Data into Back of Queue with Error Checking in C (1)
- **Modify code to check for dynamic memory allocation errors, starting with `makeNode()`.**
```c
QueueNode *makeNode(char newData) {
    QueueNode *pMem = NULL;
    pMem = (QueueNode *) malloc(sizeof(QueueNode));
    if (pMem != NULL) {
        // Initialize the dynamic memory
        pMem->data = newData;
        pMem->pNext = NULL;
    }
    // Otherwise no memory is available; could use else, but it's not necessary
    return pMem;
}
```
#### Inserting Data into Back of Queue with Error Checking in C (2)
- **Add some error checking to `enqueue()`.**
```c
Boolean enqueue(Queue *pQueue, char newData) {
    QueueNode *pMem = NULL;
    Boolean status = FALSE; // Assume can’t insert a new node; out of memory
    pMem = makeNode(newData);
    if (pMem != NULL) { // Memory was available
        // Insert the new node into the back of the queue
        if (isEmpty(*pQueue)) { // Inserting first node into queue
            pQueue->pHead = pMem;
        } else { // Already at least one node in queue; update tail only
            pQueue->pTail->pNext = pMem;
        }
        pQueue->pTail = pMem;
        status = TRUE; // Successfully added a node to the queue!
    }
    return status;
}
```
### Removing Data from Front of Queue in C
#### Removing Data from Front of Queue in C (1)
- Apply defensive design practices and ensure te queue is not empty
- This implementation of `dequeue()` returns the data in the node at the front of the queue.
```c
char dequeue(Queue *pQueue) {
    char retData = '\0';
    QueueNode *pFront = NULL;
    if (!isEmpty(*pQueue)) { // Stack is not empty; defensive design
        pFront = pQueue->pHead; // Temp storage of front of queue
        retData = pQueue->pHead->data;
        pQueue->pHead = pQueue->pHead->pNext;
        if (pQueue->pHead == NULL) { // Queue is now empty; update tail
            pQueue->pTail = NULL;
        }
        free(pFront); // Remove the front node
    }
    return retData;
}
```
### Queue Applications 
- Operating systems maintain queues of processes that are ready to execute.
- Printers queue print requests; first-come, first serve.
- Simulations of real-world processes, such as movie lines, grocery store lines, etc.

### closing Thoughts 
- Can you build a driver program to test these functions?
- A queue is essentailly a restricted linked list, where one additionl pointer is needed to keep track of the back, tail, or rear of the queue.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(8)%20Trees">Part 8: Trees</a>
</p>


