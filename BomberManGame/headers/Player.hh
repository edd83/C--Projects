//
// Player.hh for Player.hh in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat May 17 16:26:06 2014 volpe
// Last update Sun Jun 15 17:52:13 2014 ovoyan_s
//

#ifndef			PLAYER_HH_
# define		PLAYER_HH_

# include			<iostream>
# include			<string>
# include			<list>
# include			"Entity.hh"
# include			"Includes.hh"
# include			"GPlayer.hh"

enum				eState
  {
    WAITING,
    MOVING,
    BOMBING,
    DEAD
  };

enum	eMove
  {
    NONE = 0,
    RIGHT = 1,
    LEFT = 2,
    DOWN = 3,
    UP = 4
  };

class				GPlayer;

class				Bombe;

class				Map;

class				Player : public Entity
{
protected:
  int				_id;
  int				_hp;
  int				_speed;
  int				_score;
  eMove				_dir;
  int				_nbBombs;
  eState			_state;
  std::list<Bombe *>		_bombs;
  GraphPlayer::ActionToDo	actionToDo;
  GPlayer			*gPlayer;

public:
  Player();
  Player(int, int, int);
  ~Player();

  // Getters & Setters

  eMove				getDir() const;
  int				getHp() const;
  int				getId() const;
  eState			getState() const;
  int				getScore() const;
  int				getNbBombe() const;
  int				getSpeed() const;
  void				setState(eState);
  void				setDir(eMove);
  void				setHp(int);
  void				setSpeed(int);
  void				setScore(int);
  void				setNbBomb(int);
  GPlayer			*retGPlayer(int coordX, int coordY, std::list<GModel*> &modelsList);

  // Functions Core

  int				moveRight(Map &map, GPlayer*);
  int				moveLeft(Map &map, GPlayer*);
  int				moveUp(Map &map, GPlayer*);
  int				moveDown(Map &map, GPlayer*);
  bool				move(eMove, Map &, GPlayer*);
  void				setBomb(Map &, std::list<GModel*>&);
  void				takeDamage(Player &);
  void				updateScore(int);
  void				addBomb();
  void				addBomb(Bombe *);
  void				addSpeed();
  void				addRange();
};

#endif				/*	PLAYER_HH_	*/
