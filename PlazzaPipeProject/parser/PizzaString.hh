//
// PizzaString.hh for PizzaString in /home/lardet_e/TP/plazza
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Apr 14 17:49:46 2014 lardet
// Last Update Fri Apr 25 15:26:50 2014 Bonnet Vivien
//

#ifndef _PIZZASTRING_HH_
# define _PIZZASTRING_HH_

#include <iostream>
#include <vector>

class	PizzaString
{
private:
  std::vector<std::string>		_args;
public:
  PizzaString();
  ~PizzaString();
  int					Begin(const std::string &);
  int					Split(const std::string &);
  const std::vector<std::string>&	getArgs() const;
  int					verif(const std::string &);
};

#endif
