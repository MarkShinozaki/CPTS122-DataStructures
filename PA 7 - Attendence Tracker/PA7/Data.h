#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

class Data {
private:
    int recordNumber;
    int ID;
    std::string name;
    std::string email;
    std::string credits;
    std::string classLevel;
    int absenceCount;
    std::vector<std::string> absenceDates;

public:
    Data();
    Data(int recordNum, int id, const std::string& name, const std::string& email, const std::string& credits, const std::string& classLevel);

    int getRecordNumber() const;
    int getID() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getCredits() const;
    std::string getClassLevel() const;
    int getAbsenceCount() const;
    std::string getMostRecentAbsence() const;

    void setRecordNumber(int recordNum);
    void setID(int id);
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setCredits(const std::string& credits);
    void setClassLevel(const std::string& classLevel);
    void incrementAbsenceCount();
    void addAbsenceDate(const std::string& date);
};

#endif // DATA_H
