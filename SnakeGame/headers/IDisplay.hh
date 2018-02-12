//
// ILib.hh for ILib.hh in /home/volpe_p/rendu/Nibbler
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:09:27 2014 volpe
// Last update Tue Apr  1 17:07:01 2014 volpe
//

#ifndef		__IDISPLAY_HH__
#define		__IDISPLAY_HH___

#include	"Game.hh"

class		IDisplay
{
public:
  virtual bool	Window() const = 0;
  virtual void	Play(std::list<ISnake *> &, std::list<IFood *> &, std::list<IHole *> &, int) = 0;
  virtual bool	Init() = 0;
  virtual void	Finish() = 0;
  virtual ~IDisplay(){};
};

#endif
