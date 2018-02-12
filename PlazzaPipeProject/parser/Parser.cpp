//
// Parser.cpp for Parser in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 16:25:48 2014 lardet
// Last Update Fri Apr 25 13:39:07 2014 Bonnet Vivien
//

#include "Parser.hh"
#include "ParserException.hh"

Parser::Parser()
{
  this->InitSize();
  this->InitType();
}

Parser::~Parser()
{
}

void	Parser::InitSize()
{
  this->_size.push_back("S");
  this->_size.push_back("M");
  this->_size.push_back("L");
  this->_size.push_back("XL");
  this->_size.push_back("XXL");
}

void	Parser::InitType()
{
  this->_type.push_back("regina");
  this->_type.push_back("margarita");
  this->_type.push_back("americaine");
  this->_type.push_back("fantasia");
}

void	Parser::IsValidType(std::string &arg)
{
  for (std::vector<std::string>::iterator it = this->_type.begin(); it != this->_type.end(); ++it)
    if (*it == arg)
      return ;
  throw ParserException("Wrong pizza type. Types: regina, fantasia, margarita, americaine.");
}

void	Parser::IsValidSize(std::string &arg)
{
  for (std::vector<std::string>::iterator it = this->_size.begin(); it != this->_size.end(); ++it)
    if (*it == arg)
      return ;
  throw ParserException("Wrong size. Sizes: S, M, L, XL, XXL.");
}

void	Parser::Parsing(const PizzaString &pizza)
{
  std::vector<std::string>	args;

  args = pizza.getArgs();
  for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it)
    {
      this->IsValidType(*it);
      it++;
      this->IsValidSize(*it);
      it++;
    }
}

