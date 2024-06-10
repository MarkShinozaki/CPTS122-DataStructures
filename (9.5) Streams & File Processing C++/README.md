# Streams and File Processing in C++

## What is a Stream? A Refined Definition 
- A sequence of objects (generally just considered bytes) that flow from a device to memory or from memory to a device.
  - For input operations, the bytes flow from the device (i.e. keyboard, network connection, disk, etc.) to main memory.
  - For output operations, the bytes flow from main memory to the device (screen, printer, etc.).

### Analogy for a Stream
- A conveyer belt:
  - You can place an item in sequence on the belt, i.e. into the stream (insertion or output operation).
  - You can remove an item in sequence from the belt, i.e. take from the stream (extraction or input operation).

## Classic Streams vs Standard Streams
- The classic input/output streams for C++ supported byte-sized chars, which represented the ASCII characters.
  - Many alphabets require more characters than can be represented by a byte and the ASCII character set does not provide all the characters.
  - The Unicode character set provides these additional characters.
- C++ provides standard stream libraries to process Unicode characters `(wchar_t)`.

## Standard Streams in C++ (I)
- For standard input/output streams, include `<iostream>`.
  - **`cin` is a predefined object of class `istream` and is connected to the standard input device (i.e. keyboard):**
```c++
cin >> var; // cin applying stream extraction operator – stops at whitespace for strings
```
  - **`cout` is a predefined object of class `ostream` and is connected to the standard output device (i.e. screen):**
```c++
cout << var; // cout applying stream insertion operator
```

### Standard Streams in C++ (II)
- Member function `getline()` will read a line from the stream:
  - Inserts a null character at the end of the array of characters, removes and discards the `\n` from the stream (i.e. stored as a C string).

## File Processing Algorithm
1. Open the Desired File
  - Opening is based on filename and permissions (read, write, or append).
  - Associates a file with a stream.
2. Process the File
- Read data from the file:
  - Does not affect file.
- Write data to the file:
  - Completely overwrites existing file.
- Add data to the end of the file:
  - Retains previous information in file.
3. Close the File
- Disassociates a file from a stream.

## File Streams in C++ (I)
- For input/output streams to work with files, include `<fstream>`.
  - `ifstream` objects enable input from a file.
  - `ofstream` objects enable output to a file.
  - `fstream` objects for input from and output to a file.
- **Associate file with a file stream either during construction or by calling `open()`**:
```c++
fstream fstr("filename.txt"); // an instantiation of fstream object
// or
fstr.open("filename.txt"); // after instantiation
```

### File Streams in C++ (II)
- **Read from files using:**
```c++
fstr >> var; // applying the stream extraction operator – stops at whitespace for strings
```
  - `fstr.getline()` to read entire line into a character array:
    - Stored as a C string.
- **Write to files using**:
```c++
fstr << var; // applying the stream insertion operator
```
### File Streams in C++ (III)
- Each file ends with an end-of-file marker (EOF).
  - **Check if at end of file using:**
```c++
fstr.eof();
```
- **Close a file using:**
```c++
fstr.close();
```

## Closing Thoughts
- Files are required for many applications.
- Files may be created and manipulated in any manner appropriate for an application.

## Complete Example of File Streams in C++
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Create an output file stream and write data to a file
    ofstream outFile("example.txt");
    if (!outFile) {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }
    outFile << "Hello, world!" << endl;
    outFile << "Writing to a file in C++." << endl;
    outFile.close(); // Close the file

    // Create an input file stream and read data from a file
    ifstream inFile("example.txt");
    if (!inFile) {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl; // Print each line to the console
    }
    inFile.close(); // Close the file

    return 0;
}
```




