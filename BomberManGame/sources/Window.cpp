//
// Window.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May 28 10:47:21 2014 ovoyan_s
// Last update Sun Jun 15 17:47:30 2014 Fabien Casoni
//

/*
**				MY INCLUDES
*/

#include			"Window.hh"

Window::Window()
{
  this->XSizeWindow = 800;
  this->YSizeWindow = 600;
  this->name = "BOMBERMAN FNLC 2014";
  this->sdl_context = new gdl::SdlContext;
}

Window::Window(unsigned int sizeWindowToSetX, unsigned int sizeWindowToSetY)
{
  if (sizeWindowToSetX > 1920 || sizeWindowToSetX < 100
      || sizeWindowToSetY > 1080 || sizeWindowToSetY < 100)
    throw MyException("Invalid window sizes");
  this->XSizeWindow = sizeWindowToSetX;
  this->YSizeWindow = sizeWindowToSetY;
  this->name = "BOMBERMAN FNLC 2014";
  this->sdl_context = new gdl::SdlContext;
}

Window::Window(unsigned int sizeWindowToSetX, unsigned int sizeWindowToSetY,
	       const std::string &nameToSet)
{
  if (sizeWindowToSetX > 1920 || sizeWindowToSetX < 100
      || sizeWindowToSetY > 1080 || sizeWindowToSetY < 100)
    throw MyException("Invalid window sizes");
  this->XSizeWindow = sizeWindowToSetX;
  this->YSizeWindow = sizeWindowToSetY;
  this->name = nameToSet;
  this->sdl_context = new gdl::SdlContext;
}

Window::Window(const std::string &nameToSet)
{
  this->XSizeWindow = 800;
  this->YSizeWindow = 600;
  this->name = nameToSet;
  this->sdl_context = new gdl::SdlContext;
}

unsigned int			Window::getSizeX()
{
  return (this->XSizeWindow);
}

unsigned int			Window::getSizeY()
{
  return (this->YSizeWindow);
}

std::string			Window::getName()
{
  return (this->name);
}

gdl::SdlContext			*Window::getSDLContext()
{
  return (this->sdl_context);
}

Window::~Window()
{

}
