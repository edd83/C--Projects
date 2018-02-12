//
// Kitchen.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Fri Apr 25 12:01:58 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:21:12 2014 Bonnet Vivien
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include "KitchenData.hh"
# include "KitchenGraphic.hh"

class	Kitchen : public KitchenData, public KitchenGraphic
{
public:
  static void	letsWork(Kitchen* kitchen);

public:
  Kitchen(const std::string& name, Mutex* mutex,
	  float cookingTime, int cooksByKitchen, int stockReplaceTime);
  ~Kitchen();

public:
  void	update();

public:
  void	letsCook();
};

#endif // !KITCHEN_HH_
