//
// main_graphic_client.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May  7 13:41:45 2014 ovoyan_s
// Last update Sun Jun 15 20:49:40 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		<stdlib.h>
#include		"graphic_client.hh"

int			main(int ac, char **av)
{
  try
    {
      if (ac == 2)
	{
	  MyGame		lol(av[1]);

	  lol.initialize();
	  while (lol.update() == true)
	    lol.draw();
	  lol.StopGame();
	}
      else if (ac == 3)
	{
	  if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
	    return (-1);
	  MyGame		lol(atoi(av[1]), atoi(av[2]));

	  lol.initialize();
	  while (lol.update() == true)
	    lol.draw();
	  lol.StopGame();
	}
      else if (ac == 4)
	{
	  if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
	    return (-1);
	  MyGame		lol(atoi(av[1]), atoi(av[2]), av[3]);

	  lol.initialize();
	  while (lol.update() == true)
	    lol.draw();
	  lol.StopGame();
	}
      else
	{
	  std::cout << "Usage: ./client_graphique [largeur] [hauteur] <nom>" << std::endl;
	  return (-1);
	}
    }
  catch (MyException const &e)
    {
      std::cout << "Error : " << e.what() << std::endl;
      return (-1);
    }
  return (0);
}
