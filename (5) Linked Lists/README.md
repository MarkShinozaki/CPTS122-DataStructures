# Data Structures & The Basics of a Linked List I

## How do we select a Data Structure?
- Select a data structure as follows:
  - Analyze the problem and requirements to determine the resource constraints for the solution.
  - Determine basic operations that must be supported.
    - Quantify resource constraints for each operation.
  - Select the data structure that best fits these requirements/constraints.

## How do we Select a Data Structure? 2
- Questions that must be considered:
  - Is the data inserted into the structure at the beginning or the end? Or are insertions interspersed with other operations?
  - Can data be deleted?
  - Is the data processed in some well-defined order, or is random access allowed?

## Other Considerations for Data Structures
- Each data structure has costs and benefits.
- Rarely is one data structure better than another in all situations.
- A data structure requires:
  - Space for each data item it stores.
  - Time to perform each basic operation.
  - Programming effort.

## Definition of Linked List
- A finite sequence of nodes, where each node may be only accessed sequentially (through links or pointers), starting from the first node.
- Also defined as a linear collection of self-referential structures connected by pointers.

## Conventions
- An uppercase first character of a function name indicates that we are referencing the List ADT operation.
- A lowercase first character of a function indicates our implementation.

## Struct Node
- For these examples, we'll use the following definition for Node:

```c
typedef struct node {
    char data;
    // self-referential
    struct node *pNext;
} Node;
```

