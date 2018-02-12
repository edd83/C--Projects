//
// Select.hh for Select in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 22:07:54 2014 lardet
// Last Update Sat Apr 26 20:06:09 2014 Bonnet Vivien
//

#ifndef         __SELECT_HH__
# define        __SELECT_HH__

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/time.h>
#include	<cstdlib>
#include	<string>
#include	"Socket.hh"
#include	"Error.hh"

class		Select
{
  struct timeval	_tv;
  fd_set		_readfds;
public:
  Select();
  ~Select();
  void			init();
  bool			launchClient(int);
  bool			launchServer(const Socket &);
  void			readToCli(Socket &, std::string&);
  int			initMultiCli(const Socket &);
};

#endif
