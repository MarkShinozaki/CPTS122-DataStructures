/******************************************************************************
* Programmer: Mark Shinozaki											      *
* Class: CptS 122;                                                            *
* Programming Assignment: PA 5 - Grocery Store Simulation                     *
*                                                                             *
* Description: Simulate two Grocery Store lines using Queues                  *
******************************************************************************/

#include "Test.h"
#include <iostream>
using namespace std;

int main(void) {
    Test tester;
    tester.enqueueOnEmptyQueue();
    tester.enqueueOneNodeQueue();
    tester.dequeueOneNodeQueue();
    tester.dequeuTwoNodeQueue();

    int runTime = 0;
    cout << "Please enter the number of minutes you would like the simulation to run for." << endl;
    cin >> runTime;

    tester.runSimulation(runTime);
    return 0;
}
