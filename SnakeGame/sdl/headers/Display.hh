//
// Display.hh for Display in /home/lardet_e/Downloads/NIBBLER/sdl
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Sun Apr  6 15:21:46 2014 lardet
// Last update Sun Apr  6 21:36:24 2014 lardet
//

#ifndef		__DISPLAY_HH__
#define		__DISPLAY_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include	<iostream>
#include	<SDL/SDL.h>
#include	"../../headers/Game.hh"
#include	"../../headers/IDisplay.hh"
#include	"../headers/SDL_Manager.hh"

class		Display :	public IDisplay
{
private:
  int				_angle;
  SDL_Surface			*_ecran;
  SdlManager			_sdl;
  void				(Display::*move[4])(std::list<ISnake *> &) const;
public:
  Display();
  ~Display();
  virtual bool  Window() const;
  virtual void  Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hlist, int score);
  virtual bool          Init();
  virtual void          Finish();
  void                  event(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList);
  void                  see(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList);
  void                  makeSnake(std::list<ISnake *> &sList);
  void                  makeCoord(std::list<ISnake *> &sList) const;
  void                  makeFood(std::list<IFood *> &fList);
  void                  makeRedHole(std::list<IHole *> &hList);
  void			makeWall() const;
  void                  up(std::list<ISnake *> &sList) const;
  void                  left(std::list<ISnake *> &sList) const;
  void                  right(std::list<ISnake *> &sList) const;
  void                  down(std::list<ISnake *> &sList) const;
};

typedef Display *(*maker_Display)();

#endif
