// QueueNode.cpp

#include "QueueNode.h"


QueueNode::~QueueNode()
{

}

#pragma region Constructors
QueueNode::QueueNode()
{
	pData = nullptr;
	next = nullptr;
}
QueueNode::QueueNode(Data* newData)
{
	pData = newData;
	next = nullptr;
}
QueueNode::QueueNode(Data* newData, QueueNode* newNext)
{
	pData = newData;
	next = newNext;
}
#pragma endregion

#pragma region Getters
Data* QueueNode::getData(void)
{
	return pData;
}
QueueNode* QueueNode::getNext(void)
{
	return next;
}
#pragma endregion

#pragma region Setters
void QueueNode::setData(Data* newData)
{
	this->pData = newData;
}
void QueueNode::setNextNode(QueueNode* newNext)
{
	this->next = newNext;
}
#pragma endregion