# Lab 5: The Wonderful World of C++, Classes, and Objects


## I. Learner Objectives

**At the conclusion of this programming assignment, participants should be able to:**

- Design, implement and test classes in C++
- Declare and define constructors
- Declare and define destructors
- Compare and contrast public and private access specifiers in C++
- Describe what is an attribute or data member of a class
- Describe what is a method of a class
- Apply and implement overloaded functions
- Distinguish between pass-by-value and pass-by-reference
- Discuss classes versus objects
  
## II. Prerequisites

**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose a small C++ language program
- Create test cases for a program
  
## III. Overview & Requirements

**This lab will allow you to further explore lists, and navigate through designing, implementing, and testing classes in C++.**

Create a class called `Complex` for performing arithmetic with complex numbers. Write a program to test your class. Complex numbers have the form:
```
realPart + imaginaryPart * i
```

where `i` is

```
sqrt(-1)
```

Use double variables to represent the private data of the class. Provide a constructor that enables an object of this class to be initialized when it is declared. The constructor should contain default values in case no initializers are provided. Define `public` setters and getters to access the private data members. Below in Figure 1 is a summary of the Complex Number ADT:

### Complex Number ADT

| Complex Number Values | Operations |
|-----------------------|------------|
| realPart              | - Read     |
| imaginaryPart         | - Print    |
|                       | - Add      |
|                       | - Sub      |

#### **Tasks:**

1. Create a class called `Complex` that has the following:

  a. Two double variables `realPart` and `imaginaryPart` as private data members.

  b. A default constructor that initializes the complex number to 0 + 0i.

  c. A parameterized constructor that initializes the complex number to the provided values.

  d. public getter and setter methods for `realPart` and `imaginaryPart`.

  e. Methods to perform the following tasks:

**Add Complex Numbers**

- **The real parts are added together and the imaginary parts are added together. Implement the addition operation in three ways:**

**i.** Implement a member function of class `Complex` called `add()` that must do the following: accept one `Complex` number `rhs` for an argument, add rhs to the data members in the object that invokes the add() function, and return the result.

**ii.** Implement a non-member function called `add()`. Make sure it has the same name as one defined in part (i). Place the prototype/declaration for this function outside of the `Complex` number class's declaration (below the class declaration). Place its definition inside of the `Complex.cpp` file. The function must do the following: accept two `Complex` numbers called `lhs` and `rhs` for arguments, add `lhs` and `rhs` together, and return the result.

**iii.** Implement a non-member overloaded addition `+` operator. Place the prototype/declaration for this function outside of the `Complex` number class's declaration (below the class declaration). Place its definition inside of the `Complex.cpp` file. The function must do the following: accept two `Complex` numbers called `lhs` and `rhs` for arguments, add `lhs` and `rhs` together, and return the result. Use the following prototype/declaration:

```c++
Complex operator+(const Complex &lhs, const Complex &rhs);
```

Use and test the following statements in a test driver, and use the debugger to watch each of the `Complex` numbers:

```
Complex c1(3.5, 2), c2(5.5, 7), c3;

c3 = c1.add(c2); // member add() function
c3 = add(c1, c2); // non-member add() function
c3 = c1 + c2; // overloaded + operator
```

#### Subtract Complex Numbers

The real part of the right operand is subtracted from the real part of the left operand, and the imaginary part of the right operand is subtracted from the imaginary part of the left operand. Solve this problem by overloading the subtraction - operator. Use the debugger to watch each of the Complex numbers declared for part (a).



```c++
c3 = c1 - c2; // overloaded - operator
```

#### Reading Complex Numbers

Implement the read operation in two ways:

i. Implement a member function of class `Complex` called `read()` that must do the following: accept no arguments, read in the real and imaginary parts of the number from the standard input stream in the form:

```
a + bi
```

and return nothing. You must read in the `+` (or minus `-`) and the `i`, but they should be discarded. This function does not prompt the `Complex` number. The prompt is done external to the `read()` function.

ii. Implement a non-member overloaded stream extraction (`>>`) operator. Place the prototype/declaration for this function outside of the `Complex` number class's declaration (below the class declaration). Place its definition inside of the `Complex.cpp` file. The function must do the following: accept one `istream` object called `lhs` and one `Complex` number called `rhs` for arguments, extract the real and imaginary parts of the number from the standard input stream in the form:

```
a + bi
```

and return the `istream` object (so we can chain `>>` together). Note: once again, you should discard the `+` (or minus `-`) and the `i`. Use the following prototype/declaration:

```c++
istream &operator>>(istream &lhs, Complex &rhs);
```

Assuming that you still have the same `Complex` numbers instantiated: `c1`, `c2`, and `c3`. Place the following statements in a test driver:

```
c1.read();
cin >> c2;
```

#### Printing Complex Numbers
- Implement the print operation in two ways:

i. Implement a member function of class `Complex` called `print()` that must do the following: accept no arguments, insert the real and imaginary parts of the number into the standard output stream in the form:

```
a + bi
```

and return nothing.

