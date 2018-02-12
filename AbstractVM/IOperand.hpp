//
// IOperand.hpp for IOperand in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 11:05:08 2014 lardet
// Last update Sun Mar  2 20:04:45 2014 lardet
//

#ifndef __IOPERAND_HPP__
# define __IOPERAND_HPP__

# include <string>
# include <iostream>

enum	eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
  };

class	IOperand
{
public:
  virtual ~IOperand() {};
  virtual std::string const &toString() const = 0;
  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;
  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;
};

#endif
