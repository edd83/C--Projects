//
// PizzaString.cpp for PizzaString in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 17:49:42 2014 lardet
// Last Update Fri Apr 25 17:38:47 2014 Bonnet Vivien
//

#include "ParserException.hh"
#include "PizzaString.hh"

PizzaString::PizzaString()
{
}

PizzaString::~PizzaString()
{

}

const std::vector<std::string>&	PizzaString::getArgs() const
{
  return (this->_args);
}

int				PizzaString::verif(const std::string &command)
{
  unsigned int			i = 0;

  while(command[i])
    {
      if (command[i] == ' ' && command[i + 1] == ' ')
	return (-1);
      if (command[i] == ' ' && command[i + 1] == ';')
	return (-1);
      if (command[i] == ';' && command[i + 1] == ' ' && command.size() == i + 2)
	return (-1);
      i++;
    }
  return (0);
}

int				PizzaString::Split(const std::string &command)
{
  std::string::size_type prev_pos = 0, pos = 0;

  if (this->verif(command) == -1)
    return (-1);
  while((pos = command.find(' ', pos)) != std::string::npos)
    {
      std::string substring(command.substr(prev_pos, pos-prev_pos));
      this->_args.push_back(substring);
      prev_pos = ++pos;
    }
  this->_args.push_back(command.substr(prev_pos, pos-prev_pos));
  return (0);
}

int				PizzaString::Begin(const std::string& command)
{
  if (this->Split(command) != 0)
    {
      throw ParserException("So many espace");
      return (-1);
    }
  return (0);
}
