//
// Display.cpp for Display in /home/lardet_e/Downloads/NIBBLER/sdl
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Sun Apr  6 15:21:53 2014 lardet
// Last update Sun Apr  6 23:29:08 2014 Fabien Casoni
//

#include <stdlib.h>
#include <stdio.h>
#include "../headers/Display.hh"
#include "../../headers/GameException.hh"

void                    Display::see(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList)
{
  this->makeSnake(sList);
  this->makeRedHole(hList);
  this->makeFood(fList);
}

void	Display::Play(std::list<ISnake *> &sList, std::list<IFood *> &fList, std::list<IHole *> &hList, int score)
{
  score = 0;
  this->_sdl.xSDL_FillRect(this->_ecran, NULL, SDL_MapRGB(this->_ecran->format, 0, 255, 0));
  this->see(sList, fList, hList);
  this->event(sList, fList, hList);
}

Display::Display()
{
  this->_angle = 0;
  this->move[0] = &Display::up;
  this->move[1] = &Display::right;
  this->move[2] = &Display::down;
  this->move[3] = &Display::left;
}

bool    Display::Init()
{
  this->_ecran = NULL;
  this->_sdl.xSDL_Init(SDL_INIT_VIDEO);
  this->_ecran = this->_sdl.xSDL_SetVideoMode(LWINDOW, HWINDOW, 32, SDL_HWSURFACE);
  this->_sdl.xSDL_WM_SetCaption((char *)"Nibbler !", NULL);
  this->_sdl.xSDL_FillRect(this->_ecran, NULL, this->_sdl.xSDL_MapRGB(this->_ecran->format, 0, 255, 0));
  this->_sdl.xSDL_Flip(this->_ecran);
  return (true);
}


void    Display::Finish()
{
  std::cout << "GAME OVER!!" << std::endl;
  this->_sdl.xSDL_Quit();
}

void                    Display::up(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setX((sList.front()->getX()) - 10);
}

void                    Display::left(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setY((sList.front()->getY()) + 10);
}

void                    Display::down(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setX((sList.front()->getX()) + 10);
}

void                    Display::right(std::list<ISnake *>&sList) const
{
  this->makeCoord(sList);
  sList.front()->setY((sList.front()->getY()) - 10);
}

void    Display::makeCoord(std::list<ISnake *>&sList) const
{
  int   cpt = sList.size();
  std::list<ISnake *>::reverse_iterator it = sList.rbegin();
  std::list<ISnake *>::reverse_iterator it2;

  while (cpt > 1)
    {
      it2 = it;
      it2++;
      (*it)->setX((*it2)->getX());
      (*it)->setY((*it2)->getY());
      it++;
      cpt--;
    }
}

void                    Display::makeSnake(std::list<ISnake *> &sList)
{
  int                   i = 0;
  SDL_Surface		*carre = NULL;
  SDL_Surface		*corps = NULL;
  SDL_Rect		position;

  carre = this->_sdl.xSDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  this->_sdl.xSDL_FillRect(carre, NULL, SDL_MapRGB(this->_ecran->format, 255, 255, 255));
  corps = this->_sdl.xSDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  this->_sdl.xSDL_FillRect(corps, NULL, SDL_MapRGB(this->_ecran->format, 64, 224, 208));
  for (std::list<ISnake *>::const_iterator it = sList.begin(); it != sList.end(); it++)
    {
      if (i == 0)
	{
	  this->_sdl.xSDL_Flip(this->_ecran);
	  position.x = (*it)->getX() - 10;
	  position.y = (*it)->getY() - 10;
	  this->_sdl.xSDL_BlitSurface(carre, NULL, this->_ecran, &position);
	}
      else
	{
	  this->_sdl.xSDL_Flip(this->_ecran);
	  position.x = (*it)->getX() - 10;
	  position.y = (*it)->getY() - 10;
	  this->_sdl.xSDL_BlitSurface(corps, NULL, this->_ecran, &position);
	}
      i++;
    }
  this->_sdl.xSDL_FreeSurface(carre);
  this->_sdl.xSDL_FreeSurface(corps);
}

void                    Display::makeFood(std::list<IFood *> &fList)
{
  SDL_Surface		*carre = NULL;
  SDL_Rect		position;

  carre = this->_sdl.xSDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  for (std::list<IFood *>::const_iterator it = fList.begin(); it != fList.end(); it++)
    {
      this->_sdl.xSDL_Flip(this->_ecran);
      position.x = (*it)->getX() - 10;
      position.y = (*it)->getY() - 10;
      this->_sdl.xSDL_FillRect(carre, NULL, SDL_MapRGB(this->_ecran->format, 255, 255, 0));
      this->_sdl.xSDL_BlitSurface(carre, NULL, this->_ecran, &position);
   }
  this->_sdl.xSDL_FreeSurface(carre);
}

void                    Display::makeRedHole(std::list<IHole *> &hList)
{
  SDL_Surface		*carre = NULL;
  SDL_Rect		position;

  carre = this->_sdl.xSDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  for (std::list<IHole *>::const_iterator it = hList.begin(); it != hList.end(); it++)
    {
      this->_sdl.xSDL_Flip(this->_ecran);
      position.x = (*it)->getX() - 10;
      position.y = (*it)->getY() - 10;
      this->_sdl.xSDL_FillRect(carre, NULL, SDL_MapRGB(this->_ecran->format, 255, 0, 0));
      this->_sdl.xSDL_BlitSurface(carre, NULL, this->_ecran, &position);
    }
  this->_sdl.xSDL_FreeSurface(carre);
}

void                    Display::event(std::list<ISnake *>&sList, std::list<IFood *> &fList, std::list<IHole *> &hList)
{
  SDL_Event event;

  atexit(SDL_Quit);
  while (this->_sdl.xSDL_PollEvent(&event))
    {
      switch(event.type)
        {
        case SDL_QUIT:
          exit(0);
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
	      exit(0);
              break;
            case SDLK_UP:
	      if(this->_angle != 270)
		this->_angle = 90;
              break;
            case SDLK_DOWN:
	      if(this->_angle != 90)
		this->_angle = 270;
              break;
            case SDLK_LEFT:
	      if (this->_angle != 180)
		this->_angle = 0;
              break;
            case SDLK_RIGHT:
	      if (this->_angle != 0)
		this->_angle = 180;
              break;
            }
          break;
        }
    }
  (this->*move[this->_angle / 90])(sList);
  this->_sdl.xSDL_Flip(this->_ecran);
}

bool    Display::Window() const
{
  return (true);
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
