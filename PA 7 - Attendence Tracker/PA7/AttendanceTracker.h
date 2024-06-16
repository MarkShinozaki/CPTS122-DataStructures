#ifndef ATTENDANCETRACKER_H
#define ATTENDANCETRACKER_H

#include "List.h"
#include <string>

class AttendanceTracker
{
private:
    List mList;
    ifstream input;
    ofstream output;
    fstream masterFile;

public:
    friend ifstream& operator>>(ifstream& input, List& rhs);
    friend fstream& operator>>(fstream& input, List* rhs);

    AttendanceTracker();
    ~AttendanceTracker();

    void displayMenu();
    void markAbsences(List* pList);
    void editAbsences();
    void generateReports();
    void printReport1(List* pList);
    void printReport2(List* pList, int absences);
};

ifstream& operator>>(ifstream& input, List& rhs);
fstream& operator>>(fstream& masterFile, List* rhs);
fstream& operator<<(fstream& lhs, List& rhs);
ofstream& operator<<(ofstream& output, Node& rhs);

#endif // ATTENDANCETRACKER_H
