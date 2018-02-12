//
// Bonus.hh for Bonus in /home/casoni_f/Projets/cpp_bomberman/Core
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Thu May 29 17:32:19 2014 Fabien Casoni
// Last update Fri Jun 13 14:52:53 2014 volpe
//

#ifndef			BONUS_HH_
# define		BONUS_HH_

#include		"Entity.hh"
#include		"Includes.hh"
#include		"GModel.hh"

enum			BonusId
  {
    BOMB_RANGE = 0,
    BOMB_MAX = 1,
    PLAYER_SPEED = 2,
    ARMOR = 3
  };

class			Map;

class			Player;

class			Bonus : public Entity
{
private:
  BonusId		_guid;

public:
  Bonus(int, int, BonusId);
  ~Bonus();
  BonusId		getGuid() const;
  void			setGuid(BonusId);
  void			onPickUp(Player &, Map &, std::list<GModel *>);
  void			removeFromModelList(std::list<GModel *>, unsigned int,
					    unsigned int, EntityNS::Nature);
};
#endif
