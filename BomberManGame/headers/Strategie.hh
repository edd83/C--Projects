//
// Strategie.hh for Strategie in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 13:58:21 2014 volpe
// Last update Thu May 15 13:59:21 2014 volpe
//

#ifndef			STRATEGIE_HH_
# define		STRATEGIE_HH_

#include		"IStrategie.hh"

namespace		Strategie
{
  class			Easy : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    int			_pts;
    
  public:
    virtual IStrategieType		getType() const;
    virtual int				getSpeed() const;
    virtual void			setSpeed(int);
    virtual int				getPts() const;
    Easy();
    virtual ~Easy();
  };

  class			Medium : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    int			_pts;

  public:
    virtual IStrategieType		getType() const;
    virtual int				getSpeed() const;
    virtual void			setSpeed(int);
    virtual int				getPts() const;
    Medium();
    virtual ~Medium();
  };

  class			Hard : public IStrategie
  {
  private:
    IStrategieType	_type;
    int			_speed;
    int			_pts;

  public:
    virtual IStrategieType		getType() const;
    virtual int				getSpeed() const;
    virtual void			setSpeed(int);
    virtual int				getPts() const;
    Hard();
    virtual ~Hard();
  };
}

#endif
