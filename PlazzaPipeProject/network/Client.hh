//
// client.hh for client in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:28:18 2014 lardet
// Last update Sat Apr 26 00:00:38 2014 lardet
//

#ifndef _CLIENT_HH_
# define _CLIENT_HH_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Socket.hh"
#include "Select.hh"

class		Client
{
  Socket	_sock;
  Select	_slct;
public:
  Client();
  ~Client();
  void	launcher(char **);
};

#endif
