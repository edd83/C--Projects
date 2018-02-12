//
// Machine.hpp for Machine in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 11:04:54 2014 lardet
// Last update Sun Mar  2 20:06:11 2014 lardet
//

#ifndef __MACHINE_HPP__
# define __MACHINE_HPP__

#include <istream>
#include <list>

enum	eInstruction
  {
    PUSH = 0,
    POP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    EXIT
  };

class	Machine
{
private:
  bool		_ifFile;
  std::istream	*_input;
  std::list<std::string> line;
public:
  Machine();
  Machine(const char *);
  ~Machine();
  bool	start();
  bool	start_interactiv() const;
  void	execute();
  void	execute_interactiv() const;
  void	setInput(const char *);
};

#endif
