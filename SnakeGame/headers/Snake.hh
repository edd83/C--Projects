//
// Snake.hh for Snake in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:12:08 2014 volpe
// Last update Tue Apr  1 16:21:48 2014 volpe
//

#ifndef		__SNAKE_HH__
#define		__SNAKE_HH__

#include	"ISnake.hh"

class		Snake : public ISnake
{
private:
  ISnakeType		_type;
  int			_x;
  int			_y;
public: 
  Snake();
  virtual ~Snake();
  virtual void				addElem(std::list<ISnake *> &, ISnakeType, int, int)const;
  virtual int				snakeSize(std::list<ISnake *>) const;
  /******************/
  virtual ISnakeType			getType() const;
  virtual int				getX() const;
  virtual int				getY() const;
  /******************/
  virtual void				setX(int);
  virtual void			        setY(int);
  virtual void				setType(ISnakeType);
};

#endif