ii. Implement a non-member overloaded stream insertion (`<<`) operator. Place the prototype/declaration for this function outside of the `Complex` number class's declaration (below the class declaration). Place its definition inside of the `Complex.cpp` file. The function must do the following: accept one `ostream` object called `lhs` and one Complex number called `rhs` for arguments, insert the real and imaginary parts of the number into the standard output stream in the form:

```
a + bi
```

and return the `ostream` object (so we can chain `<<` together). Use the following prototype/declaration:

```
ostream &operator<<(ostream &lhs, const Complex &rhs);
```

Once again, assuming that you still have the same `Complex` numbers instantiated: `c1`, `c2`, and `c3`. Place the following statements in a test driver:

```
c1.print();
c2.print();
c3.print();

cout << c1 << " " << c2 << " " << c3 << endl;
```

### Solution 

#### Complex Class Implementation 


**Complex.h**

```c++
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double realPart;
    double imaginaryPart;

public:
    // Constructors
    Complex();
    Complex(double real, double imaginary);

    // Getter and Setter methods
    double getRealPart() const;
    double getImaginaryPart() const;
    void setRealPart(double real);
    void setImaginaryPart(double imaginary);

    // Member methods
    Complex add(const Complex &rhs) const;
    void read();
    void print() const;

    // Friend functions
    friend Complex add(const Complex &lhs, const Complex &rhs);
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
    friend Complex operator-(const Complex &lhs, const Complex &rhs);
    friend std::istream &operator>>(std::istream &lhs, Complex &rhs);
    friend std::ostream &operator<<(std::ostream &lhs, const Complex &rhs);
};

#endif
```

**Complex.cpp**

```c++
#include "Complex.h"
#include <iostream>

// Default Constructor
Complex::Complex() : realPart(0.0), imaginaryPart(0.0) {}

// Parameterized Constructor
Complex::Complex(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

// Getter methods
double Complex::getRealPart() const {
    return realPart;
}

double Complex::getImaginaryPart() const {
    return imaginaryPart;
}

// Setter methods
void Complex::setRealPart(double real) {
    realPart = real;
}

void Complex::setImaginaryPart(double imaginary) {
    imaginaryPart = imaginary;
}

// Member add() method
Complex Complex::add(const Complex &rhs) const {
    return Complex(realPart + rhs.realPart, imaginaryPart + rhs.imaginaryPart);
}

// Non-member add() function
Complex add(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.realPart + rhs.realPart, lhs.imaginaryPart + rhs.imaginaryPart);
}

// Non-member overloaded addition operator
Complex operator+(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.realPart + rhs.realPart, lhs.imaginaryPart + rhs.imaginaryPart);
}

// Non-member overloaded subtraction operator
Complex operator-(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.realPart - rhs.realPart, lhs.imaginaryPart - rhs.imaginaryPart);
}

// Member read() method
void Complex::read() {
    char sign, i;
    std::cin >> realPart >> sign >> imaginaryPart >> i;
    if (sign == '-') {
        imaginaryPart = -imaginaryPart;
    }
}

// Non-member overloaded stream extraction operator
std::istream &operator>>(std::istream &lhs, Complex &rhs) {
    char sign, i;
    lhs >> rhs.realPart >> sign >> rhs.imaginaryPart >> i;
    if (sign == '-') {
        rhs.imaginaryPart = -rhs.imaginaryPart;
    }
    return lhs;
}

// Member print() method
void Complex::print() const {
    std::cout << realPart << " + " << imaginaryPart << "i";
}

// Non-member overloaded stream insertion operator
std::ostream &operator<<(std::ostream &lhs, const Complex &rhs) {
    lhs << rhs.realPart << " + " << rhs.imaginaryPart << "i";
    return lhs;
}
```

#### Test Driver

**main.cpp**

```c++
#include "Complex.h"
#include <iostream>

int main() {
    // Testing constructors
    Complex c1(3.5, 2), c2(5.5, 7), c3;

    // Testing member add() function
    c3 = c1.add(c2);
    std::cout << "Member add: c1 + c2 = " << c3 << std::endl;

    // Testing non-member add() function
    c3 = add(c1, c2);
    std::cout << "Non-member add: c1 + c2 = " << c3 << std::endl;

    // Testing overloaded + operator
    c3 = c1 + c2;
    std::cout << "Overloaded +: c1 + c2 = " << c3 << std::endl;

    // Testing overloaded - operator
    c3 = c1 - c2;
    std::cout << "Overloaded -: c1 - c2 = " << c3 << std::endl;

    // Testing member read() method
    std::cout << "Enter a complex number in the form a + bi: ";
    c1.read();
    std::cout << "You entered: " << c1 << std::endl;

    // Testing non-member overloaded stream extraction operator
    std::cout << "Enter another complex number in the form a + bi: ";
    std::cin >> c2;
    std::cout << "You entered: " << c2 << std::endl;

    // Testing member print() method
    std::cout << "c1: ";
    c1.print();
    std::cout << std::endl;

    std::cout << "c2: ";
    c2.print();
    std::cout << std::endl;

    std::cout << "c3: ";
    c3.print();
    std::cout << std::endl;

    // Testing non-member overloaded stream insertion operator
    std::cout << "All complex numbers: " << c1 << ", " << c2 << ", " << c3 << std::endl;

    return 0;
}
```

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%206">Lab 6</a>
</p>
