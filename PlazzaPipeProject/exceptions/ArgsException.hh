//
// ArgsException.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:38:55 2014 Bonnet Vivien
// Last Update Sun Apr 27 09:04:07 2014 Bonnet Vivien
//

#ifndef ARGS_EXCEPTION_HH_
# define ARGS_EXCEPTION_HH_

# include <string>

# include "PlazzaException.hh"

# define ARGS_NUMBER		(4)
# define ARGS_BONUS_NUMBER	(5)
# define USAGE_MESSAGE		("<cooking time> <cook number by kitchen> <kitchen stock replace time> [<port>]")

class		ArgsException : public PlazzaException
{
public:
  static void	throwUsage(const char* arg0);

public:
  ArgsException(const std::string& message);
  ~ArgsException() throw();
};

#endif // !ARGS_EXCEPTION_HH_
