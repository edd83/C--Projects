//
// Recipes.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sat Apr 26 10:54:15 2014 Bonnet Vivien
// Last Update Sun Apr 27 17:08:55 2014 Bonnet Vivien
//

#ifndef RECIPES_HH_
# define RECIPES_HH_

# include <list>
# include <map>

# include "Pizza.hh"

class	Recipes
{
public:
  enum	EIngredient
  {
    Doe,
    Tomato,
    Gruyere,
    Ham,
    Mushrooms,
    Steak,
    Eggplant,
    GoatCheese,
    ChiefLove,
    IngredientsNumber
  };

private:
  std::map<Pizza::TypePizza, std::list<EIngredient> >	m_ingredients;
  std::map<Pizza::TypePizza, float>			m_cookingTimes;

public:
  Recipes();
  ~Recipes();

private:
  void	addCommonIngredients(std::list<EIngredient>& ingredients);

public:
  const	std::list<EIngredient>&	getIngredients(Pizza::TypePizza type);
  float				getCookingTime(Pizza::TypePizza type);
};

#endif // !RECIPES_HH_
