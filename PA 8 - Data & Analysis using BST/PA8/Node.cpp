#include "Node.h"

Node::Node(string newData)
{
    mData = newData;
    mpLeft = nullptr;
    mpRight = nullptr;
}

Node::~Node()
{
    // Comment out the debug message to clean up output
    // cout << "Inside Node's destructor!\n" << endl;
}

string Node::getData() const
{
    return mData;
}

Node*& Node::getLeft()
{
    return mpLeft;
}

Node*& Node::getRight()
{
    return mpRight;
}

void Node::setString(const string newData)
{
    mData = newData;
}

void Node::setLeft(Node* const newLeft)
{
    mpLeft = newLeft;
}

void Node::setRight(Node* const newRight)
{
    mpRight = newRight;
}

ostream& operator<<(ostream& lhs, const Node* newStudent)
{
    lhs << newStudent->getData();
    return lhs;
}
