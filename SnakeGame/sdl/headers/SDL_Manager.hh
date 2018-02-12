//
// SDL_Management.hh for SDL_Management in /home/lardet_e/rendu/Nibbler
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Sun Apr  6 17:13:32 2014 lardet
// Last update Sun Apr  6 21:21:05 2014 lardet
//

#ifndef		__SDL_MANAGER_HH__
#define		__SDL_MANAGER_HH__

#include	<list>
#include        <cstdlib>
#include        <unistd.h>
#include	<iostream>
#include	<SDL/SDL.h>
#include	"../../headers/GameException.hh"

class		SdlManager
{
public:
  SdlManager();
  ~SdlManager();
  SDL_Surface*	xSDL_CreateRGBSurface(Uint32, int, int, int, Uint32, Uint32, Uint32, Uint32);
  int		xSDL_FillRect(SDL_Surface *, SDL_Rect *, Uint32);
  int		xSDL_Flip(SDL_Surface*);
  int		xSDL_BlitSurface(SDL_Surface*, SDL_Rect*, SDL_Surface*, SDL_Rect*);
  int		xSDL_Init(Uint32);
  SDL_Surface*	xSDL_SetVideoMode(int, int, int, Uint32);
  void		xSDL_WM_SetCaption(char *, char *);
  Uint32	xSDL_MapRGB(SDL_PixelFormat*, Uint8, Uint8, Uint8);
  void		xSDL_Quit(void);
  int		xSDL_PollEvent(SDL_Event*);
  void		xSDL_FreeSurface(SDL_Surface*);
};

#endif
