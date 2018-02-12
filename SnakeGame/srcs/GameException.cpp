//
// GameException.cpp for GameException in /home/volpe_p/rendu/Nibbler/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:14:46 2014 volpe
// Last update Tue Apr  1 16:14:48 2014 volpe
//

#include	"../headers/GameException.hh"

GameException::GameException(const char * Msg)
{
  std::ostringstream oss;

  oss << Msg;
  this->_msg = oss.str();
}

GameException::~GameException() throw()
{

}


const char	*GameException::what() const throw()
{
  return (this->_msg.c_str());
}
