# Inheritance 

## Inheritance in C++: Base and Derived Classes

### Introduction to Inheritance 

- Inheritance is a fundamental concept in object-oriented programming that allows one class to inherit the attributes and methods of another class. This promotes code reusability and establishes a relationship between the base (parent) class and the derived (child) class.

### Base Class
- The base class, also known as the parent or superclass, is the class whose properties and methods are inherited by another class. It defines common attributes and behaviors that can be shared across multiple derived classes.

#### Example
```c++
class Base {
public:
    int publicVar;

protected:
    int protectedVar;

private:
    int privateVar;
};
```

### Dervied Class
- The derived class, also known as the child or subclass, inherits the attributes and methods of the base class. It can also have additional attributes and methods or override the existing ones.
#### Example
```c++
class Derived : public Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl; // Accessible
        std::cout << "Protected Var: " << protectedVar << std::endl; // Accessible
        // std::cout << "Private Var: " << privateVar << std::endl; // Not Accessible
    }
};
```
### Types of Inheritance 

#### Public Inheritance 
- When a derived class inherits from a base class publicly, the public and protected members of the base class retain their access levels in the derived class, while private members remain inaccessible.

#### Example
```c++
class PublicDerived : public Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl; // Accessible
        std::cout << "Protected Var: " << protectedVar << std::endl; // Accessible
        // std::cout << "Private Var: " << privateVar << std::endl; // Not Accessible
    }
};
```
#### Protected Inheritance 
- When a derived class inherits from a base class protectedly, the public and protected members of the base class become protected members in the derived class, while private members remain inaccessible.

#### Example 
```c++
class ProtectedDerived : protected Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl; // Accessible as protected
        std::cout << "Protected Var: " << protectedVar << std::endl; // Accessible
        // std::cout << "Private Var: " << privateVar << std::endl; // Not Accessible
    }
};
```

#### Private Inheritance 
- When a derived class inherits from a base class privately, the public and protected members of the base class become private members in the derived class, while private members remain inaccessible.

#### Example 
```c++
class PrivateDerived : private Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl; // Accessible as private
        std::cout << "Protected Var: " << protectedVar << std::endl; // Accessible as private
        // std::cout << "Private Var: " << privateVar << std::endl; // Not Accessible
    }
};
```
### Summary 

- **Public Inheritance**: Public and protected members of the base class remain public and protected in the derived class.
- **Protected Inheritance**: Public and protected members of the base class become protected in the derived class.
- **Private Inheritance**: Public and protected members of the base class become private in the derived class.

### Complete Example 
```c++
#include <iostream>

class Base {
public:
    int publicVar = 1;

protected:
    int protectedVar = 2;

private:
    int privateVar = 3;
};

class PublicDerived : public Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl;
        std::cout << "Protected Var: " << protectedVar << std::endl;
    }
};

class ProtectedDerived : protected Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl;
        std::cout << "Protected Var: " << protectedVar << std::endl;
    }
};

class PrivateDerived : private Base {
public:
    void display() {
        std::cout << "Public Var: " << publicVar << std::endl;
        std::cout << "Protected Var: " << protectedVar << std::endl;
    }
};

int main() {
    PublicDerived pd;
    pd.display();
    // pd.publicVar = 10; // Accessible
    // pd.protectedVar = 20; // Not Accessible

    ProtectedDerived prd;
    prd.display();
    // prd.publicVar = 10; // Not Accessible
    // prd.protectedVar = 20; // Not Accessible

    PrivateDerived pvd;
    pvd.display();
    // pvd.publicVar = 10; // Not Accessible
    // pvd.protectedVar = 20; // Not Accessible

    return 0;
}
```
- In this example, we see how different types of inheritance affect the accessibility of the base class members in the derived class

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(13)%20Polymorphism">Part 13: Polymorphism</a>
</p>
































