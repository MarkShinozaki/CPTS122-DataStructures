# Lab 6: Data Structures, Dynamic Linked Queues, and Unit Tests in C++


## I. Learner Objectives

At the conclusion of this programming assignment, participants should be able to:

- Design, implement and test a dynamic queue implemented with a singly linked list in C++
- Compare and contrast dynamic linked lists, dynamic linked stacks, and dynamic linked queues
- Summarize the advantages of applying a queue within certain applications
- Describe the operations applied to a queue including:
  1. **`enqueue()`**
  2. **`dequeue()`**

## II. Prerequisites

Before starting this programming assignment, participants should be able to:

- Analyze a basic set of requirements for a problem
- Compose a small C++ language program
- Create test cases for a program
- Apply and implement classes in C++
- Apply and implement pointers in C/C++
- Apply and implement dynamic memory in C++
- Design and implement a dynamic singly linked list
- Design and implement a dynamic stack implemented with a singly linked list

## III. Overview & Requirements

This lab, along with your TA, will help you navigate through designing, implementing, and testing a dynamic queue implemented with a linked list. Recall, a queue data structure is a restricted linked list, where only the front or head node in the queue may be processed and then removed, at any given time. However, new nodes may be added to the end, back, or tail of the queue. A queue is referred to as a first-in, first-out (FIFO) structure as a result of this constraint. Furthermore, the operations of a queue must adhere to this restriction. An `enqueue()` operation adds a node to the tail of the queue and a `dequeue()` operation removes a node from the head of the queue. We will visualize a queue in the following way:

```
head -> [Item 1] -> [Item 2] -> [Item 3] -> tail -> NULL
```

### Tasks:

1. For the following problem define a class `QueueNode` with data of type `std::string`. Also define a class Queue with two pointers: one for the head and one for the tail. Both pointers are `QueueNode*` types. Implement the following operations for your queue data structure:
  - `isEmpty()` - a predicate function which checks to see if the queue is empty; returns true if the queue is empty; false otherwise
  - `enqueue()` - inserts a node into the queue at the tail; the node is allocated dynamically on the heap using the C++ operator new; returns true if the memory was allocated for a node, false otherwise
  - `dequeue()` - deletes a node from the head of the queue using the C++ operator delete; returns the data in the node; precondition: queue is not empty (isEmpty()) must be called before dequeue() is called
  - `printQueueRecursive()` - recursively prints out the data in the queue
    
You should also consider any constructors/destructors, overloaded operators, and getters/setters that you need.


2. Test your application. In the same project, create one more header file testQueue.h and source file testQueue.cpp (for a total of at least five files). The `testQueue.h` file should contain function prototypes for test functions you will use on your queue functions. The `testQueue.cpp` source file should contain the implementations for these test functions. You will have at least one test function per application function. For example, you will have an application function called `enqueue()` (or a function very similar) that is used to insert a node into the queue at the tail. In this task, you will need to create a test function called `testEnqueue()` that passes in various data directly into `enqueue()` to see if it works as intended. You will also want to test these functions on empty and non-empty queues.

3. Work on the current programming assignment.

## Solution Implementation
### Queue Data Structure 

**QueueNode.h**

```c++
#ifndef QUEUENODE_H
#define QUEUENODE_H

#include <string>

class QueueNode {
public:
    std::string data;
    QueueNode *next;

    QueueNode(const std::string &data) : data(data), next(nullptr) {}
};

#endif
```

**Queue.h**
```c++
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"
#include <iostream>

class Queue {
private:
    QueueNode *head;
    QueueNode *tail;

public:
    Queue();
    ~Queue();

    bool isEmpty() const;
    bool enqueue(const std::string &data);
    std::string dequeue();
    void printQueueRecursive(QueueNode *node) const;
    void printQueue() const;
};

#endif
```

**Queue.cpp**
```c++
#include "Queue.h"

// Constructor
Queue::Queue() : head(nullptr), tail(nullptr) {}

// Destructor
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Check if the queue is empty
bool Queue::isEmpty() const {
    return head == nullptr;
}

// Enqueue operation
bool Queue::enqueue(const std::string &data) {
    QueueNode *newNode = new QueueNode(data);
    if (newNode == nullptr) {
        return false;
    }
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

// Dequeue operation
std::string Queue::dequeue() {
    if (isEmpty()) {
        return "";
    }
    QueueNode *temp = head;
    std::string data = head->data;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    return data;
}

// Print queue recursively
void Queue::printQueueRecursive(QueueNode *node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    printQueueRecursive(node->next);
}

// Wrapper for recursive print
void Queue::printQueue() const {
    printQueueRecursive(head);
    std::cout << std::endl;
}
```

### Testing the Queue 

**testQueue.h**

```c++
#ifndef TESTQUEUE_H
#define TESTQUEUE_H

void testEnqueue();
void testDequeue();
void testIsEmpty();
void testPrintQueue();

#endif
```

**testQueue.cpp**
```c++
#include "Queue.h"
#include "testQueue.h"
#include <iostream>

void testEnqueue() {
    Queue q;
    std::cout << "Enqueue Test:" << std::endl;
    q.enqueue("first");
    q.enqueue("second");
    q.enqueue("third");
    q.printQueue(); // Should print: first second third
}

void testDequeue() {
    Queue q;
    q.enqueue("first");
    q.enqueue("second");
    q.enqueue("third");

    std::cout << "Dequeue Test:" << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Should print: first
    std::cout << "Dequeued: " << q.dequeue() << std::endl; // Should print: second
    q.printQueue(); // Should print: third
}

void testIsEmpty() {
    Queue q;
    std::cout << "IsEmpty Test:" << std::endl;
    std::cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl; // Should print: Queue is empty
    q.enqueue("first");
    std::cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << std::endl; // Should print: Queue is not empty
}

void testPrintQueue() {
    Queue q;
    q.enqueue("first");
    q.enqueue("second");
    q.enqueue("third");

    std::cout << "PrintQueue Test:" << std::endl;
    q.printQueue(); // Should print: first second third
}

int main() {
    testEnqueue();
    testDequeue();
    testIsEmpty();
    testPrintQueue();
    return 0;
}
```

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%207">Lab 7</a>
</p>

















































