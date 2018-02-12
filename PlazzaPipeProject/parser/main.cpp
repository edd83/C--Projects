//
// main.cpp for main in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 19:25:36 2014 lardet
// Last Update Fri Apr 25 17:37:50 2014 Bonnet Vivien
//

#include "PizzaString.hh"
#include "Lexer.hh"
#include "Parser.hh"

int		main(int ac, char **av)
{
  PizzaString	my_piz;
  Lexer		lexer;
  Parser	parser;

  if (ac != 2)
    {
      return (-1);
      std::cout << "Wrong usage" << std::endl;
    }
  std::string	str(av[1]);
  std::cout << str << std::endl;

  my_piz.Begin(str);
  lexer.Lexing(my_piz);
  parser.Parsing(my_piz);
  return (0);
}
