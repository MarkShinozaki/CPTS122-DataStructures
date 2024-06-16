# EXAM 2 

## Questions and Answers

### Question 1
- (4 pts) There are 4 pillars in Object-Oriented Programming (OOP). Abstraction, encapsulation, inheritance, and polymorphism. Provide a definition for abstraction.

**Answer:**
Abstraction is a key design aspect of object-oriented programming. It transforms complex systems into more simplified objects by hiding the complex implementation details and showing only the necessary features of an object.

---

### Question 2
- **(4 pts) What is a class template? Explain.**

**Answer:**
A class template serves as a pattern for creating other similar functions. The exact types required for the function do not need to be specified until it is called, at which point the compiler will replace the placeholder types with actual types.

---

### Question 3
- **(2 pts) A(n) `Binary stream` is a sequence of objects (generally just considered bytes) that flow from a device to memory or from memory to a device.**
  
### Question 4
- **(2 pts) A(n) `reference` is another name for a variable and cannot be NULL.**

### Question 5
- **(2 pts) `Encapsulation` is an Object-Oriented Programming concept that binds together the data and functions that manipulate the data, and that keeps both safe from outside interference and misuse.**

### Question 6
- **(2 pts) It is possible to have various functions with the same name that operate on different types or number of arguments. This is called function `overloading`.**

### Question 7
- **(2 pts) When an object is returned-by-value or passed-by-value, a(n) `copy constructor` is invoked.**

### Question 8
- **(2 pts) Information `encapsulation` is the principle of separating design decisions in a module or object from the rest of the system. In objects, different visibilities may be used to restrict the impact of change to a small subset of the program.**

---

### Question 9
**(3 pts) Circle one: Given the following nonmember function prototype which multiplies two `Rational` numbers and returns the result:**
```cpp
Rational multiply(Rational &lhs, Rational rhs);
```
Which of the following functions are implicitly invoked when `multiply()` is initially called?
- A. The default constructor for lhs
- B. The copy constructor for lhs
- C. The default constructor for rhs
- **D. The copy constructor for rhs**
- E. The destructor for lhs and rhs
- F. None of the above
- G. All of the above

---

### Question 10
- (3 pts) Given the following sequence of numbers: -5, 100, 33, -10. If the numbers are inserted into a list in ascending (smallest to largest) order, then what would the list look like? Draw a diagram for the list. Connect the rest of the nodes.

**Answer:**
-5 → -10 → 33 → 100

---

### Question 11
- (4 pts) Given the following sequence of numbers: -5, 100, 33, -10. If the numbers are inserted into a linked binary search tree (BST) in the sequence provided, then what would the tree look like? Draw a diagram for the BST. The root node has been given to you. Connect the rest of the nodes.
```
      -5
     /  \
  -10   100
        /
      33
```
---

### Question 12
- (12 pts) Course List with Courses (Parts a - i). Let’s say we need to design two classes, one named Course and one named CourseList. Each Course consists of one std::string representing the course title (mCourseTitle) and one integer value representing the number of credits for the class (mCredits). A standard CourseList is defined by at most 6 courses and between 12 - 18 credits.

#### (a) (8 pts) Declare the Course class based on the description above. There are many operations that we could define for a Course, but we are only going to look at a subset for this problem. All attributes/data members should be private. The class should declare the following public member operations/functions only. Note: partial credit will NOT be provided for the function declarations:

- (1 pt) A constructor that specifies two arguments `newCourseTitle` and `newCredits` and sets them to default values of empty string and 0, respectively.
- (1 pt) A const function called `getCourseTitle()` for returning a copy of `mCourseTitle`.
- (1 pt) A function called `setCredits()` for modifying the credits pertaining to a course. The input parameter should be a constant. Credits can’t be below 1 or above 4 credits. You must validate the parameter. If it’s invalid display a message indicating so and leave the credits unchanged.
- (1 pt) A function called `displayCourse()` for displaying to the screen the length of the course information in the form: `mCourseTitle`, `mCredits` credits.
- (2 pts) The copy assignment operator that assigns one `Course` to another through memberwise assignment.
  
