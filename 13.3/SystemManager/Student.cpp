#include "pch.h"
#include "Student.h"
void Student::Input()
{
	gotoXY(0, 1);
	cout << "Input Student ID: ";
	cin >> ID;
	cin.ignore(100,'\n');

	gotoXY(0, 2);
	cout << "Input Student Lastname: ";
	getline(cin,lastName);
	
	gotoXY(0, 3);
	cout << "Input Student Firstname: ";
	getline(cin,firstName);
	
	gotoXY(0, 4);
	cout << "Input Student Gender: ";
	getline(cin, gender);

	gotoXY(0, 5);
	cout << "Input Student Date of Birth (DD-MM-YYYY): ";
	getline(cin,DOB.day,'-');
	getline(cin,DOB.month,'-');
	getline(cin,DOB.year);
	return;
}
void Student::OutputToText(ofstream &fo)
{
	fo << ID << endl;
	fo << lastName << endl;
	fo << firstName << endl;
	fo << gender << endl;
	fo << DOB.day << endl;
	fo << DOB.month << endl;
	fo << DOB.year << endl;
	fo << endl;
}

bool Student::Compare(Student Std2)
{
	return (ID == Std2.ID && lastName == Std2.lastName &&
		firstName == Std2.firstName && DOB == Std2.DOB);
}

void Student::Display()
{
	cout << left << setw(11) << ID;
	cout << setw(20) << lastName;
	cout << setw(9) << firstName;
	cout << setw(8) << gender;
	cout << DOB.day << "-" << DOB.month << "-" << DOB.year;
	return;
}
