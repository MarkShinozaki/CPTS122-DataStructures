#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::ostream;

// Abstract base class Node
class Node {
protected:
    string mData;
    Node* mpLeft;
    Node* mpRight;

public:
    Node(string newData = "");
    virtual ~Node();

    string getData() const;
    Node*& getLeft();
    Node*& getRight();

    void setString(const string newData);
    void setLeft(Node* const newLeft);
    void setRight(Node* const newRight);

    virtual void printData() const = 0; // Pure virtual function

    // Declare operator<< as a friend function
    friend ostream& operator<<(ostream& lhs, const Node* newStudent);
};

ostream& operator<<(ostream& lhs, const Node* newStudent);

#endif // NODE_H
