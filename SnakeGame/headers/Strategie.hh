//
// Strategie.hh for Strategie in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:13:00 2014 volpe
// Last update Tue Apr  1 16:18:33 2014 volpe
//

#ifndef			__STRATEGIE_HH__
#define			__STRATEGIE_HH__

#include		"IStrategie.hh"

namespace		Strategie
{
  class			Easy : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    unsigned int	_nbFood;
    int			_pts;
    
  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int);
    virtual int		getPts() const;
    virtual unsigned int		getNbFood() const ;
    Easy();
    virtual ~Easy();
  };

  class			Medium : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    unsigned int	_nbFood;
    int			_pts;

  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int);
    virtual int		getPts() const;
    virtual unsigned int		getNbFood() const ;
    Medium();
    virtual ~Medium();
  };

  class			Hard : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    unsigned int	_nbFood;
    int			_pts;

  public:
    virtual IStrategieType		getType() const;
    virtual int		getSpeed() const;
    virtual void	setSpeed(int);
    virtual int		getPts() const;
    virtual unsigned int		getNbFood() const;
    Hard();
    virtual ~Hard();
  };
}

#endif
