//
// BombermanAI.hh for bombermanAI in /home/volpe_p/rendu/Bomberman
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 10:10:58 2014 volpe
// Last update Sun Jun 15 17:52:29 2014 ovoyan_s
//

#ifndef				BOMBERMANAI_HH_
# define			BOMBERMANAI_HH_

# include			"AStar.hh"
# include			"Entity.hh"
# include			"GPlayer.hh"
# include			"Map.hh"
# include			"MyException.hh"
# include			"Node.hh"
# include			"Player.hh"
# include			"Random.hh"

class				BombermanAI : public Player
{
private:
  Random			rand;

public:
  BombermanAI(int, int, int);
  ~BombermanAI();

  // Fonctions Core

  void				chooseAction(Map &, std::list<GModel*>&);
  void				executeAction();
  void				checkMap();
  void				start(Map &, std::list<GModel*> &);
  bool				isInDanger(std::list<Entity *> &, Map &); 
  bool				bombInRange(Entity *, unsigned int, unsigned int);
  int				checkY(Map &);
  int				checkLessY();
  int				checkLessX();
  unsigned int			*checkRangePlayer(Map &);
  int				enemyClose(std::list<Entity *> &, Map &);
  int				checkBonus(std::list<Entity *> &, Map &);
  int				checkBrick(Map &, std::list<GModel*>&);
  void				moveRand(Map &);
  bool				whereToMove(int, int, Map &);
  bool				runAway(Map &);
  int				firstLoop(unsigned int, unsigned int, int *, int *, int, Map &);
  int				secondLoop(unsigned int, unsigned int, int *, int *, int, Map &);
};

#endif
