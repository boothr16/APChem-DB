#include <vector>
#include <stdexcept>
#include <iostream>
#include "Database.h"

Database::Database(int SIZE) {
	db.resize(SIZE);
	for (Student* i : db)
		i = nullptr;
	numStudents = 0;
}

Database::~Database() {
	for (Student* i : db)
		delete i;
}

void Database::AddStudent(const std::string& name, const int& score) {
	int idx = Lookup(name);
	if (idx == -1)
		throw std::runtime_error("Database full. Allocate more room.");
	Student* ptr = db[idx];
	if (!ptr) {
		db[idx] = new Student(name, score);
		std::cout << db[idx]->fullName << " added to the database." << std::endl;
		numStudents++;
	}
	else
		std::cout << "A record for " << db[idx]->fullName << " already exists." << std::endl;
}

void Database::GetStudent(const std::string& name) {
	int idx = Lookup(name);
	if (idx == -1) {
		std::cout << "Student not found." << std::endl;
		return;
	}
	Student* ptr = db[idx];
	if (!ptr) {
		std::cout << "Student not found." << std::endl;
	}
	else
		ptr->Print();
}

int Database::Hash(const std::string& name) {
	const int prime = 53; // parameter for string with capital and lower-case letters
	const int m = 1000000009;
	int hashVal = 0;
	int primeMultiplier = 1;

	for (char c : name) {
		hashVal = (hashVal + (c - 'a' + 1) * primeMultiplier) % m;
		primeMultiplier = (primeMultiplier * prime) % m;
	}
	return hashVal % db.size();
}

int Database::Lookup(const std::string& name) {
	int quadraticTerm = 1;
	const int startIdx = Hash(name);
	int idx = startIdx;
	while (true) {
		Student* ptr = db[idx];
		if (!ptr || ptr->fullName == name)
			return idx;
		idx = startIdx + (quadraticTerm * quadraticTerm);
		idx %= db.size();
		quadraticTerm++;
		if (idx == startIdx)
			return -1;
	}
}