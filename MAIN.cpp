/* Driver program gives option to: 1) add student to database, 2) lookup student in database. This will be done by reading student data from a global text file into a global vector. DB size = next prime number after numStudents.
|
 ---> 1) Add student: Hash student's name to a DB index. Store exam score at that index. If DB is full, resize DB.
 ---> 2) Retrieve student: Hash name to a DB index. If value at index == NULLPTR, student is not found in the DB.
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Database.h"
using namespace std;
//GLOBALS
ifstream inFile("Score History.txt");
//FUNCTION PROTOTYPES
void LoadDB(Database& db, ifstream& inFile);
void FetchData(Database& db);

int main() {
	try {
		Database db;
		LoadDB(db, inFile);
		FetchData(db);
		inFile.close();
	}
	catch (const exception& ex) {
		cout << "Exception: " << ex.what() << "\n";
	}
	return 0;
}

void LoadDB(Database& db, ifstream& inFile) {
	string first;
	string last;
	string full;
	int score;
	while (!inFile.eof()) {
		inFile >> first >> last >> score;
		full = first + " " + last;
		db.AddStudent(full, score);
	}
	cout << "Database loaded." << endl;
}

void FetchData(Database& db) {
	string first;
	string last;
	string name;
	char choice = 'y';
	while (choice == 'y' || choice == 'Y') {
		cout << "\nEnter student name (full name, case-sensitive): ";
		cin >> first;
		cin >> last;
		name = first + " " + last;
		db.GetStudent(name);
		cout << "Search for another student? (y/n): ";
		cin >> choice;
	}
}