**Answer:**
```cpp
class Course {
public:
    Course(const std::string &newCourseTitle = "", int newCredits = 0) : mCourseTitle(newCourseTitle), mCredits(newCredits) {}

    std::string getCourseTitle() const {
        return mCourseTitle;
    }

    void setCredits(const int credits) {
        if (credits >= 1 && credits <= 4) {
            mCredits = credits;
        } else {
            std::cout << "Invalid credits. Credits must be between 1 and 4." << std::endl;
        }
    }

    void displayCourse() const {
        std::cout << mCourseTitle << ", " << mCredits << " credits" << std::endl;
    }

    Course& operator=(const Course &other) {
        if (this != &other) {
            mCourseTitle = other.mCourseTitle;
            mCredits = other.mCredits;
        }
        return *this;
    }

private:
    std::string mCourseTitle;
    int mCredits;
};
```
#### (b) (8 pts) Declare the CourseList class. Recall, the class should declare a private pointer to a Course. The pointer will be set to the start of an array (on the heap) of Courses of max size 6 in the constructor. The class should also declare one other private data member representing the number of courses (mNumCourses) taken. Once again, there are many operations that we could define for a CourseList, but we are only going to look at a subset for this problem. All attributes/data members should be private. The class should declare the following public member operations/functions only. Note: partial credit will NOT be provided for the function declarations:

- (1 pt) A destructor.
- (1 pt) A deep copy constructor.
- (1 pt) A function called computeTotalCredits(), which computes and returns the total number of credits taken for a given CourseList.
- (1 pt) A function called addCourse(), which adds a new Course to the current CourseList. The new course should be passed in by constant reference. The function returns true if the course was added successfully; false otherwise.
- (2 pts) The output stream insertion operator that displays the course list in the form: Course Title 1, Credits 1 credits, Course Title 2, Credits 2 credits, etc. for each course.

**Answer:**
```cpp
#include <iostream>
#include <string>

class Course {
public:
    std::string title;
    int credits;

    Course(const std::string &title = "", int credits = 0) : title(title), credits(credits) {}
};

class CourseList {
private:
    Course *courses;
    int mNumCourses;

public:
    // Constructor
    CourseList() : mNumCourses(0) {
        courses = new Course[6];
    }

    // Destructor
    ~CourseList() {
        delete[] courses;
    }

    // Deep copy constructor
    CourseList(const CourseList &other) {
        mNumCourses = other.mNumCourses;
        courses = new Course[6];
        for (int i = 0; i < mNumCourses; ++i) {
            courses[i] = other.courses[i];
        }
    }

    // Compute total credits
    int computeTotalCredits() const {
        int totalCredits = 0;
        for (int i = 0; i < mNumCourses; ++i) {
            totalCredits += courses[i].credits;
        }
        return totalCredits;
    }

    // Add course
    bool addCourse(const Course &course) {
        if (mNumCourses < 6) {
            courses[mNumCourses++] = course;
            return true;
        }
        return false;
    }

    // Output stream insertion operator
    friend std::ostream &operator<<(std::ostream &os, const CourseList &courseList) {
        for (int i = 0; i < courseList.mNumCourses; ++i) {
            os << courseList.courses[i].title << ", Credits " << courseList.courses[i].credits << " credits";
            if (i != courseList.mNumCourses - 1) {
                os << "; ";
            }
        }
        return os;
    }
};
```
#### (c) (2 pts) Definition for setCredits() function. The function modifies the credits pertaining to a course. The input parameter should be a constant. Credits can’t be below 1 or above 4 credits. You must validate the parameter. If it’s invalid display a message indicating so and leave the credits unchanged.

**Answer:**
```cpp
void setCredits(const int credits) {
    if (credits >= 1 && credits <= 4) {
        mCredits = credits;
    } else {
        std::cout << "Invalid credits. Credits must be between 1 and 4." << std::endl;
    }
}
```
#### (d) (4 pts) Definition for the copy assignment operator. The function assigns one Course to another through memberwise assignment. You must check for self-assignment.

**Answer:**
```cpp
Course& operator=(const Course &other) {
    if (this != &other) {
        mCourseTitle = other.mCourseTitle;
        mCredits = other.mCredits;
    }
    return *this;
}
```
#### (e) (2 pts) Definition for the destructor.

**Answer:**
```cpp
~CourseList() {
    delete[] courses;
}
```
#### (f) (4 pts) Definition for the deep copy constructor.

**Answer:**
```cpp
CourseList(const CourseList &other) {
    mNumCourses = other.mNumCourses;
    courses = new Course[6];
    for (int i = 0; i < mNumCourses; ++i) {
        courses[i] = other.courses[i];
    }
}
```
#### (g) (4 pts) Definition for the computeTotalCredits() function. The function computes and returns the total number of credits taken for a given CourseList.

**Answer:**
```cpp
int computeTotalCredits() const {
    int totalCredits = 0;
    for (int i = 0; i < mNumCourses; ++i) {
        totalCredits += courses[i].credits;
    }
    return totalCredits;
}
```
#### (h) (4 pts) Definition for the addCourse() function. The function adds a new Course to the current CourseList at the next available slot in the list. The function returns true if the course was added successfully; false otherwise. Recall, a CourseList can’t exceed 6 Courses.

