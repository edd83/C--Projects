//
// Machine.cpp for Machine in /home/lardet_e/rendu/cpp_abstractvm
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Tue Feb 25 11:11:10 2014 lardet
// Last update Sun Mar  2 20:05:21 2014 lardet
//

#include	<iostream>
#include	<stdexcept>
#include	"IOperand.hpp"
#include	"Chipset.hpp"
#include	"Cpu.hpp"
#include	"Memory.hpp"
#include	"Machine.hpp"

Machine::Machine()
{
  this->_input = &std::cin;
  this->_ifFile = false;
}

Machine::Machine(char const *str)
{
  this->_input = new std::ifstream(str);
  this->_ifFile = true;
}

Machine::~Machine()
{
  if (this->_ifFile)
    delete this->_input;
}

bool	Machine::start()
{
  std::string		tempInput;

  try {
    if (!this->_input->good())
      throw std::invalid_argument("Error : invalid file name");
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  while (getline(*this->_input, tempInput))
    {
      this->line.push_back(tempInput);
      if (!this->_ifFile && tempInput == ";;")
	break;
    }
  return true;
}

bool	Machine::start_interactiv() const
{
  try {
    if (!this->_input->good())
      throw std::invalid_argument("Error : invalid file name");
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

void	Machine::execute()
{
  Chipset		chipset(this->_input);
  int			line = 1;
  bool			if_error = false;
  std::list<std::string> token;
  Cpu			cpu;
  std::string		buff;
  eInstruction		instr;
  Memory		memory;
  IOperand		*operand;

  while (!this->line.empty())
    {
      operand = NULL; 
      if (chipset.Lexer(token, this->line.front()))
	{
	  if (chipset.Parser(token, line))
	    {
	      if (token.front() == "exit")
		return;
	      buff = chipset.popNfront(token);
	      instr = chipset.getInstruct(buff);
	      if (!token.empty())
		operand = chipset.getOperand(token); 
	      if (!if_error)
		if (!cpu.exec(instr, operand, memory, line))
		  return;
	    }
	  else
	    if_error = true;
	}
      this->line.pop_front();
      token.clear();
      ++line;
    }
  std::cout << "Error : No exit specified" << std::endl;
}

void	Machine::execute_interactiv() const
{
  Chipset		chipset(this->_input);
  int			line = 1;
  std::list<std::string> token;
  std::string		tempInput;
  Cpu			cpu;
  std::string		buff;
  eInstruction		instr;
  Memory		memory;
  IOperand		*operand;

  while (getline(*this->_input, tempInput))
    {
      operand = NULL;
      if (tempInput == ";;")
	return;
      if (chipset.Lexer(token, tempInput))
	{
	  if (chipset.Parser(token, line))
	    {
	      if (token.front() == "exit")
		std::cout << "Exit is unavaible for interactiv mod" << std::endl;
	      else
		{
		  buff = chipset.popNfront(token);
		  instr = chipset.getInstruct(buff);
		  if (!token.empty())
		    operand = chipset.getOperand(token);
		  cpu.exec(instr, operand, memory, line);
		}
	    }
	}
      token.clear();
      ++line;
    }
}

void	Machine::setInput(const char *file_path)
{
  if (this->_ifFile == true)
    delete this->_input;
  else
    this->_ifFile = true;
  this->_input = new std::ifstream(file_path);
}
