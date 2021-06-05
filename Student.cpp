#include <string>
#include <iostream>
#include <fstream>
#include "Student.h"

/*Student::Student() {
	fullName = "";
	examScore = 0;
}*/

Student::~Student() {}

Student::Student(const Student& s) {
	fullName = s.fullName;
	examScore = s.examScore;
}

Student& Student::operator=(const Student& rhs) {
	if (this != &rhs) { // self-assignment
		fullName = rhs.fullName;
		examScore = rhs.examScore;
	}
	return *this;
}

Student::Student(const std::string& name, const int& score) {
	fullName = name;
	examScore = score;
}

std::string Student::GetName() {
	return fullName;
}

int Student::GetScore() {
	return examScore;
}

void Student::Print() {
	std::cout << fullName << ": " << examScore << std::endl;
}