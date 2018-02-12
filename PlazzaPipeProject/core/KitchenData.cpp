//
// Kitchen.cpp for pizza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 09:44:19 2014 Bonnet Vivien
// Last Update Sun Apr 27 17:57:09 2014 Bonnet Vivien
//

#include <algorithm>
#include <functional>

#include "KitchenData.hh"
#include "Kitchen.hh"
#include "Time.hh"

void
KitchenData::launchRegenerationLoop(KitchenData* kitchen)
{
  kitchen->regenerationLoop();
}


KitchenData::KitchenData(const std::string& name,
			 float cookingTime, int cooksByKitchen, int stockReplaceTime) :
  m_pass(name)
{
  m_pizzaNumber = 0;

  m_cooksNumber = cooksByKitchen;
  m_cookingTime = cookingTime;
  m_stockReplaceTime = stockReplaceTime;
}

KitchenData::~KitchenData()
{
}


void
KitchenData::findACookToAwake()
{
  std::vector<Cook*>::iterator	it;

  it = std::find_if(m_cooks.begin(), m_cooks.end(),
		    std::mem_fun(&Cook::isSleeping));
  if (it != m_cooks.end())
    (*it)->wakeUp();
}

void
KitchenData::initCooks()
{
  int	i;

  m_cooks.resize(m_cooksNumber);
  for (i = 0; i < m_cooksNumber; ++i)
    {
      m_cooks[i] = new Cook();
      m_cooks[i]->prepare(reinterpret_cast<Kitchen*>(this));
    }
}


bool
KitchenData::canHaveAnotherCommand() const
{
  return ((int)m_pizzaNumber < m_cooksNumber * 2);
}

bool
KitchenData::thereIsSomethingToDo() const
{
  return (m_waitingPizzas.empty() == false);
}

unsigned int
KitchenData::getPizzaNumber() const
{
  return (m_pizzaNumber);
}

float
KitchenData::getCookingTime() const
{
  return (m_cookingTime);
}

Reserve&
KitchenData::accessToReserve()
{
  return (m_reserve);
}


void
KitchenData::letsWait()
{
  m_pass.setSide(Fifo::In);
}

void
KitchenData::regenerationLoop()
{
  while (42)
    {
      Time::sleepMsecs(m_stockReplaceTime);
      m_reserve.regenerate();
    }
}


bool
KitchenData::getNextWaitingPizza(Pizza& pizza)
{
  bool	thereIsAPizzaHere;

  m_waitingPizzas.lock();
  {
    thereIsAPizzaHere = !m_waitingPizzas.empty();
    if (thereIsAPizzaHere)
      {
	pizza = m_waitingPizzas.front();
	m_waitingPizzas.pop();
      }
  }
  m_waitingPizzas.unlock();

  return (thereIsAPizzaHere);
}


void
KitchenData::operator>>(Pizza::Pack& pack)
{
  m_pass >> pack;
  --m_pizzaNumber;
}

void
KitchenData::operator<<(const Pizza::Pack& pack)
{
  m_pass << pack;
  ++m_pizzaNumber;
}
