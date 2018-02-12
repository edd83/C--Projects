//
// CondVar.cpp for CondVar in /home/volpe_p/rendu/Plazza/TP/ex2
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Thu Apr 17 11:41:06 2014 volpe
// Last update Fri Apr 25 18:35:38 2014 volpe
//

#include	"CondVar.hh"

CondVar::CondVar(Mutex &mutex) : _cond(), _mutex(mutex)
{
  if (pthread_cond_init(&(this->_cond), NULL) != 0)
    throw ProcessException("Error on CondVar init");
}

CondVar::~CondVar()
{
  if (pthread_cond_destroy(&(this->_cond)) != 0)
    throw ProcessException("Error destroying CondVar");
}

CondVar::CondVar(const CondVar &other) : _cond(other._cond), _mutex(other._mutex)
{
}

CondVar	&CondVar::operator=(const CondVar &other)
{
  if (this != &other)
    {
      this->_cond = other._cond;
    }
  return (*this);
}

void	CondVar::wait()
{
  if (pthread_cond_wait(&(this->_cond),&(this->_mutex.getMutex())) != 0)
    throw ProcessException("Error on CondVar wait");
}

void	CondVar::timedwait(const struct timespec *t)
{
  if (pthread_cond_timedwait(&(this->_cond), &(this->_mutex.getMutex()), t) != 0)
    throw ProcessException("Error on timedwait CondVar");
}

void	CondVar::signal(void)
{
  if (pthread_cond_signal(&(this->_cond)) != 0)
    throw ProcessException("Error on signal CondVar");
}

void	CondVar::broadcast(void)
{
  if (pthread_cond_broadcast(&(this->_cond)) != 0)
    throw ProcessException("Error on broadcast CondVar");
}
