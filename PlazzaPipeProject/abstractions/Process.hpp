//
// Process.hpp for Process in /home/volpe_p/rendu/Plazza/TP
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Wed Apr 23 08:55:11 2014 volpe
// Last Update Sat Apr 26 15:50:31 2014 Bonnet Vivien
//

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

#include	<unistd.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"ProcessException.hh"

template<typename T = void *, typename U = void *>
class Process {
public:
  static void	interrupt(int endNb)
    {
      exit(endNb);
    }

private:
  T			(*_task)(U);
  U			_args;
  pid_t			_pid;
public:
  Process(T (*task)(U), U args)
  {
    this->_task = task;
    this->_args = args;
    this->_pid = 0;
  }
  ~Process(){};
  void	start()
  {
    if ((this->_pid = fork()) != -1)
      {
	if (this->_pid == 0)
	  this->_task(this->_args);
      }
    else
      throw ProcessException("Error on fork");
  }

  void	end(int endNb)
  {
    exit(endNb);
  }

  pid_t		getPid()
  {
    return (this->_pid);
  }
};
#endif
