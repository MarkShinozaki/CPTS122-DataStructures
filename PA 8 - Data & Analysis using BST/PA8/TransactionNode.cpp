#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData) {
    mUnits = newUnits;
}

TransactionNode::~TransactionNode() {
    // Comment out the debug message to clean up output
    // cout << "Inside TransactionNode's destructor!\n" << endl;
}

int TransactionNode::getUnits() const {
    return mUnits;
}

void TransactionNode::setUnits(int newUnits) {
    mUnits = newUnits;
}

void TransactionNode::printData() const {
    cout << "Data: " << mData << " Units: " << getUnits() << endl;
}
