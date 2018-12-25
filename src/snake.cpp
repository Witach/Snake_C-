#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c),course(0,1)
{
	segments.push_back(CPoint(1,1));
	segments.push_back(CPoint(1,2));
	segments.push_back(CPoint(1,3));
}
void CSnake::paint()
{
	CFramedWindow::paint();	
	for(int i=0;i<segments.size();i++)
	{
		gotoyx(segments[i].y+geom.topleft.y,segments[i].x+geom.topleft.x);
		printc('+');
	}
	if(t())
	{
		move_snake();
	}
}
bool CSnake::handleEvent(int key)
{
	if(CFramedWindow::handleEvent(key))
	{
		return true;
	}
	else
	{
		switch (key)
		{
			case 'w':
				course=CPoint (0, -1);
				break;
			case 's':
				course=CPoint (0, 1);
				break;
			case 'd':
				course=CPoint (1, 0);
				break;
			case 'a':
				course=CPoint (-1, 0);
				break;
		};
	}
	return false;
}
void CSnake::move_snake()
{
	
}
