// Test.h 

#pragma once
#include "Queue.h"

class Test {
private:
public:
	void enqueueOnEmptyQueue(void);
	void enqueueOneNodeQueue(void);
	void dequeueOneNodeQueue(void);
	void dequeuTwoNodeQueue(void);
	void runSimulationTest(void);
	void runSimulation(int runTime);
};
