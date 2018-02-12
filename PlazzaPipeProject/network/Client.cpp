//
// client.cpp for client in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:28:05 2014 lardet
// Last Update Sun Apr 27 09:58:02 2014 Bonnet Vivien
//

#include "Client.hh"

Client::Client()
{
}

Client::~Client()
{
}

void			Client::launcher(char *argv[])
{
  std::string		buf;

  try
    {
      this->_sock.connectionClient(argv[1], atoi(argv[2]));
      while(42)
	{
	  if (this->_slct.launchClient(this->_sock.getFd()))
	    {
	      buf = this->_sock.readInput();
	      this->_sock.sendSomething(buf.c_str());
	    }
	}
    }
  catch (RuntimeError &ex)
    {
      std::cerr << ex.what() << std::endl;
    }
}

int			main(int argc, char **argv)
{
  Client		*cli = new Client();

  if(argc < 3)
    {
      std::cerr << "Syntax : ./client <host name> <port>" << std::endl;
      return (-1);
    }
  cli->launcher(argv);
  delete (cli);
  return (0);
}
