//
// Window.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 11:15:10 2014 Bonnet Vivien
// Last Update Sun Apr 27 15:50:49 2014 Bonnet Vivien
//

#ifndef WINDOW_HH_
# define WINDOW_HH_

# include <string>

# include "Color.hh"

# include <ncurses/curses.h>

# define DEFAULT_BORDER_STYLE	("||--####")

# define IS_PRINTABLE(c)	(c >= 0x20 && c < 0x7F)

namespace nc
{

class		Window
{
public:
  typedef char	borderStyle[8];
  typedef int	Attr;

public:
  enum		Event
  {
    Enter	= 0x0A,
    Escape	= 0x1B,
    Resize	= KEY_RESIZE,
    Up		= KEY_UP,
    Down	= KEY_DOWN,
    Right	= KEY_RIGHT,
    Left	= KEY_LEFT,
    Del		= 0x107
  };

private:
  WINDOW*	m_win;
  std::string	m_name;
  int		m_x;
  int		m_y;
  int		m_width;
  int		m_height;
  borderStyle	m_borderStyle;

public:
  Window();
  Window(const std::string& name);
  virtual ~Window();

private:
  void	setDefaultBorderStyle();

public:
  WINDOW*	getWindow();
  int		getWidth() const;
  int		getHeight() const;

public:
  void	activeAttr(Attr attr);
  void	disactiveAttr(Attr attr);
  void	setColor(const Color& color);
  void	unsetColor(const Color& color);
  void	setBackground(const Color& color);

public:
  void	move(int x, int y);
  void	print(const std::string& str, ...);

public:
  void		enableKeyPad();
  virtual void	resize(int width, int height);
  virtual void	displace(int x, int y);
  void		setBorderStyle(const borderStyle& style);

public:
  void	clear();
  void	drawBorder();
  void	display();

public:
  Event	getEvent();
};

}

#endif // !WINDOW_HH_
