#include "pch.h"
//#include<iostream>

using namespace std;
void setFontSize(int FontSize) // ham chinh size chu
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
void resizeConsole(int width, int height) // chinh do lon man hinh console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY(int x, int y) // toa do
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void textcolor(int x) // mau chu
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void drawRectangle(int Coordinate_x,int Coordinate_y, int width,int height) //x,y are coordinate of starting point
{
	gotoXY(Coordinate_x, Coordinate_y);
	for (int i = 0; i < width; ++i)
	{
		cout << "_" ;
	}
	for (int i = 0; i < height; ++i)
	{
		gotoXY(Coordinate_x, Coordinate_y + 1 + i);
		cout << "|";
		
	}
	for (int i = 0; i < height ; ++i)
	{
		gotoXY(Coordinate_x + width-1, Coordinate_y + 1+i);
		cout << "|";
	}
	gotoXY(Coordinate_x+1, Coordinate_y + height);
	for (int i = 0; i < width-2; ++i)
	{
		cout << "_";
	}
}

//void AccountStudent::importID(int ID, ofstream &account) {
//	account << ID << ",";
//}
//
//void AccountStudent::importPASS(Date DOB, ofstream &account) {
//	pass = DOB.day + DOB.month + DOB.year;
//	account << pass << endl;
//}

bool Date::operator==(Date d2)
{
	return (day == d2.day && month == d2.month && year == d2.year);
}
