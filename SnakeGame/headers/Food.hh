//
// Food.hh for Food in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:10:31 2014 volpe
// Last update Tue Apr  1 16:20:03 2014 volpe
//

#ifndef		__FOOD_HH__
#define		__FOOD_HH__

#include	<cstdio>
#include	<cstdlib>
#include	<ctime>
#include	"IFood.hh"

class		Food : public IFood
{
private:
  IFoodType				_type;
  int					_x;
  int					_y;
public: 
  Food();
  virtual ~Food();
  virtual void				addElem(std::list<IFood *> &, const std::list<ISnake *> &);
  virtual IFoodType			getType() const;
  virtual int				getX() const;
  virtual int				getY() const;
  virtual void				setType(IFoodType);
  virtual void				setX(int);
  virtual void				setY(int);
};

#endif
