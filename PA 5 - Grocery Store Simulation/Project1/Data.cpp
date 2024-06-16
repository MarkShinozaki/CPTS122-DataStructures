// Data.cpp

#include "Data.h"

Data::~Data()
{

}

#pragma region Constructors
Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	waitTime = 0;
}
Data::Data(int customerNum, int serviceTime, int waitTime)
{
	this->customerNumber = customerNum;
	this->serviceTime = serviceTime;
	this->waitTime = waitTime;
}
#pragma endregion

#pragma region Getters
int Data::getCustomerNum(void)
{
	return customerNumber;
}
int Data::getServiceTime(void)
{
	return serviceTime;
}
int Data::getWaitTime(void)
{
	return waitTime;
}
#pragma endregion

#pragma region Setters
void Data::setCustomerNum(int newNum)
{
	customerNumber = newNum;
}
void Data::setServiceTime(int newTime)
{
	serviceTime = newTime;
}
void Data::setWaitTime(int newTime)
{
	waitTime = newTime;
}
#pragma endregion