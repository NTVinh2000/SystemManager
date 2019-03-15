#include<iostream>
#include<Windows.h>
#include<conio.h>
int main()

{
	while(true)
		if (_kbhit())
		{
			char c = _getch();
			std::cout << int(c);
		}

}