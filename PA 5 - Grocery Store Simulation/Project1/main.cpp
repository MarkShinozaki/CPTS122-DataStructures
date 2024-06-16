// main.cpp
// Mark Shinozaki
// PA 5 - Grocery Store Simulation

#include "Test.h"


int main(void) {
	//do all the tests
	Test tester;
	tester.enqueueOnEmptyQueue();
	tester.enqueueOneNodeQueue();
	tester.dequeueOneNodeQueue();
	tester.dequeuTwoNodeQueue();
	//tester.runSimulationTest();

	int runTime = 0;
	cout << "Please enter the number of minutes you would like the simulation to run for." << endl;
	cin >> runTime;

	//start the program!
	tester.runSimulation(runTime);
	system("pause");
	return 0;
}