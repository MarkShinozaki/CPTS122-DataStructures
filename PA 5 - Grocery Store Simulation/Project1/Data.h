#pragma once
#include <iostream>
#include <string>

class Data {
private:
    int customerNumber;
    int serviceTime;
    int waitTime;
public:
    ~Data();
    Data();
    Data(int customerNum, int serviceTime, int waitTime);

    int getCustomerNum(void);
    int getServiceTime(void);
    int getWaitTime(void);

    void setCustomerNum(int newNum);
    void setServiceTime(int newTime);
    void setWaitTime(int newTime);
};
