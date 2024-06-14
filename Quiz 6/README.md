# Quiz 6
## Questions 

### **1.What is a binary search tree (BST)? Describe the properties of a BST in your answer. Also list one real-world example where a BST could be applied.**
**Answer:**
- A binary search tree (BST) is a binary tree in which each node has at most two children, referred to as the left child and the right child. The properties of a BST are:
  - The left subtree of a node contains only nodes with keys less than the node’s key.
  - The right subtree of a node contains only nodes with keys greater than the node’s key.
  - Both the left and right subtrees must also be binary search trees.
- Real-world example: A BST can be used in database indexing to quickly locate a record (e.g., finding a specific name in a phone directory).
---

### **2.Given the following sequence of numbers: 35, 50, 5, -5, 10, -1. If the numbers are inserted into a BST in the sequence provided, what would the tree look like? Draw a diagram for the BST. Be sure to show both branches of a given node.**
**Answer:**
```
        35
       /  \
      5    50
     / \
   -5   10
     \
     -1
```
---
### **3. Fill-in-the-blank - Using the BST constructed in question 2, answer the following questions:**
**Answers:**
#### i. At what level is the node containing number -5?
**`Answer: 2`**

#### ii. How many children does the node containing the number 10 have?
**`Answer: 0`**

#### iii. What is the height of the tree?
**`Answer: 3`**

#### iv. What is the height of the node containing 50?
**`Answer: 1`**

#### v. What is the depth of the node with value -1?
**`Answer: 3`**

#### vi. What is the depth of the root node?
**`Answer: 0`**

#### vii. What is the highest degree of a BST?
**`Answer: 2`**




---

<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%207">Quiz 7</a>
</p>
