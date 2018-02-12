//
// Strategie.cpp for Strategie in /home/volpe_p/rendu/Nibbler/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:14:14 2014 volpe
// Last update Tue Apr  1 16:17:26 2014 volpe
//

#include	"../headers/Strategie.hh"

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

unsigned int	Strategie::Easy::getNbFood() const
{
  return (this->_nbFood);
}

// Fin -- Getters & Setters

Strategie::Medium::Medium()
{
  this->_type = MEDIUM;
  this->_speed = 55000;
  this->_nbFood = 2;
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

unsigned int	Strategie::Medium::getNbFood() const
{
  return (this->_nbFood);
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
  this->_nbFood = 1;
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

unsigned int	Strategie::Hard::getNbFood() const
{
  return (this->_nbFood);
}

int	Strategie::Hard::getPts() const
{
  return (_pts);
}
