//
// Color.cpp for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 13:52:11 2014 Bonnet Vivien
// Last Update Fri Apr 25 18:04:41 2014 Bonnet Vivien
//

#include "Color.hh"
#include "NcursesException.hh"

#include <ncurses/curses.h>

namespace nc
{

int	Color::g_counter = 0;

Color::Color()
{
}

Color::Color(short foreground, short background)
{
  m_foreground = foreground;
  m_background = background;
  m_id = ++g_counter;
  if (init_pair(m_id, m_foreground, m_background) == ERR)
    throw NcursesException("Cannot create color");
}

Color::~Color()
{
}


int
Color::getAttr() const
{
  return (COLOR_PAIR(m_id));
}

}
