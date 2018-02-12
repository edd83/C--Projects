//
// Bombe.cpp for Bombe in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 13:36:32 2014 volpe
// Last update Sun Jun 15 18:50:30 2014 Fabien Casoni
//

#include		"Bombe.hh"

Bombe::Bombe()
{

}

Bombe::Bombe(int x, int y, unsigned int pid)
{
  this->_range = 2;
  this->_x = x;
  this->_y = y;
  this->_player_id = pid;
  this->_timer = 5;
  this->_available = true;
  this->typeOfEntity = EntityNS::Bombe;
}

Bombe::~Bombe()
{
}

bool		Bombe::isAvailable() const
{
  return (this->_available);
}

unsigned int	Bombe::getPlayerId() const
{
  return (this->_player_id);
}

unsigned int	Bombe::getRange() const
{
  return (this->_range);
}

unsigned int	Bombe::getTimer() const
{
  return (this->_timer);
}

void		Bombe::setDisponibility(bool disp)
{
  this->_available = disp;
}

void		Bombe::setPlayerId(unsigned int id)
{
  this->_player_id = id;
}

void		Bombe::setRange(unsigned int range)
{
  this->_range = range;
}

void		Bombe::setTimer(unsigned int timer)
{
  this->_timer = timer;
}

void		Bombe::decrementTimer()
{
  --this->_timer;
}

void		Bombe::removeFromModelList(std::list<GModel *> &listModel, unsigned int x,
					   unsigned int y, EntityNS::Nature nature)
{
  std::list<GModel *>::iterator	it;

  for (it = listModel.begin(); it != listModel.end(); ++it)
    {
      if (static_cast<unsigned int>((*it)->getCoordMapX()) == x
	  && static_cast<unsigned int>((*it)->getCoordMapY()) == y && (*it)->getModelType() == nature)
	{
	  if (it != listModel.end())
	    it = listModel.erase(it);
	}
    }
}

unsigned int	bombIsInRange(Map &map, unsigned int x, unsigned int y, int dir)
{
  unsigned int	_x;
  unsigned int	_y;
  std::list<Entity *>::iterator	it = (map.getBombList()).begin();
  std::list<Entity *>	bombList;

  _x = x;
  _y = y;
  if (dir == RIGHT || dir == LEFT)
  {
      if (dir == RIGHT)
          ++_x;
      else
          --_x;
  }
  else if (dir == DOWN)
    ++_y;
  else
    --_y;
  if (_x > map.getLength() || _y > map.getWidth())
    return (0);
  bombList = map.getBombList();
  it = bombList.begin();
  while (it != bombList.end()
	 && static_cast<Bombe*>(*it)->getX() != _x
	 && static_cast<Bombe*>(*it)->getY() != _y)
    ++it;
  if (static_cast<Bombe*>(*it)->getX() == _x
      && static_cast<Bombe*>(*it)->getY() == _y)
    return (static_cast<Bombe*>(*it)->getPlayerId());
  return (0);
}


bool		brickIsInRange(Map &map, unsigned int x, unsigned int y, int dir)
{
  Random	rand;
  int		r;
  int		r2;
  unsigned int	_x;
  unsigned int	_y;

  _x = x;
  _y = y;
  if (dir == RIGHT || dir == LEFT)
    if (dir == RIGHT)
      ++_x;
    else
      --_x;
  else if (dir == DOWN)
    ++_y;
  else
    --_y;
  if (_x > map.getLength() || _y > map.getWidth())
    return (0);
  if (map.getCase(_x, _y) == '2')
    {
      r = rand.GetRandomRN(100);
      r2 = rand.GetRandomRN(3);
      if (r >= 0 && r <= 50)
	map.addBonus(*(new Bonus(_x, _y, static_cast<BonusId>(r2))));
      map.setCase(_x, _y, '0');
      return (true);
    }
  return (false);
}

