//
// Cpu.cpp for cpu in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 10:04:14 2014 lardet
// Last update Sun Mar  2 20:03:31 2014 lardet
//

#include	"Cpu.hpp"
#include	"avm_error.hpp"
#include	"Operand.hpp"

Cpu::Cpu() {
  this->_ptr = new func_ptr[10];
  
  this->_ptr[0] = &Cpu::push;
  this->_ptr[1] = &Cpu::pop;
  this->_ptr[2] = &Cpu::dump;
  this->_ptr[3] = &Cpu::assert;
  this->_ptr[4] = &Cpu::add;
  this->_ptr[5] = &Cpu::sub;
  this->_ptr[6] = &Cpu::mul;
  this->_ptr[7] = &Cpu::div;
  this->_ptr[8] = &Cpu::mod;
  this->_ptr[9] = &Cpu::print;
}

Cpu::~Cpu() {
  delete[] this->_ptr;
}


bool	Cpu::push(IOperand *elem, Memory &mem, const int line) const
{
  (void)line;
  mem << elem;
  return (true);
}

bool	Cpu::pop(IOperand *elem, Memory &mem, const int line) const
{
  try {
    if (mem.lengthStack() == 0)
      throw avm_error("Error pop : the stack is empty", line);
    else
      mem >> &elem;
  }
  catch (avm_error &error) {
    std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  delete elem;
  return (true);
}

bool	Cpu::dump(IOperand *elem, Memory &mem, const int line) const
{
  std::vector<IOperand*> tmp = mem.getStack();
  int	count = mem.lengthStack();

  (void)line;
  while (--count >= 0)
    {
      elem = tmp[count];
      std::cout << elem->toString() << std::endl;
    }
  return (true);
}

bool	Cpu::assert(IOperand *elem, Memory &mem, const int line) const
{
  try {
    if (mem.lengthStack() == 0)
      throw avm_error("Error assert : The stack is empty", line);
    if (elem->getType() != (mem.getFirstElem())->getType())
      throw avm_error("Error assert : the first element in the stack have not the same type", line);
    if (elem->toString() != (mem.getFirstElem())->toString())
      throw avm_error("Error assert : the first element in the stack have not the same value", line);
    delete elem;
  }
  catch (avm_error &error) {
    std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  return (true);
}

bool	Cpu::add(IOperand *elem, Memory &mem, const int line) const
{
  IOperand *first = NULL;

  try {
    if (mem.lengthStack() < 2)
      throw avm_error("Error add : not enough elements in this stack", line);
    else {
      mem >> &first;
      mem >> &elem;
      mem << (*elem + *first);
      delete elem;
      delete first;
    }
  }
 catch (avm_error &error) {
   std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  return (true);
}

bool	Cpu::sub(IOperand *elem, Memory &mem, const int line) const
{
  IOperand *first;

  try {
    if (mem.lengthStack() < 2)
      throw avm_error("Error sub : not enough elements in this stack", line);
    else {
      mem >> &first;
      mem >> &elem;
      mem << (*elem - *first);
      delete elem;
      delete first;
    }
  }
 catch (avm_error &error) {
   std::cerr << "Line : " << error.where() << " : " << error.what() << std::endl;
    return (false);
 }
  return (true);
}

bool	Cpu::mul(IOperand *elem, Memory &mem, const int line) const
{
  IOperand *first;

  try {
    if (mem.lengthStack() < 2)
      throw avm_error("Error mul : not enough elements in this stack", line);
    else {
      mem >> &first;
      mem >> &elem;
      mem << (*elem * *first);
      delete elem;
      delete first;
    }
  }
  catch (avm_error &error) {
    std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  return (true);
}

bool	Cpu::div(IOperand *elem, Memory &mem, const int line) const
{
  IOperand *first;

  try {
    if (mem.lengthStack() < 2)
      throw avm_error("Error div : not enough elements in this stack", line);
    else {
      if (mem.checkElemEqualZero() == true)
	throw avm_error("Error div : divide by zero", line);
      mem >> &first;
      mem >> &elem;
      mem << (*elem / *first);
      delete elem;
      delete first;
    }
  }
  catch (avm_error &error) {
    std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  return (true);
}

bool	Cpu::mod(IOperand *elem, Memory &mem, const int line) const
{
  IOperand *first;

  try {
    if (mem.lengthStack() < 2)
      throw avm_error("Error mod : not enough elements in this stack", line);
    else {
      if (mem.checkElemEqualZero() == true)
	throw avm_error("Error mod : divide by zero", line);
      mem >> &first;
      mem >> &elem;
      mem << (*elem % *first);
      delete elem;
      delete first;
    }
  }
  catch (avm_error &error) {
    std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  return (true);
}

bool	Cpu::print(IOperand *elem, Memory &mem, const int line) const
{
  try {
    if ((mem.getFirstElem())->getType() != INT8)
      throw avm_error("Error print : the first element in the stack is not a int8 (char)", line);
    else
      {
	elem = mem.getFirstElem();
	std::cout << (char)convertString<int8_t>(elem->toString(), elem->getType()) << std::endl;
      }
  }
  catch (avm_error &error) {
    std::cerr << "Line " << error.where() << " : " << error.what() << std::endl;
    return (false);
  }
  return (true);
}

bool	Cpu::exec(const eInstruction type, IOperand *elem, Memory &mem, int const line) const
{
  if (type == EXIT)
    {
      delete elem;
      return (false);
    }
  else
    if (((this->*_ptr[type])(elem, mem, line)) == true)
      return (true);
  return (false);
}

