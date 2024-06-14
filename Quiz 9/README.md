# Quiz 9

## Questions 

### **1. What is an abstract class? What is the purpose of an abstract class?**
**Answer:**
- An abstract class is a class that cannot be instantiated and is designed to be inherited by other classes. It often contains at least one pure virtual function, which must be overridden by derived classes. The purpose of an abstract class is to provide a common interface for derived classes and to enforce certain functionalities across different subclasses.

**Example:**
```c++
class AbstractBase {
public:
    virtual void show() = 0; // Pure virtual function
};

class Derived : public AbstractBase {
public:
    void show() override {
        cout << "Implementation of show in Derived class" << endl;
    }
};

int main() {
    // AbstractBase obj; // Error: cannot instantiate abstract class
    Derived d;
    d.show(); // Output: Implementation of show in Derived class
    return 0;
}
```
### **2. What is Big-O notation? Discuss space and time complexity.**
**Answer:**
- Big-O notation is a mathematical notation used to describe the upper bound of an algorithm's running time or space requirements in terms of the input size. It provides a high-level understanding of the algorithm's efficiency and performance as the input size grows.
  - **Time complexity**: Describes the amount of time an algorithm takes to complete as a function of the input size.
  - **Space complexity**: Describes the amount of memory an algorithm uses as a function of the input size.
    
**Example**:
- **O(1)**: Constant time complexity.
- **O(n)**: Linear time complexity.
- **O(n^2)**: Quadratic time complexity.

### **3. What is a C++ exception? Explain.**
**Answer:**
- A C++ exception is a response to an exceptional circumstance that arises while a program is running, such as an attempt to divide by zero. Exceptions provide a way to transfer control from one part of a program to another. Exception handling is built upon three keywords: `try`, `catch`, and `throw`.

**Example**:
```c++
#include <iostream>
using namespace std;

int main() {
    try {
        int denominator = 0;
        if (denominator == 0) {
            throw runtime_error("Division by zero");
        }
        int result = 10 / denominator;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
```
---

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%201">Quiz 1</a>
</p>























