//
// Entity.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 26 18:33:12 2014 ovoyan_s
// Last update Wed Jun 11 16:57:56 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"Entity.hh"

Entity::Entity()
{
  this->_x = 0;
  this->_y = 0;
  this->typeOfEntity = EntityNS::NoNature;
}

Entity::Entity(unsigned int coordX, unsigned int coordY, const EntityNS::Nature &typeToSet)
{
  this->_x = coordX;
  this->_y = coordY;
  this->typeOfEntity = typeToSet;
}

void				Entity::setX(unsigned int coordToSetX)
{
  this->_x = coordToSetX;
}

void				Entity::setY(unsigned int coordToSetY)
{
  this->_y = coordToSetY;
}

void				Entity::setEntity(const EntityNS::Nature &typeToSet)
{
  this->typeOfEntity = typeToSet;
}

unsigned int			Entity::getX() const
{
  return (this->_x);
}

unsigned int			Entity::getY() const
{
  return (this->_y);
}

EntityNS::Nature		Entity::getEntity() const
{
  return (this->typeOfEntity);
}
