//
// Prompt.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 08:53:21 2014 Bonnet Vivien
// Last Update Fri Apr 25 17:03:41 2014 Bonnet Vivien
//

#ifndef PROMPT_HH_
# define PROMPT_HH_

# include "Color.hh"
# include "PlazzaWindow.hh"

# define PROMPT_WINDOW_NAME	("Prompt")
# define PROMPT_COLOR		(nc::Color(COLOR_BLACK, COLOR_YELLOW))

class	Prompt : public PlazzaWindow
{
public:
  typedef void	(Prompt::*Method)();

private:
  std::string	m_command;
  unsigned int	m_cursorPos;

public:
  Prompt();
  ~Prompt();

public:
  void	resize(int width, int height);
  void	update();

public:
  void	insertChar(nc::Window::Event c);
  void	deleteChar();
  void	moveCursorToRight();
  void	moveCursorToLeft();

public:
  void		resetCursor();
  std::string	getCommand();
};

#endif // !PROMPT_HH_
