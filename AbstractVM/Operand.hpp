//
// Operand.hpp for Operand in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Wed Feb 26 15:54:59 2014 lardet
// Last update Sun Mar  2 20:10:37 2014 lardet
//

#ifndef __OPERAND_HPP__
# define __OPERAND_HPP__

#include <stdint.h>
#include <sstream>
#include <math.h>
#include <limits>
#include <exception>
#include <stdexcept>
#include "IOperand.hpp"
#include "OperandCreator.hpp"
#include "operation_funcT.hpp"

template<typename T>
class	Operand : public IOperand
{
private:
  std::string	number;
  T		value;
  eOperandType	type;

public:
 Operand(std::string const &number, const eOperandType type) {
    this->type = type;
    this->number = number;
    this->value = convertString<T>(number, type);
  }
  ~Operand() {};
  
  std::string const &toString() const {
    return this->number;
  }
  int getPrecision() const {
    return (int)this->type;
  }
  eOperandType getType() const {
    return this->type;
  }
  IOperand *operator+(const IOperand &rhs) const {
    OperandCreator	maker;
    IOperand		*newOperand;
    T			res;
    T			a;
    T			b;
    std::string		result;

    if (this->getPrecision() >= rhs.getPrecision())
      {
	a = this->value;
	b = convertString<T>(rhs.toString(), rhs.getType());
	res = a + b;
	if (a + b > std::numeric_limits<T>::max())
	  throw  std::overflow_error("Error add : An overflow happend while doing operation");
	if (a + b < -(std::numeric_limits<T>::max()+1))
	  throw  std::underflow_error("Error add : An underflow happend while doing operation");
	result = convertT(res);
	newOperand = new Operand<T>(result, this->getType());
      }   
    else
      newOperand = rhs + *this; 
    return newOperand;
  }

IOperand *operator-(const IOperand &rhs) const {
  IOperand		*newOperand;
  T			res = 0;
  T			a;
  T			b = 0;
  std::string		result;
  
  if (rhs.getType() > this->getType())
    {
      switch (rhs.getType()) {
      case INT8: {newOperand = sub_op<int8_t>(*this, rhs);}
      case INT16: {newOperand = sub_op<int16_t>(*this, rhs);}
      case INT32: {newOperand = sub_op<int32_t>(*this, rhs);}
      case FLOAT: {newOperand = sub_op<float>(*this, rhs);}
      case DOUBLE: {newOperand = sub_op<double>(*this, rhs);}
      }
    }
  else { 
    a = this->value;
    b = convertString<T>(rhs.toString(), rhs.getType());
    if (a - b > std::numeric_limits<T>::max())
      throw  std::overflow_error("Error sub : An overflow happend while doing operation");
    if (a - b < -(std::numeric_limits<T>::max()+1))
      throw  std::underflow_error("Error sub : An underflow happend while doing operation");
    res = a - b;
    result = convertT(res);
    newOperand = new Operand<T>(result, this->getType());
  }
  return newOperand;
}

  IOperand *operator*(const IOperand &rhs) const {
    OperandCreator	maker;
    IOperand		*newOperand;
    T			res;
    T			a;
    T			b;
    std::string		result;
    
    a = this->value;
    b = convertString<T>(rhs.toString(), rhs.getType());
    res = a * b;
    if (a * b > std::numeric_limits<T>::max())
      throw  std::overflow_error("Error mul : An overflow happend while doing operation");
    if (a * b < -(std::numeric_limits<T>::max()+1))
      throw  std::underflow_error("Error mul : An underflow happend while doing operation");
    if (this->getPrecision() >= rhs.getPrecision()) {
      result = convertT(res);
      newOperand = new Operand<T>(result, this->getType());
    }
    else {
      newOperand = rhs * *this;
    }
    return newOperand;
  }


  IOperand *operator/(const IOperand &rhs) const {
    OperandCreator	maker;
    IOperand		*newOperand;
    T			res = 0;
    T			a;
    T			b = 0;
    std::string		result;

    if (rhs.getType() > this->getType())
      {
        switch (rhs.getType()) {
        case INT8: {newOperand = div_op<int8_t>(*this, rhs);}
        case INT16: {newOperand = div_op<int16_t>(*this, rhs);}
        case INT32: {newOperand = div_op<int32_t>(*this, rhs);}
        case FLOAT: {newOperand = div_op<float>(*this, rhs);}
        case DOUBLE: {newOperand = div_op<double>(*this, rhs);}
        }
      }
    else {
      a = this->value;
      b = convertString<T>(rhs.toString(), rhs.getType());
      if (a / b > std::numeric_limits<T>::max())
	throw  std::overflow_error("Error div : An overflow happend while doing operation");
      if (a / b < -(std::numeric_limits<T>::max()+1))
	throw  std::underflow_error("Error div : An underflow happend while doing operation");
      res = a / b;
      result = convertT(res);
      newOperand = new Operand<T>(result, this->getType());
    }
    return newOperand;
  }

  IOperand *operator%(const IOperand &rhs) const {
    OperandCreator	maker;
    IOperand		*newOperand;

    if (rhs.getType() > this->getType())
      {
        switch (rhs.getType()) {
        case INT8: {newOperand = mod_op<int8_t>(*this, rhs);}
        case INT16: {newOperand = mod_op<int16_t>(*this, rhs);}
        case INT32: {newOperand = mod_op<int32_t>(*this, rhs);}
        case FLOAT: {newOperand = mod_op<float>(*this, rhs);}
        case DOUBLE: {newOperand = mod_op<double>(*this, rhs);}
        }
      }
    else
      newOperand = new Operand<T>(convertT(fmod(this->value, convertString<T>(rhs.toString(), rhs.getType()))), this->getType());
    return newOperand;    
  }
};

#endif
