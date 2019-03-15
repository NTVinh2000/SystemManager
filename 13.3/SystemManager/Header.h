#pragma once
#ifndef	_HEADER_H_
#define _HEADER_H_

#include<fstream>
#include<string>
using namespace std;


void gotoXY(int x, int y);
void resizeConsole(int width, int height);
void textcolor(int x);
void setFontSize(int FontSize);
void drawRectangle(int Coordinate_x, int Coordinate_y, int width, int height);//x,y are coordinate of starting point

struct Date {
	bool operator == (Date d2);
	string day;
	string year;
	string month;
};

//class AccountStudent {
//public:
//	void importID(int ID, ofstream &account);
//	void importPASS(Date DOB, ofstream &account);
//	bool checkLogin();
//private:
//	int ID;
//	string pass;
//	ofstream account;
//
//};


#endif