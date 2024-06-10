# Classes & Objects 
## OOP and C++
### Key Concepts
- Object-oriented design (OOD)
- Object Oriented Programming (OOP)
- Class and Objects
- Data Encapsulation
- Abstraction/Information hiding
- C++ I/O
- References and Reference parameters
- Unary Scope Resolution Operator
Function overloading

### Object Oriented Design (OOD)
- Model software in ways that are similar to how people view/describe real-world objects.
- Descriptions and designs include properties or attributes of the real-world objects.
- Unified modeling language (UML) provides a specification for illustrating properties of objects along with interactions between them.

### Object-oriented Programming
- Programming language model which institutes mechanisms to support implementing object-driven software systems.
  - Languages: C++, C#, Java.
- Procedural programming such as instituted by C is action-oriented.
  - In C, the unit of programming is a function.
  - In C++, the unit is a class.

### Object-Oriented Programming (OOP)
- Explore OOP with classes, encapsulation, objects, operator overloading, inheritance, and polymorphism.
Classes and Objects

#### What is a class?
- A user-defined type or data structure.
- Contains data members (attributes) and member functions (operations).
- A blueprint for an object.

#### What is an object?
- An instantiation of a class.
- The class is the type, and the object is the variable with allocated memory for that type.

### Data Encapsulation
- A way of organizing or wrapping of data/attributes and methods/operations into a structure (or capsule).
  - Demonstrated by objects.
  - Objects naturally impose encapsulation: attributes and operations are closely tied together.
- How does making a function or class a friend of another class impact encapsulation?


### Abstraction/Information Hiding (I)
- A design principle which states a design decision should be hidden from the rest of the system.
  - Objects should communicate with each other through well-defined interfaces, but not know how other objects are implemented.

#### Abstraction/Information Hiding (II)
- Prevents access to data aside from the methods specified by the object.
  - Guarantees integrity of data.
  - Access specifiers in C++ control the access to information: public, protected, and private.

### Programming in C++
- When programming in an object-oriented language, we’ll be exposed to encapsulation, abstraction, and information hiding in action.
- We need to start thinking in an object-oriented way so that we can leverage the software design benefits of objects and the richness of C++.
- Always remember, objects contain data and associated operations!
  
### Basics of C++ and I/O (I)
- In C++, just like in C, every program begins execution with function main().
- To perform input and output (I/O), we need to include the C++ Standard Library <iostream>:
  - Essentially replaces <stdio.h>, but with even more richness and convenience.
    
#### Basics of C++ and I/O (II)
- In tandem with including <iostream>, we’ll need to use the following:
  - A standard output stream object (std::cout) and stream insertion operator (<<) to display information on the screen.
    - Replaces the need for printf().
  - A standard input stream object (std::cin) and the stream extraction operator (>>) to read data from the keyboard.
    - Replaces the need for scanf().
      
#### Basics of C++ and I/O Example
```c++
#include <iostream>
using std::cin;  // replaces need for std:: in front of cin
using std::cout; // replaces need for std:: in front of cout
using std::endl; // replaces need for std:: in front of endl

int main (void)
{
    int n1 = 0;
    cout << "Enter a number: ";
    cin >> n1; // Notice no address of (&) required!
    
    int n2 = 0, sum = 0; // Can declare variables right before their use in C++!
    cout << "Enter a second number: ";
    cin >> n2;
    
    sum = n1 + n2;
    cout << "The sum is: " << sum << endl; // endl outputs a newline, then flushes buffer
    
    return 0;
}
```

### References and Reference Parameters (I)
- There are two ways to pass arguments to functions in C++:
- **Pass-by-value (PBV)**: A copy of the contents/value of each argument is made and passed (on the function call stack) to the called function.
  - One disadvantage of pass-by-value is copying the contents of a large data item or object introduces longer execution times and memory space.
  - In general, should only be used with simple types.
  - Passing-by-pointer falls under this category.
- **Pass-by-reference (PBR)**: NO copy of the contents/value of each argument is made.
  - The called function can access the caller’s data directly and modify the data.

#### References and Reference Parameters (II)
- We don’t use pass-by-reference strictly so that we can modify the data in an object directly; in many cases, we use it so that the overhead of copying data is circumvented.
  - **We use the ampersand (&) to represent pass-by-reference**:
```c++
void cube (int& n); // this is a prototype
```
- Don’t confuse with the address of (&) operator! Context determines which one’s in play!

