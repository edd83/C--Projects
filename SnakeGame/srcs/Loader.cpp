//
// Loader.cpp for Loader in /home/volpe_p/rendu/Nibbler/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Apr  6 13:49:28 2014 volpe
// Last update Sun Apr  6 17:51:29 2014 volpe
//
#include "../headers/Loader.hh"

Loader::Loader(char	*libpath)
{
  this->_libpath = libpath;
  this->Init();
}

Loader::~Loader()
{
}

maker_Display Loader::Init()
{
  void			*handle;
  void			*mkr;

  handle = dlopen(this->_libpath, RTLD_LAZY);
  if (handle == NULL)
    throw GameException("Error load librairie");
  this->_handle = handle;
  mkr = dlsym(this->_handle, "make_display");
  if (mkr == NULL)
    {
      this->close();
      throw GameException("Error load function librairie");
    }
  return ((maker_Display)mkr);
}

void	Loader::close()
{
  dlclose(this->_handle);
}
