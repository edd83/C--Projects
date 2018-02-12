//
// FifoException.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:38:55 2014 Bonnet Vivien
// Last Update Mon Apr 14 16:49:16 2014 Bonnet Vivien
//

#ifndef FIFO_EXCEPTION_HH_
# define FIFO_EXCEPTION_HH_

# include <string>

# include "PlazzaException.hh"

class	FifoException : public PlazzaException
{
public:
  FifoException(const std::string& message);
  ~FifoException() throw();
};

#endif // !FIFO_EXCEPTION_HH_
