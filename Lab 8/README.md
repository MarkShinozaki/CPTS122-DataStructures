# Lab 8: Developing a Binary Search Tree (BST) Class and Application in C++

## I. Learner Objectives

**At the conclusion of this programming assignment, participants should be able to:**

- Design, implement, test, and apply a BST class in C++
- Compare and contrast value classes versus container classes
- Apply and implement overloaded functions and operators
- Discuss the properties of a BST
- Discuss the advantages and disadvantages of a BST

## II. Prerequisites

**Before starting this programming assignment, participants should be able to:**

- Analyze a basic set of requirements for a problem
- Create test cases for a program
- Design, implement and test classes in C++
- Declare and define constructors
- Declare and define destructors
- Compare and contrast public and private access specifiers in C++
- Describe what is an attribute or data member of a class
- Describe what is a method of a class
- Apply and implement overloaded functions
- Distinguish between pass-by-value and pass-by-reference
- Discuss classes versus objects

## III. Overview & Requirements
This lab, along with your TA, will help you navigate through designing, implementing, and testing a BST class in C++. It will also help you with understanding how to apply a BST object to an application.

Labs are held in a “closed” environment such that you may ask your TA questions. Please use your TAs knowledge to your advantage. You are required to move at the pace set forth by your TA. Have a great time! Labs are a vital part to your education in Cpts 122 so work diligently.

**Tasks:**

1. **Defining a class, BSTNode**

  - Start this task by defining the BSTNode class for the BST. For the initial development you should build the node class with a private std::string as its data. The BSTNode class should consist of only a string and left and right pointers to other nodes in the tree. Provide a constructor for your class. In addition, you should implement the getter and setter methods to manipulate a node. You will need access and/or modify the contents of the nodes using these methods. Implement the getters and setters. At this point in the task, your focus will be to insert strings into the BST and perform traversal. How will the getter methods get the BSTNode class? There are some useful things to consider. You should always pass the newData to the node using pass-by-reference. When a string is passed, a std::string is an object type, and hence, if the object is not passed by reference, then a copy of the object is made (std::string copy constructor is invoked). Is this the intent? Probably not!

2. **Create the BST class**

  - Implement a BST class. You are now ready to define the BST class. You should create a data member for a pointer that will be the root of the BST. The pointers should be of type BSTNode. You will also implement the constructor and the destructor (should destroy the tree through postorder traversing of nodes).

Additionally, you need:

  - **`insertNode()`** - that adds an item to the BST. Recall the properties of a BST. The values in any left subtree are less than its parent node, and any values in the right subtree are greater than its parent node. Use recursion in your implementation!

  - **`inOrderTraversal()`** - that prints the contents of the BST inOrder. Use recursion in your implementation!

  - **`preOrderTraversal()`** - that prints the contents of the BST preOrder. Use recursion in your implementation!

  - **`postOrderTraversal()`** - that prints the contents of the BST postOrder. Use recursion in your implementation!

  - **`isEmpty()`** - that is a Boolean function that indicates that the BST is empty or not.

  - **`destroyTree()`** - a private function, which is called from the destructor to delete each node in the BST through postorder traversal.

You will overload the stream insertion operator << to output a BST in an elegant way.

3. **Create an application to sort strings**

    - Create an application that populates an array with names (last, first) of your favorite people. Read the names from a text file, where each name is placed on a separate line in the form (last, first). Take the array and place all names in the array into a BST object. Traverse the BST inOrder (you will need to modify inOrder) and place the inOrder strings back into the original array. The array of people's names is now sorted.

**QUESTION:** When would it be a good idea to use a BST for sorting items? Do you know of other algorithms and data structures that are more efficient for a sorting task?


## Solution

### BSTNode Implementation

**BSTNode.h**

```c++
#ifndef BSTNODE_H
#define BSTNODE_H

#include <string>

class BSTNode {
public:
    BSTNode(const std::string &data);

    std::string getData() const;
    void setData(const std::string &data);

    BSTNode *getLeft() const;
    void setLeft(BSTNode *left);

    BSTNode *getRight() const;
    void setRight(BSTNode *right);

private:
    std::string mData;
    BSTNode *mLeft;
    BSTNode *mRight;
};

#endif
```
**BSTNode.cpp**

