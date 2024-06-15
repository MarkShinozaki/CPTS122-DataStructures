# Programming Assignment 8: Data Analysis using Binary Search Trees - up to 2% of overall grade

## I. Learner Objectives:
**At the conclusion of this assignment, participants should be able to:**

- Analyze a basic set of requirements for implementing and testing a solution to a problem
- Design, implement and test classes in C++
- Design and apply inheritance
- Design with polymorphism
- Design and implement a dynamically linked binary search tree

## II. Prerequisites:
**Before starting this assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Compose basic C++ language programs
- Create basic test cases for a program
- Apply arrays, strings, and pointers
- Define and apply structs
- Compare and contrast public and private access specifiers in C++
- Describe what is an attribute or data member of a class
- Describe what is a method of a class
- Apply and implement overloaded functions
- Distinguish between pass-by-value and pass-by-reference
- Discuss classes versus objects

## III. Overview & Requirements:
**Summary:** In this assignment, you are implementing a system for detecting trends in consumer product data for a 48-hour period. We are interested in how trends change across different geographical areas. You have been provided with data from various retail stores throughout the United States. The provided data includes the store name, product type, units sold, and the transaction time (in minutes) relative to the start of the 48-hour period.

Your task is to process this data and store it in a binary search tree (BST). The BST will be printed in order to generate a report of the product sales trends. Specifically, the report will show:

- The product types and the number of units that were purchased the most
- The product types and the number of units that were purchased the least

### Class Design:
For this assignment, you are required to implement a dynamically linked binary search tree. You will first need to start by defining an abstract base class `Node`, which encapsulates the following:

**Data members:**
- `mData`: `std::string` // denotes protected
- `mPLeft`: `Node*`
- `mPRight`: `Node*`

**Member functions:**
- `virtual destructor` // denotes public
- `virtual insert()`, which accepts a string to set the data in the node; each pointer in the node is set to NULL
- `setters` - one for each data member (3 total should be defined)
- `getters` - one for each data member (3 total should be defined); the 2 defined to set the pointers should return a reference to the pointer, i.e., `Node*&`
- `pure virtual printData()`, which must be overridden in class `TransactionNode`

Next, define a class `TransactionNode`, which **publicly** inherits from abstract base class `Node`. Class `TransactionNode` must encapsulate the following:

**Data members:**
- `mUnits`: `int` // denotes private

**Member functions:**
- `destructor` // denotes public
- `default constructor`
- `getter`
- `setter`
- `printData()`, which overrides the pure virtual function in class `Node`

Now define a class `BST`, which encapsulates the following:

**Data members:**
- `mpRoot`: `Node*` // yes, we want a pointer to a `Node`, not `TransactionNode`

**Member functions:**
- `destructor` // calls `destroyTree()`
- `destroyTree()`, yes, it's private, and it should visit each node in postOrder to delete them
- `insert()`, yes, it's private, and it dynamically allocates a `TransactionNode` and inserts recursively in the correct physical spots and prints the units; should pass a reference to a pointer, i.e., `Node*&`
- `inOrderTraversal()`, yes, once again it's private to hide pointer information
- `findSmallest()`, yes, once again each node's printData() prints the units; this function returns a pointer to the node with the smallest units
- `findLargest()`, yes, it returns a pointer to the node with the largest units

Lastly, define a class `DataAnalysis`, which encapsulates the following:

**Data members:**
- `mTreeSold`: `BST`
- `mTreePurchased`: `BST`
- `mCsvStream`: `ifstream`

**Member functions:**
- `runAnalysis()`
- `openFile()`, yes, it's private, and it should open the file
- `readFile()`, yes, it's private, and it should call the insert function of the appropriate tree based on the data
- `insertData()`, yes, it's private, and it inserts a node in either the sold or purchased tree based on the type

### What should go in main()?
```cpp
DataAnalysis obj;
obj.runAnalysis();
```

## Questions to Ponder:
Questions for you to consider (you do not need to submit answers to these questions):

- We understand that a BST is most efficient when it is balanced. If the data.csv file was not already organized to provide a fairly balanced tree, how would you balance the tree as you insert?
- Do you know what other data structures would be better suited for this problem?

## V. Grading Guidelines:
This assignment is worth 100 points. Your assignment will be evaluated based on adherence to the requirements. We will grade according to the following criteria:

- 5 pts - Appropriate top-down design, style, commenting according to class standards
- 5 pts - Appropriate design and implementation of the following classes, which inherits from the Node class, and all member functions:
  - 10 pts - BST
  - 5 pts - Destructor
  - 5 pts - Insert
  - 5 pts - Print
  - 5 pts - findSmallest
  - 5 pts - findLargest
  - 5 pts - InOrderTraversal
- 5 pts - DataAnalysis
- 15 pts - Reading the file data.csv
- 5 pts - Appropriate file stream management
- 15 pts - Correctly inserting the data into the tree and inserting in the appropriate node, based on sold or purchased
- 15 pts - Correctly identifying the trends and displaying them to the screen
- 10 pts - Printing the data
- 5 pts - Correctly destroying the tree and releasing the memory
- BONUS 15 pts - Correct implementation of the class template for both BSTNode and BST

---

## Summary and Step Guide for Completing the Assignment

1. **Understand the Requirements:**
   - Carefully read through the assignment guidelines.
   - Identify the required classes (Node, TransactionNode, BST, DataAnalysis) and their functionalities.

2. **Set Up the Development Environment:**
   - Open your C++ IDE (e.g., Microsoft Visual Studio) and create a new project.
   - Ensure the project setup includes necessary header (.h) and source (.cpp) files.

3. **Define the Node Class:**
   - Create the `Node` class:
     - Define data members: `mData`, `mPLeft`, `mPRight`.
     - Implement necessary member functions: destructor, insert, setters, getters, pure virtual printData.

4. **Define the TransactionNode Class:**
   - Create the `TransactionNode` class inheriting from `Node`:
     - Define data members: `mUnits`.
     - Implement necessary member functions: destructor, constructor, setter, getter, override printData.

5. **Define the BST Class:**
   - Create the `BST` class:
     - Define data members: `mpRoot`.
     - Implement necessary member functions: destructor (destroyTree), insert, inOrderTraversal, findSmallest, findLargest.

6. **Define the DataAnalysis Class:**
   - Create the `DataAnalysis` class:
     - Define data members: `mTreeSold`, `mTreePurchased`, `mCsvStream`.
     - Implement necessary member functions: runAnalysis, openFile, readFile, insertData.

7. **Implement Main Function:**
   - Instantiate `DataAnalysis` object and call `runAnalysis` method.

8. **Write Test Cases:**
   - Write test cases to verify the correctness of each implemented function.
   - Ensure edge cases are considered and tested.

9. **Run the Analysis:**
   - Implement the logic to read data from `data.csv`, insert data into the appropriate BST, and generate reports.
   - Ensure the data is printed in the correct order and the BST functions as expected.

10. **Test and Validate:**
   - Run the program and validate outputs against expected results.
   - Debug any issues that arise during testing.

11. **Prepare Documentation:**
   - Create a readme.txt file with assumptions, referenced files, and additional information.

12. **Submit the Assignment:**
   - Zip the project files including code, header files, test plan, readme, and data files.
   - Email the zipped file to the provided address.

By following these steps, you can ensure that you have covered all aspects of the assignment and met the requirements effectively.

