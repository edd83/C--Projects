//
// Chipset.cpp for Chipset in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Mon Feb 24 23:11:11 2014 lardet
// Last update Sun Mar  2 20:00:59 2014 lardet
//

#include	<stdexcept>
#include	"Chipset.hpp"
#include	"OperandCreator.hpp"
#include	"avm_error.hpp"

Chipset::Chipset(std::istream *input) : _input(input)
{
  this->instr = new std::string[11];
  this->instr[0] = "push";
  this->instr[1] = "pop";
  this->instr[2] = "dump";
  this->instr[3] = "assert";
  this->instr[4] = "add";
  this->instr[5] = "sub";
  this->instr[6] = "mul";
  this->instr[7] = "div";
  this->instr[8] = "mod";
  this->instr[9] = "print";
  this->instr[10] = "exit";
  
  this->val = new std::string[5];
  this->val[0] = "int8"; 
  this->val[1] = "int16";
  this->val[2] = "int32";
  this->val[3] = "float";
  this->val[4] = "double";
}

Chipset::~Chipset()
{
  delete[] this->instr;
  delete[] this->val;
}

bool Chipset::Lexer(std::list<std::string> &_token, std::string &tempInput) const
{
  std::stringstream		ss;
  int				comment = 0;
  int				nb_word = 0;
  std::list<std::string>	cpy;
  size_t			index;
  
  ss.str(tempInput);
  if (tempInput == "")
    return false;
  while (ss >> tempInput)
    {
      if ((index = tempInput.find(";")) != tempInput.npos)
	{
	  if (!index && !comment)
	    {
	      comment = 1;
	      _token.push_back(tempInput.substr(0, index));
	    }
	  if (comment != 0)
	    break;
	  tempInput = tempInput.substr(0, index);
	  comment = 2;
	}
      if ((index = tempInput.find("(")) != tempInput.npos)
	{
	  _token.push_back(tempInput.substr(0, index));
	  _token.push_back(tempInput.substr(index, 1));
	  _token.push_back(tempInput.substr(index + 1, tempInput.find(")") - index - 1));
	  _token.push_back(tempInput.substr(tempInput.find(")"), tempInput.size() - tempInput.find(")")));
	}
      else
	_token.push_back(tempInput);
      nb_word++;
    }
  if (comment == 1 && !nb_word)
    return false;
  else
    return true;
}

bool	Chipset::checkIfInstr(std::string const &to_cmp) const
{
  int		i = -1;

  while (++i < 11)
    if (this->instr[i] == to_cmp)
      return (true);
  return (false);
}

bool	Chipset::checkIfValue(std::string const &to_cmp) const
{
  int		i = -1;

  while (++i < 5)
    if (this->val[i] == to_cmp)
      return (true);
  return (false);
}

bool	Chipset::checkIfPar(std::string const &to_cmp, const int macro) const
{
  if (macro == OPEN && to_cmp == "(")
    return (true);
  else if (macro == CLOSE && to_cmp == ")")
    return (true);
  else
    return (false);
}

bool	Chipset::checkIfValidValue(std::string const &value, std::string const &type) const
{
  unsigned int	i = -1;
  int flag = 1;
  size_t	index;

  while (++i < value.size())
    {
      if (value[i] == '.')
	{
	  if (flag == 2 || (index = type.find("int")) != type.npos)
	    return false;
	  else
	    flag = 2;
	}
      else if ((value[i] < '0' || value[i] > '9') && value[i] != '-')
	return false;
    }
  return true;
}
      
std::string	Chipset::popNfront(std::list<std::string> &token) const
{
  std::string buf = "";

  if (!token.empty())
    {
      buf = token.front();
      token.pop_front();
    }
  return buf;
}

bool	Chipset::Parser(std::list<std::string> &back, const int line) const
{
  std::string	buf;
  std::list<std::string> token = back;

  try {
    buf = token.front();
    if (this->checkIfInstr(this->popNfront(token)))
      {
	if (buf == "push" || buf == "assert")
	  {
	    buf = token.front();
	    if (this->checkIfValue(this->popNfront(token)))
	      {
		if (this->checkIfPar(this->popNfront(token), OPEN) && 
		    this->checkIfValidValue(this->popNfront(token), buf) && 
		    this->checkIfPar(this->popNfront(token), CLOSE))
		  return true;		
		throw avm_error("Invalid numeric expression or missing argument", line);
	      }
	    throw avm_error("Invalid or missing type of value", line);
	  }
	if (token.empty())
	  return (true);
	throw avm_error("Too many argument", line);
      }
    throw avm_error("Invalid instruction", line);
  }
  catch (avm_error &error) {
    std::cerr << "Error in parsing: " << "At line " << error.where() << ": " << error.what() << std::endl;
    return (false);
  }
}

eInstruction	Chipset::getInstruct(const std::string &str_instr) const
{
  int	i = -1;

  while (++i < 11)
      if (this->instr[i] == str_instr)
	break;
  return (eInstruction)i;
}

IOperand	*Chipset::getOperand(std::list<std::string> &token) const
{
  int	i = -1;
  eOperandType	enum_type;
  IOperand	*newOperand;
  OperandCreator creator;
  std::string	type = this->popNfront(token);
  this->popNfront(token);
  std::string	value = this->popNfront(token);

  while (++i < 5)
    if (this->val[i] == type)
      break;
  enum_type = (eOperandType)i;
  newOperand = creator.createOperand(enum_type, value);
  return (newOperand);
}
