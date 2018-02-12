//
// IFood.hh for IFood in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:11:22 2014 volpe
// Last update Tue Apr  1 16:21:05 2014 volpe
//

#ifndef		__IFOOD_HH__
#define		__IFOOD_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		IFoodType
  {
    CAKE,
    POISON,
    POWER
  };

class		IFood
{
public:
  virtual void				addElem(std::list<IFood *> &, const std::list<ISnake *> &) = 0;
  virtual IFoodType			getType() const = 0;
  virtual void				setType(IFoodType) = 0;
  virtual int				getX() const = 0;
  virtual int				getY() const = 0;
  virtual void				setX(int) = 0;
  virtual void				setY(int) = 0;
  virtual ~IFood(){}
};

#endif