```c++
#include "BSTNode.h"

BSTNode::BSTNode(const std::string &data) : mData(data), mLeft(nullptr), mRight(nullptr) {}

std::string BSTNode::getData() const {
    return mData;
}

void BSTNode::setData(const std::string &data) {
    mData = data;
}

BSTNode *BSTNode::getLeft() const {
    return mLeft;
}

void BSTNode::setLeft(BSTNode *left) {
    mLeft = left;
}

BSTNode *BSTNode::getRight() const {
    return mRight;
}

void BSTNode::setRight(BSTNode *right) {
    mRight = right;
}
```

**BST.h**

```c++
#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <iostream>

class BST {
public:
    BST();
    ~BST();

    void insertNode(const std::string &data);
    void inOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    bool isEmpty() const;

    friend std::ostream &operator<<(std::ostream &os, const BST &bst);

private:
    BSTNode *mRoot;

    void insertNode(BSTNode *&node, const std::string &data);
    void inOrderTraversal(BSTNode *node) const;
    void preOrderTraversal(BSTNode *node) const;
    void postOrderTraversal(BSTNode *node) const;
    void destroyTree(BSTNode *node);
};

#endif
```
**BST.cpp**

```c++
#include "BST.h"

// Constructor
BST::BST() : mRoot(nullptr) {}

// Destructor
BST::~BST() {
    destroyTree(mRoot);
}

void BST::insertNode(const std::string &data) {
    insertNode(mRoot, data);
}

void BST::insertNode(BSTNode *&node, const std::string &data) {
    if (node == nullptr) {
        node = new BSTNode(data);
    } else if (data < node->getData()) {
        insertNode(node->getLeft(), data);
    } else {
        insertNode(node->getRight(), data);
    }
}

void BST::inOrderTraversal() const {
    inOrderTraversal(mRoot);
    std::cout << std::endl;
}

void BST::inOrderTraversal(BSTNode *node) const {
    if (node != nullptr) {
        inOrderTraversal(node->getLeft());
        std::cout << node->getData() << " ";
        inOrderTraversal(node->getRight());
    }
}

void BST::preOrderTraversal() const {
    preOrderTraversal(mRoot);
    std::cout << std::endl;
}

void BST::preOrderTraversal(BSTNode *node) const {
    if (node != nullptr) {
        std::cout << node->getData() << " ";
        preOrderTraversal(node->getLeft());
        preOrderTraversal(node->getRight());
    }
}

void BST::postOrderTraversal() const {
    postOrderTraversal(mRoot);
    std::cout << std::endl;
}

void BST::postOrderTraversal(BSTNode *node) const {
    if (node != nullptr) {
        postOrderTraversal(node->getLeft());
        postOrderTraversal(node->getRight());
        std::cout << node->getData() << " ";
    }
}

bool BST::isEmpty() const {
    return mRoot == nullptr;
}

void BST::destroyTree(BSTNode *node) {
    if (node != nullptr) {
        destroyTree(node->getLeft());
        destroyTree(node->getRight());
        delete node;
    }
}

std::ostream &operator<<(std::ostream &os, const BST &bst) {
    bst.inOrderTraversal(bst.mRoot);
    return os;
}
```

### Test Driver

**main.cpp**

```c++
#include "BST.h"
#include <iostream>
#include <fstream>

void testInsertNode() {
    BST bst;
    bst.insertNode("John");
    bst.insertNode("Doe");
    bst.insertNode("Alice");
    bst.insertNode("Bob");
    std::cout << "BST after insertions (in-order): ";
    bst.inOrderTraversal();
}

void testTraversals() {
    BST bst;
    bst.insertNode("John");
    bst.insertNode("Doe");
    bst.insertNode("Alice");
    bst.insertNode("Bob");
    std::cout << "BST in-order: ";
    bst.inOrderTraversal();
    std::cout << "BST pre-order: ";
    bst.preOrderTraversal();
    std::cout << "BST post-order: ";
    bst.postOrderTraversal();
}

void testBSTSort() {
    std::ifstream inputFile("names.txt");
    std::string name;
    BST bst;
    while (std::getline(inputFile, name)) {
        bst.insertNode(name);
    }
    inputFile.close();
    std::cout << "Sorted names (in-order traversal): ";
    bst.inOrderTraversal();
}

int main() {
    testInsertNode();
    testTraversals();
    testBSTSort();
    return 0;
}
```

### names.txt (Example Input File)
```
Doe, John
Smith, Jane
Adams, Samuel
Brown, Michael
Clark, Sarah
```

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%209">Lab 9</a>
</p>
