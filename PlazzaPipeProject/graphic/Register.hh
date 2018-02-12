//
// Register.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 08:51:38 2014 Bonnet Vivien
// Last Update Sun Apr 27 09:00:47 2014 Bonnet Vivien
//

#ifndef REGISTER_HH_
# define REGISTER_HH_

# include <list>

# include "PlazzaWindow.hh"

# define REGISTER_WINDOW_NAME	("Register")
# define REGISTER_COLOR		(nc::Color(COLOR_BLACK, COLOR_YELLOW))

# define REGISTER_COLORS_NUMBER	(3)

class		Register : public PlazzaWindow
{
public:
  struct	Message
  {
    std::string	data;
    nc::Color	color;
  };

public:
  enum		ColorID
  {
    Standart,
    Error,
    Network
  };

private:
  std::list<Message>	m_messages;
  nc::Color		m_colors[REGISTER_COLORS_NUMBER];

public:
  Register();
  ~Register();

public:
  void	addMessage(const std::string& message, ColorID colorID);

public:
  void	resize(int width, int height);
  void	update();
};

#endif // !REGISTER_HH_
