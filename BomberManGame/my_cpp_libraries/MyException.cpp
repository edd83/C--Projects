//
// MyException.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/merge-client/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Jun  9 18:12:00 2014 ovoyan_s
// Last update Mon Jun  9 18:12:02 2014 ovoyan_s
//

#include "MyException.hh"

MyException::MyException(std::string const& error) throw() : Error(error)
{
}

MyException::~MyException() throw()
{
}

char const*		MyException::what() const throw()
{
  return this->Error.c_str();
}