#### References and Reference Parameters (III)
- We can return a reference to a variable as well – however, we have to be very careful:
```c++
int& someFunction (int& n);
```
- If we return a reference to an automatic local variable, the variable becomes “undefined” when the function exits; unless the variable is declared as “static” (keyword).
  - References to undefined variables are called dangling references.
  - Note: Dangling references and dangling pointers are NOT the same!


### Reference and Reference Parameters Example
```c++
void cubeByRef (int &n);
void cubeByPtr (int *pN);

int main (void)
{
    int n = 5;
    cubeByRef (n); // Don’t need &, the formal parameter list indicates PBR
    cubeByPtr (&n); // Need address of (&) operator to satisfy pointer; applying PBV
    return 0;
}

void cubeByRef (int &n)
{
    n = n * n * n; // We have direct access to n, don’t need to dereference; changes are retained
}

void cubeByPtr (int *pN)
{
    *pN = (*pN) * (*pN) * (*pN); // Need to dereference to indirectly change value
}
```


### Unary Scope Resolution Operator
- It’s possible to declare local and global variables of the same name:
  - Unary Scope Resolution Operator (::) allows a global variable to be accessed without confusing it with a local variable.
```c++
int num = 42; // global variable

int main (void)
{
    double num = 100.25; // local variable
    cout << num << endl;  // displays 100.25
    cout << ::num << endl; // displays 42
    return 0;
}
```

### Function Overloading (I)
- The ability to define multiple functions with the same name:
  - Requires that each function has different types of parameters and/or different number of parameters and/or different order of parameters.
```c++
int cube (int n);
double cube (double n);
```
- The C++ compiler selects the appropriate function based on the number, types, and order of arguments in the function call.

#### Function Overloading (II)
- We use function overloading to increase readability and understandability.
  - Of course, we only want to overload functions that perform similar tasks.

### C++ Standard Template Library (STL) Class Vector
- STL class vector represents a more robust array with many more capabilities.
  - May operate with different types of data because they’re templated!
```c++
vector<int> v1(10);    // declares a 10 element vector of integers
vector<double> v2(5);  // declares a 5 element vector of doubles
```

---

# More about Classes in C++ 

## Key Concepts 
- Function Templates
- Defining Classes with Member Functions
- The Rule of Three, Law of the Big Three, or the Big Three
- Constructors
  - Default and Copy
- Destructors
- Setters (Mutators) and Getters (Accessors)

## Function Templates
- Overloaded functions are generally defined to perform similar operations that involve different types and/or program logic.
- What happens if the program logic and operations are identical for each type?
  - Function templates may be used to more concisely overload functions.

### Function Template Example 
```c++
// template function must be placed in .h files!
template <class T>
T add (T v1, T v2)
{
    T result;
    result = v1 + v2;
    return result;
}

// start of .cpp file!
int main (void)
{
    int n1 = 10, n2 = 20, n3 = 0;
    double d1 = 35.75, d2 = 45.5, d3 = 0.0;
    
    // Single function template provides capability of defining
    // a family of overloaded functions!
    n3 = add (n1, n2); // C++ generates overloaded function for integers
    d3 = add (d1, d2); // C++ generates overloaded function for doubles

    return 0;
}

```
## Class with Member Functions (I)
- In C++, we can create a user-defined type using the keyword class.
- An object is an instantiation of a `class`.
- A class consists of data members (attributes) and member functions (operations).
- A class controls access to its members.
- Typically, you cannot call a member function unless an object of the class has been instantiated.
  - One exception to this rule is when you declare a member function with the keyword `static`.

### Class with Member Functions (II)
- Classes allow the developer to separate interfaces from implementation, which is a principle of good software engineering.
  - We generally place our function prototypes for member functions in the `class.h` file and our implementation for these in our `class.cpp` file.
  - The function prototypes describe the class's public interfaces without exposing the internal implementation of the member functions.

### Class with Member Functions (III)
- Objects can interact with each other by sending messages.
  - Messages are sent from one object to another by calling a method on that object.
  - These methods are generally public member functions.

## Example Class: ComplexNumber with Member Functions (I)
- Define the class for a complex number.
  - A complex number consists of a real part and imaginary part in the form: `a + bi`, where `a` and `b` are real numbers, and `i` is the imaginary unit `i = √-1.`
  - Class `ComplexNumber` will consist of two data members:
    - `double realPart` // we choose double because these are real numbers.
    - `double imaginaryPart`.
   
### Example Class: ComplexNumber with Member Functions (II)
- Add the data members to the class.
  - To follow the good software engineering practice of information hiding, we will make the data members private.
  - Private members may only be accessed directly by member functions of the class (or friends).
