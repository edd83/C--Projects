//
// PackFactory.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Fri Apr 25 12:50:52 2014 Bonnet Vivien
// Last Update Sat Apr 26 16:34:16 2014 Bonnet Vivien
//

#include <map>

#include "PackFactory.hh"
#include "StringTransformer.hpp"

PackFactory::PackFactory()
{
  m_command = NULL;
  m_packReturnedNumber = 0;
  m_waitingPacks = 0;
}

PackFactory::~PackFactory()
{
  if (m_command != NULL)
    delete (m_command);
}


Pizza::TypePizza
PackFactory::getType(const std::string& arg) const
{
  std::map<std::string, Pizza::TypePizza>	types;

  types["regina"]	= Pizza::Regina;
  types["margarita"]	= Pizza::Margarita;
  types["americaine"]	= Pizza::Americaine;
  types["fantasia"]	= Pizza::Fantasia;
  return (types[arg]);
}

Pizza::TaillePizza
PackFactory::getSize(const std::string& arg) const
{
  std::map<std::string, Pizza::TaillePizza>	sizes;

  sizes["S"]	= Pizza::S;
  sizes["M"]	= Pizza::M;
  sizes["L"]	= Pizza::L;
  sizes["XL"]	= Pizza::XL;
  sizes["XXL"]	= Pizza::XXL;
  return (sizes[arg]);
}


void
PackFactory::setCommand(const std::string& command)
{
  if (m_command != NULL)
    delete (m_command);

  m_command = new PizzaString();
  m_command->Begin(command);
  m_lexer.Lexing(*m_command);
  m_parser.Parsing(*m_command);
  m_packReturnedNumber = 0;
}

bool
PackFactory::getPack(Pizza::Pack& pack)
{
  const std::vector<std::string>&	args = m_command->getArgs();
  bool					returned;

  returned = true;
  if (m_waitingPacks == 0 && args.size() > m_packReturnedNumber * 3)
    {
      m_pack.type = this->getType(args[m_packReturnedNumber * 3 + 0]);
      m_pack.size = this->getSize(args[m_packReturnedNumber * 3 + 1]);
      m_waitingPacks = StringTransformer::castTo<unsigned int>
	(args[m_packReturnedNumber * 3 + 2].substr(1, args[m_packReturnedNumber * 3 + 2].size() - 1));
      ++m_packReturnedNumber;
    }

  if (m_waitingPacks > 0)
    {
      --m_waitingPacks;
      pack = m_pack;
    }
  else
    returned = false;

  return (returned);
}
