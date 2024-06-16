#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <string>

class BST {
private:
    BSTNode* root;
    void insert(BSTNode*& node, char ch, const std::string& morse);
    std::string search(BSTNode* node, char ch) const;
    void destroy(BSTNode* node);

public:
    BST();
    ~BST();
    void insert(char ch, const std::string& morse);
    std::string search(char ch) const;
};

#endif // BST_H
