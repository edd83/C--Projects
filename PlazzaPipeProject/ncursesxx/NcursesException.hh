//
// NcursesException.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:48:39 2014 Bonnet Vivien
// Last Update Fri Apr 25 18:01:06 2014 Bonnet Vivien
//

#ifndef NCURSES_EXCEPTION_HH_
# define NCURSES_EXCEPTION_HH_

# include <exception>
# include <string>

namespace nc
{

class			NcursesException : std::exception
{
private:
  const std::string	m_message;

public:
  NcursesException(const std::string& message);
  virtual ~NcursesException() throw();

public:
  virtual const char*	what() const throw();
};

}

#endif // !NCURSES_EXCEPTION_HH_
