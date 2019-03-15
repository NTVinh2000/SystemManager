#include "pch.h"

Class::Class(string s)
{
	Classname = s;
	ifstream fi;
	s += ".txt";
	fi.open(s);
	if (fi.is_open())
	{
		fi.close();
		this->ImportFromFile();
	}
}

void Class::ImportStudents() { //import to StudentsList.txt and Account.txt
	string pass;
	//gets file location from the user
	string fileLocation;
	cout << "Please enter the location of the file: ";
	getline(cin, fileLocation);
	//opens the file
	ifstream importstds;
	importstds.open(fileLocation);
	//makes sure that the file opened properly
	while (importstds.fail())
	{
		cout << "The file at location " << fileLocation << " failed to open" << endl;
		cout << "Please enter the location of the file: ";
		getline(cin, fileLocation);
		importstds.open(fileLocation);
	}

	Student std;
	string path = Classname;
	path += ".txt";
	ofstream account("UsernameAndPassword.txt");
	ofstream studentsList(path);
	if (studentsList.is_open())
	{
		string trash;
		getline(importstds,trash,'\n');
		while (!importstds.eof()) {
			getline(importstds, trash, ',');
			//ID
			importstds >> std.ID;
			getline(importstds, trash, ',');
			
			//lastname
			getline(importstds, std.lastName, ',');

			//1stname
			getline(importstds, std.firstName, ',');

			//gender
			getline(importstds, std.gender, ',');

			//DOB
			getline(importstds, std.DOB.year, '-');			
			getline(importstds, std.DOB.month, '-');
			getline(importstds, std.DOB.day);
			//Add to student list
			StdList.push_back(std);

		}
		importstds.close();

		for (int i = 0; i < StdList.size(); i++) {
			//Export class data
			studentsList << StdList[i].ID << '\n';
			studentsList << StdList[i].lastName << '\n';
			studentsList << StdList[i].firstName << '\n';
			studentsList << StdList[i].gender << '\n';
			studentsList << StdList[i].DOB.day << '\n';
			studentsList << StdList[i].DOB.month << '\n';
			studentsList << StdList[i].DOB.year << '\n';
			studentsList << '\n';
	
			//Export account data
			account << StdList[i].ID << " ";
			pass = StdList[i].DOB.day + StdList[i].DOB.month + StdList[i].DOB.year;
			account << pass << endl;
		}
		account.close();
		studentsList.close();
		cout << "Imported successfully";
	}
	else
		cout << "Unable to open file of system"; 
}

void Class::ImportFromFile()
{
	ifstream fi;
	string path = Classname;
	path += ".txt";
	Student stu;
	fi.open(path);
	if (fi.is_open())
	{
		while (!fi.eof())
		{
			fi >> stu.ID;
			fi.ignore(1,'\n');
			getline(fi, stu.lastName);
			getline(fi, stu.firstName);
			getline(fi, stu.gender);
			getline(fi, stu.DOB.day);
			getline(fi, stu.DOB.month);
			getline(fi, stu.DOB.year);
			StdList.push_back(stu);
		}
	}
	else
	{
		cout << "Class not found.";
	}
	return;
}

void Class::AddAStudent()
{
	//Add a new student
	system("cls");
	Student newStd;
	cout << "ADD A STUDENT";
	newStd.Input();
	system("cls");
	StdList.push_back(newStd);
	
	//Update account and password
	ofstream account;
	account.open("UsernameAndPassword.txt", std::ios_base::app);
	string pass = newStd.DOB.day + newStd.DOB.month + newStd.DOB.year;
	account << newStd.ID << " " << pass << endl;		account.close();
	
	//Update to student list
	ofstream Stdlist;
	string path = Classname;
	path += ".txt";
	Stdlist.open(path,std::ios_base::app);
	newStd.OutputToText(Stdlist);
	return;
}

void Class::EditStudent()
{
	this->DisplayStudent();
	cout << endl;
	//
	bool flag = true;
	int index; // Index of the student 
	while (flag)
	{
		gotoXY(0, StdList.size() + 4);
		cout << "Enter i_th student you want to edit: ";
		 cin >> index;
		if (index > 0 && index < StdList.size())
			flag = false;
	}
	system("cls");
	cout << "EDIT STUDENT INFORMATION";
	Student newStudent;
	newStudent.Input();
	StdList[index - 1] = newStudent;
	return;
}