```c++
class ComplexNumber
{
private:
    // m – represents member of a class
    double mRealPart; 
    double mImaginaryPart;
}; // Don’t forget the semicolon!
```
### Example Class: ComplexNumber with Member Functions (III)
- Consider operations that we need to perform on the data members of the class.
  - We should be able to add and subtract two complex numbers.
  - We should also be able to print complex numbers in the form a + bi.
  - We could perform each of these operations by using the C++ operator overloading capability, but we’ll reserve that for another example.

### Example Class: ComplexNumber with Member Functions (IV)
- Add the member functions to the class.
  - The member functions will represent the well-defined interfaces to the "outside" world, thus, we’ll make them public.
  - Public functions may be accessed by other (non-member) functions in the program as well as member functions of other classes.
```c++
class ComplexNumber
{
public: 
    // const forces the implementation to NOT allow
    // the operand object to be modified; pass-by-ref
    // so a copy of the operand object is not made!
    ComplexNumber add (const ComplexNumber &operand);
    ComplexNumber sub (const ComplexNumber &operand);
    // Remember since print() is a member function,
    // it has access to the private data members,
    // so no parameters are required!
    void print (); 

private:
    double mRealPart; // m – represents member of a class
    double mImaginaryPart;
}; // Don’t forget the semicolon!
```

### Example Class: ComplexNumber with Member Functions (V)
- Define the definitions for the member functions.
  - All member functions must be associated with a class.
  - Since we’ll separate our interface `(.h)` from our implementation `(.cpp)`, we’ll need to use the binary scope resolution operator `(::)` to provide this association.
  - Don’t confuse this operator with the unary scope resolution operator!

### Example Class: ComplexNumber with Member Functions (VI)
- Write the definition for the `add()` member function.
```c++
// Prototype: ComplexNumber add (const ComplexNumber &operand);
// Definition – notice the binary scope resolution operator
ComplexNumber ComplexNumber::add (const ComplexNumber &operand)
{
    // This adds the real part of the “operand” object
    // to the real part of the object that invokes the
    // call to the function; it also adds the imaginary
    // parts
    ComplexNumber result; // Declare local ComplexNumber
    // Recall we use the dot member operator (.) to access
    // members of a class; no dot (.) denotes accessing the
    // instantiated object’s members; note we don’t have to apply “special”
    // operators to access an object passed by reference!
    result.mRealPart = mRealPart + operand.mRealPart; 
    result.mImaginaryPart = mImaginaryPart + operand.mImaginaryPart;
    // Don’t want to pass back by reference; cause undefined behavior
    return result; 
}
```
### Example Class: ComplexNumber with Member Functions (VII)
- **Could you write the definition for the `sub()` function? Try it!**
```c++
// Prototype: ComplexNumber sub (const ComplexNumber &operand);
// Definition – notice the binary scope resolution operator
ComplexNumber ComplexNumber::sub (const ComplexNumber &operand)
{
    // This subtracts the real part of the “operand” object
    // from the real part of the object that invokes the
    // call to the function; it also subtracts the imaginary
    // parts
    ComplexNumber result; // Declare local ComplexNumber
    // Recall we use the dot member operator (.) to access
    // members of a class; no dot (.) denotes accessing the
    // instantiated object’s members; note we don’t have to apply “special”
    // operators to access an object passed by reference!
    result.mRealPart = mRealPart - operand.mRealPart; 
    result.mImaginaryPart = mImaginaryPart - operand.mImaginaryPart;
    // Don’t want to pass back by reference; cause undefined behavior
    return result; 
}
```

### Example Class: ComplexNumber with Member Functions (VIII)
- **Write the definition for the print() member function**.
```c++
// Prototype: void print(); 
// Definition
void ComplexNumber::print()
{
    // Print in the form -> real + imaginary i
    cout << mRealPart << " + " << mImaginaryPart << "i" << endl;
}
```
## The Rule of Three
- Also known as the Law of The Big Three or The Big Three.
- **The rule states that if one or more of the following are defined, then all three should be explicitly defined**:
  - `Destructor`
  - `Copy constructor`
  - `Copy assignment operator`

## How to Instantiate Objects from `main()` (I)
- **Continuing with our ComplexNumber example…**
```c++
int main (void)
{
    // Instantiate three objects!
    ComplexNumber c1, c2, c3;
    // Some other code needs to be in place for this
    // to work in reality…
    c3 = c1.add (c2); // c1 invokes the add () call
    // c3 contains the result, so it invokes the
    // print () call
    c3.print (); 
    return 0;
}
```

