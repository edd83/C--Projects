//
// StringException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:42:12 2014 Bonnet Vivien
// Last Update Sun Apr 27 13:41:07 2014 Bonnet Vivien
//

#include "StringException.hh"

StringException::StringException(const std::string& message) :
  PlazzaException(message)
{
}

StringException::~StringException() throw()
{
}
