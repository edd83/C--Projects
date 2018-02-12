//
// Collision.cpp for Collision in /home/volpe_p/rendu/Nibbler/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:15:40 2014 volpe
// Last update Tue Apr  1 16:15:41 2014 volpe
//

#include	"../headers/Game.hh"

Collision::Collision()
{

}

Collision::~Collision()
{

}

bool		Collision::checkSAndS(const std::list<ISnake *> &list) const
{
  ISnake	*tmp;

  if (list.size() != 4)
    {
      tmp = list.front();
      for (std::list<ISnake *>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
	  if (it != list.begin())
	    {
	      if ((tmp->getX() == (*it)->getX()) && (tmp->getY() == (*it)->getY()))
		return (true);
	    }
	}
    }
  return (false);
}

bool		Collision::checkSAndF(const std::list<ISnake *> &slist, std::list<IFood *> &flist) const
{
  ISnake	*head;

  head = slist.front();
  for (std::list<IFood *>::iterator it = flist.begin(); it != flist.end(); ++it)
    {
      if ((*it)->getX() >= head->getX() && (*it)->getX() <= head->getX())
	if ((*it)->getY() >= head->getY() && (*it)->getY() <= head->getY())
	  {
	    flist.erase(it);
	    return (true);
	  }
    }
  return (false);
}

bool		Collision::checkSAndW(const std::list<ISnake *> &list) const
{
  ISnake	*head;

  head = list.front();
  if ((head->getX() > 0 && head->getX() < LWINDOW) && (head->getY() > 0 && head->getY() < HWINDOW))
    return (false);
  return (true);
}

void		Collision::displayCoord(const std::list<ISnake *> &list) const
{
  for (std::list<ISnake *>::const_iterator it = list.begin(); it != list.end(); ++it)
    std::cout << (*it)->getX() << "\t" << (*it)->getY() << std::endl;
}

int		Collision::checkSAndH(const std::list<ISnake *> &slist, std::list<IHole *> &hlist)
{
  ISnake	*head;

  head = slist.front();
  for (std::list<IHole *>::iterator it = hlist.begin(); it != hlist.end(); ++it)
    {
      if (((*it)->getX() == head->getX()) && ((*it)->getY() == head->getY()))
	return (-1);
    }
  return (0);
}
