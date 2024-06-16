#include "Node.h"

Node::Node()
{
    mStudent.record_number = 0;
    mStudent.ID_number = 0;
    mStudent.name = "";
    mStudent.email = "";
    mStudent.unit = "";
    mStudent.major = "";
    mStudent.level = "freshman";
    mNumAbsences = 0;
    mpNext = nullptr;
}

Node::Node(Record newStudent)
{
    mStudent = newStudent;
    mNumAbsences = 0;
    mpNext = nullptr;
}

Node::~Node()
{
    cout << "deconstructor ~Node()" << endl;
}

Record Node::getStudent() const
{
    return mStudent;
}

int Node::getNumAbsences() const
{
    return mNumAbsences;
}

const Stack& Node::getpDateAbsences() const
{
    return mpDateAbsences;
}

Stack& Node::getpDateAbsences()
{
    return mpDateAbsences;
}

const Node* Node::getpNext() const
{
    return mpNext;
}

Node*& Node::getpNext()
{
    return mpNext;
}

void Node::setStudent(Record newStudent)
{
    mStudent = newStudent;
}

void Node::setNumAbsences(int newNumAbsences)
{
    mNumAbsences = newNumAbsences;
}

void Node::setDateAbsences(Stack newpDateAbstance)
{
    mpDateAbsences = newpDateAbstance;
}

void Node::setpNext(Node* newpNext)
{
    mpNext = newpNext;
}

ostream& operator<<(ostream& lhs, const Record& newStudent)
{
    lhs << " -record number: " << newStudent.record_number << endl;
    lhs << " -ID : " << newStudent.ID_number << endl;
    lhs << " -Name : " << newStudent.name << endl;
    lhs << " -Email : " << newStudent.email << endl;
    lhs << " -Unit : " << newStudent.unit << endl;
    lhs << " -Major : " << newStudent.major << endl;
    lhs << " -Level : " << newStudent.level << endl;

    return lhs;
}

ostream& operator<<(ostream& lhs, const Node* newStudent)
{
    lhs << newStudent->getStudent();
    lhs << "The number of Absence : " << newStudent->getNumAbsences() << endl;
    lhs << "The recent date of Absence : " << newStudent->getpDateAbsences().getDateAbs()[newStudent->getpDateAbsences().getIndex()] << endl;
    return lhs;
}
