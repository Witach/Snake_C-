#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c),course(0,1)
{
	segments.push_back(CPoint(2,4));
	segments.push_back(CPoint(2,5));
	segments.push_back(CPoint(2,6));
}
void CSnake::paint()
{
	CFramedWindow::paint();
	move_snake();
	death();
	for(int i=0;i<segments.size();i++)
	{
		gotoyx(segments[i].y+geom.topleft.y,segments[i].x+geom.topleft.x);
		printc('+');
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

	for(int i=segments.size()-1;i>0;i--)
	{
		segments[i]=segments[i-1];
	}
	segments[0].x+=course.x;	
	segments[0].y+=course.y;
	if(segments[0].x>=geom.size.x)
	{
		segments[0].x=0;
	}
	if(segments[0].y>=geom.size.y)
	{
		segments[0].y=0;
	}
}
bool CSnake::death()
{
	for(int i=2;i<segments.size();i++)
	{
		if(segments[0]==segments[i])
		{
			return true;
		}
	}
	return false;
}
