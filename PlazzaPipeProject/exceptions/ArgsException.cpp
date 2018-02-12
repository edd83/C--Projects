//
// ArgsException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:42:12 2014 Bonnet Vivien
// Last Update Mon Apr 14 14:28:37 2014 Bonnet Vivien
//

#include "ArgsException.hh"

void
ArgsException::throwUsage(const char* arg0)
{
  throw ArgsException((std::string)("Usage : ") + arg0 + " " + USAGE_MESSAGE);
}


ArgsException::ArgsException(const std::string& message) :
  PlazzaException(message)
{
}

ArgsException::~ArgsException() throw()
{
}
