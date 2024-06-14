# Exception Handling 
## Introduction to Exception Handling 

**Exception handling in C++ is a mechanism that allows a program to detect and handle error conditions (exceptions) in a controlled and structured manner. This helps in maintaining the normal flow of the program and ensures that the program can gracefully recover from unexpected situations.**

### Key Concepts
**Exception**

An exception is an event that occurs during the execution of a program that disrupts the normal flow of instructions. It is typically used to signal an error or other unusual conditions.

**Try Block**

A `try` block is used to wrap the code that might throw an exception. This block is followed by one or more `catch` blocks to handle the exceptions.

**Catch Block**

A `catch` block is used to handle the exceptions thrown by the `try` block. Multiple catch blocks can be used to handle different types of exceptions

**Throw Statement**

The `throw` statement is used to signal the occurrence of an anomalous situation (exception) that a program cannot handle during normal execution.

**Standard Exceptions**

C++ provides a standard set of exceptions defined in the `<stdexcept>` header. Some commonly used standard exceptions are:

- `std::exception`
- `std::runtime_error`
- `std::logic_error`
- `std::out_of_range`
- `std::invalid_argument`

### Example of Exception Handling 
**Basic Example**
```c++
#include <iostream>
using namespace std;

int main() {
    try {
        int denominator = 0;
        if (denominator == 0) {
            throw "Division by zero condition!";
        }
        int result = 10 / denominator;
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }
    return 0;
}
```

### Example with Standard Exceptions
```c++
#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero");
    }
    return numerator / denominator;
}

int main() {
    try {
        cout << divide(10.0, 2.0) << endl; // This will work
        cout << divide(10.0, 0.0) << endl; // This will throw an exception
    } catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    }
    return 0;
}
```

### Key Topics
#### Multiple Catch Blocks

C++ allows multiple catch blocks to handle different types of exceptions. The appropriate catch block is executed based on the type of exception thrown.

**Example**

```c++
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        throw out_of_range("Out of range error");
    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Out of range: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
```

#### Catch-All Handler
A catch-all handler can be used to catch any type of exception. This is done using an ellipsis (...) in the catch block.

**Example**
```c++
#include <iostream>
using namespace std;

int main() {
    try {
        throw 20;
    } catch (int e) {
        cout << "Caught an integer: " << e << endl;
    } catch (...) {
        cout << "Caught an unknown exception" << endl;
    }
    return 0;
}
```
#### Rethrowing Exceptions 
Sometimes, a catch block may need to rethrow an exception to be handled at a higher level.

**Example**
```c++
#include <iostream>
using namespace std;

void func() {
    try {
        throw "An error occurred";
    } catch (const char* msg) {
        cout << "Caught in func: " << msg << endl;
        throw; // Rethrow the exception
    }
}

int main() {
    try {
        func();
    } catch (const char* msg) {
        cout << "Caught in main: " << msg << endl;
    }
    return 0;
}
```
#### Custom Exceptions 

C++ allows the creation of custom exceptions by inheriting from the `std::exception` class.

**Example**
```c++
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "My custom exception";
    }
};

int main() {
    try {
        throw MyException();
    } catch (const MyException& e) {
        cout << "Caught: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Caught a standard exception: " << e.what() << endl;
    }
    return 0;
}
```

### Conclusion 

Exception handling in C++ is a powerful feature that helps in managing errors and unexpected situations in a structured manner. By understanding and using try, catch, and throw statements, along with standard and custom exceptions, programmers can create robust and error-resistant applications.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(16)%20Abstract%20Data%20Types">Part 16: Abstract Data Types</a>
</p>
