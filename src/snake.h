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
	public:
	CSnake(CRect r, char _c = ' ');
  	void paint();
	bool handleEvent(int key);
	void move_snake();
	bool death();
};

#endif
