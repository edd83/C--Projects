//
// Bonus.cpp for Bonus$ in /home/casoni_f/Projets/cpp_bomberman/Core
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Thu May 29 17:36:09 2014 Fabien Casoni
// Last update Fri Jun 13 14:51:02 2014 volpe
//

#include	"Bonus.hh"

Bonus::Bonus(int x, int y, BonusId guid)
{
  this->_x = x;
  this->_y = y;
  this->_guid = guid;
  this->typeOfEntity = EntityNS::Bonus;
}

BonusId		Bonus::getGuid() const
{
  return (this->_guid);
}

void		Bonus::setGuid(BonusId guid)
{
  this->_guid = guid;
}

void		Bonus::removeFromModelList(std::list<GModel *> listModel, unsigned int x, unsigned int y, EntityNS::Nature nature)
{
  std::list<GModel *>::iterator	it;

  for (it = listModel.begin(); it != listModel.end(); it++)
    {
      if (static_cast<unsigned int>((*it)->getCoordMapX()) == x && static_cast<unsigned int>((*it)->getCoordMapY()) == y && (*it)->getModelType() == nature)
	listModel.erase(it);
    }
}

void		Bonus::onPickUp(Player &player, Map &map, std::list<GModel *> listModel)
{
  std::list<Entity *>::iterator	it;
  std::list<Entity *> bonusList = map.getBonusList();

  it = bonusList.begin();
  void (Player::*tab[3])();

  tab[0] = &Player::addRange;
  tab[1] = &Player::addBomb;
  tab[2] = &Player::addSpeed;

  if (this->_guid == ARMOR)
      player.setHp(player.getHp() + 1);
  else
      (player.*tab[this->_guid])();
  while (it != bonusList.end()
	 && (*it)->getX() != this->_x
	 && (*it)->getY() != this->_y)
    ++it;
  (map.getBonusList()).remove((*it));
  this->removeFromModelList(listModel, this->_x, this->_y, EntityNS::Bonus);
  
}

Bonus::~Bonus()
{
}
