#ifndef BSTNODE_H
#define BSTNODE_H

#include <string>

class BSTNode {
public:
    char character;
    std::string morseCode;
    BSTNode* left;
    BSTNode* right;

    BSTNode(char ch, const std::string& morse);
};

#endif // BSTNODE_H
