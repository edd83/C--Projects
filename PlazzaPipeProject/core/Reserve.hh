//
// Reserve.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sun Apr 27 17:12:48 2014 Bonnet Vivien
// Last Update Sun Apr 27 17:34:01 2014 Bonnet Vivien
//

#ifndef RESERVE_HH_
# define RESERVE_HH_

# include "CondVar.hh"
# include "Mutex.hh"
# include "Recipes.hh"

# define INGREDIENTS_BASE_NUMBER	(5)

class	Reserve
{
private:
  Mutex		m_mutex;
  Mutex		m_condMutex;
  CondVar	m_condVar;
  int		m_ingredients[Recipes::IngredientsNumber];

public:
  Reserve();
  ~Reserve();

private:
  bool	tryToTakeIngredient(Recipes::EIngredient ingredient);

public:
  void	takeIngredient(Recipes::EIngredient ingredient);
  void	regenerate();
};

#endif // !RESERVE_HH_
