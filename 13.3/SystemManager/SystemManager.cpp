#include "pch.h"
#include <iostream>

int main()
{

	Class APCS186("18APCS4");
	vector<Class> ClassList;
	ClassList.push_back(APCS186);
	APCS186.DisplayStudent();
	system("PAUSE");
	char User[16]; // id
	while (true)
	{
		system("cls");
		int CheckExit = Login(User);
		if (CheckExit == 0) // check xem co lenh exit chuong trinh khong
		{
			system("cls");
			return 0;
		}
		else
		{
			system("cls");
			ShowMenu(User,APCS186);
		}
	}
	//trinh tui lam dc toi day thoi nha may ong <3
	/*
	Class APCS181("18APCS4");
	APCS181.ImportStudents();
	APCS181.DisplayStudent();
	Class APCS186("18APCS4");
	vector<Class> ClassList;
	ClassList.push_back(APCS186);
	APCS186.DisplayStudent();
	*/
	system("pause");
	return 0;
}

