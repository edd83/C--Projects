//
// PlazzaException.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:38:55 2014 Bonnet Vivien
// Last Update Mon Apr 14 14:35:27 2014 Bonnet Vivien
//

#ifndef PLAZZA_EXCEPTION_HH_
# define PLAZZA_EXCEPTION_HH_

# include <exception>
# include <string>

class	PlazzaException : public std::exception
{
private:
  const std::string	m_message;

public:
  PlazzaException(const std::string& message);
  virtual ~PlazzaException() throw();

public:
  virtual const char*	what() const throw();
};

#endif // !PLAZZA_EXCEPTION_HH_
