#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
private:
    Node* mpHead;
    Node* mpTail;
    fstream input;
    void insertAtFront(Node*& node, Record newRecord);

public:
    List();
    ~List();

    Node* getpHead() const;
    Node* getpTail() const;

    void setpHead(Node* newpHead);
    void setpTail(Node* newpTail);

    void insertAtFront(Record newRecord);
};

#endif // LIST_H
