//
// Thread.cpp for Thread in /home/volpe_p/rendu/Plazza/TP/ex2
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr 15 10:35:46 2014 volpe
// Last Update Sat Apr 26 17:19:36 2014 Bonnet Vivien
//

#ifndef THREAD_HH_
# define THREAD_HH_

#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <signal.h>

#include "ProcessException.hh"

enum eStatus {
  CREATED,
  RUNNING,
  WAITING,
  DEAD
};

template<typename T = void *, typename U = void *>
class Thread
{
private:
  eStatus	_status;
  pthread_t	_thread;
  U		(*_start_routine)(T);
  T		_args;

public:
  Thread(U (*start_routine)(T), T args)
  {
    this->_status = CREATED;
    this->_start_routine = start_routine;
    this->_args = args;
  }

  Thread(Thread const &other)
  {
    this->_status = other._status;
    this->_start_routine = other._start_routine;
    this->_args = other._args;
    this->_thread = other._thread;
  }

  Thread &operator=(Thread const &other)
  {
    if (this != &other)
      {
	this->_thread = pthread_t();
	this->_state = other._state();
	this->_start_routine = other._start_routine;
	this->_args = other._args;
      }
    return (*this);
  }

  ~Thread()
  {
    this->_status = DEAD;
  }
  
  eStatus	getStatus() const
  {
    return (this->_status);
  }

  void		setStatus(eStatus state)
  {
    this->_status = state;
  }

  void		_runRoutine()
  {
    this->_start_routine(this->_args);
  }

  void		killMe()
  {
    if (pthread_kill(this->_thread, SIGUSR1) != 0)
      throw ProcessException("Error killing thread");
  }

  U		waitEnd()
  {
    void	*r;
 
    if (pthread_join(this->_thread, &r) != 0)
      throw ProcessException("Error joining thread");
    this->_status = DEAD;
    return (static_cast<U>(r));
  }

  bool		run()
  {
    if (pthread_create(&this->_thread, NULL,
		       (void *(*)(void *))_start_routine, this->_args) == 0)
      {
	this->_status = RUNNING;
	return (true);
      }
    return (false);
  }

  static void	*my_start_routine(void *p)
  {
    return (reinterpret_cast<Thread<T, U> *>(p)->_runRoutine());
  }
  
};

#endif
