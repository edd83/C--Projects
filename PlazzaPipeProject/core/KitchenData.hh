//
// Kitchen.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Mon Apr 14 16:25:36 2014 Bonnet Vivien
// Last Update Sun Apr 27 17:46:51 2014 Bonnet Vivien
//

#ifndef KITCHEN_DATA_HH_
# define KITCHEN_DATA_HH_

# include <queue>

# include "Cook.hh"
# include "Fifo.hpp"
# include "Pizza.hh"
# include "Reserve.hh"
# include "SecureQueue.hpp"
# include "Thread.hpp"

class			KitchenData
{
protected:
  typedef Thread<KitchenData*, void>	KitchenThread;

protected:
  static void	launchRegenerationLoop(KitchenData* kitchen);

protected:
  SecureQueue<Pizza>	m_waitingPizzas;
  std::vector<Cook*>	m_cooks;
  Reserve		m_reserve;
  Fifo			m_pass;
  unsigned int		m_pizzaNumber;
  int			m_cooksNumber;

private:
  float			m_cookingTime;
  int			m_stockReplaceTime;

public:
  KitchenData(const std::string& name, float cookingTime, int cooksByKitchen, int stockReplaceTime);
  virtual ~KitchenData();

protected:
  void	findACookToAwake();
  void	initCooks();

public:
  bool		canHaveAnotherCommand() const;
  bool		thereIsSomethingToDo() const;
  unsigned int	getPizzaNumber() const;
  float		getCookingTime() const;
  Reserve&	accessToReserve();

public:
  void	letsWait();
  void	regenerationLoop();

public:
  bool	getNextWaitingPizza(Pizza& pizza);

public:
  void	operator>>(Pizza::Pack& pack);
  void	operator<<(const Pizza::Pack& pack);
};

#endif // !KITCHEN_DATA_HH_
