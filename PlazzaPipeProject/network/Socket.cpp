//
// Socket.cpp for Socket in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Fri Apr 25 21:46:42 2014 lardet
// Last Update Sat Apr 26 19:57:00 2014 Bonnet Vivien
//

#include "Socket.hh"

Socket::Socket()
{
  bzero((char *) &this->_svrAdd, sizeof(this->_svrAdd));
  this->_len = sizeof(this->_clntAdd);
  this->_nbClient = 0;
  this->_connFd = -1;
}

Socket::~Socket()
{
  if (close(this->_listenFd) == -1)
    throw RuntimeError("Failed to close socket.");
}

int	Socket::getFd() const
{
  return (this->_listenFd);
}

int	Socket::getNb() const
{
  return (this->_nbClient);
}

int	Socket::getFdConn() const
{
  return (this->_connFd);
}

int	Socket::getElem(int j) const
{
  return (this->_t[j]);
}

void		Socket::closeFd(int fd)
{
  if (close(fd) == -1)
    throw RuntimeError("Failed to close file descriptor.");
}

std::string	Socket::readInput()
{
  char		buf[4096];
  std::string	end;

  bzero(buf, 4096);
  if (std::cin.getline(buf, 4096) <= 0)
    throw RuntimeError("Failed to read on input standard.");
  end = buf;
  return (end);
}

void	Socket::printCli(int i, std::string &str)
{
  char	buf[4096];

  bzero(buf, 4096);
  if(recv(this->_t[i],&buf,4096,0) <= 0)
    {
      this->closeFd(this->_t[i]);
      this->_nbClient--;
    }
  str.assign(buf);
}

void	Socket::sendSomething(const char *buf)
{
  if(send(this->_listenFd, buf, 4096, 0) == -1)
    throw RuntimeError("Failed to send.");
}

void	Socket::initialiseConnection()
{
  if((this->_listenFd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    throw RuntimeError("Failed to open socken.");
}

void	Socket::getHost(const char *ip)
{
  if((this->_server = gethostbyname(ip)) == NULL)
    throw RuntimeError("Failed to get the host.");
}

void	Socket::bindFd()
{
  if (bind(this->_listenFd, (struct sockaddr *)&this->_svrAdd, sizeof(this->_svrAdd)) == -1)
    throw RuntimeError("Failed to bind to socket.");
}

void	Socket::listenFd()
{
  if (listen(this->_listenFd, 10) == -1)
    throw RuntimeError("Failed to listen to socket.");
}

void	Socket::connectionClient(const char *ip, int port)
{
  this->initialiseConnection();
  this->getHost(ip);

  this->_svrAdd.sin_family = AF_INET;
  this->_svrAdd.sin_port = htons(port);
  bcopy((char *)this->_server->h_addr, (char *)&this->_svrAdd.sin_addr.s_addr, this->_server->h_length);
  
  if (connect(this->_listenFd,(struct sockaddr *) &this->_svrAdd, sizeof(this->_svrAdd)) == -1)
    throw RuntimeError("Failed to connect to socket.");
}

void			Socket::acceptToCli()
{
  if ((this->_connFd = accept(this->_listenFd, (struct sockaddr *)&this->_clntAdd, &this->_len)) == -1)
    throw RuntimeError("Failed to accept the socket.");
}

void			Socket::incMulti()
{
  this->acceptToCli();
  this->_nbClient++;
  this->_t[this->_nbClient - 1] = this->_connFd;
}

void	Socket::connectionServer(int port)
{
  this->initialiseConnection();

  this->_svrAdd.sin_family = AF_INET;
  this->_svrAdd.sin_addr.s_addr = INADDR_ANY;
  this->_svrAdd.sin_port = htons(port);

  this->bindFd();
  this->listenFd();
  this->_t[0] = this->_listenFd;
  this->_nbClient++;
}
