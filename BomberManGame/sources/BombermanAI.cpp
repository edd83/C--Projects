//
// BombermanAI.cpp for BombermanAI in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 10:44:36 2014 volpe
// Last update Sun Jun 15 18:57:45 2014 Fabien Casoni
//

#include		"BombermanAI.hh"

BombermanAI::BombermanAI(int x, int y, int id)
{
  this->_speed = 5;
  this->_x = x;
  this->_y = y;
  this->_nbBombs = 1;
  this->_state = WAITING;
  this->_score = 0;
  this->_id = id;
  this->_dir = NONE;
  this->typeOfEntity = EntityNS::Player;
  this->rand.Srandom();
  this->gPlayer = NULL;
  this->actionToDo = GraphPlayer::None;
}

BombermanAI::~BombermanAI()
{

}

bool	BombermanAI::runAway(Map &map)
{
  std::list<Entity *>::iterator it;
  std::list<Entity *> bombList;

  bombList = map.getBombList();
  for (it = bombList.begin(); it != bombList.end(); it++)
    {
      if (bombInRange((*it), this->_x, this->_y) == true &&
	  map.wallCover(this->getX(), this->getY(), (*it)->getX(), (*it)->getY()) == false)
	{
	  if ((*it)->getX() != this->_x)
	    {
	      if (this->move(UP, map, this->gPlayer) == 1)
		return (true);
	      else if (this->move(DOWN, map, this->gPlayer))
		return (true);
	      else if (this->_x > (*it)->getX())
		{
		  if (this->move(RIGHT, map, this->gPlayer))
		    return (true);
		}
	      else
		{
		  if (this->move(LEFT, map, this->gPlayer))
		    return (true);
		}
	    }
	  else if ((*it)->getY() != this->_y)
	    {
	      if (this->move(RIGHT, map, this->gPlayer))
		return (true);
	      else if (this->move(LEFT, map, this->gPlayer))
		return (true);
	      else if (this->_y > (*it)->getY())
		{
		  if (this->move(UP, map, this->gPlayer))
		    return (true);
		}
	      else
		{
		  if (this->move(DOWN, map, this->gPlayer))
		    return (true);
		}
	    }
	  else if ((*it)->getX() == this->_x && (*it)->getY() == this->_y)
	    {
	      this->moveRand(map);
	      return (true);
	    }
	  return (false);
	}
    }
  return (false);
}

bool	BombermanAI::whereToMove(int x, int y, Map &map)
{
  std::list<int> x_ends;
  std::list<int> y_ends;
  std::list<Node *> path;

  x_ends.push_back(x);
  y_ends.push_back(y);
  AStar *astar = new AStar(this->_x, this->_y, x_ends, y_ends, "12");
  path = astar->GivePath((MyStringArray&)*map.getMap());
  if (path.size() == 0)
    return (false);
  if (static_cast<unsigned int>(path.front()->getCoordX()) != this->_x)
    {
      if (path.front()->getCoordX() > x)
	{
	  this->move(RIGHT, map, this->gPlayer);
	  return (true);
	}
      else
	{
	  this->move(LEFT, map, this->gPlayer);
	  return (true);
	}
    }
  else if (static_cast<unsigned int>(path.front()->getCoordY()) != this->_y)
    {
      if (static_cast<unsigned int>(path.front()->getCoordY()) > this->_y)
	{
	  this->move(UP, map, this->gPlayer);
	  return (true);
	}
      else
	{
	  this->move(DOWN, map, this->gPlayer);
	  return (true);
	}
    }
  return (false);
}

bool	BombermanAI::bombInRange(Entity *bomb, unsigned int x, unsigned int y)
{
  if ((bomb->getX() == x && bomb->getY() == y) 
      || (bomb->getY() == y))
    {
      if (bomb->getX() >= x)
	{
	  if ((bomb->getX() - (((Bombe*)(bomb))->getRange())) <= x)
	      return (true);
	}
      else if (bomb->getX() < x)
	{
	  if ((bomb->getX() + (((Bombe *)(bomb))->getRange())) >= x)
	    return (true);
        }
    }
  else if (bomb->getX() == x)
    {
      if (bomb->getY() >= y)
	{
	  if ((bomb->getY() - (((Bombe *)(bomb))->getRange())) <= y)
	    return (true);
	}
      else if (bomb->getY() < y)
	{
	  if ((bomb->getY() + (((Bombe *)(bomb))->getRange())) >= y)
	    return (true);
	}
    }
  return (false);
}

