#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include<vector>
#include"cpoint.h"
#include"screen.h"
class CSnake:public CFramedWindow
{
	vector<CPoint> czlony;
	public:
	CSnake(CRect r, char _c = ' ');
  	void paint();
};

#endif
