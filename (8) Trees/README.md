# Trees

## What are Trees?
- A tree is a hierarchical data structure consisting of nodes connected by edges.
- Each tree has a root node from which all other nodes descend.
- Nodes can have zero or more child nodes.
- Trees are widely used in computer science for organizing data, enabling efficient search, insertion, and deletion operations.

## Key Concepts

### Node
- A node contains a value or data and pointers to its children.
- Example structure of a node in C:
    ```c
    typedef struct node {
        int data;
        struct node *left;
        struct node *right;
    } Node;
    ```
- Example structure of a node in C++:
    ```cpp
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    ```

### Root
- The topmost node of the tree.

### Edge
- The connection between two nodes.

### Leaf
- A node with no children.

### Subtree
- A tree consisting of a node and its descendants.

### Binary Tree
- A tree in which each node has at most two children, referred to as the left child and the right child.

## Basic Tree Operations

### Insertion
- Adding a new node to the tree.

### Deletion
- Removing a node from the tree.

### Traversal
- Visiting all the nodes in a specific order.

## Binary Tree Implementation in C

### Structure Definition
```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
```
### Insertion Function 
```c
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
```
### In-Order Traversal 
```c
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
```
### Main Function 
```c
int main() {
    Node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    
    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    
    return 0;
}
```
## Binary Tree Implementation in C++
### Structure Definition

```c
#include <iostream>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
```
### Insertion function 

```c
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
```
### In-Order Traversal
```c
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
```
### Main Function
```c
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    
    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    
    return 0;
}
```

## Key Differences Between C and C++ Implementations
- Memory Management:
  - In C, dynamic memory allocation is done using malloc() and free().
  - In C++, dynamic memory allocation is done using new and delete.
- Standard Libraries:
  - C uses <stdio.h> for input/output operations.
  - C++ uses <iostream> for input/output operations.
- Syntax:
  - C++ provides constructors for initializing objects, which is more concise and less error-prone.

## Conclusion 
- Trees are a fundamental data structure in computer science, providing efficient ways to store and manage hierarchical data. Understanding the implementation and manipulation of trees in both C and C++ is essential for efficient algorithm design and problem-solving.

--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(9)%20Classes%20%26%20Objects">Part 9: Classes & Objects</a>
</p>


















