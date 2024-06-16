#include "Test.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Test::enqueueOnEmptyQueue(void) {
    Queue testQueue;
    testQueue.enqueue(1, 10);
    testQueue.printQueue();
}

void Test::enqueueOneNodeQueue(void) {
    Queue testQueue;
    testQueue.enqueue(1, 10);
    testQueue.enqueue(2, 20);
    testQueue.printQueue();
}

void Test::dequeueOneNodeQueue(void) {
    Queue testQueue;
    testQueue.enqueue(1, 10);
    testQueue.dequeue();
    testQueue.printQueue();
}

void Test::dequeuTwoNodeQueue(void) {
    Queue testQueue;
    testQueue.enqueue(1, 10);
    testQueue.enqueue(2, 20);
    testQueue.dequeue();
    testQueue.printQueue();
}

void Test::runSimulationTest(void) {
    int runTime = (24 * 60);
    runSimulation(runTime);
}

void Test::runSimulation(int runTime) {
    int totalTimeRan = 0, expressArrival = 0, normalArrival = 0, customerCounter = 0;
    Queue normalQueue, expressQueue;

    srand(time(NULL));

    expressArrival = rand() % 5 + 1;
    normalArrival = rand() % 6 + 3;

    while (totalTimeRan < runTime) {
        if (expressArrival == 0) {
            int expressServiceTime = rand() % 5 + 1;
            customerCounter++;
            expressQueue.enqueue(customerCounter, expressServiceTime);
            cout << "Someone is entering the Express Queue" << endl;
            expressQueue.printQueue();
            expressArrival = rand() % 5 + 1;
        }
        if (normalArrival == 0) {
            int normalServiceTime = rand() % 6 + 3;
            customerCounter++;
            normalQueue.enqueue(customerCounter, normalServiceTime);
            cout << "Someone is entering the Normal Queue" << endl;
            normalQueue.printQueue();
            normalArrival = rand() % 6 + 3;
        }

        expressQueue.processCustomer();
        normalQueue.processCustomer();

        if (totalTimeRan % 10 == 0) {
            cout << "***************************** Express Queue *********************************" << endl;
            expressQueue.printQueue();
            cout << "***************************** Normal Queue **********************************" << endl;
            normalQueue.printQueue();
        }

        totalTimeRan++;
        normalArrival--;
        expressArrival--;
        normalQueue.incrementWaitTime();
        expressQueue.incrementWaitTime();
    }
}
