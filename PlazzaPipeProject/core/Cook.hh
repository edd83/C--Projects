//
// Cook.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:16:58 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:18:31 2014 Bonnet Vivien
//

#ifndef COOK_HH_
# define COOK_HH_

# include "Mutex.hh"
# include "Recipes.hh"
# include "Thread.hpp"

class		Kitchen;

class		Cook
{
private:
  typedef Thread<Cook*, void>	CookThread;

public:
  enum	Status
  {
    Sleeping,
    Waiting,
    Cooking
  };

private:
  static void	letsWork(Cook* cook);

private:
  Mutex		m_mutex;
  Recipes	m_recipes;
  Kitchen*	m_kitchen;
  Status	m_status;
  float		m_cookingTime;
  bool		m_working;

public:
  Cook();
  ~Cook();

private:
  void	changeStatus(Status newStatus);

private:
  void	cook(const Pizza& pizza);
  bool	workABit();

public:
  void	goToSleep();
  void	wakeUp();

public:
  bool		isWorking() const;
  bool		isSleeping() const;
  Status	getStatus() const;

public:
  void	prepare(Kitchen* kitchen);
  void	work();
};

#endif // !COOK_HH_
