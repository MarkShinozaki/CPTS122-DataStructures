// Queue.h

#include "QueueNode.h"


class Queue
{
private:
	QueueNode* head;
	QueueNode* tail;
public:
	void enqueue(int customerCounter, int serviceTime);
	void dequeue(void);
	void printQueue(void);
	void incrementWaitTime(void);
	void processCustomer(void);

#pragma region Constructors
	~Queue();
	Queue();
	Queue(QueueNode* head, QueueNode* tail);
#pragma endregion

#pragma region Getters
	QueueNode* getHead(void);
	QueueNode* getTail(void);
#pragma endregion

#pragma region Setters
	void setHead(QueueNode* newHead);
	void setTail(QueueNode* newTail);
#pragma endregion
};