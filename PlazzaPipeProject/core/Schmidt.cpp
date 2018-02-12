//
// Schmidt.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Mon Apr 14 15:48:23 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:22:08 2014 Bonnet Vivien
//

#include "Schmidt.hh"
#include "StringTransformer.hpp"

Schmidt::Schmidt()
{
  m_id = 0;
}

Schmidt::~Schmidt()
{
}


void
Schmidt::setParameters(float cookingTime, int cooksByKitchen, int stockReplaceTime)
{
  m_cookingTime = cookingTime * 1000000.0f;
  m_cooksByKitchen = cooksByKitchen;
  m_stockReplaceTime = stockReplaceTime;
}

Kitchen*
Schmidt::createKitchen(Mutex* mutex)
{
  return (new Kitchen(StringTransformer::castFrom(++m_id), mutex,
		      m_cookingTime, m_cooksByKitchen, m_stockReplaceTime));
}
