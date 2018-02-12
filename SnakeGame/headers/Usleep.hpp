//
// Usleep.hpp for Usleep in /home/volpe_p/rendu/Nibbler/srcs
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Apr  6 15:21:16 2014 volpe
// Last update Sun Apr  6 15:28:06 2014 volpe
//

#ifndef USLEEP_HPP_
# define USLEEP_HPP_

#include <unistd.h>

class Usleep
{
public:
  static int	my_usleep(useconds_t usec)
  {
    return (usleep(usec));
  }
};

#endif
