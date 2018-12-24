#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
	czlony.push_back(CPoint(1,1));
	czlony.push_back(CPoint(1,2));
	czlony.push_back(CPoint(1,3));
}
void CSnake::paint()
{
	CFramedWindow::paint();	
	for(int i=0;i<czlony.size();i++)
	{
		gotoyx(czlony[i].y+geom.topleft.y,czlony[i].x+geom.topleft.x);
		printc('+');
	}
}
