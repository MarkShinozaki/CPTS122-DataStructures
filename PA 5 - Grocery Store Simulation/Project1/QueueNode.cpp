#include "QueueNode.h"

QueueNode::~QueueNode() {
    delete pData;
}

QueueNode::QueueNode() : pData(nullptr), next(nullptr) {}

QueueNode::QueueNode(Data* newData) : pData(newData), next(nullptr) {}

QueueNode::QueueNode(Data* newData, QueueNode* newNext)
    : pData(newData), next(newNext) {}

Data* QueueNode::getData(void) {
    return pData;
}

QueueNode* QueueNode::getNext(void) {
    return next;
}

void QueueNode::setData(Data* newData) {
    pData = newData;
}

void QueueNode::setNextNode(QueueNode* newNext) {
    next = newNext;
}
