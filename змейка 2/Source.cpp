#include <iostream>
#include <ctime>
#include "snake.h"
#include <windows.h>//konsol obnovlalas s zaderdjkoy;
#include <conio.h>
using namespace std;
int main()
{
	game g1;
	int speed = 300;
	while (g1.gameover != true)
	{
		//static int speed = 300;
		g1.draw();
		g1.input();
		g1.logic();


		//if (g1.eat_fruits() == true)
		//{
		//	
		//	Sleep(speed-=30);
		//}

		Sleep(300);//из виндовс.х 





		//Sleep(30);
	}
}
