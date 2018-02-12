//
// Display.hh<2> for Nibbler in /home/casoni_f/Projets/cpp_nibbler/opengl
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Sun Apr  6 14:11:16 2014 Fabien Casoni
// Last update Sun Apr  6 21:33:43 2014 lardet
//

#ifndef		_DISPLAY_HH_
# define	_DISPLAY_HH_

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include	<SDL/SDL.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<iostream>
#include        <SDL/SDL.h>
#include	"../../headers/Game.hh"
#include	"../../headers/IDisplay.hh"

class		Display : public IDisplay
{
private:
  SDL_Surface	*_win;
  int		_angle;
  void                          (Display::*move[4])(std::list<ISnake *> &) const;
public:
  Display();
  ~Display();
  virtual bool	Window() const;
  virtual void	Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score);
  virtual bool		Init();
  virtual void		Finish();
  void                  up(std::list<ISnake *>&sList) const;
  void                  down(std::list<ISnake *>&sList) const;
  void                  left(std::list<ISnake *>&sList) const;
  void                  right(std::list<ISnake *>&sList) const;
  void			event(std::list<ISnake *> &sList);
  void			makeCarre(double x, double y, int r, int v, int b) const;
  void			see(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList);
  void			makeSnake(std::list<ISnake *> &sList);
  void			makeCoord(std::list<ISnake *> &sList) const;
  void			makeFood(std::list<IFood *> &fList) const;
  void			makeBlackHole(std::list<IHole *> &hList) const;
  
};

typedef Display	*(*maker_Display)();

#endif		/* _DISPLAY_HH_ */
