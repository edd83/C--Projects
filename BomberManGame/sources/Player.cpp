//
// Player.cpp for Player in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat May 17 16:19:07 2014 volpe
// Last update Sun Jun 15 20:30:19 2014 ovoyan_s
//

#include	"Player.hh"
#include	"Map.hh"

Player::Player()
{
}

Player::Player(int x, int y, int id)
{
  this->_speed = 5;
  this->_x = x;
  this->_y = y;
  this->_nbBombs = 1;
  this->_state = WAITING;
  this->_score = 0;
  this->_id = id;
  this->_dir = RIGHT;
  this->_hp = 1;
  this->typeOfEntity = EntityNS::Player;
  this->actionToDo = GraphPlayer::None;
}

Player::~Player()
{
}

GPlayer				*Player::retGPlayer(int coordX, int coordY,
						    std::list<GModel*> &modelsList)
{
  std::list<GModel*>::iterator	it;
  std::list<GModel*>		listOfModels;

  listOfModels = modelsList;
  it = listOfModels.begin();
  while (it != listOfModels.end())
    {
      if ((*it)->getCoordMapX() == coordX && (*it)->getCoordMapY() == coordY)
	return (static_cast<GPlayer*>(*it));
      ++it;
    }
  return (NULL);
}

// Debut -- Getters & Setters

eMove	Player::getDir() const
{
  return (this->_dir);
}

void	Player::setDir(eMove dir)
{
  this->_dir = dir;
}
int	Player::getSpeed() const
{
  return (this->_speed);
}

eState	Player::getState() const
{
  return (this->_state);
}

void	Player::setState(eState state)
{
  this->_state = state;
}

int	Player::getScore() const
{
  return (this->_score);
}

int	Player::getNbBombe() const
{
  return (this->_nbBombs);
}

int	Player::getId() const
{
  return (this->_id);
}

void	Player::setHp(int hp)
{
  this->_hp = hp;
}

int	Player::getHp() const
{
  return (this->_hp);
}

void    Player::setSpeed(int i)
{
    this->_speed = i;
}

void    Player::setScore(int i)
{
    this->_score = i;
}

void    Player::setNbBomb(int i)
{
    this->_nbBombs = i;
}

// Fin -- Getters & Setters

// Debut -- Fonctions Core

int     Player::moveUp(Map &map, GPlayer *graphPlayer)
{
  if (map.getCase(this->_x, this->_y - 1) == '0')
    {
      if (!(bombIsInRange(map, this->_x, this->_y, DOWN))
	  && graphPlayer->getActionToDo() != GraphPlayer::None)
	{
	  --(this->_y);
	  this->actionToDo = GraphPlayer::Down;
	  graphPlayer->changeActionToDo(this->actionToDo);
	  return (1);
	}
    }
  return (0);
}

int     Player::moveDown(Map &map, GPlayer *graphPlayer)
{
  if (map.getCase(this->_x, this->_y + 1) == '0')
    {
      if (!(bombIsInRange(map, this->_x, this->_y, UP)))
	{
	  ++(this->_y);
	  this->actionToDo = GraphPlayer::Up;
	  graphPlayer->changeActionToDo(this->actionToDo);
	  return (1);
	}
    }
  return (0);
}

int     Player::moveLeft(Map &map, GPlayer *graphPlayer)
{
  if (map.getCase(this->_x - 1, this->_y) == '0')
    {
      if (!(bombIsInRange(map, this->_x, this->_y, LEFT)))
	{
	  --(this->_x);
	  this->actionToDo = GraphPlayer::Left;
	  graphPlayer->changeActionToDo(this->actionToDo);
	  return (1);
	}
    }
  return (0);
}

int     Player::moveRight(Map &map, GPlayer *graphPlayer)
{
  if (map.getCase(this->_x + 1, this->_y) == '0')
    {
      if (!(bombIsInRange(map, this->_x, this->_y, RIGHT)))
	{
	  ++(this->_x);
	  this->actionToDo = GraphPlayer::Right;
	  graphPlayer->changeActionToDo(this->actionToDo);
	  return (1);
	}
    }
  return (0);
}

bool	Player::move(eMove dir, Map &map, GPlayer *gPlayer)
{
  if (dir <= 0)
    return (false);
  this->_state = MOVING;

  int   (Player::*tab[4])(Map &, GPlayer*);

  tab[0] = &Player::moveRight;
  tab[1] = &Player::moveLeft;
  tab[2] = &Player::moveDown;
  tab[3] = &Player::moveUp;
  this->_state = MOVING;
  if ((this->*tab[dir - 1])(map, gPlayer) == 0)
    return(false);
  return (true);
}


void	Player::setBomb(Map &map, std::list<GModel*> &listOfModels)
{
  std::list<Bombe *>::iterator	it = this->_bombs.begin();

  if (gPlayer == NULL)
    this->gPlayer = this->retGPlayer(this->_x, this->_y, listOfModels); 
  while (it != this->_bombs.end() && !((*it)->isAvailable()))
    ++it;
  if (it != this->_bombs.end())
    {
      this->_state = BOMBING;
      (*it)->setX(this->_x);
      (*it)->setY(this->_y);
      (*it)->setDisponibility(false);
      this->gPlayer->putBomb(map, this->_x, this->_y, listOfModels);
      map.addBomb(*(*it));
    }
}

void	Player::takeDamage(Player &dealer)
{
  if (this->_hp == 1)
    {
      this->_hp = 0;
      this->_state = DEAD;
      dealer.updateScore(10);
    }
  else
    --(this->_hp);
}

void	Player::updateScore(int nb)
{
  this->_score += nb;
}

void	Player::addBomb()
{
  Bombe	*newBomb;

  newBomb = new Bombe(0, 0, this->_id);
  this->_bombs.push_back(newBomb);
}

void	Player::addBomb(Bombe *bombe)
{
  this->_bombs.push_back(bombe);
}

void	Player::addRange()
{
  std::list<Bombe *>::iterator	it = this->_bombs.begin();

  while (it != this->_bombs.end())
    {
      (*it)->setRange((*it)->getRange() + 1);
      ++it;
    }
}

void	Player::addSpeed()
{
  this->_speed += 1;
}

// Fin -- Fonctions core
