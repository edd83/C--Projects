//
// GraphicModule.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 16:37:44 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:26:42 2014 Bonnet Vivien
//

#include <algorithm>
#include <map>

#include "GraphicModule.hh"

GraphicModule::GraphicModule()
{
  m_kitchen = NULL;

  this->resize();

  m_graphicEventHandlers[nc::Window::Escape] = &GraphicModule::stopLoop;
  m_graphicEventHandlers[nc::Window::Resize] = &GraphicModule::resize;
  m_promptEventHandlers[nc::Window::Del] = &Prompt::deleteChar;
  m_promptEventHandlers[nc::Window::Right] = &Prompt::moveCursorToRight;
  m_promptEventHandlers[nc::Window::Left] = &Prompt::moveCursorToLeft;
}

GraphicModule::~GraphicModule()
{
}


void
GraphicModule::resize()
{
  this->clear();
  this->display();

  this->getWidthAndHeight(m_width, m_height);

  if (m_kitchen != NULL)
    m_kitchen->resize(m_width, m_height);
  m_register.resize(m_width, m_height);
  m_prompt.resize(m_width, m_height);
}


void
GraphicModule::getEvent(nc::Window::Event event)
{
  GraphicModule::Method	graphicHandler;
  Prompt::Method	promptHandler;

  graphicHandler = m_graphicEventHandlers[event];
  promptHandler = m_promptEventHandlers[event];
  if (graphicHandler != NULL)
    (this->*graphicHandler)();
  else if (promptHandler != NULL)
    (m_prompt.*promptHandler)();
  else
    m_prompt.insertChar(event);
}


void
GraphicModule::loop()
{
  nc::Window::Event	event;

  m_loop = true;
  while (m_loop)
    {
      event = m_prompt.getEvent();
      this->getEvent(event);
      m_prompt.update();
    }
}

void
GraphicModule::resetCursor()
{
  m_cursorMutex.lock();
  {
    m_prompt.resetCursor();
  }
  m_cursorMutex.unlock();
}


void
GraphicModule::stopLoop()
{
  m_loop = false;
}

std::string
GraphicModule::getPromptLine()
{
  std::string	message;

  m_cursorMutex.lock();
  {
    message = m_prompt.getCommand();
  }
  m_cursorMutex.unlock();
  
  return (message);
}


void
GraphicModule::addMessageToRegister(const std::string& message, Register::ColorID id)
{
  m_cursorMutex.lock();
  {
    m_register.addMessage(message, id);
    m_register.update();
  }
  m_cursorMutex.unlock();
  this->resetCursor();
}

void
GraphicModule::selectKitchen(KitchenGraphic* kitchen)
{
  m_kitchen = kitchen;
  m_kitchen->select();
  this->getWidthAndHeight(m_width, m_height);
  m_kitchen->resize(m_width, m_height);
  m_kitchen->update();
}
