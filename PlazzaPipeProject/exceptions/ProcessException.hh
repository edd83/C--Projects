//
// ProcessException.hh for ProcessException in /home/volpe_p/rendu/Plazza/TP
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Fri Apr 25 18:11:50 2014 volpe
// Last Update Sat Apr 26 10:37:03 2014 Bonnet Vivien
//

#ifndef	PROCESSEXCEPTION_HH_
# define PROCESSEXCEPTION_HH_

# include <string>

# include "PlazzaException.hh"

class	ProcessException : public PlazzaException
{
public:
  ProcessException(const std::string& message);
  ~ProcessException() throw();
};

#endif
