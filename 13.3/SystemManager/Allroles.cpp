#include "pch.h"
//#include<Windows.h>
//#include<fstream>
//#include<conio.h>
#include<string.h>

using namespace std;
void DrawLoginScreen()
{
	gotoXY(0, 0);
	cout << "USE UP OR DOWN ARROW";
	gotoXY(20, 5);
	cout << "LOGIN SCREEN";
	gotoXY(10, 7);
	cout << "Username:" ;
	drawRectangle(9, 6, 31, 2); // ham nay duoc duoc define trong header.cpp dung de ve hinh chu nhat drawRectangle(toadox,toadoy,chieudai,chieucao
	gotoXY(10, 11);
	cout << "Password:";
	drawRectangle(9, 10, 31, 2);
	drawRectangle(14, 14, 22, 3);
	gotoXY(22, 16);
	cout << "LOGIN";

}                              //
int verify(char c,char Username[],char Password[])
{
	if (int(c) == 13)
	{

		textcolor(5);
		drawRectangle(14, 14, 22, 3);
		gotoXY(22, 16);
		cout << "LOGIN";
		gotoXY(0, 0);
		Sleep(200);
		textcolor(15);
		drawRectangle(14, 14, 22, 3);
		gotoXY(22, 16);
		cout << "LOGIN";
		gotoXY(12, 20);
		char readfromfile[50];

		ifstream read("UsernameAndPassword.txt");
		if (read.fail())
			cout << "Can not connect";
		else 
		{
			int ExistUsername = 0;
			while (!read.eof())
			{
				read.getline(readfromfile, 50);
				char *next_token;
				char *token = strtok_s(readfromfile, " ", &next_token);
				if (token != NULL)
				{
					if (strcmp(Username, token) == 0)
					{
						ExistUsername = 1;
						token = strtok_s(NULL, " ", &next_token);
						if (strcmp(Password, token) == 0)
						{
							
							cout << "Verify success";
							return 1;
						}
						else 
						{
							cout << "Wrong password"; 
							return 0;
						}
					}
				}

			}
			if (ExistUsername == 0)
				cout << "Username is not exist";
			read.close();
			return 0;
		}

	}
	return 0;
} //so sanh  verify username ,password   // 
void ProtectPassword(char Password[])
{
	gotoXY(10, 11);
	for (int i = 0; i < strlen(Password); ++i)
		cout << "*";
}				//
int Login(char _User[]) // _User dung de truy cap vao du lieu cua user do
{
	textcolor(15);
	DrawLoginScreen();

	char Username[16]="";
	char Password[16]="";
	int Location = 0;
	int c;
	while (true)
	{
		if (_kbhit())
		{
			c = _getch();
			
			if (c == 80) //down
			{
				if (Location < 2)
					++Location;

			}
			if (c == 72) //up
			{
				if (Location == 2)
					--Location;
			}
			if (Location == 1)
			{
				gotoXY(10, 7);
				if (Username[0] == '\0')
				{
					gotoXY(10, 7);
					cout << "                ";
					gotoXY(10, 7);
				}
				while (true)
				{

					if (_kbhit())
					{
						
						char ch = _getch();
						if (verify(ch, Username, Password) == 1)
						{
							strcpy_s(_User,16, Username);
							return 1;
						}
						if (int(ch)==80 || int(ch)==-32  || ch=='P') //down .-32 is null ,P is down
						{
							Location = 2;
							gotoXY(10, 7);
							if (Username[0] == '\0')
								cout << "Username:";
							else cout << Username;
							char remain = _getch(); // con thua -32
							
							break;
						}
						else if (int(ch) == 8 && strlen(Username)>0) //backspace
						{
							Username[strlen(Username) - 1] = '\0';
							gotoXY(10, 7);
							cout << "                  ";
							gotoXY(10, 7);
							cout << Username;
							
						}
						else if(int(ch) != 8 && int(ch)!=-32 &&int(ch)!=13) // neu ch ko phai la backspace de tranh truong hop else if o tren khong thoa do strlen=0
						{
							char ch2[2];
							ch2[0] = ch;
							ch2[1] = '\0';
							if (strlen(Username) < 15)
							{
								strcat_s(Username, ch2);
							}
							gotoXY(10, 7);
							cout << "                             ";
							gotoXY(10, 7);
							cout << Username;
						}
					}
				}

			}
			if (Location == 2)
			{	
				gotoXY(10, 11);
				if (Password[0] == '\0')
				{
					gotoXY(10, 11);
					cout << "                ";
					gotoXY(10, 11);
				}
				while (true)
				{
					
					if (_kbhit())
					{
						char ch = _getch();
						if (verify(ch, Username, Password) == 1)
						{
						
							strcpy_s(_User, 16, Username);
							return 1;
						}
						if (int(ch) == 72 || int(ch) == -32 || ch == 'H') //down .-32 is null ,H is up
						{
							Location = 2;
							gotoXY(10, 11);
							if (Password[0] == '\0')
								cout << "Password:";
							else ProtectPassword;
							break;
						}
						else if (int(ch) == 8 && strlen(Password) > 0) //backspace
						{
							Password[strlen(Password) - 1] = '\0';
							gotoXY(10, 11);
							cout << "                  ";
							ProtectPassword(Password);

						}
						else if (int(ch) != 8 && int(ch) != -32 && int(ch) != 13) // neu ch ko phai la backspace de tranh truong hop else if o tren khong thoa do strlen=0
						{
							char ch2[2];
							ch2[0] = ch;
							ch2[1] = '\0';
							if (strlen(Password) < 15)
							{
								strcat_s(Password, ch2);
							}
							gotoXY(10, 11);
							cout << "                             ";
							ProtectPassword(Password);
						}
					}
				}
			}
			
			
		}
	}
}			
//4 ham tren dung de dung login screen
void DrawMenu()
{

	gotoXY(2, 4);
	cout << char(16) << "Staff menu";
	gotoXY(3, 5);
	cout << "Lecturer menu";
	gotoXY(3, 6);
	cout << "Class menu";
	gotoXY(3, 7);
	cout << "Profile";
	gotoXY(3, 8);
	cout << "Back to login screen";
}

