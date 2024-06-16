#include "BSTNode.h"

BSTNode::BSTNode(char ch, const std::string& morse)
    : character(ch), morseCode(morse), left(nullptr), right(nullptr) {}
