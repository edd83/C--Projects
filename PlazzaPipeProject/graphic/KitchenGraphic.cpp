//
// KitchenGraphic.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 08:32:00 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:25:31 2014 Bonnet Vivien
//

#include "Kitchen.hh"
#include "KitchenGraphic.hh"

KitchenGraphic::KitchenGraphic(const std::string& name, Mutex* mutex) :
  PlazzaWindow(name, KITCHEN_GRAPHIC_COLOR)
{
  m_selected = false;
  m_cursorMutex = mutex;
}

KitchenGraphic::~KitchenGraphic()
{
}


bool
KitchenGraphic::isSelected() const
{
  return (m_selected);
}



void
KitchenGraphic::select()
{
  m_selected = true;
}

void
KitchenGraphic::unselect()
{
  m_selected = false;
}


void
KitchenGraphic::resize(int width, int height)
{
  this->displace(width / 4, 0);
  PlazzaWindow::resize(width * 3 / 4, height - 3);
}
