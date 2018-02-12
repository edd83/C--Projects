//
// Fifo.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Mon Apr 14 17:02:35 2014 Bonnet Vivien
// Last Update Tue Apr 15 09:07:42 2014 Bonnet Vivien
//

#include "FifoException.hh"

#include "Fifo.hpp"

#include <fcntl.h>
#include <errno.h>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

Fifo::Fifo(const std::string& name) :
  m_name(name)
{
  m_side = Nothing;
  m_fdin = -1;
  m_fdout = -1;
  this->createFifoFiles();
}

Fifo::Fifo(const Fifo& ref) :
  m_name(ref.getName())
{
  m_side = Nothing;
  m_fdin = -1;
  m_fdout = -1;
}

Fifo::~Fifo()
{
  if (m_side != Nothing)
    {
      if (close(m_fdin) == -1 || close(m_fdout) == -1)
	throw FifoException((std::string)("Cannot close FIFO's fds : ") + strerror(errno));
      if (m_side == In)
	this->removeFifoFiles();
    }
}


void
Fifo::getFilesNames(std::string& in, std::string& out) const
{
  in = m_name + ".in";
  out = m_name + ".out";
}

void
Fifo::createFifoFiles() const
{
  std::string	inName;
  std::string	outName;

  this->getFilesNames(inName, outName);
  if (mkfifo(inName.c_str(), 0600) || mkfifo(outName.c_str(), 0600))
    throw FifoException((std::string)("Cannot create FIFO's files : ") + strerror(errno));
}

void
Fifo::removeFifoFiles() const
{
  std::string	inName;
  std::string	outName;

  this->getFilesNames(inName, outName);
  if (unlink(inName.c_str()) || unlink(outName.c_str()))
    throw FifoException((std::string)("Cannot remove FIFO's files : ") + strerror(errno));
}


const std::string&
Fifo::getName() const
{
  return (m_name);
}


#include <iostream> // DBEUG
void
Fifo::setSide(Side side)
{
  std::string	inName;
  std::string	outName;

  this->getFilesNames(inName, outName);
  m_side = side;
  if (side == In)
    {
      m_fdin = open(inName.c_str(), O_RDONLY);
      m_fdout = open(outName.c_str(), O_WRONLY);
    }
  else if (side == Out)
    {
      m_fdout = open(inName.c_str(), O_WRONLY);
      m_fdin = open(outName.c_str(), O_RDONLY);
    }
}
