//
// ncursesManagement.hh for ncursesManagement in /home/volpe_p/rendu/Nibbler/ncurses/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Apr  6 16:14:04 2014 volpe
// Last update Sun Apr  6 18:05:08 2014 volpe
//

#ifndef NCURSESMANAGER_HH_
# define NCURSESMANAER_HH_

#include	<ncurses.h>
#include	<string>

class NcursesManager
{
public:
  NcursesManager();
  ~NcursesManager();
  WINDOW		*xinitscr();
  int			xstart_color();
  int			xnodelay(WINDOW *, bool);
  int			xkeypad(WINDOW *, bool);
  int			xnoecho();
  int			xcurs_set(int);
  int			xrefresh() const;
  int			xmove(int, int) const;
  int			xaddch(chtype ch) const;
  int			xinit_pair(short, short, short) const;
  int			xattron(int) const;
  int			xattroff(int) const;
  int			xendwin();
  int			xgetch();
};
#endif
