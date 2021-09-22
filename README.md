# APChem-DB
A model database of AP Chemistry Exam student scores using object-oriented programming in C++. Student information is scored as a record struct with a key-value pair member attribute. Student names are passed as strings to a hash function, which generates a hash value that maps to an index in the model database. When the student name is loaded into the Database class, the student's corresponding score is entered, and can be returned at a later time. This action is meant to mimic database storing and database querying.

This project was done to deepen my understanding of dynamic memory allocation and pointers in C++, as well as the concept of hashing strings.
