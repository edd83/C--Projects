//
// Select.cpp for Select in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 22:08:06 2014 lardet
// Last Update Sun Apr 27 09:57:14 2014 Bonnet Vivien
//
#include <stdio.h>
#include "Select.hh"

Select::Select()
{
}

Select::~Select()
{
}

void		Select::init()
{
  this->_tv.tv_sec = 5;
  this->_tv.tv_usec = 0;
}

bool		Select::launchClient(int listenFd)
{
  FD_ZERO(&this->_readfds);
  FD_SET(0, &this->_readfds);
  FD_SET(listenFd, &this->_readfds);
  if(select(listenFd + 1, &this->_readfds, NULL, NULL, NULL) == -1)
    throw RuntimeError("Can't execute select.\n");
  if(FD_ISSET(0, &this->_readfds))
    return (true);
  return (false);
}

int		Select::initMultiCli(const Socket &_sock)
{
  int               sockmax = 0;
  
  for(int j = 0; j < _sock.getNb(); j++)
    {
      if(_sock.getElem(j) != 0)
	FD_SET(_sock.getElem(j),&this->_readfds);
      if(sockmax < _sock.getElem(j))
	sockmax = _sock.getElem(j);
    }
  return (sockmax);
}

void		Select::readToCli(Socket &_sock, std::string& str)
{
  for(int i = 1; i < _sock.getNb(); i++)
    {
      if(FD_ISSET(_sock.getElem(i),&this->_readfds))
        _sock.printCli(i, str);
    }
}

bool		Select::launchServer(const Socket &_sock)
{
  int		sockmax = 0;

  this->init();

  FD_ZERO(&this->_readfds);
  FD_SET(_sock.getFd(), &this->_readfds);

  sockmax = this->initMultiCli(_sock);

  if (select(sockmax + 1, &this->_readfds, NULL, NULL, NULL) == -1)
    throw RuntimeError("Can't execute select.\n");

  if(FD_ISSET(_sock.getFd(), &this->_readfds))
    return (true);
  return (false);
}
