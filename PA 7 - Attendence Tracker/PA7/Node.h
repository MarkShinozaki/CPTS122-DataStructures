#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::string;

typedef struct record
{
    int record_number;
    int ID_number;
    string name;
    string email;
    string unit;
    string major;
    string level;
} Record;

class Node
{
private:
    Record mStudent;
    int mNumAbsences;
    Stack mpDateAbsences;
    Node* mpNext;

public:
    Node();
    Node(Record newStudent);
    ~Node();

    Record getStudent() const;
    int getNumAbsences() const;
    const Stack& getpDateAbsences() const;
    Stack& getpDateAbsences();
    const Node* getpNext() const;
    Node*& getpNext();

    void setStudent(Record newStudent);
    void setNumAbsences(int newNumAbsences);
    void setDateAbsences(Stack newpDateAbstance);
    void setpNext(Node* newpNext);

    friend ostream& operator<<(ostream& lhs, const Node* newStudent);
};

ostream& operator<<(ostream& lhs, const Record& newStudent);
ostream& operator<<(ostream& lhs, const Node* newStudent);

#endif // NODE_H
