//
// Node.cpp for PSU_2013_zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue May 13 15:57:14 2014 ovoyan_s
// Last update Fri Jun  6 11:45:35 2014 volpe
//

/*
**		MY INCLUDES
*/

#include		"../headers/Node.hh"

Node::Node()
{

}

Node::Node(int x_coord_to_set, int y_coord_to_set,
	   int index_to_set, int weight_to_set)
{
  this->_x = x_coord_to_set;
  this->_y = y_coord_to_set;
  this->_weight = weight_to_set;
  this->_parent_index = index_to_set;
}

void		Node::setParentIndex(int parent_index_to_set)
{
  this->_parent_index = parent_index_to_set;
}

void		Node::setWeight(int weight)
{
  this->_weight = weight;
}

void		Node::setCoordX(int x)
{
  this->_x = x;
}

void		Node::setCoordY(int y)
{
  this->_y = y;
}

void		Node::setState(eStateNode state)
{
  this->_state = state;
}

eStateNode		Node::getState() const
{
  return (this->_state);
}

int		Node::getParentIndex() const
{
  return (this->_parent_index);
}

int		Node::getCoordX() const
{
  return (this->_x);
}

int		Node::getCoordY() const
{
  return (this->_y);
}

int		Node::getWeight() const
{
  return (this->_weight);
}

Node		&Node::operator=(const Node &other)
{
  if (this != &other)
    {
      this->_parent_index = other.getParentIndex();
      this->_x = other.getCoordX();
      this->_y = other.getCoordY();
      this->_weight = other.getWeight();
    }
  return (*this);
}
