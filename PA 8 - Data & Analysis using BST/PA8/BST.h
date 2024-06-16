#ifndef BST_H
#define BST_H

#include "TransactionNode.h"

class BST {

private:
    Node* mpRoot;

    void destroyTree(Node*& pTree); //it should visit each node in postOrder to delete them
    void insert(Node*& pTree, int newUnits, string newData);
    void inOrderTraversal(Node*& pTree);

public:
    BST();
    ~BST();

    Node* getRoot() const;

    void setRoot(Node* const newRoot);

    void insert(int newUnits, string newData);
    void inOrderTraversal();

    TransactionNode& findSmallest();
    TransactionNode& findLargest();

    void printTree(Node* node, int space = 0, int height = 10);
};

#endif // BST_H
