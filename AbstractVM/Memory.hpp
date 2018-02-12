//
// Memory.hpp for Memory in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 16:20:30 2014 lardet
// Last update Sun Mar  2 20:08:27 2014 lardet
//

#ifndef		__MEMORY_HPP__
# define	__MEMORY_HPP__

#include	<iostream>
#include	<string>
#include	<vector>
#include	"IOperand.hpp"

class		Memory
{
private:
  std::vector<IOperand*>		_stack;
public:
  Memory();
  ~Memory();
  IOperand			*getFirstElem() const;
  void				operator<<(IOperand *);
  IOperand			*operator>>(IOperand **);
  int				lengthStack() const;
  std::vector<IOperand*>	getStack() const;
  bool				checkElemEqualZero() const;
};

#endif		/*__MEMORY_HPP__*/
