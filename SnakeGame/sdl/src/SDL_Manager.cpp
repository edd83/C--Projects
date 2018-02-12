//
// SDL_Manager.cpp for SDL_Manager in /home/lardet_e/rendu/Nibbler
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Sun Apr  6 17:21:20 2014 lardet
// Last update Sun Apr  6 21:25:27 2014 lardet
//

#include "../headers/SDL_Manager.hh"

SdlManager::SdlManager()
{
}

SdlManager::~SdlManager()
{
}

SDL_Surface	*SdlManager::xSDL_CreateRGBSurface(Uint32 a, int b, int c, int d, Uint32 e, Uint32 f, Uint32 g, Uint32 h)
{
  if ((SDL_CreateRGBSurface(a, b, c, d, e, f, g, h)) == NULL)
    throw GameException("Error on create a square");
  else
    return (SDL_CreateRGBSurface(a, b, c, d, e, f, g, h));
}

int		SdlManager::xSDL_FillRect(SDL_Surface *a, SDL_Rect *b, Uint32 c)
{
  if ((SDL_FillRect(a, b, c)) != 0)
    throw GameException("Error on refresh screen");
  else
    return (SDL_FillRect(a, b, c));
}

int		SdlManager::xSDL_Flip(SDL_Surface *a)
{
  if (SDL_Flip(a) == -1)
    throw GameException("Error on refresh window");
  else
    return (SDL_Flip(a));
}

int		SdlManager::xSDL_BlitSurface(SDL_Surface *a, SDL_Rect *b, SDL_Surface *c, SDL_Rect *d)
{
  if ((SDL_BlitSurface(a, b, c, d)) != 0)
    throw GameException("Error on copy surface");
  else
    return (SDL_BlitSurface(a, b, c, d));
}

int		SdlManager::xSDL_Init(Uint32 a)
{
  if ((SDL_Init(a)) == -1)
    throw GameException("Error on init window");
  else
    return (SDL_Init(a));
}

SDL_Surface*	SdlManager::xSDL_SetVideoMode(int a, int b, int c, Uint32 d)
{
  if ((SDL_SetVideoMode(a, b, c, d)) == NULL)
    throw GameException("Error on init window");
  else
    return (SDL_SetVideoMode(a, b, c, d));
}

void		SdlManager::xSDL_WM_SetCaption(char *title, char *icon)
{
  SDL_WM_SetCaption(title, icon);
}

Uint32		SdlManager::xSDL_MapRGB(SDL_PixelFormat* format, Uint8 r, Uint8 g, Uint8 b)
{
  SDL_MapRGB(format, r, g, b);
}

void		SdlManager::xSDL_Quit(void)
{
  SDL_Quit();
}

int		SdlManager::xSDL_PollEvent(SDL_Event* event)
{
  SDL_PollEvent(event);
}
  
void		SdlManager::xSDL_FreeSurface(SDL_Surface* surface)
{
  SDL_FreeSurface(surface);
}