int		playerIsInRange(Map &map, unsigned int x, unsigned int y, int dir)
{
  unsigned int	_x;
  unsigned int	_y;
  std::list<Entity *>::iterator	it;
  std::list<Entity *>	playerList;

  playerList = map.getPlayerList();
  it = playerList.begin();
  _x = x;
  _y = y;
  if (dir == RIGHT || dir == LEFT)
    if (dir == RIGHT)
      ++_x;
    else
      --_x;
  else if (dir == DOWN)
    ++_y;
  else
    --_y;
  if (_x > map.getLength() || _y > map.getWidth())
    return (0);
  while (it != playerList.end()
	 && static_cast<Player *>((*it))->getX() != _x 
	 && static_cast<Player *>((*it))->getY() != _y)
    ++it;
  if (it != playerList.end()
      && static_cast<Player *>((*it))->getX() == _x
      && static_cast<Player *>((*it))->getY() == _y)
    return (static_cast<Player *>((*it))->getId());
  return (0);
}

bool		wallIsInRange(Map &map, unsigned int x, unsigned int y, int dir)
{
  unsigned int	_x;
  unsigned int	_y;

  _x = x;
  _y = y;
  if (dir == RIGHT || dir == LEFT)
  {
      if (dir == RIGHT)
          ++_x;
      else
          --_x;
  }
  else if (dir == DOWN)
    ++_y;
  else
    --_y;
  if (_x > map.getLength() || _y > map.getWidth())
    return (0);
  if (map.getCase(_x, _y) == '1')
    return (true);
  return (false);
}

// void				Bombe::explose(Map &map, std::list<GModel *> &listModel)
// {
//   int				dir;
//   unsigned int			i;
//   unsigned int			bid;
//   int				pid;
//   std::list<Entity *>::iterator it;
//   std::list<Entity *>		playerList;
//   std::list<Entity *>		bombList;
//   std::list<Entity*>::iterator	endIt;
//   std::list<Entity*>::iterator	ii;

//   playerList = map.getPlayerList();
//   bombList = map.getBombList();

//   it = bombList.begin();
//   endIt = playerList.end();
//   dir = -1;
//   i = 0;
//   while (++dir <= UP)
//     {
//       while (++i < this->_range)
// 	{
// 	  if (wallIsInRange(map, this->_x, this->_y, dir) || brickIsInRange(map,
// 									    this->_x, this->_y, dir))
// 	    {
// 	      i = this->_range;
// 	    }
// 	  else if ((pid = playerIsInRange(map, this->_x, this->_y, dir)) > 0)
// 	    {
// 	      Player *player = map.getPlayerById(pid);
// 	      Player *thisPlayer = map.getPlayerById(this->_player_id);
// 	      if (player != NULL && thisPlayer != NULL)
// 		{
// 		  player->takeDamage(*thisPlayer);
// 		  if (player->getHp() == 0)
// 		    {
// 		      if (playerList.size() != 0)
// 			{
// 			  ii = map.getPlayerIT(pid);
// 			  if (ii != endIt)
// 			    playerList.erase(ii);
// 			}
// 		      this->removeFromModelList(listModel, player->getX(), player->getY(),
// 						EntityNS::Player);
// 		    }
// 		}
// 	    }
// 	  else if ((bid = bombIsInRange(map, this->_x, this->_y, dir)) > 0)
// 	    {
// 	      Bombe *bombe = map.getBombById(bid);

// 	      if (bombe != NULL)
// 		bombe->explose(map, listModel);
// 	    }
// 	}
//       i = 0;
//     }
//   this->_available = true;
//   while (it != bombList.end()
// 	 && !(static_cast<Bombe *>((*it))->isAvailable()) && (*it)->getX() != this->_x
// 	 && (*it)->getY() != this->_y)
//     ++it;
//   this->removeFromModelList(listModel, (*it)->getX(), (*it)->getY(), EntityNS::Bombe);
//   this->_x = 0;
//   this->_y = 0;
//   this->_timer = 5;
//   if (it != bombList.end())
//     (map.getBombList()).remove(map.getBombById(this->_player_id));
// }