bool	BombermanAI::isInDanger(std::list<Entity *> &bombList, Map &map)
{
  std::list<Entity *>::iterator it;

  for (it = bombList.begin(); it != bombList.end(); it++)
    {
      if (bombInRange((*it), this->_x, this->_y) == true &&
	  map.wallCover(this->getX(), this->getY(), (*it)->getX(), (*it)->getY()) == false)
	return (true);
    }
  return (false);
}

int	BombermanAI::checkY(Map &map)
{
  if (this->getY() + 2 <= map.getLength())
    return (2);
  else if(this->getY() + 1 <= map.getLength())
    return (1);
  else
    return (0);
}

int	BombermanAI::checkLessY()
{
  if (this->getY() >= 2)
    return (-2);
  else if (this->getY() >= 1)
    return (-1);
  else
    return (0);
}

int	BombermanAI::checkLessX()
{
  if (this->getX() >= 2)
    return (-2);
  else if (this->getX() >= 1)
    return (-1);
  else
    return (0);
}

unsigned int*	BombermanAI::checkRangePlayer(Map &map)
{
  unsigned int	x = 0;
  unsigned int	y = 0;
  unsigned int	x2 = 0;
  unsigned int	y2 = 0;
  unsigned int	*tab;

  if ((tab = static_cast<unsigned int*>(malloc(sizeof(int) * 4))) == NULL)
    return (NULL);
  if (this->getX() + 2 <= map.getWidth())
    {
      x = 2;
      x2 = checkLessX();
      y = checkY(map);
      y2 = checkLessY();
    }
  else if (this->getX() + 1 <= map.getWidth())
    {
      x = 1;
      x2 = checkLessX();
      y = checkY(map);
      y2 = checkLessY();
    }
  else
    {
      x = 0;
      x2 = checkLessX();
      y = checkY(map);
      y2 = checkLessY();
    }
  tab[0] = this->getX() + x2; //MinX
  tab[1] = this->getX() + x; //MaxX
  tab[2] = this->getY() + y2; //MinY
  tab[3] = this->getY() + y; //MaxY
  return (tab);
}

int	BombermanAI::enemyClose(std::list<Entity *> &playerList, Map &map)
{
  std::list<Entity *>::iterator it;
  unsigned int                  *tab;
  if ((tab = static_cast<unsigned int*>(malloc(sizeof(int) * 4))) == NULL)
    return (-1);
  for (it = playerList.begin(); it != playerList.end(); it++)
    {
      if ((tab = checkRangePlayer(map)) == NULL)
        return (-1);
      Player *play = dynamic_cast<Player *>((*it));
      if (play->getId() != this->getId() 
	  && (play->getX() > tab[0] || play->getX() == tab[0]) 
	  && (play->getX() < tab[1] || play->getX() == tab[1])
	  && (play->getY() > tab[2] || play->getY() == tab[2])
	  && (play->getY() < tab[3] || play->getY() == tab[3]))
	return (play->getId());
    }
  return (-1);
}

void	BombermanAI::chooseAction(Map &map, std::list<GModel*> &listOfModels)
{
  int		id = 0;
  std::list<Entity *> bombList;
  std::list<Entity *> playerList;
  std::list<Entity *> bonusList;
  
  bombList = map.getBombList();
  playerList = map.getPlayerList();
  bonusList = map.getBonusList();  
  if (this->isInDanger(bombList, map) == true)
    this->runAway(map);
  else if ((id = enemyClose(playerList, map)) != -1)
    {
      Player *play;
      
      if ((play = map.getPlayerById(id)) != NULL)
	{
	  // if (play->getX() - 1 == this->getX() || play->getX() - 2 == this->getX() || play->getX() + 1 == this->getX() || play->getX() + 2 == this->getX() || play->getY() - 1 == this->getY() || play->getY() - 2 == this->getY() || play->getY() + 1 == this->getY() || play->getY() + 2 == this->getY())
	  //   {
	  //     //this->setBomb(map, listOfModels);
	  //     this->runAway(map);
	  this->whereToMove(play->getX(), play->getY(), map);
	}
    }
  else if (this->checkBonus(bonusList, map) == -1)
    {
      if (this->checkBrick(map, listOfModels) == -1)
	this->moveRand(map);
    }
}

