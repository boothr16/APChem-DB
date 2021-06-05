#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <string>
#include "Student.h"

class Database {
private:
	std::vector<Student*> db; // vector of pointers to students. empty spaces in vector set to NULLPTR.
	int numStudents;
	int Hash(const std::string& name); // hash student name into an DB index, called by Add/Get student
	int Lookup(const std::string& name);

public:
	Database(int SIZE = 79);
	~Database(); // dtor necessary to free dynamically allocated memory
	void AddStudent(const std::string& name, const int& score);
	void GetStudent(const std::string& name);
};
#endif
