# Pointers

## What are Pointers?
- Pointers are variables that store the memory address of another variable.
- They provide a way to directly access and manipulate memory.
- Essential for dynamic memory allocation, arrays, and data structures like linked lists and trees.

### Key Concepts of Pointers
1. **Pointer Declaration:**
   - Syntax: `type *pointer_name;`
   - Example: `int *ptr;`

2. **Pointer Initialization:**
   - Assigning the address of a variable to a pointer.
   - Example: `ptr = &variable;`

3. **Dereferencing:**
   - Accessing the value stored at the memory address.
   - Syntax: `*pointer_name`
   - Example: `int value = *ptr;`

4. **Pointer Arithmetic:**
   - Operations that involve pointers and integer values.
   - Example: `ptr++`, `ptr--`

### Advantages of Pointers
- Efficient array and string manipulation.
- Dynamic memory allocation.
- Implementation of data structures (e.g., linked lists, trees).
- Function arguments for passing by reference.

### Disadvantages of Pointers
- Complexity in code.
- Potential for memory leaks if not handled properly.
- Dangling pointers and segmentation faults.

## Example: Basic Pointer Usage

### **C Implementation**
```c
#include <stdio.h>

int main() {
    int var = 42;
    int *ptr = &var; // Pointer initialization

    printf("Address of var: %p\n", &var);
    printf("Address stored in ptr: %p\n", ptr);
    printf("Value of var using ptr: %d\n", *ptr); // Dereferencing

    *ptr = 100; // Modifying the value using the pointer
    printf("Modified value of var: %d\n", var);

    return 0;
}
```

### **C++ Implementation**
```c++
#include <iostream>
using namespace std;

int main() {
    int var = 42;
    int *ptr = &var; // Pointer initialization

    cout << "Address of var: " << &var << endl;
    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Value of var using ptr: " << *ptr << endl; // Dereferencing

    *ptr = 100; // Modifying the value using the pointer
    cout << "Modified value of var: " << var << endl;

    return 0;
}
```

#### Key Differences Between C and C++ Implementations
- Header Files:
  - C uses #include <stdio.h> for standard input and output functions.
  - C++ uses #include <iostream> for input and output stream.
- Output Functions:
  - C uses printf for formatted output.
  - C++ uses cout for output stream.
- Namespace:
  - C++ uses namespaces (using namespace std;) to avoid naming conflicts and to bring names from the standard library into the current scope.

### Example: Dynamic Memory Allocation
- **C Implementation**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // Allocating memory
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 42; // Using the allocated memory
    printf("Value at allocated memory: %d\n", *ptr);

    free(ptr); // De-allocating memory
    return 0;
}
```
- **C++ Implementation**
```c++
#include <iostream>
using namespace std;

int main() {
    int *ptr = new int; // Allocating memory
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return 1;
    }

    *ptr = 42; // Using the allocated memory
    cout << "Value at allocated memory: " << *ptr << endl;

    delete ptr; // De-allocating memory
    return 0;
}
```
### Key Differences Between C and C++ Implementations
- **Memory Allocation Functions**:
  - C uses `malloc()` and `free()`.
  - C++ uses `new` and `delete`.
- **Null Pointer**:
  - In C, `NULL` is used to represent a null pointer.
  - In C++, `nullptr` is preferred.

### Example: Pointers and Arrays
- **C Implementation**
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30};
    int *ptr = arr; // Pointer to the first element

    for (int i = 0; i < 3; i++) {
        printf("arr[%d] = %d\n", i, *(ptr + i)); // Pointer arithmetic
    }

    return 0;
}
```
- **C++ Implementation**
```c++
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    int *ptr = arr; // Pointer to the first element

    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << *(ptr + i) << endl; // Pointer arithmetic
    }

    return 0;
}
```
### Key Takeaways
- Pointers are crucial for dynamic memory management, array manipulation, and implementing complex data structures.
- C and C++ both support pointers, but C++ provides additional features like `new` and `delete` for dynamic memory management.
- Understanding pointer basics, including declaration, initialization, dereferencing, and pointer arithmetic, is essential for effective programming in both C and C++.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(4)%20Characters%20%26%20Strings">Part 4: Characters & Strings Review</a>
</p>




