//
// Collision.hh for Colission in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:10:21 2014 volpe
// Last update Tue Apr  1 16:19:46 2014 volpe
//

#ifndef		__Collision_HH__
#define		__Collision_HH__

#include	"../headers/ISnake.hh"
#include	"../headers/IFood.hh"

class		Collision
{
public:
  Collision();
  ~Collision();
  bool		checkSAndS(const std::list<ISnake *> &) const;
  bool		checkSAndF(const std::list<ISnake *> &, std::list<IFood *> &) const;
  bool		checkSAndW(const std::list<ISnake *> &) const;
  int		checkSAndH(const std::list<ISnake *> &, std::list<IHole *> &);
  void		displayCoord(const std::list<ISnake *> &) const;
};

#endif
