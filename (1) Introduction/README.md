# Data Structures

## What is a Data Structure?
- A software construct describing the organization and storage of information.
  - Designed to be accessed efficiently.
  - Composite of related items.
- An implementation of an abstract data type (ADTs) to be defined later.
- Defined and applied for particular applications and/or tasks.

### Data Structures Exposed
- You've already seen a few fixed-sized data structures:
  - Arrays.
  - Structures or structs in C.

### Review of Basic C Data Structures (1)
- Recall an array is a collection of related data items.
  - Accessed by the same variable name and an index.
  - Data is of the same type.
  - Items are contiguous in memory.
  - Subscripts or indices must be integral and 0 or positive only.

### Review of Basic C Data Structures (2)
- Recall a structure or struct is a collection of related fields or variables under one name.
  - Represent real world objects.
  - Each field may be of a different data type.
  - The fields are contiguous in memory.
  - Example struct describing a dog:

```c
typedef struct dog {
    char *breed; // need to allocate memory for string separately
    char name[100]; // memory is included for string
    double weight;
} Dog;
```
### Expanding Data Structure Knowledge
- In this course, we will focus on dynamic data structures:
  - These grow and shrink at runtime.
  - The major dynamic data structures include:
    - Lists.
    - Stacks.
    - Queues.
    - Binary Trees.
    - Binary Search Trees.
   
### Basic Applications of Dynamic Data Structures
- Lists are collections of data items lined up in a row.
  - Insertions and deletions may be made anywhere.
  - May represent movie & music collections, grocery store lists, and many more.
- Stacks are restricted lists.
  - Insertions and deletions may be made at one end only.
  - These are Last in, First Out (LIFO) structures.
  - May be used with compilers & operating systems, and many more applications.

### Basic Applications of Dynamic Data Structures (continued)
- Queues are also restricted lists.
  - Insertions are made at the back of the queue and deletions are made from the front.
  - These are First in, First out (FIFO) structures.
- BSTs require linked data items.
  - Efficient for searching and sorting data.
  - May represent directories on a file system.
> [!NOTE]
> This course will focus on these dynamic data structures and corresponding implementations in both C and C++..

### Commonalities of C Dynamic Structures
- Dynamic growing and shrinking properties.
- Implemented with pointers.
  - Recall a pointer is a variable that stores as its contents the address of another variable.
  - Operators applied to pointers include:
    - Pointer declaration - i.e. char *ptr.
    - Dereference or indirection - i.e. *ptr.
    - Address of - i.e. &ptr.
    - Assignment - i.e. ptr1 = ptr2.
- Require the use of structs.
  - Actually self-referential structures for linked implementations.

### Self-Referential Structure
- A struct which contains a pointer field that represents an address of a struct of the same type
```c
typedef struct node {
    char data;
    // self-referential
    struct node *pNext;
} Node;
```
### Dynamic Memory Allocation / De-allocation in C
- The growing and shrinking properties may be achieved through functions located in <stdlib.h> including:
  - `malloc()` for allocating/growing memory.
  - `free()` for de-allocating/shrinking memory.
  - `realloc()` for resizing memory.
  - Also consider `calloc()`.


### Dynamic Memory Allocation / De-allocation Example
**Assume the following**:

```c 
Node *pItem = NULL;
```
- **How to use `malloc()`
  
```c
pItem = (Node *) malloc (sizeof (Node));
// Recall malloc() returns a void *, which should be typecasted
```

- **How to use `free()`**

```c
free(pItem);
// Requires the pointer to the memory to be de-allocated
```

- **How to use `realloc()`**
  
```c
pItem = realloc(pItem, sizeof(Node) * 2);
// Allocates space for two Nodes and returns pointer to beginning of resized memory
```

### Abstract Data Types (ADTs)
Each data structure has a corresponding model represented by the ADT.
The model defines the behavior of operations, but not how they should be implemented.

#### Definition of ADT
- Abstract Data Types (ADTs) according to NIST:
  
  - > "A set of values and associated operations that are precisely specified independent of any particular implementation."
  - > "An organization of information, usually in memory, for better algorithm efficiency, such as queue, stack, linked list, heap, dictionary, and tree, or conceptual unity, such as the name and address of a person. It may include redundant information, such as length of the list or number of nodes in a subtree."

### ADTs versus Data Structures
- Many people think that ADTs and Data structures are interchangeable in meaning.
  - ADTs are logical descriptions or specifications of data operations.
    - To abstract is to leave out concrete details.
  - Data structures are the actual representations of data and operations, i.e., implementation.
- Semantic versus syntactic.

### Specification of ADT
- Consists of at least 5 items:
  - Types/Data.
  - Functions/Methods/Operations.
  - Axioms.
  - Preconditions.
  - Postconditions.

### Example Specification of List ADT
- Description: A list is a finite sequence of nodes, where each node may be only accessed sequentially, starting from the first node.
- Types/Data:
  - `e` is the element type.
  - `L` is the list type.

### Example Specification of List ADT (continued)
- Functions/Methods/Operations:
  - `initList(L)`: Procedure to initialize the list `L` to empty.
  - `destroyList(L)`: Procedure to make an existing list `L` empty.
  - `listIsEmpty(L) -> b`: Boolean function to return TRUE if `L` is empty.
  - `listIsFull(L) -> b`: Boolean function to return TRUE if `L` is full.
  - `currIsEmpty(L) -> b`: Boolean function to return TRUE if the current position in `L` is empty.

### Example Specification of List ADT (continued)
- Functions/Methods/Operations Continued:
  - `toFirst(L)`: Procedure to make the current node the first node in `L`; if the list is empty, the current position remains empty.
  - `atFirst(L) -> b`: Boolean function to return TRUE if the current node is the first node in the list or if the list and the current position are both empty.
  - `atEnd(L) -> b`: Boolean function to return TRUE if the current node is the last node in the list or if the list and the current position are both empty.
  - `advance(L)`: Procedure to make the current position indicate the next node in `L`; if the current node is the last node, the current position becomes empty.

### Example Specification of List ADT (continued again)
- Functions/Methods/Operations Continued Again:
  - `insert(L, e)`: Procedure to insert a node with information e before the current position or, in case `L` was empty, as the only node in L; the new node becomes the current node.
  - `insertAfter(L, e)`: Procedure to insert a node with information e into `L` after the current node without changing the current position; in case L is empty, make a node containing e the only node in `L` and the current node.
  - `insertFront(L, e)`: Procedure to insert a node with information e into `L` as the first node in the list; in case `L` is empty, make a node containing e the only node in `L` and the current node.
  - `insertInOrder(L, e)`: Procedure to insert a node with information e into `L` as a node in the list, maintaining the order of the elements; in case L is empty, make a node containing e the only node in `L` and the current node.

### Example Specification of List ADT (final)
- Functions/Methods/Operations **Continued One Last Time**:
  - `delete(L)`: Procedure to delete the current node in L and to have the current position indicate the next node; if the current node is the last node, the current position becomes empty.
  - `storeInfo(L, e)`: Procedure to update the information portion of the current node to contain e; assume the current position is nonempty.
  - `retrieveInfo(L) -> e`: Function to return the information in the current node; assume the current position is nonempty.

### Example Specification of List ADT - Axioms, Preconditions, Postconditions

- Axioms:
  - Empty ()?
  - Not empty ()?
  - Others?
- Preconditions:
  - `delete()` requires that the list is not empty ().
- Postconditions:
  - After `insert()` is executed, the list is not empty ().
  - Others?
 
--- 

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Lectures-Slides/(2)%20Recursion">Part 2: Recursion Review</a>
</p>
