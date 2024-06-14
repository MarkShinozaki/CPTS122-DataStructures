# Abstract Data Types in C++

## Introduction to Abstract Data Types (ADTs)

**Abstract Data Types (ADTs) are a fundamental concept in computer science and programming. An ADT is a type (or class) for objects whose behavior is defined by a set of values and a set of operations. The definition of ADTs focuses on what operations are to be performed, rather than how these operations will be implemented.**

### Key Concepts 
**Definition of ADTs**

An Abstract Data Type is defined by:

- **Values:** The data stored in the ADT.
- **Operations:** The functions or procedures that can be performed on the data.

**Benefits of ADTs**

- **Encapsulation:** Hides the implementation details from the user.
- **Modularity:** Makes the program easier to manage and understand.
- **Reusability:** Can be used across different programs without modification.

### Examples of ADTs
**Common examples of ADTs include:**
- Stack
- Queue
- List
- Tree
- Graph

### Example: Stack ADT
**A stack is a collection of elements with two main operations:**
- **Push:** Adds an element to the top of the stack.
- **Pop:** Removes the element from the top of the stack.

#### Stack Interface (Abstract Definition)
```c++
template <typename T>
class Stack {
public:
    virtual void push(T element) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Stack() {}
};
```

#### Stack Implementation using Arrays
```c++
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack : public Stack<T> {
private:
    int topIndex;
    int capacity;
    T* stackArray;

public:
    ArrayStack(int size) {
        capacity = size;
        stackArray = new T[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] stackArray;
    }

    void push(T element) override {
        if (topIndex >= capacity - 1) {
            throw overflow_error("Stack overflow");
        }
        stackArray[++topIndex] = element;
    }

    void pop() override {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        topIndex--;
    }

    T top() const override {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return stackArray[topIndex];
    }

    bool isEmpty() const override {
        return topIndex == -1;
    }
};

int main() {
    try {
        ArrayStack<int> stack(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        cout << "Top element: " << stack.top() << endl; // Output: 3
        stack.pop();
        cout << "Top element after pop: " << stack.top() << endl; // Output: 2
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
```
### Example: Queue ADT
**A queue is a collection of elements with two main operations:**
- **Enqueue:** Adds an element to the back of the queue.
- **Dequeue:** Removes the element from the front of the queue.

#### Queue Interface (Abstract Definition)
```c++
template <typename T>
class Queue {
public:
    virtual void enqueue(T element) = 0;
    virtual void dequeue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Queue() {}
};
```

#### Queue Implementation using Linked List
```c++
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedQueue : public Queue<T> {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;

public:
    LinkedQueue() : frontNode(nullptr), rearNode(nullptr) {}

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T element) override {
        Node<T>* newNode = new Node<T>(element);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() override {
        if (isEmpty()) {
            throw underflow_error("Queue underflow");
        }
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
    }

    T front() const override {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return frontNode->data;
    }

    bool isEmpty() const override {
        return frontNode == nullptr;
    }
};

int main() {
    try {
        LinkedQueue<int> queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        cout << "Front element: " << queue.front() << endl; // Output: 1
        queue.dequeue();
        cout << "Front element after dequeue: " << queue.front() << endl; // Output: 2
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
```

### Conclusion

Abstract Data Types (ADTs) are a powerful way to encapsulate and manage data and operations in a modular and reusable manner. By using ADTs, you can create robust and maintainable code that abstracts away the implementation details and focuses on the interface and behavior of the data structures.





--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(17)%20Hash%20Table">Part 17: Hash Table</a>
</p>
