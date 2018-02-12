//
// Fifo.hpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Mon Apr 14 16:44:43 2014 Bonnet Vivien
// Last Update Sun Apr 27 15:10:20 2014 Bonnet Vivien
//

#ifndef FIFO_HPP_
# define FIFO_HPP_

# include <string>

# include "FifoException.hh"
# include "Mutex.hh"

# include <errno.h>
# include <cstring>
# include <unistd.h>

typedef int		fd;

class			Fifo
{
public:
  enum			Side
  {
    In,
    Out,
    Nothing
  };

private:
  const std::string	m_name;
  Mutex			m_mutex;
  Side			m_side;
  fd			m_fdin;
  fd			m_fdout;

public:
  Fifo(const std::string& name);
  Fifo(const Fifo& ref);
  ~Fifo();

private:
  void	getFilesNames(std::string& in, std::string& out) const;
  void	createFifoFiles() const;
  void	removeFifoFiles() const;

public:
  void	setSide(Side side);

public:
  const std::string&	getName() const;

public:
  template <typename T>
  void		operator>>(T& packet)
    {
      ssize_t	size;

      if ((size = read(m_fdin, &packet, sizeof(T))) != sizeof(T))
	{
	  if (size == -1)
	    throw FifoException((std::string)("Read error : ") + strerror(errno));
	  else
	    throw FifoException("Bad read size.");
	}
    }

public:
  template <typename T>
  void		operator<<(const T& packet)
    {
      if (write(m_fdout, &packet, sizeof(T)) != sizeof(T))
	throw FifoException((std::string)("Write error : ") + strerror(errno));
    }
};

template <typename T>
void	operator>>(const T& packet, Fifo& fifo)
{
  fifo << packet;
}

template <typename T>
void	operator<<(T& packet, Fifo& fifo)
{
  fifo >> packet;
}

#endif // !FIFO_HPP_
