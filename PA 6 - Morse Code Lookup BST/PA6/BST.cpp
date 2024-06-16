#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr) {}

BST::~BST() {
    destroy(root);
}

void BST::insert(BSTNode*& node, char ch, const std::string& morse) {
    if (node == nullptr) {
        node = new BSTNode(ch, morse);
    }
    else if (ch < node->character) {
        insert(node->left, ch, morse);
    }
    else {
        insert(node->right, ch, morse);
    }
}

std::string BST::search(BSTNode* node, char ch) const {
    if (node == nullptr) {
        return "";
    }
    else if (ch == node->character) {
        return node->morseCode;
    }
    else if (ch < node->character) {
        return search(node->left, ch);
    }
    else {
        return search(node->right, ch);
    }
}

void BST::insert(char ch, const std::string& morse) {
    insert(root, ch, morse);
}

std::string BST::search(char ch) const {
    return search(root, ch);
}

void BST::destroy(BSTNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}
