#include "snake.h"
#include<unistd.h>
#include<cstdlib>
#include<time.h>
#include"screen.h"
CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c),course(1,0),timer(90000),food(r.size.x/2,r.size.y/2),statesOfTheGame(0)
{
	segments.push_back(CPoint(2,4));
	segments.push_back(CPoint(2,5));
	segments.push_back(CPoint(2,6));
	
}
void CSnake::run()
{
   while(1)
  {
   	if(!death())
	{
	      int c = ngetch();
		if(handleEvent(c))
		{
			break;
		}
	      update_screen();
	      usleep(timer);
	      moveSnake();
	      eat();
	      paint();
	      refresh();
	      if(death())
		{
			statesOfTheGame=4;
			break;
		}
	}
  }
}
void CSnake::printSnake()
{
	for(int i=0;i<segments.size();i++)
	{
		gotoyx(segments[i].y+geom.topleft.y,segments[i].x+geom.topleft.x);
		printc('+');
	}
	gotoyx(food.y+geom.topleft.y,food.x+geom.topleft.x);
	printc('*');
}
void CSnake::paint()
{
	switch(statesOfTheGame)
	{
		case 0:
			CFramedWindow::paint();
			gotoyx(geom.size.y/8,geom.size.x/8);
			printl("h - toggle help information");
			gotoyx(2*geom.topleft.y/8,2*geom.size.x/8);
			printl("p - toggle pause/play mode");
			gotoyx(3*geom.size.y/8,3*geom.size.x/8);
			printl("r - toggle restatr game");
			gotoyx(3*geom.size.y/8,3*geom.size.x/8);
			printl("wsad - move snake in play mode");			
			gotoyx(4*geom.size.y/8,4*geom.size.x/8);
			printl("arrows - move window in pause mode");			
			gotoyx(5*geom.size.y/8,5*geom.size.x/8);
			printl("f - toggle start game");
			gotoyx(6*geom.size.y/8,6*geom.size.x/8);
			printl("q - toggle end game");
			break;
		case 1:
			CFramedWindow::paint();
			printSnake();
			break;
		case 2:
			CFramedWindow::paint();
			printSnake();
			gotoyx(geom.size.y/2,geom.size.y/2);
			printl("PAUSE");
			gotoyx(geom.size.y/2+3,geom.size.y/2);
			printl("press p or f to contiunue your game");
			break;
		case 3:
			CFramedWindow::paint();
			printSnake();
			gotoyx(geom.size.y/8,geom.size.x/8);
			printl("h - toggle help information");
			gotoyx(2*geom.size.y/8,2*geom.size.x/8);
			printl("p - toggle pause/play mode");
			gotoyx(3*geom.size.y/8,3*geom.size.x/8);
			printl("r - toggle restatr game");
			gotoyx(3*geom.size.y/8,3*geom.size.x/8);
			printl("wsad - move snake in play mode");			
			gotoyx(4*geom.size.y/8,4*geom.size.x/8);
			printl("arrows - move window in pause mode");					
			gotoyx(5*geom.size.y/8,5*geom.size.x/8);
			printl("f - toggle start game");
			gotoyx(7*geom.size.y/8,7*geom.size.x/8);
			printl("Press f or p to continue your game ...");
			break;
		case 4:
			CFramedWindow::paint();
			printSnake();
			gotoyx(geom.size.y/2,geom.size.y/2);
			printl("GAME OVER");
			gotoyx(geom.size.y/2+3,geom.size.y/2);
			printl("press r or f to restart  game");
			break;
	}
}
bool CSnake::handleEvent(int key)
{
	if(CFramedWindow::handleEvent(key))
	{
		return false;
	}
	else
	{
		switch (key)
		{
			case 'w':
				if(course.y==1)
				{
					break;
				}
				course=CPoint (0, -1);
				break;
			case 's':
				if(course.y==-1)
				{
					break;
				}
				course=CPoint (0, 1);
				break;
			case 'd':
				if(course.x==-1)
				{
					break;
				}
				course=CPoint (1, 0);
				break;
			case 'a':
				if(course.x==1)
				{
					break;
				}
				course=CPoint (-1, 0);
				break;
			case 'f':
				if(statesOfTheGame==0||statesOfTheGame==2||statesOfTheGame==3)
				{
					statesOfTheGame=1;
					run();
				}
				else if(statesOfTheGame==4)
				{
					restart();
					statesOfTheGame=1;
					run();
				}
				break;
			case 'p':
				if(statesOfTheGame==1||statesOfTheGame==3)
				{
					statesOfTheGame=2;
					return true;
				}
				else if(statesOfTheGame==2)
				{
					statesOfTheGame=1;
					run();
					break;
				}
			case 'q':
				statesOfTheGame=0;
				restart();
				return true;
			case 'h':
				if(statesOfTheGame==1||statesOfTheGame==2)
				{
					statesOfTheGame=3;
					return true;
				}
				else if(statesOfTheGame==4)
				{
					statesOfTheGame=0;
					restart();
					return true;
				}
			case 'r':
				if(statesOfTheGame!=0)
				{
					restart();
				}
				
				
		};
	}
	return false;
}
void CSnake::moveSnake()
{

	for(int i=segments.size()-1;i>0;i--)
	{
		segments[i]=segments[i-1];
	}
	segments[0].x+=course.x;	
	segments[0].y+=course.y;
	if(segments[0].x>=geom.size.x-1)
	{
		segments[0].x=1;
	}
	if(segments[0].y>=geom.size.y-1)
	{
		segments[0].y=1;
	}
	if(segments[0].x<1)
	{
		segments[0].x=geom.size.x-2;
	}
	if(segments[0].y<1)
	{
		segments[0].y=geom.size.y-2;
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
void CSnake::snakeGrow()
{
	segments.push_back(CPoint(segments[segments.size()-1]));
}
void CSnake::eat()
{
	if(segments[0]==food)
	{
		snakeGrow();
		randFood();
		accelerate(timer);
	}
}
void CSnake::randFood()
{
	
		srand(time(NULL));
		food.x=rand()%(geom.size.x-2)+1;
		food.y=rand()%(geom.size.y-2)+1;
		for(int i=0;i<segments.size();i++)
		{
			if(segments[i]==food)
			{
				randFood();
			}
		}
}
void CSnake::accelerate(int &a)
{
	if(a>0)
	{
		a-=2500;
	}
}
void CSnake::restart()
{	
	vector<CPoint> segments_new;
	segments_new.push_back(CPoint(2,4));
	segments_new.push_back(CPoint(2,5));
	segments_new.push_back(CPoint(2,6));
	segments=segments_new;
	timer=90000;
	score=0;
	course=CPoint(1,0);
	food.x=geom.size.x/2;
	food.y=geom.size.y/2;
}
