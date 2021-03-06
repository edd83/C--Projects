//
// IStrategie.hh for IStrategie in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:11:49 2014 volpe
// Last update Mon Jun  9 18:08:45 2014 ovoyan_s
//

#ifndef					__ISTRATEGIE_HH__
#define					__ISTRATEGIE_HH__

enum					IStrategieType
  {
    EASY,
    MEDIUM,
    HARD
  };

class					IStrategie
{
public:
  virtual int				getSpeed() const = 0;
  virtual void				setSpeed(int) = 0;
  virtual int				getPts() const = 0;
  virtual IStrategieType		getType() const = 0;
  virtual ~IStrategie(){}
};

#endif
