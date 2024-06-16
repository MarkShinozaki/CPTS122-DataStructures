// Test.cpp

#include "Test.h"

void Test::enqueueOnEmptyQueue(void)
{
	Queue testQueue;
	testQueue.enqueue(1, 10);
	testQueue.printQueue();
}

void Test::enqueueOneNodeQueue(void)
{
	Queue testQueue;
	testQueue.enqueue(1, 10);
	testQueue.enqueue(2, 20);
	testQueue.printQueue();
}

void Test::dequeueOneNodeQueue(void)
{
	Queue testQueue;
	testQueue.enqueue(1, 10);
	testQueue.dequeue();
	testQueue.printQueue();
}

void Test::dequeuTwoNodeQueue(void)
{
	Queue testQueue;
	testQueue.enqueue(1, 10);
	testQueue.enqueue(2, 20);
	testQueue.dequeue();
	testQueue.printQueue();
}

void Test::runSimulationTest(void)
{
	int runTime = (24 * 60);
	runSimulation(runTime);
}

void Test::runSimulation(int runTime)
{
	int totalTimeRan = 0, expressArrival = 0, normalArrival = 0, customerCounter = 0;
	Queue normalQueue, expressQueue;

	//generate first customer arrival times
	expressArrival = rand() % 5 + 1;
	normalArrival = rand() % 6 + 3;

	while (totalTimeRan < runTime) {
		
		//see if it is time for someone to enter the line
		if (expressArrival == 0) {
			int expressServiceTime = rand() % 5 + 1;
			//add someone to the express lane
			customerCounter++;
			expressQueue.enqueue(customerCounter, expressServiceTime);
			cout << "Someone is entering the Express Queue" << endl;
			expressQueue.printQueue();
			//reset the arrival time
			expressArrival = rand() % 5 + 1;
		}
		if (normalArrival == 0) {
			int normalServiceTime = rand() % 6 + 3;
			//add someone to the normal line
			customerCounter++;
			normalQueue.enqueue(customerCounter, normalServiceTime);
			cout << "Someone is entering the Normal Queue" << endl;
			normalQueue.printQueue();
			//reset the arrival time
			normalArrival = rand() % 6 + 3;
		}

		//process the first person in both lines --> decrement their service time by 1-->if their service time == 0, then delete them from the queue
		expressQueue.processCustomer();
		normalQueue.processCustomer();

		//check to see if its been 10 minutes -- if we need to print the queue
		if (totalTimeRan % 10 == 0) {
			cout << "***************************** Express Queue*********************************" << endl;
			expressQueue.printQueue();
			cout << "***************************** Normal Queue**********************************" << endl;
			normalQueue.printQueue();
		}

		totalTimeRan++;
		normalArrival--;
		expressArrival--;
		normalQueue.incrementWaitTime();
		expressQueue.incrementWaitTime();

	}
}