//
// SecureQueue.hpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sun Apr 27 15:18:12 2014 Bonnet Vivien
// Last Update Sun Apr 27 15:28:39 2014 Bonnet Vivien
//

#ifndef SECURE_QUEUE_HPP_
# define SECURE_QUEUE_HPP_

# include <queue>

# include "Mutex.hh"

template <typename T>
class	SecureQueue : public std::queue<T>, public Mutex
{
public:
  SecureQueue() {}
  virtual ~SecureQueue() {}
};

#endif // !SECURE_QUEUE_HPP_
