#include "Data.h"

Data::~Data() {}

Data::Data() : customerNumber(0), serviceTime(0), waitTime(0) {}

Data::Data(int customerNum, int serviceTime, int waitTime)
    : customerNumber(customerNum), serviceTime(serviceTime), waitTime(waitTime) {}

int Data::getCustomerNum(void) {
    return customerNumber;
}

int Data::getServiceTime(void) {
    return serviceTime;
}

int Data::getWaitTime(void) {
    return waitTime;
}

void Data::setCustomerNum(int newNum) {
    customerNumber = newNum;
}

void Data::setServiceTime(int newTime) {
    serviceTime = newTime;
}

void Data::setWaitTime(int newTime) {
    waitTime = newTime;
}
