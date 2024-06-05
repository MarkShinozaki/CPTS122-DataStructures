# Recursion

## What is Recursion?
- Recursion is the process in which a function calls itself directly or indirectly through another function.
- The function that is called is known as a recursive function.

### Key Attributes of Recursive Problems:
1. One or more simple cases have a straightforward, non-recursive solution (base case).
2. The other cases can be defined in terms of problems that are closer to the simple cases (recursive case).
3. Through a series of calls to the recursive function, the problem eventually is stated in terms of simple cases.

### Advantages of Recursion:
- May provide a simpler solution than an iterative one.
- May lead to a reduction in code size.
- Can be easier to understand and implement for certain problems.

### Disadvantages of Recursion:
- May require large amounts of memory.
- Each call to the function allocates memory for local variables.
- The "call stack" grows with each call, potentially leading to a stack overflow.
- Can be difficult to test and debug.

## Example: Factorial Calculation

### C Implementation
```c
#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int number = 5;
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}
```
### C++ Implementation 

```c++
#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int number = 5;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}
```

### Key Differences Between C and C++ Implementations
- Header Files:
  - C uses #include <stdio.h> for standard input and output functions.
  - C++ uses #include <iostream> for input and output stream.
- Output Functions:
  - C uses printf for formatted output.
  - C++ uses cout for output stream.
- Namespace:
  - C++ uses namespaces (using namespace std;) to avoid naming conflicts and to bring names from the standard library into the current scope.

### Recursive Function Properties
- Base Case:
  - The condition under which the recursion ends.
  - In the factorial example, the base case is when n is 0 or 1.
- Recursive Case:
  - The part of the function where the function calls itself with a modified argument.
  - In the factorial example, the recursive case is n * factorial(n - 1).

### Example: Fibonacci Sequence
- **C Implementation**
```c
#include <stdio.h>

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case
    } else if (n == 1) {
        return 1; // Base case
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int number = 5;
    printf("Fibonacci of %d is %d\n", number, fibonacci(number));
    return 0;
}
```

- **C++ Implementation**
```c++
#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case
    } else if (n == 1) {
        return 1; // Base case
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int number = 5;
    cout << "Fibonacci of " << number << " is " << fibonacci(number) << endl;
    return 0;
}
```
### Key Takeaways
- Both C and C++ can handle recursion effectively.
- The main differences lie in the way input and output are handled and the use of namespaces in C++.
- Understanding the base and recursive cases is crucial for implementing recursive functions correctly.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(3)%20Pointers">Part 3: Pointer Review</a>
</p>












