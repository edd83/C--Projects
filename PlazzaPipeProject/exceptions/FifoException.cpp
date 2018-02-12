//
// FifoException.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:42:12 2014 Bonnet Vivien
// Last Update Mon Apr 14 16:49:37 2014 Bonnet Vivien
//

#include "FifoException.hh"

FifoException::FifoException(const std::string& message) :
  PlazzaException("FIFO problem : " + message)
{
}

FifoException::~FifoException() throw()
{
}
