# Programming Assignment 6: Morse Code Lookup BST

## I. Learner Objectives
**At the conclusion of this programming assignment, participants should be able to:**

- Design, implement, and test a Binary Search Tree (BST)
- Apply a BST for looking up Morse Codes
- Discuss classes versus objects
- Implement container classes

## II. Prerequisites
**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose basic C++ language programs
- Create basic test cases for a program
- Apply arrays, strings, and pointers
- Design, implement, and apply classes
- Design, implement, and apply linked lists

## III. Overview & Requirements
Recall, a Binary Search Tree (BST) data structure is a nonlinear data structure. A BST is traversed by starting at the root of the tree. The root node is the first node inserted into the tree. Nodes are inserted into the tree such that all nodes in the left subtree are less than, and all nodes in the right subtree are greater than this item. Also, this property holds true for each node, meaning all items to the left of a parent node are less, and all items to the right of a parent node are greater.

In this assignment, you will be using a BST to convert English characters to Morse code strings. Morse code is a famous coding scheme that assigns a series of dots and dashes to each letter of the alphabet, each digit, and a few special characters. In sound-oriented systems, the dot represents a short sound and the dash represents a long sound. Other representations of dots and dashes are used with light-oriented systems and signal-flag systems (from Deitel and Deitel *C How to Program*).

**Morse Code Alphabet:**

| Character | Morse Code | Character | Morse Code | Character | Morse Code |
|-----------|------------|-----------|------------|-----------|------------|
| A         | .-         | N         | -.         | 0         | -----      |
| B         | -...       | O         | ---        | 1         | .----      |
| C         | -.-.       | P         | .--.       | 2         | ..---      |
| D         | -..        | Q         | --.-       | 3         | ...--      |
| E         | .          | R         | .-.        | 4         | ....-      |
| F         | ..-.       | S         | ...        | 5         | .....      |
| G         | --.        | T         | -          | 6         | -....      |
| H         | ....       | U         | ..-        | 7         | --...      |
| I         | ..         | V         | ...-       | 8         | ---..      |
| J         | .---       | W         | .--        | 9         | ----.      |
| K         | -.-        | X         | -..-       | .         | .-.-.-     |
| L         | .-..       | Y         | -.--       | ,         | --..--     |
| M         | --         | Z         | --..       | ?         | ..--..     |
|           |            |           |            | /         | -..-.      |
|           |            |           |            | FULLSTOP  | .-.-.-     |
|           |            |           |            | COMMA     | --..--     |
|           |            |           |            | QUERY     | ..--..     |

### Task 1. Defining the BSTNode structure
For the first part of the assignment, you should start by designing the BSTNode class for the BST. Create a class for the BSTNode data that will have as its members a character and a string. The character will hold the English text character, and the string will hold the corresponding Morse code characters for that English text character. You must also define left and right pointers that point to BSTNode objects. You must have a constructor that accepts arguments to set the English text character and Morse code string.

### Task 2. Creating the BST class
Next, you should be able to read in the Morse table from a file called "MorseTable.txt". You should arrange the nodes so that they are alphabetically ordered from left to right. Create a print() function that uses recursion to traverse the tree in order (left nodes, root node, right nodes). Also, build a search() function that will return the Morse code string for each English character searched for. Do you need to return a found indicator from the search function? Should you use recursion? Finally, implement a destructor, which destroys the entire tree.

### Task 3. Putting the pieces together
First, print the current tree. Next, you must open a file called "Convert.txt", which consists of English alphabetic characters, spaces, and periods. You should "look" for each English character in the tree, and, for each character in "Convert.txt", convert the character into a Morse code string. Each Morse character in the string will be separated by a space. Each complete word will be separated by three spaces. Each character to be converted should be represented in the tree. Note: you should ensure you only traverse English characters to uppercase before processing the English text.

### Example Input and Morse Code Output:
```
This is the cpts 122
.... .. ... / .. ... / - .... . / -.-. .--. - ... / .---- ..--- ..---
```


## IV. Submitting Assignments:
1. Using Canvas (https://canvas.wsu.edu/), please submit your solution to the correct "Programming Assignments (PA)" folder. Your solution should be zipped into a .zip file with the name `<your_last_name>_PA6.zip` and uploaded. To upload your solution, please navigate to your correct Canvas lab course space. Select the "Assignments" link in the main left menu bar. Navigate to the correct PA submission folder. Click the "Start Assignment" button. Click the "Upload File" button. Choose the appropriate .zip file with your solution. Finally, click the "Submit Assignment" button.

2. Your project must contain at least two header files (.h files) and three C++ source files (.cpp files) that include all required implementations and tests.

3. Your project must build properly. The most points an assignment can receive if it does not build properly is 65 out of 100.

## V. Grading Guidelines:
This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:

- 5 pts - Appropriate top-down design, style, file organization (each class should be in its own .h file), and commenting according to class standards
- 15 pts - Defining the BSTNode structure
- 10 pts - Correct setting of pointers for node (char, string, left and right pointers)
- 5 pts - Correct constructor
- 10 pts - Creating the BST code and creating a Morse lookup BST
- 5 pts - Correct definition of BST root
- 10 pts - Correct implementation of insert function
- 5 pts - Correct implementation of search function
- 5 pts - Correct implementation of destructor
- 5 pts - Correct print function
- 10 pts - Correct opening and reading of "MorseTable.txt"
- 5 pts - Correct conversion of characters of "Convert.txt"
- 10 pts - Correct printing of converted English to Morse code
- 10 pts - Correct opening and reading of "Convert.txt"
- 5 pts - Correct printing Morse code to screen
- BONUS 15 pts - Working BSTNode and BST class template

---

# Summary and Step Guide for Completing the Assignment

1. **Understand the Requirements**
   - Carefully read through the assignment guidelines.
   - Identify the required classes (BSTNode and BST) and their functionalities.

2. **Set Up the Development Environment**
   - Open Microsoft Visual Studio 2019 and create a new project.
   - Ensure the project setup includes necessary header (.h) and source (.cpp) files.

3. **Define Classes and Member Functions**
   - Create the BSTNode class:
     - Define data members: character (English text), string (Morse code), and pointers to left and right BSTNode objects.
     - Implement necessary member functions and constructor.
   - Create the BST class:
     - Define data members: root (pointer to BSTNode).
     - Implement functions for inserting nodes, searching for nodes, printing the tree (in-order traversal), and destructor.

4. **Read and Build the Morse Lookup BST**
   - Implement file reading functionality to read from "MorseTable.txt".
   - Insert nodes into the BST to build the Morse code lookup tree.
   - Ensure the tree is alphabetically ordered and balanced if necessary.

5. **Convert English to Morse Code**
   - Implement functionality to read from "Convert.txt".
   - Convert each character to its corresponding Morse code using the BST lookup.
   - Ensure proper formatting with spaces between Morse code characters and words.
   - Print the converted Morse code to the screen.

6. **Implement Bonus (Optional)**
   - Consider implementing a BSTNode and BST class template to accommodate different types.

7. **Test the Program**
   - Write test cases to verify the correctness of BST operations (insert, search, print, destructor).
   - Ensure edge cases are considered and tested.

8. **Prepare Documentation**
   - Write a short write-up on your Morse code conversion.
   - Create a readme.txt file with assumptions, referenced files, and additional information.

9. **Submit the Assignment**
   - Zip the project files including code, header files, test plan, readme, and data files.
   - Upload the zipped file to the appropriate Canvas assignment submission folder.
