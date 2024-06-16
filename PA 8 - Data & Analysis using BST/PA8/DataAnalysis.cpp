#include "DataAnalysis.h"
#include <iostream> // Include the iostream header for cout and cin

void DataAnalysis::openCsvFile() {
    mCsvStream.open("data.csv");
    if (mCsvStream.is_open()) {
        cout << "\"data.csv\" opened successfully!\n" << endl;
    }
    else {
        cout << "\"data.csv\" did not open..." << endl;
    }
}

void DataAnalysis::readOneLine(int& units, string& type, string& transaction) {
    // A function that reads one line from the file and splits the line into units, type, and transaction fields
    char line[100] = { NULL };
    mCsvStream.getline(line, 100, ',');
    units = atoi(line);

    mCsvStream.getline(line, 100, ',');
    type = line;

    mCsvStream.getline(line, 100, '\n');
    transaction = line;
}

void DataAnalysis::readAllLines() {
    // A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs; use inOrderTraversal() to display the trees
    int units = 0;
    string type = "";
    string transaction = "";

    while (!mCsvStream.eof()) {
        readOneLine(units, type, transaction);
        insertToTree(units, type, transaction);
    }
    cout << "< Tree for Purchased transaction: In Order >" << endl;
    mTreePurchased.inOrderTraversal();
    cout << "< Tree for Sold transaction: In Order >" << endl;
    mTreeSold.inOrderTraversal();
}

void DataAnalysis::insertToTree(int& units, string& type, string& transaction) {
    // A function that compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased)
    if (transaction == "Purchased") {
        mTreePurchased.insert(units, type);
    }
    else if (transaction == "Sold") {
        mTreeSold.insert(units, type);
    }
}

void DataAnalysis::writeTree() {
    // A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least purchased and sold, and the most purchased and sold
    cout << "The Most Purchased Item: " << mTreePurchased.findLargest().getData() << " ( Units: " << mTreePurchased.findLargest().getUnits() << " )" << endl;
    cout << "The Most Sold Item: " << mTreeSold.findLargest().getData() << " ( Units: " << mTreeSold.findLargest().getUnits() << " )" << endl;
    cout << "The Least Purchased Item: " << mTreePurchased.findSmallest().getData() << " ( Units: " << mTreePurchased.findSmallest().getUnits() << " )" << endl;
    cout << "The Least Sold Item: " << mTreeSold.findSmallest().getData() << " ( Units: " << mTreeSold.findSmallest().getUnits() << " )" << endl << endl;
}

void DataAnalysis::runAnalysis() {
    // Aside from possibly a constructor and/or destructor; this function calls the other private functions
    openCsvFile();
    readAllLines();
    writeTree();
    printTrees(); // Call the new function to print the structure of the trees
    mCsvStream.close();
}

void DataAnalysis::printTrees() {
    // Print the structure of the trees visually
    cout << "Visual Representation of Purchased Tree:" << endl;
    mTreePurchased.printTree(mTreePurchased.getRoot());
    cout << endl;

    cout << "Visual Representation of Sold Tree:" << endl;
    mTreeSold.printTree(mTreeSold.getRoot());
    cout << endl;
}
