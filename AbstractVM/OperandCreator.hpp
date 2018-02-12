//
// OperandCreator.hpp for OperandCreator.hpp in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Wed Feb 26 14:06:14 2014 lardet
// Last update Sun Mar  2 20:09:39 2014 lardet
//
  
#ifndef __OPERANDCREATOR_HPP__
# define __OPERANDCREATOR_HPP__

#include	"IOperand.hpp"

class	OperandCreator
{
private:
  IOperand	*createInt8(const std::string	&);
  IOperand	*createInt16(const std::string &);
  IOperand	*createInt32(const std::string &);
  IOperand	*createFloat(const std::string &);
  IOperand	*createDouble(const std::string &);

public:
  OperandCreator();
  ~OperandCreator();
  IOperand 	*createOperand(eOperandType type, const std::string & value);
};

#endif
