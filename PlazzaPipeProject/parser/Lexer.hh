//
// Lexeur.hh for Lexeur in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 16:25:28 2014 lardet
// Last Update Fri Apr 25 13:01:13 2014 Bonnet Vivien
//

#ifndef _LEXER_HH_
# define _LEXER_HH_

#include "PizzaString.hh"

class	Lexer
{
public:
  Lexer();
  ~Lexer();
  void	Lexing(const PizzaString &);
  int	IsValidType();
  int	IsValidSize();
  void	IsValidNb(std::string &, std::string &, int);
};

#endif
