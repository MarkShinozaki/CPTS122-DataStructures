# Lab 7: Developing a (Linked) List Class in C++


### I. Learner Objectives

**At the conclusion of this programming assignment, participants should be able to:**

- Design, implement, and test a List class in C++
- Apply a customized linked List class
- Compare and contrast shallow versus deep copy
- Compare and contrast value classes versus container classes
- Apply and implement overloaded functions and operators
  
### II. Prerequisites
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

### III. Overview & Requirements

This lab, along with your TA, will help you navigate through designing, implementing, testing a List class in C++. It will also help you with understanding how to apply a List object to an application.

Labs are held in a “closed” environment such that you may ask your TA questions. Please use your TAs knowledge to your advantage. You are required to move at the pace set forth by your TA. Have a great time! Labs are a vital part to your education in Cpts 122 so work diligently.

**Tasks:**

1. Starting with the List code found at List Code:

a. Download the file and review main.cpp with your teammates. Answer questions 1-6, which are provided throughout this file. Use the debugger to help answer the questions!

b. Review the “ListNode.h”, “ListNode.cpp”, “List.h”, and “List.cpp” files to fill in the code for the functions listed below. Note: the ListNode class declaration (`ListNode.h`) and ListNode function implementation (`ListNode.cpp`) have already been defined for you!

c. Write the implementation for the deep copy constructor for the List class (found in “List.cpp”). After you finish writing your copy constructor, uncomment line 25 (`List list2 = list1`) in main().

d. Write the implementation for the overloaded assignment operator for the List class (found in “List.cpp”). After you finish writing your overloaded assignment operator, uncomment line 37 (`list2 = list1`) in main().

e. Test your copy constructor by calling it in main() (or within a test function).

f. Test your assignment operator by calling it in main() (or within a test function).

g. Write a test function to test the other methods in “List.cpp”. Test your function by calling it in main() (or within a test function).

h. Write a program that will compute the high, low, and mean scores in the “ExamScores.csv” file. The functions for reading and extracting the scores are already implemented in the List class. Your program should read in the list of scores, use the ListApp class to compute the high, low, and mean, and write the scores to a file called “ExamStats.txt”. You should test your ListApp class constructor takes care of opening the files!


## Solution Implemetion 

### ListNode Implementation 

**ListNode.h**

```c++
#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
public:
    ListNode(int data);

    int getData() const;
    void setData(int data);

    ListNode *getNext() const;
    void setNext(ListNode *next);

private:
    int mData;
    ListNode *mNext;
};

#endif
```

**ListNode.cpp**

```c++
#include "ListNode.h"

ListNode::ListNode(int data) : mData(data), mNext(nullptr) {}

int ListNode::getData() const {
    return mData;
}

void ListNode::setData(int data) {
    mData = data;
}

ListNode *ListNode::getNext() const {
    return mNext;
}

void ListNode::setNext(ListNode *next) {
    mNext = next;
}
```

### List Implementation

**List.h**

```c++
#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

class List {
public:
    List();
    ~List();
    List(const List &other); // Copy constructor
    List &operator=(const List &other); // Overloaded assignment operator

    void insertAtFront(int data);
    void insertAtBack(int data);
    bool removeFromFront(int &data);
    bool removeFromBack(int &data);
    bool isEmpty() const;
    void print() const;

private:
    ListNode *mHead;
    ListNode *mTail;

    void clear(); // Helper function to clear the list
    void copyList(const List &other); // Helper function to copy the list
};

#endif
```

**List.cpp**

