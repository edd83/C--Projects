//
// Recipes.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sat Apr 26 11:01:23 2014 Bonnet Vivien
// Last Update Sat Apr 26 11:22:02 2014 Bonnet Vivien
//

#include "Recipes.hh"

Recipes::Recipes()
{
  this->addCommonIngredients(m_ingredients[Pizza::Margarita]);
  this->addCommonIngredients(m_ingredients[Pizza::Regina]);
  this->addCommonIngredients(m_ingredients[Pizza::Americaine]);
  this->addCommonIngredients(m_ingredients[Pizza::Fantasia]);

  m_ingredients[Pizza::Margarita].push_front(Recipes::Gruyere);

  m_ingredients[Pizza::Regina].push_front(Recipes::Gruyere);
  m_ingredients[Pizza::Regina].push_front(Recipes::Ham);
  m_ingredients[Pizza::Regina].push_front(Recipes::Mushrooms);

  m_ingredients[Pizza::Americaine].push_front(Recipes::Gruyere);
  m_ingredients[Pizza::Americaine].push_front(Recipes::Steak);

  m_ingredients[Pizza::Fantasia].push_front(Recipes::Eggplant);
  m_ingredients[Pizza::Fantasia].push_front(Recipes::GoatCheese);
  m_ingredients[Pizza::Fantasia].push_front(Recipes::ChiefLove);

  m_cookingTimes[Pizza::Margarita]	= 1.0f;
  m_cookingTimes[Pizza::Regina]		= 2.0f;
  m_cookingTimes[Pizza::Americaine]	= 2.0f;
  m_cookingTimes[Pizza::Fantasia]	= 4.0f;
}

Recipes::~Recipes()
{
}


void
Recipes::addCommonIngredients(std::list<Recipes::EIngredient>& ingredients)
{
  ingredients.push_front(Recipes::Doe);
  ingredients.push_front(Recipes::Tomato);
}


const std::list<Recipes::EIngredient>&
Recipes::getIngredients(Pizza::TypePizza type)
{
  return (m_ingredients[type]);
}

float
Recipes::getCookingTime(Pizza::TypePizza type)
{
  return (m_cookingTimes[type]);
}
