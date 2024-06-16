// Queue.cpp

#include "Queue.h"

void Queue::enqueue(int customerCounter, int serviceTime) {
	Data* newCustomer = new Data(customerCounter, serviceTime, 0);
	QueueNode* newNode = new QueueNode(newCustomer);

	if (head == nullptr) //then the queue is empty
	{
		head = newNode;
		tail = newNode;
	}
	else //not empty
	{
		tail->setNextNode(newNode);
		tail = newNode;
	}

}

void Queue::dequeue(void)
{
	if (head == nullptr) {
		cout << "The Queue is empty." << endl;
	}
	else if (head->getNext() == nullptr) {
		head->~QueueNode();
		head = nullptr;
		tail = nullptr;
	}
	else {
		QueueNode* temp = head;
		head = head->getNext();
		delete temp;
	}
}

void Queue::printQueue(void)
{
	QueueNode* current = head;
	while (current != nullptr)
	{
		Data* temp = current->getData();
		cout << "Customer Number: " << temp->getCustomerNum() << endl;
		cout << "Service Time: " << temp->getServiceTime() << endl;
		cout << "Wait Time: " << temp->getWaitTime() << endl;
		cout << "----------------------------------------------------------------------------" << endl;
		current = current->getNext();
	}
}

void Queue::incrementWaitTime(void)
{
	QueueNode* current = head;
	while (current != nullptr)
	{
		int temp = current->getData()->getWaitTime();
		temp++;
		current->getData()->setWaitTime(temp);
		current = current->getNext();
	}
}

void Queue::processCustomer(void)
{
	if (head != nullptr) {
		int temp = head->getData()->getServiceTime();
		temp--;
		head->getData()->setServiceTime(temp);
		if (head->getData()->getServiceTime() == 0) {
			cout << "A customer has been helped." << endl;
			dequeue();
		}
	}

}

#pragma region Constructors
Queue::~Queue(void)
{

}
Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}
Queue::Queue(QueueNode* head, QueueNode* tail)
{
	this->head = head;
	this->tail = tail;
}
#pragma endregion

#pragma region Getters
QueueNode* Queue::getHead(void)
{
	return head;
}
QueueNode* Queue::getTail(void)
{
	return tail;
}
#pragma endregion

#pragma region Setters
void Queue::setHead(QueueNode* newHead)
{
	this->head = newHead;
}
void Queue::setTail(QueueNode* newTail)
{
	this->tail = newTail;
}
#pragma endregion