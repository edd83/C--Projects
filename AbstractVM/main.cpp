//
// main.cpp for main in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Feb 24 22:11:11 2014 lardet
// Last update Sun Mar  2 20:01:11 2014 lardet
//

#include "Machine.hpp"
#include "Chipset.hpp"

int	main(int ac, char **av)
{
  Machine machine;
  std::string	help_flag = "-help";

  if (ac > 2)
    {
      std::cout << "Usage : ./Abstract_VM (-i | FILE)" << std::endl;
      return 1;
    }
  else if (ac == 2)
    {
      if (av[1][0] == '-' && av[1][1] == 'i')
	{
	  if (machine.start_interactiv())
	    machine.execute_interactiv();
	  return 1;
	}
      else if (help_flag == av[1])
	{
	  std::cout << "Usage : ./Abstract_VM (-i | FILE)" << std::endl;
	  return 1;
	}
      else
	machine.setInput(av[1]);
  }
  if (machine.start())
    machine.execute();
}
