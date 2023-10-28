#pragma once
#include <iostream>
#include <time.h>
//include
enum Move { STOP = 0, LEFT, RIGHT, UP, DOWN };
//using namespace std;
class snake
{
protected:
	int width;//shirina polya;
	int height;//dlinna polya;
	int x[100], y[100];//koordinaty xvosta;
	int tail;//dlina xvosta;

public:

	snake()
	{
		width = 20;
		height = 15;
		tail = 0;

	}

};
//naslednik klassa snake
class game :public snake
{

public:

	Move dir;
	bool gameover;
	int xhead, yhead, xfruit, yfruit, score;
	game() :snake()//konstryktor nachlnogo polodjenya igri;
	{
		srand(time(NULL));
		gameover = false;
		dir = STOP;
		xhead = (width / 2) - 1;
		yhead = (height / 2) - 1;
		xfruit = rand() % (width - 1);
		yfruit = rand() % height;
		score = 0;


	}
	void draw();//rusuem pole;
	void input();//vhodnie dannie;
	void logic();
	void draw_horizont_lines();
	bool draw_vertical_lines(int ycoord, int xcoord);
	bool draw_head(int ycoord, int xcoord);
	bool draw_fruits(int ycoord, int xcoord);
	void draw_snake_tail(int ycoord, int xcoord);
	void tail_move();
	void head_move();
	bool eat_fruits();
	void meet_with_lines();
	void check_tail_and_head_coord();
	bool check_tail_and_fruit_coord();


};
