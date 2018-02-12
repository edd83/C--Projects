//
// NcursesException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:50:59 2014 Bonnet Vivien
// Last Update Fri Apr 25 18:05:11 2014 Bonnet Vivien
//

#include "NcursesException.hh"

namespace nc
{

NcursesException::NcursesException(const std::string& message) :
  m_message(message)
{
}

NcursesException::~NcursesException() throw()
{
}


const char*
NcursesException::what() const throw()
{
  return (m_message.c_str());
}

}
