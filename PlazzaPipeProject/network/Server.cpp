#include "Server.hh"

Server::Server()
{
}

Server::~Server()
{
}

void		Server::launcher(const char *port, void (*fun)(void*, const std::string&), void* data)
{
  std::string	string;

  this->_sock.connectionServer(atoi(port));
  while (1)
    {
      if (this->_slct.launchServer(this->_sock))
	this->_sock.incMulti();
      this->_slct.readToCli(this->_sock, string);
      fun(data, string);
    }
  this->_sock.closeFd(this->_sock.getFdConn());
}
