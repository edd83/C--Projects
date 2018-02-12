//
// MyException.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/merge-client/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Jun  9 18:13:19 2014 ovoyan_s
// Last update Mon Jun  9 18:15:00 2014 ovoyan_s
//

#ifndef			MYEXCEPTION_HH_
# define		MYEXCEPTION_HH_

# include <iostream>
# include <exception>

class			MyException : public std::exception
{

 private:

  std::string const	Error;

 public:

  MyException(std::string const& error) throw();
  ~MyException() throw();

  char const*		what() const throw();
};

#endif			/*	MYEXCEPTION_HH_		*/
