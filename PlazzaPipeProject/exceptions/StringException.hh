//
// StringException.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:38:55 2014 Bonnet Vivien
// Last Update Sun Apr 27 13:40:39 2014 Bonnet Vivien
//

#ifndef STRING_EXCEPTION_HH_
# define STRING_EXCEPTION_HH_

# include <string>

# include "PlazzaException.hh"

class	StringException : public PlazzaException
{
public:
  StringException(const std::string& message);
  ~StringException() throw();
};

#endif // !STRING_EXCEPTION_HH_
