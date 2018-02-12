//
// PackFactory.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Fri Apr 25 12:35:58 2014 Bonnet Vivien
// Last Update Fri Apr 25 17:41:48 2014 Bonnet Vivien
//

#ifndef PACK_FACTORY_HH_
# define PACK_FACTORY_HH_

# include "Lexer.hh"
# include "Parser.hh"
# include "Pizza.hh"
# include "PizzaString.hh"

class			PackFactory
{
private:
  Lexer			m_lexer;
  Parser		m_parser;
  PizzaString*		m_command;
  Pizza::Pack		m_pack;
  unsigned int		m_packReturnedNumber;
  unsigned int		m_waitingPacks;

public:
  PackFactory();
  ~PackFactory();

private:
  Pizza::TypePizza	getType(const std::string& arg) const;
  Pizza::TaillePizza	getSize(const std::string& arg) const;

public:
  void	setCommand(const std::string& command);
  bool	getPack(Pizza::Pack& pack);
};

#endif // !PACK_FACTORY_HH_
