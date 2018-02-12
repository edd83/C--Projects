//
// Schmidt.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Mon Apr 14 15:43:39 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:22:03 2014 Bonnet Vivien
//

#ifndef SCHMIDT_HH_
# define SCHMIDT_HH_

# include "Kitchen.hh"
# include "Mutex.hh"

class	Schmidt
{
private:
  float	m_cookingTime;
  int	m_cooksByKitchen;
  int	m_stockReplaceTime;
  int	m_id;

public:
  Schmidt();
  ~Schmidt();

public:
  void		setParameters(float cookingTime, int cooksByKitchen, int stockReplaceTime);
  Kitchen*	createKitchen(Mutex* mutex);
};

#endif // !SCHMIDT_HH_
