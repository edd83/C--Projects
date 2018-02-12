//
// Register.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 08:54:32 2014 Bonnet Vivien
// Last Update Sun Apr 27 09:00:57 2014 Bonnet Vivien
//

#include "Register.hh"

Register::Register() :
  PlazzaWindow(REGISTER_WINDOW_NAME, REGISTER_COLOR)
{
  m_colors[Register::Standart]	= nc::Color(COLOR_BLACK, COLOR_YELLOW);
  m_colors[Register::Error]	= nc::Color(COLOR_RED, COLOR_YELLOW);
  m_colors[Register::Network]	= nc::Color(COLOR_GREEN, COLOR_YELLOW);
}

Register::~Register()
{
}


void
Register::addMessage(const std::string& message, Register::ColorID colorID)
{
  Register::Message	newMessage;

  newMessage.data = message;
  newMessage.color = m_colors[colorID];
  m_messages.push_back(newMessage);
  if ((int)m_messages.size() > this->getHeight() - 2)
    m_messages.pop_front();
}


void
Register::resize(int width, int height)
{
  this->displace(0, 0);
  PlazzaWindow::resize(width / 4, height - 3);
}

void
Register::update()
{
  std::list<Message>::iterator	it;
  int				y;

  this->clear();
  {
    this->drawBorder();
    y = 0;
    for (it = m_messages.begin(); it != m_messages.end(); ++it)
      {
	this->move(1, ++y);
	this->activeAttr(it->color.getAttr());
	this->print(it->data);
	this->disactiveAttr(it->color.getAttr());
      }
  }
  this->display();
}
