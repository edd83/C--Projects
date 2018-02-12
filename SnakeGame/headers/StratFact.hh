//
// StratFact.hh for StratFact in /home/volpe_p/rendu/Nibbler/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:12:23 2014 volpe
// Last update Tue Apr  1 16:18:05 2014 volpe
//

#ifndef		__STRATFACT_H__
#define		__STRATFACT_H__

#include	<cstdio>
#include	<cstdlib>
#include	"Strategie.hh"

class		StratFact
{
private:
  IStrategie	*newEasy() const;
  IStrategie	*newMedium() const;
  IStrategie	*newHard() const;
  IStrategie	*(StratFact::*creation[3])() const;
public:
  StratFact();
  ~StratFact();
  void		initTab();
  IStrategie	*create(IStrategieType ) const;
};

#endif
