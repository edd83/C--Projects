//
// ISnake.hh for ISnake in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:11:37 2014 volpe
// Last update Tue Apr  1 16:21:27 2014 volpe
//

#ifndef		__ISNAKE_HH__
#define		__ISNAKE_HH__

#include	<list>
#include	<iostream>
#include	<string>

enum		ISnakeType
  {
    HEAD,
    BODY,
    TAIL
  };

class		ISnake
{
public:
  virtual void						addElem(std::list<ISnake *> &, ISnakeType, int, int) const = 0;
  virtual int						snakeSize(std::list<ISnake *>) const = 0;
  /****************/
  virtual ISnakeType					getType() const = 0;
  virtual int						getX() const = 0;
  virtual int						getY() const = 0;
  /***************/
  virtual void						setType(ISnakeType) = 0;
  virtual void						setX(int) = 0;
  virtual void						setY(int) = 0;
  virtual ~ISnake(){}
};

#endif
