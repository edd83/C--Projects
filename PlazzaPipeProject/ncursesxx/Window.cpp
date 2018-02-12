//
// Window.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 11:18:12 2014 Bonnet Vivien
// Last Update Sat Apr 26 17:26:11 2014 Bonnet Vivien
//

#include "NcursesException.hh"
#include "Window.hh"

namespace nc
{

Window::Window()
{
  m_win = newwin(1, 1, 0, 0);
  if (m_win == NULL)
    throw NcursesException("Cannot create window");

  m_x = 0;
  m_y = 0;
  m_width = 1;
  m_height = 1;

  this->setDefaultBorderStyle();
}

Window::Window(const std::string& name)
{
  m_win = newwin(1, 1, 0, 0);
  if (m_win == NULL)
    throw NcursesException("Cannot create window");

  m_x = 0;
  m_y = 0;
  m_width = 1;
  m_height = 1;
  m_name = name;

  this->setDefaultBorderStyle();
}

Window::~Window()
{
  if (delwin(m_win) == ERR)
    throw NcursesException("Cannot destroy window");
}


void
Window::setDefaultBorderStyle()
{
  unsigned int	i;

  for (i = 0; i < 8; ++i)
    m_borderStyle[i] = DEFAULT_BORDER_STYLE[i];
}


WINDOW*
Window::getWindow()
{
  return (m_win);
}

int
Window::getWidth() const
{
  return (m_width);
}

int
Window::getHeight() const
{
  return (m_height);
}


void
Window::activeAttr(Window::Attr attr)
{
  if (wattron(m_win, attr) == ERR)
    throw NcursesException("Cannot active an attr in a window");
}

void
Window::disactiveAttr(Window::Attr attr)
{
  if (wattroff(m_win, attr) == ERR)
    throw NcursesException("Cannot disactive an attr in a window");
}

void
Window::setColor(const Color& color)
{
  this->activeAttr(color.getAttr());
}

void
Window::unsetColor(const Color& color)
{
  this->disactiveAttr(color.getAttr());
}

void
Window::setBackground(const Color& color)
{
  wbkgdset(m_win, color.getAttr());
}


void
Window::move(int x, int y)
{
  if (wmove(m_win, y, x))
    throw NcursesException("Cannot move in window");
}

void
Window::print(const std::string& message, ...)
{
  va_list	list;

  va_start(list, message);
  {
    vw_printw(m_win, message.c_str(), list);
  }
  va_end(list);
}


void
Window::enableKeyPad()
{
  if (keypad(m_win, true) == ERR)
    throw NcursesException("Cannot enable out-ascii keys");
}

void
Window::resize(int width, int height)
{
  m_width = width;
  m_height = height;
  if (wresize(m_win, height, width) == ERR)
    throw NcursesException("Cannot resize window");
}

void
Window::displace(int x, int y)
{
  m_x = x;
  m_y = y;
  if (mvwin(m_win, y, x) == ERR)
    throw NcursesException("Cannot move window");
}

void
Window::setBorderStyle(const borderStyle& style)
{
  unsigned int	i;

  for (i = 0; i < 8; ++i)
    m_borderStyle[i] = style[i];
}


void
Window::clear()
{
  if (werase(m_win) == ERR)
    throw NcursesException("Cannot clear window");
}

void
Window::drawBorder()
{
  if (wborder(m_win,
	      m_borderStyle[0], m_borderStyle[1], m_borderStyle[2], m_borderStyle[3],
	      m_borderStyle[4], m_borderStyle[5], m_borderStyle[6], m_borderStyle[7]) == ERR)
    throw NcursesException("Cannot draw window border");

  if (m_name.empty() == false)
    {
      this->move(m_width / 2 - m_name.size() / 2, 0);
      this->print(m_name);
    }
}

void
Window::display()
{
  if (wrefresh(m_win) == ERR)
    throw NcursesException("Cannot clear window");
}


Window::Event
Window::getEvent()
{
  Window::Event	event;

  event = (Window::Event)wgetch(m_win);
  if (event == ERR)
    throw NcursesException("Cannot get window event");
  return (event);
}

}
