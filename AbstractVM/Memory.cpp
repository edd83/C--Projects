//
// Memory.cpp for Memory in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 16:25:23 2014 lardet
// Last update Sun Mar  2 20:08:02 2014 lardet
//

#include	"Memory.hpp"
#include	"Operand.hpp"

Memory::Memory() {}

Memory::~Memory() {
  IOperand	*del;

  while (!this->_stack.empty())
    {
      del = this->_stack.back();
      this->_stack.pop_back();
      delete del;
    }
}

bool		Memory::checkElemEqualZero() const
{
  IOperand	*elem = this->_stack.back();

  if (convertString<double>(elem->toString(), elem->getType()) == 0)
    return (true);
  return (false);
}

IOperand	*Memory::getFirstElem() const
{
  return (this->_stack.back());
}

std::vector<IOperand*> Memory::getStack() const
{
  return (this->_stack);
}

void  Memory::operator<<(IOperand *elem)
{
  this->_stack.push_back(elem);
}

IOperand	*Memory::operator>>(IOperand **elem)
{
  *elem = this->_stack.back();
  this->_stack.pop_back();
  return (*elem);
}

int	Memory::lengthStack() const
{
  int		count = 0;

  for (std::vector<IOperand*>::const_iterator it = this->_stack.begin(); it != this->_stack.end(); ++it)
    ++count;
  return (count);
}
