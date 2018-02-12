//
// ParserException.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:38:55 2014 Bonnet Vivien
// Last Update Sun Apr 27 13:40:43 2014 Bonnet Vivien
//

#ifndef PARSER_EXCEPTION_HH_
# define PARSER_EXCEPTION_HH_

# include <string>

# include "PlazzaException.hh"

class	ParserException : public PlazzaException
{
public:
  ParserException(const std::string& message);
  ~ParserException() throw();
};

#endif // !PARSER_EXCEPTION_HH_
