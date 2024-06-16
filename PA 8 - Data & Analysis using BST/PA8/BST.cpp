#include "BST.h"

// Sets the starting node in the tree to a nullptr 
BST::BST() {
    mpRoot = nullptr;
}

BST::~BST() {
    destroyTree(mpRoot);
    // Comment out the debug message to clean up output
    // cout << "Inside BST's destructor!\n" << endl;
}

Node* BST::getRoot() const {
    return mpRoot;
}

// creates root node in the BST
void BST::setRoot(Node* const newRoot) {
    mpRoot = newRoot;
}

// inserts Node into BST
void BST::insert(int newUnits, string newData) {
    insert(this->mpRoot, newUnits, newData);
}

// Traverses the BST in order 
void BST::inOrderTraversal() {
    inOrderTraversal(mpRoot);
}

// Finds smallest node in the BST 
TransactionNode& BST::findSmallest() {
    TransactionNode* pCur = (TransactionNode*)mpRoot;

    while (pCur->getLeft() != nullptr) {
        pCur = (TransactionNode*)pCur->getLeft();
    }
    return *pCur;
}

// Finds the largest node in the BST
TransactionNode& BST::findLargest() {
    TransactionNode* pCur = (TransactionNode*)mpRoot;

    while (pCur->getRight() != nullptr) {
        pCur = (TransactionNode*)pCur->getRight();
    }
    return *pCur;
}

//private member function
void BST::destroyTree(Node*& pTree) {
    //it should visit each node in postOrder to delete them
    if (pTree != nullptr) {
        destroyTree(pTree->getLeft());
        destroyTree(pTree->getRight());
        delete pTree;
        // Comment out the debug message to clean up output
        // cout << "Tree has been deleted\n" << endl;
    }
}

void BST::insert(Node*& pTree, int newUnits, string newData) {
    if (pTree == nullptr) {
        pTree = new TransactionNode(newData, newUnits);
    }
    else if (newUnits < dynamic_cast<TransactionNode*>(pTree)->getUnits()) {
        insert(pTree->getLeft(), newUnits, newData);
    }
    else if (newUnits > dynamic_cast<TransactionNode*>(pTree)->getUnits()) {
        insert(pTree->getRight(), newUnits, newData);
    }
    else {
        cout << "duplicate\n" << endl;
    }
}

void BST::inOrderTraversal(Node*& pTree) {
    if (pTree != nullptr) {
        inOrderTraversal(pTree->getLeft());
        pTree->printData(); // Corrected to use the overridden printData function
        cout << endl;
        inOrderTraversal(pTree->getRight());
    }
}

void BST::printTree(Node* node, int space, int height) {
    // Base case
    if (node == nullptr)
        return;

    space += height;

    // Process right child first
    printTree(node->getRight(), space, height);

    // Print current node after space
    cout << endl;
    for (int i = height; i < space; i++)
        cout << ' ';
    cout << node->getData() << " (" << dynamic_cast<TransactionNode*>(node)->getUnits() << ")" << endl;

    // Process left child
    printTree(node->getLeft(), space, height);
}
