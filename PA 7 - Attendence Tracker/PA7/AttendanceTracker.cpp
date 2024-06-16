#define _CRT_SECURE_NO_WARNINGS
#include "AttendanceTracker.h"
#include <string>
#include <ctime> // Include this for time functions

AttendanceTracker::AttendanceTracker()
{
    displayMenu();
}

AttendanceTracker::~AttendanceTracker()
{
    cout << "Inside ListApp's destructor! Closing open files!" << endl;
    if (input.is_open())
    {
        input.close();
    }
}

void AttendanceTracker::displayMenu()
{
    int menu = 0;
    do
    {
        cout << endl << "********< MENU >********" << endl;
        cout << "1. Import course list" << endl;
        cout << "2. Load master list" << endl;
        cout << "3. Store master list" << endl;
        cout << "4. Mark absences" << endl;
        cout << "5. Edit absences" << endl;
        cout << "6. Generate report" << endl;
        cout << "7. Exit" << endl << endl;
        cout << "Select Menu: ";
        cin >> menu;
        system("cls");
        switch (menu)
        {
        case 1:
            input.open("classList.csv");
            if (input.is_open())
            {
                cout << "\"class List\" file open successfully!" << endl;
                input >> mList;
            }
            else
            {
                cout << "\"class List\" file was not opened.." << endl;
            }
            input.close();
            break;
        case 2:
            masterFile.open("master.txt", std::ios::in);
            if (masterFile.is_open())
            {
                cout << "\"master.txt\" file open successfully!" << endl;
                masterFile >> &mList;
            }
            else
            {
                cout << "\"master.txt\" file was not opened..." << endl;
            }
            masterFile.close();
            break;
        case 3:
            masterFile.open("master.txt", std::ios::out);
            if (masterFile.is_open())
            {
                cout << "\"master.txt\" file open successfully!" << endl;
                masterFile << mList;
            }
            else
            {
                cout << "\"master.txt\" file was not opened..." << endl;
            }
            masterFile.close();
            break;
        case 4:
            markAbsences(&mList);
            break;
        case 5:
            editAbsences();
            break;
        case 6:
            generateReports();
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (menu != 7);
}

void AttendanceTracker::markAbsences(List* pList)
{
    char YorN = '\0';
    string year = "", month = "", date = "", today = "";
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);

    Node* pCur = pList->getpHead();

    year = std::to_string(now.tm_year + 1900);
    month = std::to_string(now.tm_mon + 1);
    date = std::to_string(now.tm_mday);
    today = year + '-' + month + '-' + date;

    cout << "- Mark Absences for today (";
    cout << (now.tm_year + 1900) << '-' << (now.tm_mon + 1) << '-' << now.tm_mday << ")" << endl << endl;
    cout << "[student List]" << endl;

    while (pCur != nullptr)
    {
        do
        {
            cout << "Name: " << pCur->getStudent().name << endl;
            cout << " - Absent?(Y/N)  :";
            cin >> YorN;
            cout << endl;
        } while ((YorN != 'Y') && (YorN != 'y') && (YorN != 'N') && (YorN != 'n'));

        if ((YorN == 'Y') || (YorN == 'y'))
        {
            pCur->setNumAbsences(pCur->getNumAbsences() + 1);
            pCur->getpDateAbsences().push(today);
        }

        pCur = pCur->getpNext();
    }
}

void AttendanceTracker::editAbsences()
{
    // Implement editing absences for a student
}

void AttendanceTracker::generateReports()
{
    int menu1 = 0, absences = 0;
    do
    {
        cout << "***********************************" << endl;
        cout << "1. Generate report for all students" << endl;
        cout << "2. Generate report for students whose absences exceed" << endl;
        cout << "- Select Menu : ";
        cin >> menu1;
        system("cls");
    } while ((menu1 != 1) && (menu1 != 2));

    if (menu1 == 1)
    {
        printReport1(&mList);
    }
    else if (menu1 == 2)
    {
        cout << "* Find student with absences match or exceed *" << endl;
        cout << "Enter the number of absence :";
        cin >> absences;
        printReport2(&mList, absences);
    }
}

void AttendanceTracker::printReport1(List* pList)
{
    int i = 0;
    Node* pCur = pList->getpHead();

    output.open("Report1.txt", std::ios::trunc);
    if (output.is_open())
    {
        cout << "output file \"Report1.txt\" open successfully!" << endl;
        output << "[ Report for All students ]" << endl << endl;

        while (pCur != nullptr)
        {
            cout << ++i << ')' << endl << pCur->getStudent();
            cout << "The number of Absence : " << pCur->getNumAbsences() << endl;
            if (pCur->getNumAbsences() == 0)
            {
                cout << "there is no absence record" << endl << endl;
            }
            else
            {
                cout << "The most recent date of Absence: " << pCur->getpDateAbsences().getDateAbs()[pCur->getpDateAbsences().getIndex()] << endl << endl;
            }
            output << pCur << endl;
            pCur = pCur->getpNext();
        }
    }
    else
    {
        cout << "output file \"Report1.txt\" was not opened...." << endl;
    }

    output.close();
}

void AttendanceTracker::printReport2(List* pList, int absences)
{
    int i = 1;
    Node* pCur = pList->getpHead();
    output.open("Report2.txt", std::ios::trunc);
    if (output.is_open())
    {
        cout << "output file \"Report2.txt\" open successfully!" << endl;
        output << "[ Report for the students who absent over " << absences << " times ]" << endl << endl;
        while (pCur != nullptr)
        {
            if (pCur->getNumAbsences() >= absences)
            {
                cout << pCur << endl;
                output << pCur;
                output << "record of absent dates" << endl;
                for (i = 1; i <= pCur->getNumAbsences(); ++i)
                {
                    output << "/" << pCur->getpDateAbsences().getDateAbs()[i];
                }
                output << endl << endl;
            }
            pCur = pCur->getpNext();
        }
    }
    else
    {
        cout << "output file \"Report2.txt\" was not opened...." << endl;
    }
    output.close();
}

ifstream& operator>>(ifstream& input, List& rhs)
{
    char line[100] = "";
    input.getline(line, 100);
    Record newStudent;

    while (!input.eof())
    {
        input.getline(line, 100, ',');
        newStudent.record_number = atoi(line);

        input.getline(line, 100, ',');
        newStudent.ID_number = atoi(line);

        input.getline(line, 100, '"');
        input.getline(line, 100, '"');
        newStudent.name = line;

        input.getline(line, 100, ',');
        input.getline(line, 100, ',');
        newStudent.email = line;

        input.getline(line, 100, ',');
        newStudent.unit = line;

        input.getline(line, 100, ',');
        newStudent.major = line;

        input.getline(line, 100, '\n');
        newStudent.level = line;

        cout << newStudent << endl;

        rhs.insertAtFront(newStudent);
    }
    return input;
}

fstream& operator>>(fstream& masterFile, List* rhs)
{
    char line[100] = "";
    string line_S = "";
    Record newStudent;
    Node* pCur = rhs->getpHead();

    while (!masterFile.eof())
    {
        masterFile >> newStudent.record_number;
        masterFile >> newStudent.ID_number;
        masterFile >> newStudent.name;
        masterFile >> newStudent.email;
        masterFile >> newStudent.unit;
        masterFile >> newStudent.major;
        masterFile >> newStudent.level;

        pCur->setStudent(newStudent);

        masterFile >> line;
        pCur->setNumAbsences(atoi(line));

        masterFile >> line;
        line_S = line;
        pCur->getpDateAbsences().push(line_S);

        pCur = pCur->getpNext();
    }
    return masterFile;
}

fstream& operator<<(fstream& lhs, List& rhs)
{
    Node* pCur = rhs.getpHead();
    while (pCur != nullptr)
    {
        lhs << pCur->getStudent().record_number << endl;
        lhs << pCur->getStudent().ID_number << endl;
        lhs << pCur->getStudent().name << endl;
        lhs << pCur->getStudent().email << endl;
        lhs << pCur->getStudent().unit << endl;
        lhs << pCur->getStudent().major << endl;
        lhs << pCur->getStudent().level << endl;
        lhs << pCur->getNumAbsences() << endl;
        lhs << '/' << pCur->getpDateAbsences().getDateAbs()[pCur->getpDateAbsences().getIndex()] << endl << endl;

        pCur = pCur->getpNext();
    }
    return lhs;
}

ofstream& operator<<(ofstream& output, Node& rhs)
{
    output << rhs;
    return output;
}

