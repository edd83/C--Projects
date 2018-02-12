//
// StratFact.cpp for Stratfact in /home/volpe_p/rendu/Nibbler/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:13:52 2014 volpe
// Last update Tue Apr  1 16:13:59 2014 volpe
//

#include	"../headers/StratFact.hh"

StratFact::StratFact()
{  
  initTab();
}

StratFact::~StratFact()
{

}

void	StratFact::initTab()
{
  this->creation[0] = &StratFact::newEasy;
  this->creation[1] = &StratFact::newMedium;
  this->creation[2] = &StratFact::newHard;
}

IStrategie	*StratFact::newEasy() const
{
  return (new Strategie::Easy());
}

IStrategie	*StratFact::newMedium() const
{
  return (new  Strategie::Medium);
}

IStrategie	*StratFact::newHard() const
{
  return (new  Strategie::Hard);
}

IStrategie	*StratFact::create(IStrategieType type) const
{
  if (type >= 0 && type <= 2)
    return ((this->*creation[type])());
  return NULL;
}
