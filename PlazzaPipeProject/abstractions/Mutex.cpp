//
// Mutex.cpp for Mutex in /home/volpe_p/rendu/Plazza/TP/ex2
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr 15 00:20:08 2014 volpe
// Last Update Sun Apr 27 11:07:18 2014 Bonnet Vivien
//

#include "Mutex.hh"

Mutex::Mutex()
{
  pthread_mutex_t mutex;

  this->_mutex = mutex;
  if (pthread_mutex_init(&this->_mutex, NULL) != 0)
    throw ProcessException("Error initializing mutex");
}

Mutex::~Mutex()
{
  if (pthread_mutex_destroy(&this->_mutex) != 0)
    throw ProcessException("Error destroying mutex");
}

pthread_mutex_t	&Mutex::getMutex()
{
  return (this->_mutex);
}

#include <errno.h>   // DEBUG
#include <string.h>
void	Mutex::lock()
{
  if (pthread_mutex_lock(&this->_mutex) != 0)
    throw ProcessException((std::string)("Error when locking mutex"));
}

void	Mutex::unlock()
{
  if (pthread_mutex_unlock(&this->_mutex) != 0)
    throw ProcessException("Error when locking mutex");
}

bool	Mutex::trylock()
{
  if (pthread_mutex_trylock(&this->_mutex) == 0)
    return (true);
  return (false);
}
