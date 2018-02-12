//
// ProcessException.cpp for GameException in /home/volpe_p/rendu/Plazza/TP
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Fri Apr 25 18:14:01 2014 volpe
// Last Update Sat Apr 26 10:37:29 2014 Bonnet Vivien
//

#include	"ProcessException.hh"

ProcessException::ProcessException(const std::string& message) :
  PlazzaException(message)
{
}

ProcessException::~ProcessException() throw()
{
}