**Answer:**
```cpp
bool addCourse(const Course &course) {
    if (mNumCourses < 6) {
        courses[mNumCourses++] = course;
        return true;
    }
    return false;
}
```
#### (i) (4 pts) Definition for the output stream insertion operator that displays an entire CourseList. You must use the displayCourse() function in class Course.

**Answer:**
```cpp
friend std::ostream &operator<<(std::ostream &os, const CourseList &courseList) {
    for (int i = 0; i < courseList.mNumCourses; ++i) {
        os << courseList.courses[i].title << ", Credits " << courseList.courses[i].credits << " credits";
        if (i != courseList.mNumCourses - 1) {
            os << "; ";
        }
    }
    return os;
}
```

--- 

### Question 13
(8 pts) Given the following Queue class template, write the function template for the enqueue() function. Note: the queue is constructed by using an array allocated on the heap.

```cpp
template <class T>
class Queue {
public:
    Queue(int newSize = 0);
    ~Queue();

    bool enqueue(T &newItem);
    bool dequeue(T &removedItem);

    bool isEmpty();

private:
    int mSize;       // represents the number of items currently in the queue
    int mMaxSize;    // must not exceed the max size of our allocated array
    T *mpContainer;  // will point to the beginning of contiguous memory on the heap (an array)
};
```
Place your function template for enqueue() below.

- Description: inserts the item at the tail of the queue. You may assume that any necessary overloaded operators to perform the insert are available for type T. A successful insertion increases mSize by 1.

- Returns: true if the item was inserted into the contiguous memory; false otherwise.

- Precondition: mpContainer must already point to contiguous memory; specifically item at index 0.

**Answer:**

```cpp
template <class T>
bool Queue<T>::enqueue(T &newItem) {
    if (mSize < mMaxSize) {
        mpContainer[mSize++] = newItem;
        return true;
    }
    return false;
}
```
---

### Question 14
(12 pts) In this problem, you will be working with a dynamically linked binary search tree (BST). Given a class BSTNode with the following private data members:
```cpp
BSTNode *mpLeft;
BSTNode *mpRight;
string mData;
```
**and the following public member functions:**

```cpp
BSTNode (const string &newData);
BSTNode *getLeft();
BSTNode *getRight();
string getData();
```
**and a class BST with the following private data member:**

```cpp
BSTNode *mpRoot;
```

- Write an appropriate recursive insert() method that is a member of the BST class. The function should accept a reference to a pointer to a BSTNode and a const reference to the data to insert. The function does not need to return a value. However, no makeNode() function exists.

**Answer:**

```cpp
void BST::insert(BSTNode *&pRoot, const string &newData) {
    if (pRoot == nullptr) {
        pRoot = new BSTNode(newData);
    } else if (newData < pRoot->getData()) {
        insert(pRoot->mpLeft, newData);
    } else {
        insert(pRoot->mpRight, newData);
    }
}
```

---

### Question 15

(10 pts) Write a convertStrtoInt() nonmember function that accepts a reference to List container (dynamically singly linked), converts the sequence of characters contained in each Node of the List to the corresponding integer representation for the collection of characters in the List. The List does not contain a null character. In the successful case, the function returns the converted integer value. In the unsuccessful case, the sequence contains a nondigit character or the number of digit characters exceeds a valid integer size which is 10 digits, then -1 is returned. For example, given the following cases:

**Case 1: List => 1 ➔ 2 ➔ 3 ➔ 4 ➔ 5, Result = 12345.**

**Case 2: List => 1 ➔ A ➔ 3 ➔ c ➔ 5, Result = -1.**

**Case 3: List => 1 ➔ 2 ➔ 3 ➔ 4 ➔ 5 ➔ 6 ➔ 7 ➔ 8 ➔ 9 ➔ 0 ➔ 1, Result = -1.**

Given: a class Node with the following private data members only:

```cpp
Node *mpNext;
char mData;
```
and the following public member functions:

```cpp
Node *getNextPtr();
char getData();
```
and a class List with the following private data member only:

```cpp
Node *mpHead;  // points to the front of the list
```
and the following public member function:

```cpp
Node *getHeadPtr();

// Precondition: list must not be empty!
// Assumption: negative digit sequences are not considered.
```
**Answer:**
```cpp
int convertStrtoInt(const List &list) {
    Node *current = list.getHeadPtr();
    int result = 0;
    int digitCount = 0;
    
    while (current != nullptr) {
        char ch = current->getData();
        if (!isdigit(ch)) {
            return -1;
        }
        result = result * 10 + (ch - '0');
        digitCount++;
        if (digitCount > 10) {
            return -1;
        }
        current = current->getNextPtr();
    }
    
    return result;
}
```










