//
// avm_error.hpp for avm_error in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Feb 24 23:05:03 2014 lardet
// Last update Sun Mar  2 20:02:07 2014 lardet
//

#ifndef __SYNTAX_ERROR_HPP
# define __SYNTAX_ERROR_HPP

#include	<stdexcept>

class	avm_error : public std::exception
{
private:
  std::string	_what;
  int		_where;
public:
  avm_error(std::string const &what, int const where);
  ~avm_error() throw();
  const char	*what() const throw();
  int		where() const throw();
};

#endif
