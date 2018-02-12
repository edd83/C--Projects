//
// Window.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May 28 10:41:14 2014 ovoyan_s
// Last update Fri Jun  6 12:02:13 2014 volpe
//

#ifndef				WINDOW_HH_
# define			WINDOW_HH_

/*
**				GDL INCLUDES
*/

# include			<SdlContext.hh>

/*
**				GENERAL INCLUDES
*/

# include			<iostream>
# include			<string>

/*
**				MY INCLUDES
*/

# include			"MyException.hh"

class				Window
{
private:
  unsigned int			XSizeWindow;
  unsigned int			YSizeWindow;
  std::string			name;
  gdl::SdlContext		*sdl_context;

public:
  Window();
  Window(unsigned int sizeWindowToSetX, unsigned int sizeWindowToSetY);
  Window(unsigned int sizeWindowToSetX, unsigned int sizeWindowToSetY, const std::string &name);
  Window(const std::string &name);
  ~Window();

  unsigned int			getSizeX();
  unsigned int			getSizeY();
  std::string			getName();
  gdl::SdlContext		*getSDLContext();
};

#endif				/*	WINDOW_HH_	*/
