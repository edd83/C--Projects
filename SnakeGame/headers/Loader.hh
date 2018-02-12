//
// Loader.hh for Loader in /home/volpe_p/rendu/Nibbler/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Apr  6 13:51:25 2014 volpe
// Last update Sun Apr  6 14:21:07 2014 volpe
//

#ifndef LOADER_HH_
# define LOADER_HH_

#include "../ncurses/headers/Display.hh"
#include <string>

class Loader
{
private:
  char		*_libpath;
  void		*_handle;
public:
  Loader(char	*);
  ~Loader();

  maker_Display	Init();
  void		close();


};
#endif
