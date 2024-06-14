# Quiz 2

## Questions 

1. **Implement a function `deleteAtPositionN()`**
- **Question:** Write a function `deleteAtPositionN()` for a singly-linked list that has the following declaration and precondition:
```c
int deleteAtPositionN(struct node **pHead, int n, int *pData);
```

Precondition: `n > 0`.

The function should find the node at position `n`, and delete it, using function `free()`. The data should be returned indirectly through `pData`, then the node must be released back to the heap. The first node in the list starts at position 1. The function should return 1 if a node was deleted; 0 otherwise. Assume that struct node is defined as follows:

```c
struct node {
    int data;
    struct node *pNext;
};
```

**Answer:**
```c
int deleteAtPositionN(struct node **pHead, int n, int *pData) {
    int success = 0, position = 1;
    struct node *pPrev = NULL, *pCur = *pHead;

    while ((pCur != NULL) && (position != n)) {
        pPrev = pCur;
        pCur = pCur->pNext;
        ++position;
    }

    if ((pCur != NULL) && (position == n)) {
        success = 1;
        *pData = pCur->data;

        if (pPrev != NULL) {
            pPrev->pNext = pCur->pNext;
        } else {
            *pHead = pCur->pNext;
        }

        free(pCur);
    }

    return success;
}
```

---


<p align= "center">
  <a href="https://github.com/MarkShinozaki/CPTS122-DataStructures/tree/Quizzes/Quiz%203">Quiz 3</a>
</p>
