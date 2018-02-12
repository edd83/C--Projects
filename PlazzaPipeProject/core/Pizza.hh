//
// Pizza.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 09:12:08 2014 Bonnet Vivien
// Last Update Sat Apr 26 17:38:03 2014 Bonnet Vivien
//

#ifndef PIZZA_HH_
# define PIZZA_HH_

# include <string>

class		Pizza
{
public:
  enum		TypePizza
  {
    Regina = 1,
    Margarita = 2,
    Americaine = 4,
    Fantasia = 8
  };

  enum		TaillePizza
  {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  };

public:
  struct	Pack
  {
    TypePizza	type;
    TaillePizza	size;
  };

private:
  TypePizza	m_type;
  TaillePizza	m_size;

public:
  Pizza();
  Pizza(TypePizza type, TaillePizza size);
  Pizza(const Pack& pack);
  ~Pizza();

public:
  TypePizza		getType() const;
  TaillePizza		getSize() const;
  const std::string	getName() const;
  const std::string	getSizeName() const;

public:
  const Pack	pack() const;
  void		unpack(const Pack& pack);
};

#endif // !PIZZA_HH_