void Class::ExportToText()
{
	ofstream ListFile;
	string path = Classname;
	path += ".txt";
	ListFile.open(path);
	for (int i = 0; i < StdList.size(); i++)
		StdList[i].OutputToText(ListFile);
	ListFile.close();
	return;
}
void Class::Display1student()
{
	StdList[1].Display();

}
int Class:: FindStudentId(char _User[])
{
	for (int i = 0; i < StdList.size(); ++i)
	{
		if (StdList[i].ID == atoi(_User))
		{
			cout << "Your profile:\n";
			cout << "Name: "<< StdList[i].lastName <<" "<< StdList[i].firstName << " " <<  endl;
			cout << "ID: " << StdList[i].ID << endl;
			cout << "Gender: " << StdList[i].gender << endl;
			cout <<"Day of birth: "<< StdList[i].DOB.day << "-" << StdList[i].DOB.month << "-" << StdList[i].DOB.year;
			return 0;
		}
	}
	cout << "Can not find your profile";
	return 0;
}

void Class::DisplayStudent()
{
	system("cls");
	gotoXY(30, 1);
	cout << "Student List of Class " << Classname;
	for (int i = 0; i < StdList.size(); i++)
	{
		gotoXY(0, i + 3);
		cout << right << setw(2) << i + 1 << "   ";
		StdList[i].Display();
	}
	cout << endl;
	system("pause");
}

void Class::RemoveAStudent()
{
	bool found = false;
	Student RemoveStd;
	int RemoveIndex = -1;
	while (!found)
	{
		system("cls");
		cout << "INPUT STUDENT INFORMATION YOU WANT TO REMOVE FROM CLASS";
		RemoveStd.Input();
		for (int i = 0; i < StdList.size(); i++) {
			if (StdList[i].Compare(RemoveStd))
			{
				found = true;
				RemoveIndex = i;
				break;
			}
		}
		if (!found)
		{
			cout << "Student not found." << endl;
			bool flag = false;
			while (!flag)
			{
				cout << "Do you want to input student information again (Y/N): ";
				char c;
				cin >> c;
				if (tolower(c) == 'n')
				{
					found = true;
					flag = true;
				}
				else if (tolower(c) == 'y')
					flag = true;
			}
			
		}
		else
		{
			cout << "Remove student completed";
		}
		system("pause");
	}
	if (RemoveIndex != -1)
		StdList.erase(StdList.begin() + RemoveIndex);
	this->ExportToText();
	return;
}

void Class::DisplayName(int x, int y)
{
	gotoXY(x, y);
	cout << Classname << endl;
}

bool Class::isChosen(string s)
{
	if (s == Classname) return true;
	return false;
}

void Class::ChangeStudents(Class &B)
{ 
	this->DisplayStudent();
	int index;
	bool flag = true;
	while (flag)
	{
		gotoXY(0, StdList.size() + 3);
		cout << "Which student you want to change: ";
		cin >> index;
		if (index > 0 && index <= StdList.size())
			flag = false;
	}

	B.StdList.push_back(StdList[index - 1]);
	B.ExportToText();
	StdList.erase(StdList.begin() + index - 1);
	this->ExportToText();
}

void Classes::ViewClasses()
{
	system("cls");
	gotoXY(30, 1);
	cout << "LIST OF CLASS ";
	for (int i = 0; i < ClassList.size(); i++)
	{
		gotoXY(15, i + 3);
		cout << right << setw(2) << i + 1 << "   ";
		ClassList[i].DisplayName(0, 35);
	}
	cout << endl;
	system("pause");
}

void Classes::ViewAClass()
{
	gotoXY(30, 1);
	cout << "VIEW A CLASS";
	gotoXY(10, 1);
	bool available = false;
	while (!available) {
		cout << "Which class you want to view:	";
		string name;
		getline(cin, name);
		for (int i = 0; i < ClassList.size(); i++) {
			if (ClassList[i].isChosen(name)) ClassList[i].DisplayStudent();
			available = true;
			break;
		}
		if (!available) {
			cout << "This class is not avalaible.";
			bool flag = false;
			while (!flag)
			{
				cout << "Do you want to try again (Y/N): ";
				char c;
				cin >> c;
				if (tolower(c) == 'n')
				{
					available = true;
					flag = true;
				}
				else if (tolower(c) == 'y')
					flag = true;
			}
		}
	}
}

void Classes::ChangeStudents()
{
	//Choose class
	ViewClasses();
	int ClassIndexA, ClassIndexB;
	//Class A
	bool flag = true;
	while (flag)
	{
		cout << "Enter the number of the class you want change students: ";
		cin >> ClassIndexA;
		if (ClassIndexA > 0 && ClassIndexA <= ClassList.size())
			flag = false;
		else
			cout << "Index not found, please try again" << endl;
	}
	int A = ClassIndexA - 1;
	//Class B
	flag = true;
	while (flag)
	{
		cout << "Enter the number of the class you want to move students to: ";
		cin >> ClassIndexB;
		if (ClassIndexB > 0 && ClassIndexB <= ClassList.size())
			flag = false;
		else
			cout << "Index not found, please try again" << endl;
	}
	int B = ClassIndexB - 1;
	system("cls");

	//Change students from A to B
	ClassList[A].ChangeStudents(ClassList[B]);
	cout << "Changed successfully" << endl;
}
