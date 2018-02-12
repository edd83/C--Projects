//
// operation_funcT.hpp for operation_funcT in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Wed Feb 26 19:47:14 2014 lardet
// Last update Sun Mar  2 20:10:57 2014 lardet
//

#include <stdint.h>
#include <sstream>
#include <math.h>
#include <limits>
#include <exception>
#include <stdexcept>
#include "IOperand.hpp"
#include "OperandCreator.hpp"

template<typename T>
std::string const convertT(const T value)
{
  std::stringstream oss;
  int	val = value;

  if (sizeof(value) == sizeof(int8_t))
    oss << val;
  else
    oss << value;
  return oss.str();
}

template<typename T>
T convertString(std::string const &nb, const eOperandType type)
{
  T	val;
  int	tmp;
  std::stringstream oss(nb);

  if (type == INT8) {
    oss >> tmp;
    if (tmp < -(std::numeric_limits<T>::max()+1))
      throw std::underflow_error("Error in convertion : An underflow happend while declaration of operand");
    else if (tmp > std::numeric_limits<T>::max())
      throw std::overflow_error("Error in convertion : An overflow happend while declaration of operand");
    val = tmp;
  }
  else {
    if (!(oss >> val)) {
      if (nb[0] == '-')
	throw std::underflow_error("Error in convertion : An underflow happend while declaration of operand");
      else
	throw std::overflow_error("Error in convertion : An overflow happend while declaration of operand");
    }
  }
  return val;
}

template<typename T>
IOperand *sub_op(const IOperand &_this, const IOperand &rhs){
  OperandCreator	maker;
  IOperand		*newOperand;
  T			res = 0;
  T			a;
  T			b = 0;
  std::string		result;

  a = convertString<T>(_this.toString(), rhs.getType());
  b = convertString<T>(rhs.toString(), rhs.getType());
  if (a - b > std::numeric_limits<T>::max())
    throw  std::overflow_error("Error sub : An overflow happend while doing operation");
  if (a - b < -(std::numeric_limits<T>::max()+1))
    throw  std::underflow_error("Error sub : An underflow happend while doing operation");
  res = a - b;
  result = convertT(res);
  newOperand = maker.createOperand(rhs.getType(), result);
  return (newOperand);
}

template<typename T>
IOperand *div_op(const IOperand &_this, const IOperand &rhs){
  OperandCreator	maker;
  IOperand		*newOperand;
  T			res = 0;
  T			a;
  T			b = 0;
  std::string		result;

  a = convertString<T>(_this.toString(), rhs.getType());
  b = convertString<T>(rhs.toString(), rhs.getType());
  if (a / b > std::numeric_limits<T>::max())
    throw  std::overflow_error("Error sub : An overflow happend while doing operation");
  if (a / b < -(std::numeric_limits<T>::max()+1))
    throw  std::underflow_error("Error sub : An underflow happend while doing operation");
  res = a / b;
  result = convertT(res);
  newOperand = maker.createOperand(rhs.getType(), result);
  return (newOperand);
}

template<typename T>
IOperand *mod_op(const IOperand &_this, const IOperand &rhs){
  OperandCreator        maker;
  IOperand              *newOperand;
  T                     res = 0;
  T                     a;
  T                     b = 0;
  std::string           result;

  a = convertString<T>(_this.toString(), rhs.getType());
  b = convertString<T>(rhs.toString(), rhs.getType());
  res = fmod(a, b);
  result = convertT(res);
  newOperand = maker.createOperand(rhs.getType(), result);
  return (newOperand);
}
