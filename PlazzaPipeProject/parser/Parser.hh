//
// Parser.hh for Parser in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 16:25:22 2014 lardet
// Last Update Fri Apr 25 13:00:26 2014 Bonnet Vivien
//

#ifndef _PARSER_HH_
# define _PARSER_HH_

#include "PizzaString.hh"

class	Parser
{
  std::vector<std::string>	_type;
  std::vector<std::string>	_size;
public:
  Parser();
  ~Parser();
  void	InitSize();
  void	InitType();
  void	Parsing(const PizzaString &);
  void	IsValidType(std::string &);
  void	IsValidSize(std::string &);
};

#endif
