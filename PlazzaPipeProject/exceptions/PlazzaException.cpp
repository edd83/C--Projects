//
// PlazzaException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Mon Apr 14 13:41:29 2014 Bonnet Vivien
// Last Update Mon Apr 14 13:42:06 2014 Bonnet Vivien
//

#include "PlazzaException.hh"

PlazzaException::PlazzaException(const std::string& message) :
  m_message(message)
{
}

PlazzaException::~PlazzaException() throw()
{
}


const char*
PlazzaException::what() const throw()
{
  return (m_message.c_str());
}
