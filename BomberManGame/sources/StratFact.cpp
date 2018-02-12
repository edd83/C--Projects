//
// StratFact.cpp for StratFact in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 10:53:26 2014 volpe
// Last update Sun Jun 15 17:47:35 2014 Fabien Casoni
//

#include	"StratFact.hh"

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
