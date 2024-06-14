# Quiz 4
## Questions 

### **1. What is a copy Constructor? Explain.**
**Answer:**
- A copy constructor is a special constructor in C++ used to create a new object as a copy of an existing object. It initializes the new object with the values from the existing object. The copy constructor has the following signature:
```c
ClassName(const ClassName &old_obj);
```
**Example:**
```c++
class MyClass {
public:
    int data;
    MyClass(int d) : data(d) {} // Parameterized constructor
    MyClass(const MyClass &obj) { // Copy constructor
        data = obj.data;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Using copy constructor
    return 0;
}
```

---

### **2. What is a destructor? Explain.**
**Answer:**
- A destructor is a member function which destructs or deletes an object. It has the same name as the class with a tilde (~) prefix and does not take any arguments or return any value. The destructor is called when an object goes out of scope or is explicitly deleted. It is primarily used to release resources that the object may have acquired during its lifetime.

**Example:**
```c++
class MyClass {
public:
    MyClass() {
        // Constructor
    }
    ~MyClass() {
        // Destructor
        cout << "Object is being deleted" << endl;
    }
};

int main() {
    MyClass obj; // Destructor will be called automatically when obj goes out of scope
    return 0;
}
```
---
### **3. What is the rule of three or the Law of Three? Explain.**
**Answer:**
- The rule of three (or Law of Three) in C++ states that if a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three. This rule is important to ensure proper resource management and to avoid shallow copies which can lead to resource leaks and undefined behavior.

**Example:**
 ```c++
  class MyClass {
private:
    int* data;
public:
    MyClass(int d) {
        data = new int(d);
    }
    ~MyClass() {
        delete data;
    }
    MyClass(const MyClass &obj) {
        data = new int(*(obj.data));
    }
    MyClass& operator=(const MyClass &obj) {
        if (this != &obj) {
            delete data;
            data = new int(*(obj.data));
        }
        return *this;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Copy constructor
    MyClass obj3(20);
    obj3 = obj1; // Copy assignment operator
    return 0;
}
```
---

### **4. What is function overloading? Explain.**
**Answer:**
- Function overloading is a feature in C++ that allows multiple functions to have the same name with different parameters. The function to be called is determined by the number and types of arguments passed. This enhances the readability of the code and allows the same function name to be used for different purposes.

**Example:**
```c++
#include <iostream>
using namespace std;

class Print {
public:
    void display(int i) {
        cout << "Integer: " << i << endl;
    }
    void display(double f) {
        cout << "Float: " << f << endl;
    }
    void display(string s) {
        cout << "String: " << s << endl;
    }
};

int main() {
    Print p;
    p.display(5);
    p.display(3.14);
    p.display("Hello, World!");
    return 0;
}
```
---

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%205">Quiz 5</a>
</p>


