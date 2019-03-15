#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "pch.h"
#include "Header.h"
#include <string>
using namespace std;

struct Student {
	void Input();//Input student information
	void OutputToText(ofstream &fo);//Output to text file 
	bool Compare(Student Std2);//Return true when 2 students are the same
	void Display();
	int ID;
	string lastName;
	string firstName;
	string gender;
	Date DOB;
};

#endif // !_STUDENT_H_


