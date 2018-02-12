//
// StratFact.hh for StratFact in /home/volpe_p/rendu/Bomberman/cpp_bomberman/ai_sources/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu May 15 10:50:54 2014 volpe
// Last update Mon Jun  9 18:19:08 2014 ovoyan_s
//

#ifndef			STRATFACT_HH_
# define		STRATFACT_HH_

#include		<cstdio>
#include		<cstdlib>
#include		"Strategie.hh"

class			StratFact
{
private:
  IStrategie		*newEasy() const;
  IStrategie		*newMedium() const;
  IStrategie		*newHard() const;
  IStrategie		*(StratFact::*creation[3])() const;
public:
  StratFact();
  ~StratFact();
  void			initTab();
  IStrategie		*create(IStrategieType ) const;
};

#endif
