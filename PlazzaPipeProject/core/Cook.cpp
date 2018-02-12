//
// Cook.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:16:34 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:20:30 2014 Bonnet Vivien
//

#include <exception>
#include <iostream>

#include "Cook.hh"
#include "Kitchen.hh"
#include "Time.hh"

void
Cook::letsWork(Cook* cook)
{
  try
    {
      cook->work();
    }
  catch (const std::exception& exception)
    {
      std::cerr << "Fatal error : " << exception.what() << std::endl;
    }
}


Cook::Cook()
{
  m_status = Cook::Sleeping;
}

Cook::~Cook()
{
}

Cook::Status
Cook::getStatus() const
{
  return (m_status);
}

void
Cook::changeStatus(Cook::Status newStatus)
{
  m_status = newStatus;
  if (m_kitchen->isSelected())
    m_kitchen->update();
}


void
Cook::cook(const Pizza& pizza)
{
  const std::list<Recipes::EIngredient>&		ingredientList =
    m_recipes.getIngredients(pizza.getType());
  std::list<Recipes::EIngredient>::const_iterator	it;

  this->changeStatus(Cook::Waiting);
  for (it = ingredientList.begin(); it != ingredientList.end(); ++it)
    m_kitchen->accessToReserve().takeIngredient(*it);

  this->changeStatus(Cook::Cooking);
  Time::sleepUsecs(m_recipes.getCookingTime(pizza.getType()) * m_cookingTime);
}

bool
Cook::workABit()
{
  Pizza		pizza;
  Pizza::Pack	pack;
  bool		work;

  work = m_kitchen->getNextWaitingPizza(pizza);
  if (work)
    {
      this->cook(pizza);
      pack = pizza.pack();
      *m_kitchen << pack;
    }
  return (work);
}


void
Cook::goToSleep()
{
  this->changeStatus(Cook::Sleeping);
  m_working = false;
  m_mutex.lock();
}

void
Cook::wakeUp()
{
  m_working = true;
  m_mutex.unlock();
}


bool
Cook::isWorking() const
{
  return (m_working == true);
}

bool
Cook::isSleeping() const
{
  return (m_working == false);
}


void
Cook::prepare(Kitchen* kitchen)
{
  CookThread*	thread;

  m_cookingTime = kitchen->getCookingTime();
  m_kitchen = kitchen;

  thread = new CookThread(&Cook::letsWork, this);
  thread->run();
  delete (thread);
}

void
Cook::work()
{
  while (42)
    {
      this->goToSleep();
      while (this->workABit());
    }
}
