//
// Plazza.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sun Apr 13 09:36:39 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:22:25 2014 Bonnet Vivien
//

#include <algorithm>
#include <sstream>

#include "ArgsException.hh"
#include "NcursesException.hh"
#include "ParserException.hh"
#include "Plazza.hh"
#include "Process.hpp"
#include "StringTransformer.hpp"

void
Plazza::waitForKitchen(Plazza* plazza)
{
  plazza->waitKitchen();
}

void
Plazza::launchPlazzaServer(Plazza* plazza)
{
  plazza->launcher(plazza->getPort(), (void (*)(void*, const std::string&))(&Plazza::getClientCommand), plazza);
}

void
Plazza::getClientCommand(Plazza* plazza, const std::string& command)
{
  plazza->analyseCommand(command, "Client", Register::Network);
}


Plazza::Plazza(int argc, char **argv)
{
  PlazzaThread*	server;

  if (argc != ARGS_NUMBER && argc != ARGS_BONUS_NUMBER)
    ArgsException::throwUsage(argv[0]);
  m_schmidt.setParameters(StringTransformer::castTo<float>(argv[1]),
			  StringTransformer::castTo<int>(argv[2]),
			  StringTransformer::castTo<int>(argv[3]));

  if (argc == ARGS_BONUS_NUMBER)
    {
      m_port = argv[4];
      server = new PlazzaThread(&Plazza::launchPlazzaServer, this);
      server->run();
      delete (server);
    }

  m_plazzaEventHandlers[nc::Window::Enter] = &Plazza::getCommand;
  m_plazzaEventHandlers[nc::Window::Up] = &Plazza::scrollUp;
  m_plazzaEventHandlers[nc::Window::Down] = &Plazza::scrollDown;
}

Plazza::~Plazza()
{
  std::list<Kitchen*>::iterator	it;

  for (it = m_kitchenList.begin(); it != m_kitchenList.end(); ++it)
    delete (*it);
}


Kitchen*
Plazza::findFreeKitchen()
{
  std::list<Kitchen*>::iterator	it;
  Kitchen*			kitchen;

  kitchen = NULL;
  for (it = m_kitchenList.begin(); it != m_kitchenList.end(); ++it)
    if ((*it)->canHaveAnotherCommand()
	&& (kitchen == NULL || (*it)->getPizzaNumber() < kitchen->getPizzaNumber()))
      kitchen = *it;

  return (kitchen);
}

Kitchen*
Plazza::createAndPrepareKitchen()
{
  Kitchen*			newKitchen;
  Process<void, Kitchen*>*	child;
  PlazzaThread*			waiting;

  newKitchen = m_schmidt.createKitchen(&m_cursorMutex);
  if (m_kitchenList.empty())
    this->selectKitchen(newKitchen);
  m_kitchenList.push_back(newKitchen);

  child = new Process<void, Kitchen*>(&Kitchen::letsWork, newKitchen);
  child->start();
  delete (child);

  newKitchen->letsWait();

  waiting = new PlazzaThread(&Plazza::waitForKitchen, this);
  waiting->run();
  delete (waiting);

  return (newKitchen);
}

void
Plazza::waitKitchen()
{
  std::ostringstream	oss;
  Kitchen*		kitchen;
  Pizza			pizza;
  Pizza::Pack		pack;

  kitchen = m_kitchenList.back();
  try
    {
      while (42)
	{
	  *kitchen >> pack;
	  pizza.unpack(pack);
	  oss.str("");
	  oss << "Pizza ready : " << pizza.getSizeName() << ' ' << pizza.getName();
	  this->addMessageToRegister(oss.str(), Register::Standart);
	}
    }

  catch (const FifoException& exception)
    {
      this->addMessageToRegister((std::string)("Kitchen broken : ") + exception.what(),
				 Register::Error);
    }
}


void
Plazza::addPizzaToDo(const Pizza::Pack& pack)
{
  Kitchen*	kitchen;

  kitchen = this->findFreeKitchen();
  if (kitchen == NULL)
    kitchen = this->createAndPrepareKitchen();
  *kitchen << pack;
}


void
Plazza::analyseCommand(const std::string& command, const std::string& author, Register::ColorID id)
{
  PizzaString	pizza;
  Pizza::Pack	pack;

  try
    {
      m_packFactory.setCommand(command);
      this->addMessageToRegister((std::string)("Command from ") + author + " !", id);
      while (m_packFactory.getPack(pack) == true)
	addPizzaToDo(pack);
    }
  catch (const ParserException& exception)
    {
      this->addMessageToRegister(author + " : " + exception.what(), Register::Error);
    }
}

void
Plazza::getCommand()
{
  std::string	command;

  command = this->getPromptLine();
  this->analyseCommand(command, INPUT_NAME, Register::Standart);
}

void
Plazza::scrollUp()
{
  std::list<Kitchen*>::iterator	it;

  it = std::find(m_kitchenList.begin(), m_kitchenList.end(), m_kitchen);
  if (it != m_kitchenList.end())
    {
      (*it)->unselect();
      ++it;
      if (it == m_kitchenList.end())
	it = m_kitchenList.begin();
      this->selectKitchen(*it);
    }
}

void
Plazza::scrollDown()
{
  std::list<Kitchen*>::iterator	it;

  it = std::find(m_kitchenList.begin(), m_kitchenList.end(), m_kitchen);
  if (it != m_kitchenList.end())
    {
      (*it)->unselect();
      if (it == m_kitchenList.begin())
	it = m_kitchenList.end();
      --it;
      this->selectKitchen(*it);
    }
}

const char*
Plazza::getPort() const
{
  return (m_port);
}


void
Plazza::getEvent(nc::Window::Event event)
{
  Plazza::Method	plazzaHandler;

  GraphicModule::getEvent(event);
  plazzaHandler = m_plazzaEventHandlers[event];
  if (plazzaHandler != NULL)
    (this->*plazzaHandler)();
}


void
Plazza::launch()
{
  this->loop();
}
