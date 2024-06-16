#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::string;

class Stack
{
public:
    Stack(int newSize = 0);
    ~Stack();

    string* const& getDateAbs() const; // Marked as const
    int getMaxSize() const;
    int getIndex() const; // Marked as const

    void setMaxSize(int newMaxSize);
    void setIndex(int newIndex);

    void push(const string& newDateAbs); // const correctness
    void pop(string& poppedDateAbs);
    bool peek(string& dateAbs) const; // Marked as const
    bool isEmpty() const; // Marked as const

private:
    string* mDateAbs;
    int mMaxSize;
    int mIndex;
};

#endif // STACK_H
