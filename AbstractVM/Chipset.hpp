//
// Chipset.hpp for Chipset in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Feb 24 22:42:18 2014 lardet
// Last update Sun Mar  2 20:02:45 2014 lardet
//

#ifndef		__CHIPSET_HPP__
# define	__CHIPSET_HPP__

#define OPEN (0)
#define CLOSE (1)


#include	<iostream>
#include	<istream>
#include	<fstream>
#include	<sstream>
#include	<string>
#include	<map>
#include	<list>
#include	"IOperand.hpp"
#include        "Machine.hpp"


class		Chipset
{
  std::istream			*_input;
  std::list<std::string**>	_keyword;
  std::string			*instr;
  std::string			*val;
public:
  Chipset(std::istream *);
  ~Chipset();
  bool	Lexer(std::list<std::string> &, std::string &) const;

  bool	checkIfInstr(std::string const &to_cmp) const;
  bool	checkIfValue(std::string const &to_cmp) const;
  bool	checkIfPar(std::string const &to_cmp, const int macro) const;
  bool	checkIfValidValue(std::string const &value, std::string const &type) const;
  bool	Parser(std::list<std::string> &token, const int line) const;
  std::string  popNfront(std::list<std::string> &token) const;
  eInstruction	getInstruct(const std::string &) const;
  IOperand	*getOperand(std::list<std::string> &) const;
};

#endif		/*__CHIPSET_HPP__*/
