//
// avm_error.cpp for avm_error in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Feb 24 23:12:50 2014 lardet
// Last update Sun Mar  2 20:01:41 2014 lardet
//

#include "avm_error.hpp"

avm_error::avm_error(std::string const &what, int const where) : std::exception(), _what(what), _where(where) {}

avm_error::~avm_error() throw() {}

const char	*avm_error::what() const throw()
{
  return this->_what.c_str();
}

int	avm_error::where() const throw()
{
  return this->_where;
}
