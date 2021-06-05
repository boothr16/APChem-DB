#ifndef STUDENT_H
#define STUDENT_H
#include<string>

struct Student {
	std::string fullName;
	int examScore;
	Student() =default;
	Student(const std::string& name, const int& score); //ctor
	~Student(); //dstor
	Student(const Student& s); //copy ctor
	Student& operator=(const Student& rhs); //assignment operator
	std::string GetName();
	int GetScore();
	void Print();
};

#endif

