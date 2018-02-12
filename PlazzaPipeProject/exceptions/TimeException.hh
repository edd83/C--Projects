//
// TimeException.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:38:55 2014 Bonnet Vivien
// Last Update Sun Apr 27 13:41:01 2014 Bonnet Vivien
//

#ifndef TIME_EXCEPTION_HH_
# define TIME_EXCEPTION_HH_

# include <string>

# include "PlazzaException.hh"

class	TimeException : public PlazzaException
{
public:
  TimeException(const std::string& message);
  ~TimeException() throw();
};

#endif // !TIME_EXCEPTION_HH_
