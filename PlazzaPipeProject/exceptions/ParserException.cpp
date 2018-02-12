//
// ParserException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:42:12 2014 Bonnet Vivien
// Last Update Sat Apr 26 10:37:18 2014 Bonnet Vivien
//

#include "ParserException.hh"

ParserException::ParserException(const std::string& message) :
  PlazzaException(message)
{
}

ParserException::~ParserException() throw()
{
}
