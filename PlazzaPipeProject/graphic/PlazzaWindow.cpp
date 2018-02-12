//
// PlazzaWindow.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 09:35:17 2014 Bonnet Vivien
// Last Update Fri Apr 25 16:59:56 2014 Bonnet Vivien
//

#include "PlazzaWindow.hh"

PlazzaWindow::PlazzaWindow(const std::string& name, const nc::Color& color) :
  nc::Window(name)
{
  this->activeAttr(PLAZZA_WINDOW_ATTR | color.getAttr());
  this->setBackground(color);
}

PlazzaWindow::~PlazzaWindow()
{
}


void
PlazzaWindow::resize(int width, int height)
{
  nc::Window::resize(width, height);
  this->update();
}
