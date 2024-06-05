# Characters & Strings

## What are Characters and Strings?
- **Characters**: The basic building blocks representing individual symbols like letters, digits, and punctuation.
- **Strings**: Sequences of characters terminated by a null character (`'\0'` in C and C++).

### Key Concepts
1. **Character Representation**:
   - Stored as integers using the ASCII or Unicode encoding.
   - Example: The character 'A' has the ASCII value 65.

2. **String Representation**:
   - In C and C++, strings are arrays of characters ending with a null character (`'\0'`).
   - Example: The string "Hello" is stored as `['H', 'e', 'l', 'l', 'o', '\0']`.

### Differences Between C and C++
- **String Handling**:
  - C uses character arrays and pointers for string manipulation.
  - C++ provides a built-in `std::string` class for easier string handling.

## Example: Basic String Usage

### **C Implementation**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20];

    // Copying string
    strcpy(str2, str1);
    printf("Copied string: %s\n", str2);

    // Concatenating strings
    strcat(str1, " World");
    printf("Concatenated string: %s\n", str1);

    // String length
    printf("Length of str1: %lu\n", strlen(str1));

    return 0;
}
```

### **C++ Implementation**
```c++
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2;

    // Copying string
    str2 = str1;
    std::cout << "Copied string: " << str2 << std::endl;

    // Concatenating strings
    str1 += " World";
    std::cout << "Concatenated string: " << str1 << std::endl;

    // String length
    std::cout << "Length of str1: " << str1.length() << std::endl;

    return 0;
}
```
### Key Differences Between C and C++ Implementations
- **String Handling**:
  - In C, `strcpy()`, `strcat()`, and `strlen()` functions from `<string.h>` are used for copying, concatenation, and finding the length of strings, respectively.
  - In C++, `std::string` class methods are used for copying (`=` operator), concatenation (`+=` operator), and finding the length (`length()` method).
- **Header Files**:
  - C uses `#include <stdio.h>` and `#include <string.h>`.
  - C++ uses `#include <iostream>` and `#include <string>`.

### Example: Character Operations 
#### **C Implementation**
```c
#include <stdio.h>

int main() {
    char ch = 'A';
    printf("Character: %c\n", ch);
    printf("ASCII value: %d\n", ch);

    // Checking if a character is a digit
    if (ch >= '0' && ch <= '9') {
        printf("%c is a digit.\n", ch);
    } else {
        printf("%c is not a digit.\n", ch);
    }

    return 0;
}
```
#### **C++ Implementation**
```c++
#include <iostream>
using namespace std;

int main() {
    char ch = 'A';
    cout << "Character: " << ch << endl;
    cout << "ASCII value: " << static_cast<int>(ch) << endl;

    // Checking if a character is a digit
    if (isdigit(ch)) {
        cout << ch << " is a digit." << endl;
    } else {
        cout << ch << " is not a digit." << endl;
    }

    return 0;
}
```
### Key Differences Between C and C++ Implementations
- **Character Handling**:
  - In C, character checks are done using relational operators (e.g., ch >= '0' && ch <= '9').
  - In C++, functions like isdigit() from <cctype> are used for checking character types.

### Example: String Input & Output 
#### **C Implementation**
```c

#include <stdio.h>

int main() {
    char str[50];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Reading string input
    printf("You entered: %s\n", str);

    return 0;
}
```
#### **C++ Implementation**
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // Reading string input
    cout << "You entered: " << str << endl;

    return 0;
}
```
### Key Differences Between C and C++ Implementations
- **String Input and Output**:
  - In C, `fgets()` is used for reading strings from input.
  - In C++, `getline()` is used for reading strings from input.

### Key Takeaways
- Characters and strings are fundamental data types in both C and C++.
- C uses character arrays and pointers for string handling, while C++ provides a more powerful and convenient std::string class.
- Understanding the differences in string manipulation functions and methods between C and C++ is essential for effective programming in both languages.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(5)%20Linked%20Lists">Part 5: Linked Lists Review</a>
</p>





















