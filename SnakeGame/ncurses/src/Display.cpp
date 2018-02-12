//
// Display.cpp for Display in /home/volpe_p/rendu/Nibbler
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Apr  6 17:40:39 2014 volpe
// Last update Sun Apr  6 18:05:52 2014 volpe
//

#include	"../headers/Display.hh"
#include	"../../headers/Game.hh"

Display::Display()
{
  NcursesManager c;

  this->_maxheight = HWINDOW / SIDE + 3;
  this->_maxwidth = LWINDOW / SIDE + 2;
  this->_partchar = 'x';
  this->_direction = 'l';
  this->_c = c;
}

bool	Display::Init()
{
  this->_c.xinitscr();
  this->_c.xstart_color();
  this->_c.xnodelay(stdscr, true);
  this->_c.xkeypad(stdscr, true);
  this->_c.xnoecho();
  this->_c.xcurs_set(0);
  this->_c.xrefresh();
  return (true);
}

void    Display::drawWall() const
{
  for (int i=0; i < this->_maxwidth; i++)
    {
      this->_c.xmove(0, i);
      this->_c.xaddch('-');
    }
  for (int i=0; i < this->_maxheight-3; i++)
    {
      this->_c.xmove(i, 0);
      this->_c.xaddch('|');
    }
  for (int i=0; i < this->_maxheight - 3; i++)
    {
      this->_c.xmove(i, this->_maxwidth -1);
      this->_c.xaddch('|');
    }
  for (int i=0; i < this->_maxwidth; i++)
    {
      this->_c.xmove(this->_maxheight-3, i);
      this->_c.xaddch('-');
    }
  this->_c.xrefresh();
}

bool	Display::Window() const
{
  return (true);
}

void   		Display::dispFood(std::list<IFood *> list) const
{
  for (std::list<IFood *>::const_iterator it = list.begin(); it != list.end(); it++)
    {
      this->_c.xmove((*it)->getY()/SIDE, (*it)->getX()/SIDE);
      this->_c.xinit_pair(4, COLOR_YELLOW, COLOR_BLACK);
      this->_c.xattron(COLOR_PAIR(4));
      this->_c.xaddch('+');
      this->_c.xattroff(COLOR_PAIR(4));
    }
}

void   		Display::dispHole(std::list<IHole *> list) const
{
  for (std::list<IHole *>::const_iterator it = list.begin(); it != list.end(); it++)
    {
      if ((*it)->getY()/SIDE < 30 && ((*it)->getX()/SIDE > 0))
	{
	  this->_c.xmove((*it)->getY()/SIDE, (*it)->getX()/SIDE);
	  this->_c.xinit_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	  this->_c.xattron(COLOR_PAIR(5));
	  this->_c.xaddch('#');
	  this->_c.xattroff(COLOR_PAIR(5));
	}
    }
}

void		Display::movesnake(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList)
{
  int		tmp = getch();
  ISnake	*s;
  
  this->drawWall();
  this->dispFood(fList);
  this->dispHole(hList);
  switch (tmp)
    {
    case KEY_LEFT:
      if (this->_direction != 'r')
        this->_direction = 'l';
      break;
    case KEY_UP:
      if (this->_direction != 'd')
        this->_direction = 'u';
      break;
    case KEY_DOWN:
      if (this->_direction != 'u')
        this->_direction = 'd';
      break;
    case KEY_RIGHT:
      if (this->_direction != 'l')
        this->_direction = 'r';
      break;
    case 27:
      this->_c.xendwin();
      exit(EXIT_SUCCESS);
      break;
    }
  this->_c.xmove((sList.back()->getY())/SIDE, (sList.back()->getX())/SIDE);
  this->_c.xaddch(' ');
  this->_c.xrefresh();
  s = sList.back();
  sList.pop_back();
  if (this->_direction == 'l')
    {
      s->setX((sList.front()->getX())-SIDE);
      s->setY(sList.front()->getY());
      sList.push_front(s);
    }
  else if (this->_direction == 'r')
    {
      s->setX((sList.front()->getX())+SIDE);
      s->setY(sList.front()->getY());
      sList.push_front(s);
    }
  else if (this->_direction == 'u')
    {
      s->setX(sList.front()->getX());
      s->setY((sList.front()->getY())-SIDE);
      sList.push_front(s);
    }
  else if (this->_direction == 'd')
    {
      s->setX(sList.front()->getX());
      s->setY((sList.front()->getY())+SIDE);
      sList.push_front(s);
    }
  this->_c.xmove((sList.front()->getY())/SIDE, (sList.front()->getX())/SIDE);
  this->_c.xinit_pair(3, COLOR_RED, COLOR_BLACK);
  this->_c.xattron(COLOR_PAIR(3));
  this->_c.xaddch(this->_partchar);
  this->_c.xattroff(COLOR_PAIR(3));
  this->_c.xrefresh();
}

void    Display::dispScore(int score) const
{
  this->_c.xmove(this->_maxheight-2, 0);
  this->_c.xinit_pair(2, COLOR_GREEN, COLOR_BLACK);
  this->_c.xattron(COLOR_PAIR(2));
  printw("Score: %d", score);
  this->_c.xattroff(COLOR_PAIR(2));  
  this->_c.xrefresh();
}

void	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList, int score)
{
  this->movesnake(sList, fList, hList);
  this->dispScore(score);
}

void	Display::Finish()
{
  this->_c.xmove(this->_maxheight/3, this->_maxwidth/3);
  this->_c.xinit_pair(1, COLOR_RED, COLOR_BLACK);
  this->_c.xattron(COLOR_PAIR(1));
  printw("GAME OVER");
  this->_c.xattroff(COLOR_PAIR(1));
  this->_c.xmove(this->_maxheight/3+3, this->_maxwidth/4);
  printw("Appuyez sur une touche pour quitter");
  this->_c.xrefresh();
  this->_c.xnodelay(stdscr, false);
  this->_c.xkeypad(stdscr, false);
  getch();
  this->_c.xendwin();
}

Display::~Display()
{

}

extern "C"
{
  Display		*make_display()
  {
    return new	Display();
  }
}
