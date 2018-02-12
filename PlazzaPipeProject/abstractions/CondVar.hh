//
// CondVar.hh for CondVar in /home/volpe_p/rendu/Plazza/TP/ex2
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu Apr 17 11:38:22 2014 volpe
// Last Update Sun Apr 27 10:06:43 2014 Bonnet Vivien
//

#ifndef CONDVAR_HH_
# define CONDVAR_HH_

#include	"Mutex.hh"

class CondVar
{
private:
  pthread_cond_t	_cond;
  Mutex			&_mutex;

public:

  CondVar(Mutex &);
  ~CondVar();
  CondVar(const CondVar &);

  CondVar &operator=(const CondVar &);
  void	wait();
  void	timedwait(const struct timespec *);
  void	signal();
  void	broadcast();
};

#endif
