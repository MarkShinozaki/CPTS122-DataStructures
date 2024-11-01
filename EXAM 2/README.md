# EXAM 2

## Questions and Answers

### Question 1
- **(4 pts)** Describe the concept of **inheritance** in Object-Oriented Programming (OOP).

**Answer:**
Inheritance allows a new class to inherit the properties and behavior (methods) of an existing class, enabling code reuse and establishing a relationship between the new class and the base class.

---

### Question 2
- **(4 pts)** What is the purpose of **function templates** in C++?

**Answer:**
Function templates enable the creation of generic functions that can operate on different data types, allowing code reusability without explicitly defining the data type for each specific use.

---

### Question 3
- **(2 pts)** A(n) `Character stream` is a sequence of characters transferred between a device and memory or vice versa.

---

### Question 4
- **(2 pts)** A(n) `pointer` holds the address of a variable and can be `NULL`.

---

### Question 5
- **(2 pts)** **Polymorphism** is a core OOP principle that allows functions or methods to work in multiple forms based on the input or type provided.

---

### Question 6
- **(2 pts)** Having multiple functions with identical names but varying parameters is called **function overloading**.

---

### Question 7
- **(2 pts)** When an object is assigned-by-value, the **assignment operator** is invoked.

---

### Question 8
- **(2 pts)** **Modularity** is the practice of breaking down a program into separate modules or parts, each responsible for a particular functionality, which allows isolated design changes.

---

### Question 9 
- (3 pts) Insert the sequence -12, 8, 30, 15 in descending order into a list. Draw the diagram for the list with connections.
  - **Answer: 30 → 15 → 8 → -12**

---

### Question 10 
- (4 pts) Insert the sequence -7, 40, 21, 0 into a binary search tree (BST) in the given order. Draw the BST with each node connected.
  
```
      -7
       \
       40
      /
    21
     \
      0
```

---

### Question 11

- (12 pts) Class definitions for Book and Library. Create two classes: Book, with **title** (string) and **pages** (int), and Library, a collection of up to 8 books.

  - **Part (a) - Book Class (8 pts)**
Define the Book class with private attributes, a constructor, getter and setter for **pages** with validation (min 1, max 1000), a **displayBook()** method, and an assignment operator.

Answer:

```
class Book {
public:
    Book(const std::string &title = "", int pages = 0) : mTitle(title), mPages(pages) {}

    std::string getTitle() const {
        return mTitle;
    }

    void setPages(int pages) {
        if (pages >= 1 && pages <= 1000) {
            mPages = pages;
        } else {
            std::cout << "Invalid page count. Must be between 1 and 1000." << std::endl;
        }
    }

    void displayBook() const {
        std::cout << mTitle << ", " << mPages << " pages" << std::endl;
    }

    Book& operator=(const Book &other) {
        if (this != &other) {
            mTitle = other.mTitle;
            mPages = other.mPages;
        }
        return *this;
    }

private:
    std::string mTitle;
    int mPages;
};
```

- Part (b) - Library Class (8 pts)

  - Define the Library class with a pointer to an array of Book objects, a destructor, a deep copy constructor, **totalPages()** method, **addBook()** method, and a stream insertion operator for displaying the list of books.

```
#include <iostream>

class Library {
private:
    Book *books;
    int mNumBooks;

public:
    Library() : mNumBooks(0) {
        books = new Book[8];
    }

    ~Library() {
        delete[] books;
    }

    Library(const Library &other) {
        mNumBooks = other.mNumBooks;
        books = new Book[8];
        for (int i = 0; i < mNumBooks; ++i) {
            books[i] = other.books[i];
        }
    }

    int totalPages() const {
        int total = 0;
        for (int i = 0; i < mNumBooks; ++i) {
            total += books[i].getPages();
        }
        return total;
    }

    bool addBook(const Book &book) {
        if (mNumBooks < 8) {
            books[mNumBooks++] = book;
            return true;
        }
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const Library &library) {
        for (int i = 0; i < library.mNumBooks; ++i) {
            os << library.books[i].getTitle() << ", " << library.books[i].getPages() << " pages";
            if (i != library.mNumBooks - 1) os << "; ";
        }
        return os;
    }
};
```

---

### Question 13

- (8 pts) Implement the **enqueue()** method for a Queue template class that manages memory on the heap.

  - **Answer**:

```
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

- (12 pts) Write the recursive **removeNode()** method for a BST that removes a node with specified data. Define BSTNode with **mpLeft**, **mpRight**, and **mData**.

  - **Answer**:

```
void BST::removeNode(BSTNode *&root, const std::string &data) {
    if (!root) return;
    if (data < root->mData) {
        removeNode(root->mpLeft, data);
    } else if (data > root->mData) {
        removeNode(root->mpRight, data);
    } else {
        if (!root->mpLeft && !root->mpRight) {
            delete root;
            root = nullptr;
        } else if (!root->mpLeft) {
            BSTNode *temp = root;
            root = root->mpRight;
            delete temp;
        } else if (!root->mpRight) {
            BSTNode *temp = root;
            root = root->mpLeft;
            delete temp;
        }
    }
}
```

---

### Question 15

- (10 pts) Implement **convertStrtoList()** that converts a list of nodes with character data to an integer if all characters are digits and within 10 digits. Return -1 otherwise.

  - **Answer:**

```
  int convertStrtoList(const List &list) {
    Node *current = list.getHeadPtr();
    int result = 0;
    int count = 0;

    while (current) {
        char ch = current->getData();
        if (!isdigit(ch)) return -1;

        result = result * 10 + (ch - '0');
        count++;
        if (count > 10) return -1;
        
        current = current->getNextPtr();
    }
    return result;
}
```
