# Polymorphism 

## Introduction to Polymorphism 
**Polymorphism is one of the core concepts of object-oriented programming (OOP). It refers to the ability of a function, object, or method to take on many forms. Polymorphism allows for methods to do different things based on the object it is acting upon, even if they share the same name.**

### Types of Polymorphism
**There are two main types of polymorphism in C++:**
1. **Compile-time Polymorphism (Static Polymorphism)**
  - Achieved through function overloading and operator overloading.
2. **Run-time Polymorphism (Dynamic Polymorphism)**
  - Achieved through inheritance and virtual functions.

### Compile-time Polymorphism
**Function Overloading**

Function overloading allows multiple functions to have the same name with different parameters. The correct function is chosen based on the number and type of arguments passed.

**Example**
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
### Operator Overloading 

Operator overloading allows the same operator to have different meanings based on its context, especially for user-defined types.

**Example**

```c++
#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;
public:
    Complex() : real(0), imag(0) {}

    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator + (const Complex &obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << "Real: " << real << " Imaginary: " << imag << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
```

### Run-time Polymorphism
**Inheritance and Virtual Functions**

Run-time polymorphism is achieved through the use of base and derived classes, and by declaring functions as virtual in the base class. This ensures that the correct function is called for an object, regardless of the reference type used to call the function.

**Example**
```c++
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show function called" << endl;
    }

    void display() {
        cout << "Base class display function called" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function called" << endl;
    }

    void display() {
        cout << "Derived class display function called" << endl;
    }
};

int main() {
    Base *bptr;
    Derived d;
    bptr = &d;

    bptr->show();     // Calls Derived's show()
    bptr->display();  // Calls Base's display()

    return 0;
}
```

### Key Topics

**Virtual Functions**

A virtual function is a member function in the base class that you expect to override in derived classes. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

**Pure Virtual Functions and Abstract Classes**

A pure virtual function is a function that has no implementation in the base class and is declared by assigning 0 to it. Classes containing pure virtual functions are called abstract classes. These cannot be instantiated and must be inherited.

**Example**
```c++
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

int main() {
    Shape *shape1 = new Circle();
    Shape *shape2 = new Square();

    shape1->draw(); // Calls Circle's draw()
    shape2->draw(); // Calls Square's draw()

    delete shape1;
    delete shape2;

    return 0;
}
```

**Conclusion**

Polymorphism in C++ allows for more flexible and reusable code. By using polymorphism, you can design and implement systems that are easier to extend and maintain. Understanding both compile-time and run-time polymorphism is crucial for effective C++ programming.























--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(14)%20Templates">Part 14: Templates</a>
</p>
