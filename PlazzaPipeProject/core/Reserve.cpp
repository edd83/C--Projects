//
// Reserve.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sun Apr 27 17:20:41 2014 Bonnet Vivien
// Last Update Sun Apr 27 17:59:55 2014 Bonnet Vivien
//

#include "Reserve.hh"

Reserve::Reserve() :
  m_mutex(),
  m_condMutex(),
  m_condVar(m_condMutex)
{
  int	i;

  for (i = 0; i < Recipes::IngredientsNumber; ++i)
    m_ingredients[i] = INGREDIENTS_BASE_NUMBER;
}

Reserve::~Reserve()
{
}


bool
Reserve::tryToTakeIngredient(Recipes::EIngredient ingredient)
{
  bool	taken;

  m_mutex.lock();
  {
    taken = (m_ingredients[ingredient] > 0);
    if (taken)
      --m_ingredients[ingredient];
  }
  m_mutex.unlock();

  return (taken);
}


void
Reserve::takeIngredient(Recipes::EIngredient ingredient)
{
  bool	taken;

  taken = this->tryToTakeIngredient(ingredient);
  while (taken == false)
    {
      m_condMutex.trylock();
      m_condVar.wait();
      taken = this->tryToTakeIngredient(ingredient);
    }
}

void
Reserve::regenerate()
{
  int	i;

  m_mutex.lock();
  {
    for (i = 0; i < Recipes::IngredientsNumber; ++i)
      ++m_ingredients[i];
    m_condMutex.trylock();
    m_condMutex.unlock();
    m_condVar.broadcast();
  }
  m_mutex.unlock();
}
