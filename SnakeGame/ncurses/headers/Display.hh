#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include	<cstdlib>
#include	<string>
#include	<ncurses.h>
#include	<unistd.h>
#include	<iostream>
#include	<fstream>
#include	"../../headers/Game.hh"
#include	"../../headers/IDisplay.hh"
#include	"ncursesManager.hh"

class		Display :	public IDisplay
{
private:
  char				_direction;
  int				_maxheight;
  int				_maxwidth;
  char				_partchar;
  NcursesManager		_c;

public:
  Display();
  ~Display();
  virtual bool			Window() const;  
  virtual void			Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score);
  virtual bool			Init();
  virtual void			Finish();
  void				drawWall() const;
  void				dispFood(std::list<IFood *> list) const;
  void				dispHole(std::list<IHole *> list) const;
  void                          dispScore(int score) const;
  void				movesnake(std::list<ISnake *> &list, std::list<IFood *> &fList, std::list<IHole *> &hList);
};

typedef Display *(*maker_Display)();

#endif
