#include "List.h"

List::List()
{
    mpHead = nullptr;
    mpTail = nullptr;
}

List::~List()
{
    cout << "deconstructor ~List()" << endl;
}

Node* List::getpHead() const
{
    return mpHead;
}

Node* List::getpTail() const
{
    return mpTail;
}

void List::setpHead(Node* newpHead)
{
    mpHead = newpHead;
}

void List::setpTail(Node* newpTail)
{
    mpTail = newpTail;
}

void List::insertAtFront(Record newRecord)
{
    insertAtFront(this->mpHead, newRecord);
}

void List::insertAtFront(Node*& node, Record newRecord)
{
    Node* pMem = new Node(newRecord);
    if (pMem != nullptr)
    {
        pMem->setpNext(mpHead);
        mpHead = pMem;
    }
}
