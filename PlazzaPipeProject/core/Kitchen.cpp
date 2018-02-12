//
// Kitchen.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Fri Apr 25 12:04:43 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:24:54 2014 Bonnet Vivien
//

#include <map>
#include <sstream>

#include "Kitchen.hh"
#include "Process.hpp"

void
Kitchen::letsWork(Kitchen* kitchen)
{
  kitchen->letsCook();
}


Kitchen::Kitchen(const std::string& name, Mutex* mutex,
		 float cookingTime, int cooksByKitchen, int stockReplaceTime) :
  KitchenData(name, cookingTime, cooksByKitchen, stockReplaceTime),
  KitchenGraphic(name, mutex)
{
}

Kitchen::~Kitchen()
{
}


void
Kitchen::update()
{
  std::map<Cook::Status, std::string>	statusNames;
  std::vector<Cook*>::iterator		it;
  std::ostringstream			oss;
  int					i;

  statusNames[Cook::Sleeping]	= "Sleeping";
  statusNames[Cook::Waiting]	= "Waiting";
  statusNames[Cook::Cooking]	= "Cooking";

  m_cursorMutex->lock();
  {
    this->clear();
    {
      this->drawBorder();

      oss.str("");
      oss << "Waiting pizzas : " << m_waitingPizzas.size();
      this->move(2, 2);
      this->print(oss.str());

      i = 0;
      for (it = m_cooks.begin(); it != m_cooks.end(); ++it)
	{
	  ++i; 
	  oss.str("");
	  oss << "Cook  : " << statusNames[(*it)->getStatus()];
	  this->move(2, 3 + i * 2);
	  this->print(oss.str());
	}

    }
    this->display();
  }
  m_cursorMutex->unlock();
}


void
Kitchen::letsCook()
{
  KitchenThread*	regeneration;
  Pizza			pizza;
  Pizza::Pack		pack;

  m_pass.setSide(Fifo::Out);
  this->initCooks();

  regeneration = new KitchenThread(&KitchenData::launchRegenerationLoop, this);
  regeneration->run();
  delete (regeneration);

  try
    {
      while (42)
	{
	  *this >> pack;
	  pizza.unpack(pack);
	  m_waitingPizzas.push(pizza);
	  this->findACookToAwake();
	}
    }
  catch (const FifoException& exception)
    {
      Process<>::interrupt(0);
    }
}
