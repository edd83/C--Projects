//
// OperandCreator.cpp for OperandCreator in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Wed Feb 26 14:12:14 2014 lardet
// Last update Sun Mar  2 20:10:11 2014 lardet
//

#include "Operand.hpp"
#include "OperandCreator.hpp"

OperandCreator::OperandCreator()
{
}

OperandCreator::~OperandCreator() {}

IOperand	*OperandCreator::createInt8(const std::string &str_value)
{
  return new Operand<int8_t>(str_value, INT8);
}

IOperand	*OperandCreator::createInt16(const std::string &str_value)
{
  return new Operand<int16_t>(str_value, INT16);  
}

IOperand	*OperandCreator::createInt32(const std::string &str_value)
{
  return new Operand<int32_t>(str_value, INT32);
}

IOperand	*OperandCreator::createFloat(const std::string &str_value)
{
  return new Operand<float>(str_value, FLOAT);
}

IOperand	*OperandCreator::createDouble(const std::string &str_value)
{
  return new Operand<double>(str_value, DOUBLE);
}

IOperand * OperandCreator::createOperand(eOperandType type, const std::string & value)
{
  IOperand *newOperand;
  IOperand *(OperandCreator::*ptr[5])(const std::string&) = {&OperandCreator::createInt8,
							     &OperandCreator::createInt16,
							     &OperandCreator::createInt32,
							     &OperandCreator::createFloat,
							     &OperandCreator::createDouble};

  newOperand = (this->*ptr[type])(value); 
  return newOperand;
}
