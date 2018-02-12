//
// IHole.hh for IHole in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:11:29 2014 volpe
// Last update Tue Apr  1 16:19:11 2014 volpe
//

#ifndef		__IHOLE_HH__
#define		__IHOLE_HH__

enum		HoleType
  {
    BLACKHOLE
  };

class		IHole
{
public:
  virtual ~IHole(){}
  virtual int	getX() const = 0;
  virtual int	getY() const = 0;
  virtual HoleType	getType() const = 0;
  //
  virtual void	setX(int) = 0;
  virtual void	setY(int) = 0;
  //
  virtual void	addElem(std::list<IHole *> &, int, int, HoleType) = 0;
  virtual void	setType(HoleType) = 0;
};

#endif