int ShowMenu(char _User[],Class std)
{
	int ChooseMenu = 0;
	int c; // lay ki tu nhap tu ban phim
	cout << "Username:" << _User;
	DrawMenu();
	int i = 0;
	while (true)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 8) //backspace
			{
				system("cls");
				return 0;// quay lai login
			}
			if (c == 80 && ChooseMenu < 4) // down && tranh ChooseMenu lon hon 4
				++ChooseMenu;
			else if (c == 72 && ChooseMenu > 0) //up && tranh chooseMenu am
				--ChooseMenu;
			else if (c == 13)// enter
				break;
			if (ChooseMenu == 0)
			{
				gotoXY(2, 5);
				cout << " ";
				gotoXY(2, 4);
				cout << char(16);
			}
			else if (ChooseMenu == 1)
			{
				gotoXY(2, 4);
				cout << " ";
				gotoXY(2, 6);
				cout << " ";
				gotoXY(2, 5);
				cout << char(16);
			}
			else if(ChooseMenu==2)
			{
				gotoXY(2, 5);
				cout << " ";
				gotoXY(2, 7);
				cout << " ";
				gotoXY(2, 6);
				cout << char(16);
				
			}
			else if (ChooseMenu == 3)
			{
				gotoXY(2, 6);
				cout << " ";
				gotoXY(2, 8);
				cout << " ";
				gotoXY(2, 7);
				cout << char(16);
			}
			else if (ChooseMenu == 4)
			{
				gotoXY(2, 7);
				cout << " ";
				gotoXY(2, 8);
				cout << char(16);
			}

		}
	}
	system("cls");
	gotoXY(0, 0);
	// bo ca menu o day
	if (ChooseMenu == 0)
		cout << "Staff Menu";
	else if (ChooseMenu == 1)
		cout << "Lecturer Menu";
	else if (ChooseMenu == 2)
	{
		cout << "Class Menu";
		gotoXY(5, 5);
	}
	else if (ChooseMenu == 3)
	{
		std.FindStudentId(_User);
	}
	else if (ChooseMenu == 4)
	{
		return 0;
	}
	system("PAUSE");
	system("cls");
	ShowMenu(_User, std);
	return 0;
}