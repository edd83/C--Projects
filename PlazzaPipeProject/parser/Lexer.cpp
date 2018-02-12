//
// Lexeur.cpp for Lexeur in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 16:25:33 2014 lardet
// Last Update Fri Apr 25 13:01:40 2014 Bonnet Vivien
//

#include "Lexer.hh"
#include "ParserException.hh"
#include <stdlib.h>

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}

void	Lexer::IsValidNb(std::string &arg, std::string &it, int i)
{
  if (arg[0] == 'x')
    if (arg.size() == 3 && i == 0)
      {
        if (arg[1] >= '0' && arg[1] <= '9')
	  {
	    if (arg[arg.length() - 1] == ';')
	      return ;
	    else
	      throw ParserException("Wrong syntax for the pizza number");
	  }
	else
	  throw ParserException("Wrong number for the pizza number");
      }
    else if (arg.size() == 2 && arg.find(it) == 0 && i == 1)
      {
	if (arg[1] >= '0' && arg[1] <= '9')
	  return ;
	else
	  throw ParserException("Wrong number for the pizza number");
      }
    else
      throw ParserException("Wrong syntax for the pizza number");
  else
    throw ParserException("Wrong syntax for the pizza number, it's x[0..9];");
}

void	Lexer::Lexing(const PizzaString &pizza)
{
  std::vector<std::string>	args;
  std::string			end;
  int				nb;

  args = pizza.getArgs();
  end = args.at(args.size() - 1);
  if ((nb = args.size()) < 3)
    throw ParserException("Need more arguments");
  for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it)
    {
      if (it + 1 == args.end())
	throw ParserException("Wrong syntax");
      it++;
      if (it + 1 == args.end())
	throw ParserException("Wrong syntax");
      it++;
      if ((it + 1) == args.end())
	{
	  this->IsValidNb(*it, end, 1);
	}
      else
	this->IsValidNb(*it, end, 0);
    }
}
