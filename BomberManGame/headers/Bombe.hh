//
// Bombe.hh for Bombe in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 13:34:39 2014 volpe
// Last update Sun Jun 15 18:50:57 2014 Fabien Casoni
//

#ifndef			BOMBE_HH_
#define			BOMBE_HH_

#include		"GModel.hh"
#include		"Includes.hh"

class			Map;

class			Player;

class			Bombe : public Entity
{
private:
  unsigned int		_range;
  unsigned int		_player_id;
  unsigned int		_timer;
  bool			_available;
  Bombe();

public:
  Bombe(int, int, unsigned int);
  ~Bombe();

  bool			isAvailable() const;
  void			setDisponibility(bool);
  void			setPlayerId(unsigned int);
  void			setRange(unsigned int);
  void			setTimer(unsigned int);
  unsigned int		getPlayerId() const;
  unsigned int		getRange() const;
  unsigned int		getTimer() const;
  //  void			explose(Map &, std::list<GModel *> &);
  void			decrementTimer();
  void			removeFromModelList(std::list<GModel *>&, unsigned int, unsigned int,
					    EntityNS::Nature);
};

unsigned int		bombIsInRange(Map &, unsigned int, unsigned int, int);
bool			brickIsInRange(Map &, unsigned int, unsigned int, int);
int			playerIsInRange(Map &, unsigned int, unsigned int, int);
bool			wallIsInRange(Map &, unsigned int, unsigned int, int);


#endif
