#include "Data.h"

Data::Data() : recordNumber(0), ID(0), absenceCount(0) {}

Data::Data(int recordNum, int id, const std::string& name, const std::string& email, const std::string& credits, const std::string& classLevel)
    : recordNumber(recordNum), ID(id), name(name), email(email), credits(credits), classLevel(classLevel), absenceCount(0) {}

int Data::getRecordNumber() const { return recordNumber; }
int Data::getID() const { return ID; }
std::string Data::getName() const { return name; }
std::string Data::getEmail() const { return email; }
std::string Data::getCredits() const { return credits; }
std::string Data::getClassLevel() const { return classLevel; }
int Data::getAbsenceCount() const { return absenceCount; }
std::string Data::getMostRecentAbsence() const { return absenceCount > 0 ? absenceDates.back() : ""; }

void Data::setRecordNumber(int recordNum) { recordNumber = recordNum; }
void Data::setID(int id) { ID = id; }
void Data::setName(const std::string& name) { this->name = name; }
void Data::setEmail(const std::string& email) { this->email = email; }
void Data::setCredits(const std::string& credits) { this->credits = credits; }
void Data::setClassLevel(const std::string& classLevel) { this->classLevel = classLevel; }
void Data::incrementAbsenceCount() { absenceCount++; }
void Data::addAbsenceDate(const std::string& date) { absenceDates.push_back(date); }
