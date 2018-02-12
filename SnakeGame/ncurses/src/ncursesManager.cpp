//
// ncursesManagement.cpp for ncursesManagement in /home/volpe_p/rendu/Nibbler/ncurses/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Apr  6 16:13:24 2014 volpe
// Last update Sun Apr  6 18:06:15 2014 volpe
//

#include	<ncurses.h>
#include	"../headers/ncursesManager.hh"
#include	"../../headers/GameException.hh"

NcursesManager::NcursesManager()
{
}

NcursesManager::~NcursesManager()
{
}

WINDOW	*NcursesManager::xinitscr()
{
  return (initscr());
}

int	NcursesManager::xstart_color()
{
  int	i;
  
  if ((i = start_color()) == ERR)
    throw GameException("Error on start_color");
  return (i);
}

int	NcursesManager::xnodelay(WINDOW *win, bool bf)
{
  int	i;

  if ((i = nodelay(win, bf)) == ERR)
    throw GameException("Error on nodelay");
  return (i);
}


int	NcursesManager::xkeypad(WINDOW *win, bool bf)
{
  int	i;

  if ((i = keypad(win, bf)) == ERR)
    throw GameException("Error on keypad");
  return (i);
}

int	NcursesManager::xnoecho()
{
  int	i;

  if ((i = noecho()) == ERR)
    throw GameException("Error on noecho");
  return (i);
}

int	NcursesManager::xcurs_set(int visibility)
{
  int	i;

  if ((i = curs_set(visibility)) == ERR)
    throw GameException("Error on curs_set");
  return (i);
}

int	NcursesManager::xrefresh() const
{
  int	i;

  if ((i = refresh()) == ERR)
    throw GameException("Error on refresh");
  return (i);
}

int	NcursesManager::xmove(int y, int x) const
{
  int	i;

  if ((i = move(y, x)) == ERR)
    throw GameException("Error on move");
  return (i);
}

int	NcursesManager::xaddch(chtype ch) const
{
  int	i;

  if ((i = addch(ch)) == ERR)
    throw GameException("Error on addch");
  return (i);
}

int	NcursesManager::xinit_pair(short pair, short f, short b) const
{
  int	i;

  if ((i = init_pair(pair, f, b)) == ERR)
    throw GameException("Error on init_pair");
  return (i);
}

int	NcursesManager::xattron(int attrs) const
{
  int	i;

  if ((i = attron(attrs)) == ERR)
    throw GameException("Error on attron");
  return (i);
}

int	NcursesManager::xattroff(int attrs) const
{
  int	i;

  if ((i = attroff(attrs)) == ERR)
    throw GameException("Error on attroff");
  return (i);
}

int	NcursesManager::xendwin()
{
  int	i;


  if ((i = endwin()) == ERR)
    throw GameException("Error on endwin");
  return (i);
}
