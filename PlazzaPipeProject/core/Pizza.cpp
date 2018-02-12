//
// Pizza.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 09:29:28 2014 Bonnet Vivien
// Last Update Sat Apr 26 17:37:53 2014 Bonnet Vivien
//

#include <map>

#include "Pizza.hh"

Pizza::Pizza()
{
}

Pizza::Pizza(TypePizza type, TaillePizza size)
{
  m_type = type;
  m_size = size;
}

Pizza::Pizza(const Pizza::Pack& pack)
{
  this->unpack(pack);
}

Pizza::~Pizza()
{
}


Pizza::TypePizza
Pizza::getType() const
{
  return (m_type);
}

Pizza::TaillePizza
Pizza::getSize() const
{
  return (m_size);
}

const std::string
Pizza::getName() const
{
  std::map<Pizza::TypePizza, std::string>	names;

  names[Pizza::Regina]		= "Regina";
  names[Pizza::Margarita]	= "Margarita";
  names[Pizza::Americaine]	= "Americaine";
  names[Pizza::Fantasia]	= "Fantasia";

  return (names[m_type]);
}

const std::string
Pizza::getSizeName() const
{
  std::map<Pizza::TaillePizza, std::string>	names;

  names[Pizza::S]	= "short";
  names[Pizza::M]	= "medium";
  names[Pizza::L]	= "large";
  names[Pizza::XL]	= "very large";
  names[Pizza::XXL]	= "serguei";

  return (names[m_size]);
}


const Pizza::Pack
Pizza::pack() const
{
  Pack	pack;

  pack.type = m_type;
  pack.size = m_size;

  return (pack);
}

void
Pizza::unpack(const Pizza::Pack& pack)
{
  m_type = pack.type;
  m_size = pack.size;
}
