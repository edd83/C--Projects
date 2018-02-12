//
// Game.hh for Game in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:11:08 2014 volpe
// Last update Sun Apr  6 15:01:52 2014 volpe
//

#ifndef		__GAME_HH__
#define		__GAME_HH__

#include	<iostream>
#include	<list>
#include	<dlfcn.h>
#include	<sys/types.h>
#include	<cstring>
#include	"Hole.hh"
#include	"Snake.hh"
#include	"Food.hh"
#include	"Collision.hh"
#include	"Strategie.hh"
#include	"StratFact.hh"
#include	"GameException.hh"

const int	SIDE     = 20;
const int	LWINDOW  = 800;
const int	HWINDOW  = 600;
const int	PIX	 = 32;

class		Game
{
private:
  std::list<ISnake *>		_sList;
  std::list<IFood *>		_fList;
  std::list<IHole *>		_assList;
  ISnake			*_snake;
  IFood				*_food;
  IHole				*_hole;
  StratFact			*_stratFact;
  IStrategie			*_strategie;
  Collision			*_collision;
  int				_score;
public:
  Game();
  ~Game();

  void				start(char	*);
  void				Init();
  ISnake			*getSnakeI() const;
  IFood				*getFoodI() const;
  int				getSpeed() const;
  void				setScore();
  int				getScore() const;
  std::list<ISnake *>		getSList() const;
  std::list<IFood *>		getFList() const;
  std::list<IHole *>		getHole() const;
  Collision			*getCollision() const;
  int				checkCollision(std::list<ISnake *> &, std::list<IFood *> &, std::list<IHole *> &) const;
  void				updateSList(std::list<ISnake *> &) const;
  void				setSList(const std::list<ISnake *> &);
  void				setFList(std::list<IFood *> &);
  void				updateFList(std::list<IFood *> &);
  void				displayCoord() const;
  void				analyseLevel();
};

#endif
