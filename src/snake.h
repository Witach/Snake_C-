#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include<vector>
#include"cpoint.h"
#include"screen.h"
class CSnake:public CFramedWindow
{
	vector<CPoint> segments;
	CPoint course;
	CPoint food;
	int statesOfTheGame;
	int score;
	public:
	int timer;
	CSnake(CRect r, char _c = ' ');
  	void paint();
	bool handleEvent(int key);
	void moveSnake();
	bool death();
	void snakeGrow();
	void eat();
	void randFood();
	void accelerate(int &a);
	void run();
	void printSnake();
	void restart();
};

#endif
