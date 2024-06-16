// Data.h 
#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


//#include "Test.h"

class Data
{
private:
	int customerNumber;
	int serviceTime;
	int waitTime;
public:
	~Data();

#pragma region Constructors
	Data();
	Data(int customerNum, int serviceTime, int waitTime);
#pragma endregion

#pragma region Getters
	int getCustomerNum(void);
	int getServiceTime(void);
	int getWaitTime(void);
#pragma endregion

#pragma region Setters
	void setCustomerNum(int newNum);
	void setServiceTime(int newTime);
	void setWaitTime(int newTime);
#pragma endregion

};