int	BombermanAI::checkBonus(std::list<Entity *> &bonusList, Map &map)
{
  std::list<Entity *>::iterator it;
  unsigned int                  *tab;

  if ((tab = static_cast<unsigned int*>(malloc(sizeof(int) * 4))) == NULL)
    throw MyException ("Error on malloc");
  for (it = bonusList.begin(); it != bonusList.end(); it++)
    {
      if ((tab = checkRangePlayer(map)) == NULL)
	throw MyException ("Error on checkRangePlayer()");
      Bonus *bon = dynamic_cast<Bonus *>((*it));
      if ((bon->getX() > tab[0] || bon->getX() == tab[0])
	  && (bon->getX() < tab[1] || bon->getX() == tab[1])
	  && (bon->getY() > tab[2] || bon->getY() == tab[2])
	  && (bon->getY() < tab[3] || bon->getY() == tab[3]))
	{
	  this->whereToMove(bon->getX(), bon->getY(), map);
	  return (0);
	}
    }
  return (-1);
}

int	BombermanAI::firstLoop(unsigned int i, unsigned int j, int *k, int *h,
			       int save_i, Map &map)
{
  while ((*k) != -1)
    {
      save_i = i;
      if (((i + (*h)) == map.getWidth()) || ((i - (*h)) <= 0))
	break;
      if (map.getCase(i + (*h), j) == static_cast<unsigned char>('2'))
	{
	  save_i = i + (*h);
	  (*k) = -1;
	}
      else if (map.getCase(i - (*h), j) == static_cast<unsigned char>('2'))
	{
	  (*k) = -1;
	  save_i = i - (*h);
	}
      (*h)++;
    }
  return (save_i);
}

int	BombermanAI::secondLoop(unsigned int i, unsigned int j, int *k,
				int *h, int save_j, Map &map)
{
  while ((*k) != -1)
    {
      save_j = j;
      if ((j + (*h)) >= map.getLength() || (j - (*h)) <= 0)
	break;
      if (map.getCase(i, j + (*h)) == static_cast<unsigned char>('2'))
	{
	  (*k) = -1;
	  save_j = j + (*h);
	}
      else if (map.getCase(i, j - (*h)) == static_cast<unsigned char>('2'))
	{
	  (*k) = -1;
	  save_j = j - (*h);
	}
      (*h)++;
    }
  return (save_j);
}

int	BombermanAI::checkBrick(Map &map, std::list<GModel*> &)
{
  unsigned int	i = this->getX();
  unsigned int	j = this->getY();
  int		k = 1;
  int		h = 1;
  int		save_i = this->getX();
  int		save_j = this->getY();

  save_i = this->firstLoop(i, j, &k, &h, save_i, map);
  if (h == 2 && k == -1)
    {
      //this->setBomb(map, listOfModels);
      this->runAway(map);
      return (0);
    }
  else if (k != -1)
    {
      h = 1;
      save_j = this->secondLoop(i, j, &k, &h, save_j, map);
      if (h == 2 && k == -1)
	{
	  //this->setBomb(map, listOfModels);
	  this->runAway(map);
	  return (0);
	}
    }
  else
    {
      if (k == -1 && h != 2)
	{
	  if (!this->whereToMove(save_i, save_j, map))
	    this->moveRand(map);
	  return (0);
	}
    }
  return (-1);
}

void	BombermanAI::moveRand(Map &map)
{
  Random	rand;
  int		i = 0;

  i = this->rand.GetRandomRN(4);
  this->move(static_cast<eMove>(i - 1), map, this->gPlayer);
}

void	BombermanAI::executeAction()
{
}

void	BombermanAI::checkMap()
{
}

void	BombermanAI::start(Map &map, std::list<GModel*> &listOfModels)
{
  std::list<Entity *> bombList;
  std::list<Entity *>::iterator it;

  if (this->gPlayer == NULL)
    this->gPlayer = this->retGPlayer(this->_x, this->_y, listOfModels);
  if (this->gPlayer != NULL && (this->gPlayer->getFrameCounter() == 0
				|| this->gPlayer->getFrameCounter() == 1))
    {
      bombList = map.getBombList();
      this->chooseAction(map, listOfModels);
    }
}
