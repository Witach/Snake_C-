#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include<vector>
#include"cpoint.h"
#include"screen.h"
class Timer
{
	int clock;
	int refresh;
	Timer(_refresh=5):clock(0),refresh(_refresh){}
	bool operator()()
	{
		if(++clock==refresh)
		{
			clock=0;
			return true;
		}
		return false;
	}
}
class CSnake:public CFramedWindow
{
	vector<CPoint> segments;
	CPoint course;
	Timer i;
	public:
	CSnake(CRect r, char _c = ' ');
  	void paint();
	bool handleEvent(int key);
	void move_snake();
};

#endif
