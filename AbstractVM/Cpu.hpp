//
// Cpu.hpp for Cpu in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 10:00:02 2014 lardet
// Last update Sun Mar  2 20:04:12 2014 lardet
//

#ifndef		__CPU_HPP__
# define	__CPU_HPP__

#include	<iostream>
#include	<string>
#include	"Machine.hpp"
#include	"Memory.hpp"

class		Cpu
{
private:
  typedef bool (Cpu::*func_ptr)(IOperand *, Memory &, const int) const;
  typedef bool (Cpu::*type_value)(IOperand *, Memory &);
  func_ptr		*_ptr;
  type_value		*_value;
public:
  Cpu();
  ~Cpu();
  bool	exec(const eInstruction, IOperand*, Memory &, int const) const;
  bool	push(IOperand *, Memory &, const int) const;
  bool	pop(IOperand *, Memory &, const int) const;
  bool	dump(IOperand *, Memory &, const int) const;
  bool	assert(IOperand *, Memory &, const int) const;
  bool	add(IOperand *, Memory &, const int) const;
  bool	sub(IOperand *, Memory &, const int) const;
  bool	mul(IOperand *, Memory &, const int) const;
  bool	div(IOperand *, Memory &, const int) const;
  bool	mod(IOperand *, Memory &, const int) const;
  bool	print(IOperand *, Memory &, const int) const;
};


#endif		/*__CPU_HPP__*/
