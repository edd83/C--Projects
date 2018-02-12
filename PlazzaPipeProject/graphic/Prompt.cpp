//
// Prompt.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 08:55:55 2014 Bonnet Vivien
// Last Update Sat Apr 26 17:30:44 2014 Bonnet Vivien
//

#include "Prompt.hh"

Prompt::Prompt() :
  PlazzaWindow(PROMPT_WINDOW_NAME, PROMPT_COLOR)
{
  this->enableKeyPad();
}

Prompt::~Prompt()
{
}


void
Prompt::resize(int width, int height)
{
  this->displace(0, height - 3);
  PlazzaWindow::resize(width, 3);
}

void
Prompt::update()
{
  this->clear();
  {
    this->drawBorder();
    this->move(1, 1);
    this->print(m_command.c_str());
  }
  this->display();

  this->resetCursor();
}


void
Prompt::insertChar(nc::Window::Event c)
{
  if (IS_PRINTABLE(c))
    {
      m_command.insert(m_cursorPos, 1, c);
      ++m_cursorPos;
    }
}

void
Prompt::deleteChar()
{
  if (m_command.empty() == false)
    {
      if (m_cursorPos > 0)
	--m_cursorPos;
      m_command.erase(m_cursorPos, 1);
    }
}

void
Prompt::moveCursorToRight()
{
  if (m_cursorPos < m_command.size())
    ++m_cursorPos;
}

void
Prompt::moveCursorToLeft()
{
  if (m_cursorPos > 0)
    --m_cursorPos;
}


void
Prompt::resetCursor()
{
  this->move(1 + m_cursorPos, 1);
}

std::string
Prompt::getCommand()
{
  std::string	command;

  command = m_command;
  m_command.clear();
  m_cursorPos = 0;

  return (command);
}
