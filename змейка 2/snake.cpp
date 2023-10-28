#include <iostream>
#include "snake.h"
#include <ctime>
#include <windows.h>//konsol obnovlalas s zaderdjkoy;
#include <conio.h>
using namespace std;
void game::draw_horizont_lines()
{
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;


}
bool game::draw_vertical_lines(int ycoord, int xcoord)
{
	if (xcoord == 0 || xcoord == width - 1)
	{
		cout << "#";
		return true;
	}
	return false;
}
bool game::draw_head(int ycoord, int xcoord)
{
	if (xcoord == xhead && ycoord == yhead)
	{
		cout << "0";
		return true;
	}
	return false;
}
bool game::draw_fruits(int ycoord, int xcoord)
{
	if (xcoord == xfruit && ycoord == yfruit)
	{
		cout << "&";
		return true;
	}
	return false;
}
void game::draw_snake_tail(int ycoord, int xcoord)
{
	bool print = false;
	for (int i = 0; i < tail; i++)
		if (x[i] == xcoord && y[i] == ycoord)
		{
			print = true;
			cout << "o";
		}
	if (print == false)
	{
		cout << ' ';
	}
}
void game::draw()
{
	system("cls");//ochishaet console;
	draw_horizont_lines();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (draw_vertical_lines(i, j));
			if (draw_head(i, j));
			else
			{
				if (draw_fruits(i, j));
				else
				{
					draw_snake_tail(i, j);
				}

			}
		}
		cout << endl;
	}
	draw_horizont_lines();
	cout << "Score: " << score << endl;
}
void game::input()
{
	if (_kbhit())//возвращает тру, когда пользователь нажимает на кнопку
	{
		switch (_getch())//определяет какую кнопку нажал пользователь
		{
		case 'a':
		{
			dir = LEFT;
			break;
		}
		case 'd':
		{
			dir = RIGHT;
			break;
		}
		case 'w':
		{
			dir = UP;
			break;
		}
		case 's':
		{
			dir = DOWN;
			break;
		}
		case 'x':
		{
			gameover = true;
			break;
		}
		}
	}
}
void game::tail_move()
{
	int prevx = x[0];
	int prevy = y[0];
	int prev2x, prev2y;
	x[0] = xhead;
	y[0] = yhead;
	for (int i = 1; i < tail; i++)
	{
		prev2x = x[i];
		prev2y = y[i];
		x[i] = prevx;
		y[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
}
void game::head_move()
{
	switch (dir)
	{
	case LEFT:
	{
		xhead--;
		break;
	}
	case RIGHT:
	{
		xhead++;
		break;
	}
	case UP:
	{
		yhead--;
		break;
	}
	case DOWN:
	{
		yhead++;
		break;
	}
	}
}
void game::meet_with_lines()
{
	//if (xhead > width || xhead<0 || yhead>height || yhead > height || yhead < 0)
		//gameover = true;

	if (xhead >= width - 1)
		xhead = 0;
	else if (xhead < 0)
		xhead = width - 2;
	if (yhead >= height)
		yhead = 0;
	else if (yhead < 0)
		yhead = height - 1;
}
void game::check_tail_and_head_coord()
{
	for (int i = 0; i < tail; i++)
	{
		if (x[i] == xhead && y[i] == yhead)
			gameover = true;
	}
}
bool game::check_tail_and_fruit_coord()
{
	bool f = true;
	for (int i = 0; i < tail && f == true; i++)
	{
		f = false;
		if (x[i] == xfruit && y[i] == yfruit)
		{
			xfruit = rand() % (width - 1);
			yfruit = rand() % height;
			f = true;
		}
		else f = false;
	}
	return f;
}
bool game::eat_fruits()
{
	if (xhead == xfruit && yhead == yfruit)
	{
		score += 10;
		xfruit = rand() % (width - 1);
		yfruit = rand() % height;
		if (tail > 0)
			while (check_tail_and_fruit_coord());

		tail++;
		return true;

	}
	return false;
}
void game::logic()
{
	tail_move();
	head_move();
	meet_with_lines();
	check_tail_and_head_coord();

	eat_fruits();




}
