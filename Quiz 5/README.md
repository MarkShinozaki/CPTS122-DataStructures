# Quiz 5
## Questions 

### **1.What is a `const` object? What kids of functions can a `const` object invoke? Explain.**
**Answer:**
- A `const` object is an object whose state cannot be modified after it is created. This means that once a `const` object is initialized, none of its data members can be changed, and only `const` member functions can be called on it. `const` member functions are functions that do not modify the state of the object and are marked with the const keyword at the end of the function signature.

**Example:**
```c++
class MyClass {
public:
    int getValue() const {
        return value;
    }
    void setValue(int v) {
        value = v;
    }
private:
    int value;
};

int main() {
    const MyClass obj; // const object
    obj.getValue();    // Allowed
    // obj.setValue(5); // Not allowed, as setValue is not a const member function
    return 0;
}
```
---
### **2. What is Abstraction? Explain.**
**Answer:**
- Abstraction is an object-oriented programming concept that focuses on hiding the complex implementation details and showing only the necessary features of an object. It allows a programmer to work with high-level interfaces without worrying about the underlying complexities. Abstraction can be achieved using classes and interfaces, where the class exposes only the essential attributes and behaviors and hides the implementation details.
**Example:**
```c++
class Car {
public:
    void start() {
        // Complex internal mechanism to start the car
    }
    void stop() {
        // Complex internal mechanism to stop the car
    }
};

int main() {
    Car myCar;
    myCar.start(); // User does not need to know how start() works internally
    myCar.stop();
    return 0;
}
```
---
3. What is a Function Template? Explain.
**Answer:**
- A function template is a blueprint for creating a family of functions with different parameter types. It allows the creation of generic functions that can work with any data type. Templates enable code reuse and flexibility. The keyword template is used to define a template.
**Example:**
```c++
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of integers: " << add(3, 4) << endl;
    cout << "Sum of doubles: " << add(3.5, 4.5) << endl;
    return 0;
}
```
---

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%206">Quiz 6</a>
</p>


  
