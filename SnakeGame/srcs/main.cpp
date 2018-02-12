//
// main.cpp for main in /home/volpe_p/rendu/Nibbler/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:14:23 2014 volpe
// Last update Sun Apr  6 18:07:26 2014 volpe
//

#include	"../ncurses/headers/Display.hh"

int	main(int ac, char **av)

{ 
  Game			*game = new Game();

  if (ac == 4)
    {
      try {
	game->start(av[3]);
      }
      catch (const std::exception &e) {
	std::cerr << e.what() << std::endl;
      }
    }
  else
    std::cout << "Usage : ./nibbler [LEN] [WIDTH] [LIB]" << std::endl;
  return (0);
}
