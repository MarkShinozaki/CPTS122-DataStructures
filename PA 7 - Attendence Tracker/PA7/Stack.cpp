#include "Stack.h"

Stack::Stack(int newSize)
{
    mDateAbs = new string[100];
    mMaxSize = 100;
    mIndex = newSize;
}

Stack::~Stack()
{
    delete[] mDateAbs;
}

string* const& Stack::getDateAbs() const
{
    return mDateAbs;
}

int Stack::getMaxSize() const
{
    return mMaxSize;
}

int Stack::getIndex() const
{
    return mIndex;
}

void Stack::setMaxSize(int newMaxSize)
{
    mMaxSize = newMaxSize;
}

void Stack::setIndex(int newIndex)
{
    mIndex = newIndex;
}

void Stack::push(const string& newDateAbs)
{
    setIndex(getIndex() + 1);
    this->mDateAbs[this->mIndex] = newDateAbs;
}

void Stack::pop(string& poppedDateAbs)
{
    poppedDateAbs = this->mDateAbs[this->mIndex];
    this->mIndex--;
}

bool Stack::peek(string& dateAbs) const
{
    return (getIndex() == getMaxSize());
}

bool Stack::isEmpty() const
{
    return (getIndex() == 0);
}
