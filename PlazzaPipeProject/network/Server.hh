//
// server.hh for server in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:45:44 2014 lardet
// Last Update Sun Apr 27 09:32:49 2014 Bonnet Vivien
//

#ifndef _SERVER_HH_
# define _SERVER_HH_

#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include <signal.h>
#include "Select.hh"
#include "Socket.hh"

class	Server
{
  Socket	_sock;
  Select	_slct;
public:
  Server();
  ~Server();
  void	launcher(const char *, void (*fun)(void*, const std::string&), void* data);
};

#endif