```c++
#include "List.h"
#include <iostream>

List::List() : mHead(nullptr), mTail(nullptr) {}

List::~List() {
    clear();
}

List::List(const List &other) : mHead(nullptr), mTail(nullptr) {
    copyList(other);
}

List &List::operator=(const List &other) {
    if (this != &other) {
        clear();
        copyList(other);
    }
    return *this;
}

void List::insertAtFront(int data) {
    ListNode *newNode = new ListNode(data);
    if (isEmpty()) {
        mHead = mTail = newNode;
    } else {
        newNode->setNext(mHead);
        mHead = newNode;
    }
}

void List::insertAtBack(int data) {
    ListNode *newNode = new ListNode(data);
    if (isEmpty()) {
        mHead = mTail = newNode;
    } else {
        mTail->setNext(newNode);
        mTail = newNode;
    }
}

bool List::removeFromFront(int &data) {
    if (isEmpty()) {
        return false;
    } else {
        ListNode *temp = mHead;
        data = mHead->getData();
        mHead = mHead->getNext();
        delete temp;
        if (mHead == nullptr) {
            mTail = nullptr;
        }
        return true;
    }
}

bool List::removeFromBack(int &data) {
    if (isEmpty()) {
        return false;
    } else {
        ListNode *current = mHead;
        ListNode *previous = nullptr;
        while (current->getNext() != nullptr) {
            previous = current;
            current = current->getNext();
        }
        data = current->getData();
        delete current;
        if (previous == nullptr) {
            mHead = mTail = nullptr;
        } else {
            previous->setNext(nullptr);
            mTail = previous;
        }
        return true;
    }
}

bool List::isEmpty() const {
    return mHead == nullptr;
}

void List::print() const {
    ListNode *current = mHead;
    while (current != nullptr) {
        std::cout << current->getData() << " -> ";
        current = current->getNext();
    }
    std::cout << "NULL" << std::endl;
}

void List::clear() {
    int dummy;
    while (!isEmpty()) {
        removeFromFront(dummy);
    }
}

void List::copyList(const List &other) {
    ListNode *current = other.mHead;
    while (current != nullptr) {
        insertAtBack(current->getData());
        current = current->getNext();
    }
}
```

### Test Driver

**main.cpp**

```c++
#include "List.h"
#include <iostream>

void testCopyConstructor() {
    List list1;
    list1.insertAtBack(1);
    list1.insertAtBack(2);
    list1.insertAtBack(3);

    List list2 = list1;
    std::cout << "List 1: ";
    list1.print();
    std::cout << "List 2 (copy constructed): ";
    list2.print();
}

void testAssignmentOperator() {
    List list1;
    list1.insertAtBack(4);
    list1.insertAtBack(5);
    list1.insertAtBack(6);

    List list2;
    list2 = list1;
    std::cout << "List 1: ";
    list1.print();
    std::cout << "List 2 (assigned): ";
    list2.print();
}

void testListFunctions() {
    List list;
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtBack(30);

    std::cout << "List after insertions: ";
    list.print();

    int data;
    list.removeFromFront(data);
    std::cout << "Removed from front: " << data << std::endl;
    list.print();

    list.removeFromBack(data);
    std::cout << "Removed from back: " << data << std::endl;
    list.print();
}

int main() {
    testCopyConstructor();
    testAssignmentOperator();
    testListFunctions();
    return 0;
}
```

### ListApp Implementation for ExamScores
**ListApp.h**

```c++
#ifndef LISTAPP_H
#define LISTAPP_H

#include "List.h"
#include <fstream>

class ListApp {
public:
    ListApp(const std::string &inputFile, const std::string &outputFile);
    ~ListApp();

    void computeStatistics();

private:
    List mList;
    std::ifstream mInputFile;
    std::ofstream mOutputFile;

    void readScores();
    void writeStatistics();
};

#endif
```

**ListApp.cpp**
```c++
#include "ListApp.h"
#include <iostream>
#include <limits>

ListApp::ListApp(const std::string &inputFile, const std::string &outputFile)
    : mInputFile(inputFile), mOutputFile(outputFile) {
    if (!mInputFile.is_open() || !mOutputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }
}

ListApp::~ListApp() {
    if (mInputFile.is_open()) {
        mInputFile.close();
    }
    if (mOutputFile.is_open()) {
        mOutputFile.close();
    }
}

void ListApp::computeStatistics() {
    readScores();
    writeStatistics();
}

void ListApp::readScores() {
    int score;
    while (mInputFile >> score) {
        mList.insertAtBack(score);
    }
}

void ListApp::writeStatistics() {
    int high = std::numeric_limits<int>::min();
    int low = std::numeric_limits<int>::max();
    double sum = 0.0;
    int count = 0;
    int data;

    ListNode *current = mList.getHead();
    while (current != nullptr) {
        data = current->getData();
        if (data > high) {
            high = data;
        }
        if (data < low) {
            low = data;
        }
        sum += data;
        ++count;
        current = current->getNext();
    }

    double mean = (count == 0) ? 0.0 : sum / count;

    mOutputFile << "High: " << high << std::endl;
    mOutputFile << "Low: " << low << std::endl;
    mOutputFile << "Mean: " << mean << std::endl;
}
```
**main.cpp (for ListApp)**

```c++
#include "ListApp.h"
#include <iostream>

int main() {
    ListApp app("ExamScores.csv", "ExamStats.txt");
    app.computeStatistics();
    return 0;
}
```




































--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Labs/Lab%208">Lab 8</a>
</p>
