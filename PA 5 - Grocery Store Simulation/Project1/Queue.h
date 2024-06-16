#pragma once
#include "QueueNode.h"

class Queue {
private:
    QueueNode* head;
    QueueNode* tail;
public:
    Queue();
    ~Queue();

    void enqueue(int customerCounter, int serviceTime);
    void dequeue(void);
    void printQueue(void);
    void incrementWaitTime(void);
    void processCustomer(void);

    QueueNode* getHead(void);
    QueueNode* getTail(void);

    void setHead(QueueNode* newHead);
    void setTail(QueueNode* newTail);
};