### How to Instantiate Objects from `main()` (II)
- You should be asking yourself how do we know which values are stored in each of the `ComplexNumber` objects (`c1`, `c2`, `c3`) for each real and imaginary part.
  - Right now we really don’t know…most likely 0 for both data members though…
  - We need to create a means of initializing our objects.
  - Constructor functions solve this problem for us!

## Constructors for Initializing Objects! (I)
- Each class declared provides a constructor that may be used to initialize an object.
  - A constructor is a special member function because it MUST be named the same as the class, it cannot return a value, and it is called implicitly when an object is instantiated.
  - If a class does not explicitly provide a constructor, then the compiler provides a default constructor (a constructor with no parameters).
  - Generally, constructors are declared public.
  - When is an object instantiated?
    - When a variable of the type of class is declared.
    - When the `new` operator is explicitly invoked.
    - Note: `new` is used in place of` malloc()` for C++.

### Constructors for Initializing Objects (II)
- **Add a default constructor to our ComplexNumber class.**
```c++
class ComplexNumber
{
public: 
    ComplexNumber(); // Default constructor
    // const forces the implementation to NOT allow
    // the operand object to be modified; pass-by-ref
    // so a copy of the operand object is not made!
    ComplexNumber add (const ComplexNumber& operand);
    ComplexNumber sub (const ComplexNumber& operand);
    // Remember since print () is a member function,
    // it has access to the private data members,
    // so no parameters are required!
    void print (); 

private:
    double mRealPart; // m – represents member of a class
    double mImaginaryPart;
}; // Don’t forget the semicolon!
```

### Constructors for Initializing Objects (III)
- **Write the definition for the default constructor member function.**

```c++
// Prototype: ComplexNumber();
// Definition
ComplexNumber::ComplexNumber()
{
    // Initialize the data members
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}
```
### Constructors for Initializing Objects (IV)
- Notice the default constructor sets the real and imaginary parts to 0.
- What if we want to set the parts to values other than 0?
  - We create another version of the constructor, which accepts parameters.
  - This implies we need to overload our constructor!

```c++
ComplexNumber(double real, double imaginary);

ComplexNumber::ComplexNumber(double real, double imaginary)
{
    mRealPart = real;
    mImaginaryPart = imaginary;
}
```
## How to Initalize Objects with a Constructor?
```c++
int main (void)
{
    // Instantiate three objects! Use a constructor that supports arguments!
    ComplexNumber c1(2.5, 3.5), c2(1.25, 5.0), c3;
    // With the addition of constructors we now know the following:
    // c1 = 2.5 + 3.5i, c2 = 1.25 + 5.0i, c3 = 0.0 + 0.0i
    c3 = c1.add (c2); // c1 invokes the add () call
    // State of c3? It should be c3 = 3.75 + 8.5i
    // c3 contains the result, so it invokes the
    // print () call
    c3.print (); // Would print 3.75 + 8.5i
    return 0;
}
```
## Copy Constructor
- A copy constructor always accepts a parameter, which is a reference to an object of the same class type.
```c++
ComplexNumber(ComplexNumber& copyObject);
```
- Copy constructors make a copy of an object of the same type.
- A copy constructor is implicitly invoked when an object is passed-by-value!
- A shallow copy is made if only the data members are copied directly over to the object.
- A deep copy is made if new memory is allocated for each of the data members.
- We will explore these constructors more in the future!

## Destructors 
- Each class declared provides a destructor.
- A destructor is a special member function because it MUST also be named the same as the class (with a tilde `~` in front). It cannot return a value, and it is called implicitly when an object is destroyed.

```c++
~ComplexNumber ();
```

- If a class does not explicitly provide a destructor, then the compiler provides an “empty” destructor.
- When does an object get destroyed?
  - When the object leaves scope.
  - When the delete operator is explicitly invoked.
  - Note: delete is used in place of free () for C++.
 
## Setters and Getters
- These are public interfaces/functions to provide access to private data members.
  - Setters allow clients of an object to set or modify the data members.
    - Clients include any statement that calls the object’s member functions from outside the object.
    - May be used to validate data.
  - Getters allow the client to obtain/get a copy of the data members.
  - There generally should be 1 setter function per data member, and 1 getter function per data member (of course, this depends on whether or not a data member should be accessed by a client object).
 
  --- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/blob/Lectures-Slides">Part 9.5: Streams & File Processing in C++</a>
</p>
