#ifndef _CLASS_H_
#define _CLASS_H_
#include "pch.h"
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

class Class {
public:
	Class(string s); //constructor s is the name of the class to save to txt file
	void ImportStudents();//Import students of a class from csv
	void ImportFromFile();//Import student from txt file.
	void ExportToText();//Export student information to text file
	void DisplayStudent();//Display student list of the class
	void AddAStudent(); //Manually add a new student to a class
	void EditStudent(); //Edit an existing student
	void RemoveAStudent(); //Remove a student
	void DisplayName(int x, int y); //Display class name
	bool isChosen(string s); //Check whether the class is chosen
	void ChangeStudents(Class &B); //Change students from class A to class B
private:
	vector <Student>  StdList;
	string Classname;
};

class Classes {
public:
	Classes();
	void ViewClasses(); //View list of classes
	void ViewAClass(); //View list of students in a class
	void ChangeStudents(); //Change students from class A to class B
private:
	vector <Class> ClassList;
};

#endif 
