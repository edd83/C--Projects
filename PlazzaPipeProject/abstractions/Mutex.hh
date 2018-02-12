//
// Mutex.hh for Mutex in /home/volpe_p/rendu/Plazza/TP/ex2
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr 15 00:16:50 2014 volpe
// Last Update Sun Apr 27 11:15:36 2014 Bonnet Vivien
//

#ifndef MUTEX_HH_
# define MUTEX_HH_

#include <pthread.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>

#include "ProcessException.hh"

class Mutex
{
  pthread_mutex_t	_mutex;
  pthread_mutexattr_t	_attr;

public:
  Mutex();
  ~Mutex();

  void	lock();
  void	unlock();
  bool	trylock();
  pthread_mutex_t	&getMutex();
};
#endif
