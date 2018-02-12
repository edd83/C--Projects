//
// Strategie.cpp for Strategie in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 10:53:40 2014 volpe
// Last update Mon Jun  9 18:01:04 2014 ovoyan_s
//

#include		"Strategie.hh"

Strategie::Easy::Easy()
{
  this->_type = EASY;
  this->_speed = 70000;
  this->_nbFood = 3;
  this->_pts = 10;
}

Strategie::Easy::~Easy()
{

}

// Debut -- Getters & Setters

IStrategieType		Strategie::Easy::getType() const
{
  return (_type);
}

int	Strategie::Easy::getSpeed() const
{
  return (_speed);
}

void	Strategie::Easy::setSpeed(int speed)
{
  this->_speed = speed;
}

int	Strategie::Easy::getPts() const
{
  return (_pts);
}

// Fin -- Getters & Setters

Strategie::Medium::Medium()
{
  this->_type = MEDIUM;
  this->_speed = 55000;
  this->_pts = 20;
}

Strategie::Medium::~Medium()
{

}

IStrategieType		Strategie::Medium::getType() const
{
  return (_type);
}

int	Strategie::Medium::getSpeed() const
{
  return (_speed);
}

void	Strategie::Medium::setSpeed(int speed)
{
  this->_speed = speed;
}

int	Strategie::Medium::getPts() const
{
  return (_pts);
}

/******************************/

Strategie::Hard::Hard()
{
  this->_type = HARD;
  this->_speed = 45000;
  this->_pts = 30;
}

Strategie::Hard::~Hard()
{

}

IStrategieType		Strategie::Hard::getType() const
{
  return (_type);
}

int	Strategie::Hard::getSpeed() const
{
  return (_speed);
}

void	Strategie::Hard::setSpeed(int speed)
{
  this->_speed = speed;
}

int	Strategie::Hard::getPts() const
{
  return (_pts);
}
