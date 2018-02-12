//
// GameException.hh for GameException in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:10:57 2014 volpe
// Last update Tue Apr  1 16:19:37 2014 volpe
//


#ifndef	__GAMEEXCEPTION_HH__
#define	__GAMEEXCEPTION_HH__

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

class	GameException : public std::exception
{
protected:
  std::string	_msg;
public:
  GameException(const char *);
  virtual	~GameException() throw();
  virtual const char * what() const throw();
};

#endif
