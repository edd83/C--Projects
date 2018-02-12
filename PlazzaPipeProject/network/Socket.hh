//
// Socket.hh for Socket in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 21:33:24 2014 lardet
// Last Update Sat Apr 26 20:00:37 2014 Bonnet Vivien
//

#ifndef _SOCKET_HH_
# define _SOCKET_HH_

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include "Error.hh"

class	Socket
{
  int			_listenFd;
  struct hostent	*_server;
  struct sockaddr_in	_svrAdd;
  int			_t[FD_SETSIZE];
  int			_nbClient;
  socklen_t		_len;
  struct sockaddr_in	_clntAdd;
  int			_connFd;
public:
  Socket();
  ~Socket();
  int			getFd() const;
  int			getNb() const;
  int			getFdConn() const;
  void			bindFd();
  void			listenFd();
  void			closeFd(int);
  void			initialiseConnection();
  void			getHost(const char *);
  void			connectionClient(const char *, int);
  void			connectionServer(int);
  int			getElem(int) const;
  std::string		readInput();
  void			sendSomething(const char *);
  void			acceptToCli();
  void			incMulti();
  void			printCli(int, std::string &str);
};

#endif
