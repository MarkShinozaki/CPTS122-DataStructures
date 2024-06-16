#pragma once
#include "Data.h"

class QueueNode {
private:
    Data* pData;
    QueueNode* next;
public:
    ~QueueNode();

    QueueNode();
    QueueNode(Data* newData);
    QueueNode(Data* newData, QueueNode* newNext);

    Data* getData(void);
    QueueNode* getNext(void);

    void setData(Data* newData);
    void setNextNode(QueueNode* newNext);
};
