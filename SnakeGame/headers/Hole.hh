//
// Hole.hh for Hole in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:11:13 2014 volpe
// Last update Tue Apr  1 16:19:33 2014 volpe
//

#ifndef		__HOLE_HH__
#define		__HOLE_HH__

#include	"IHole.hh"

class	Hole : public IHole
{
private:
  int		_x;
  int		_y;
  HoleType	_type;
public:
  Hole();
  virtual ~Hole();
  //
  virtual int		getX() const;
  virtual int		getY() const;
  //
  virtual void		setX(int);
  virtual void		setY(int);
  //
  virtual void		addElem(std::list<IHole *> &, int, int, HoleType);
  virtual HoleType	getType() const;
  virtual void		setType(HoleType);
};

#endif
