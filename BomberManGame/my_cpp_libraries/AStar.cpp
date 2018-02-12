// //
// // AStar.cpp for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// // 
// // Made by ovoyan_s
// // Login   <ovoyan_s@epitech.net>
// // 
// // Started on  Mon May  5 19:38:32 2014 ovoyan_s
// Last update Sat Jun 14 10:21:06 2014 ovoyan_s
// //

// /*
// **				MY INCLUDES
// */

#include			"../headers/AStar.hh"

AStar::AStar()
{
  this->depart_weight = 0;
  this->end_weight = 0;
  this->x_start = 0;
  this->y_start = 0;
  this->x_ends.clear();
  this->y_ends.clear();
  this->obstacles.clear();
  this->map_size_x = 0;
  this->map_size_y = 0;
}

AStar::AStar(int x_depart, int y_depart, std::list<int> x_ends, std::list<int> y_ends,
	     std::string obstacles)
{
  this->depart_weight = 0;
  this->end_weight = 0;
  this->x_start = x_depart;
  this->y_start = y_depart;
  if (x_ends.size() <= 0 || y_ends.size() <= 0)
    throw MyException("At least one end lists is empty");
  this->x_ends = x_ends;
  this->y_ends = y_ends;
  this->obstacles = obstacles;
  if (x_ends.size() != y_ends.size())
    throw MyException("The ends sizes are not sames");
  this->map_size_x = 0;
  this->map_size_y = 0;
}

std::list<Node*>		AStar::GivePath(MyStringArray &map)
{
  std::list<int>::iterator	it_x;
  std::list<int>::iterator	it_y;
  std::list<Node*>		ret_list;
  std::list<Node*>		res_list;

  ret_list.clear();
  it_x = this->x_ends.begin();
  it_y = this->y_ends.begin();
  res_list.clear();
  if (map.size() > 0)
    {
      this->map_size_x = map.begin()->size();
      this->map_size_y = map.size();
      while (it_x != this->x_ends.end() && it_y != this->y_ends.end())
	{
	  this->depart_weight = 0;
	  res_list = FindAllPath(*it_x, *it_y, map);
	  if (res_list.size() > 0)
	    {
	      if (ret_list.size() >= res_list.size() || ret_list.size() == 0)
		ret_list = res_list;
	    }
	  ++it_x;
	  ++it_y;
	}
    }
  std::list<Node*>::iterator	it;

  it = ret_list.begin();
  while (it != ret_list.end())
    ++it;
  return (ret_list);
}

Node*				AStar::FindArrivalWeight(int start_x, int start_y,
							 int finish_x, int finish_y,
							 const MyStringArray &map,
							 std::list<Node*> &list_node)
{
  Node				**tNode;
  Node				*ret_node;
  int				counter;
  
  if (size_of_path < 10000)
    {
      if ((tNode = (Node**)malloc(sizeof(*tNode) * 5)) == NULL)
	return (NULL);
      this->size_of_path = this->size_of_path + 1;
      tNode[4] = NULL;
      ret_node = NULL;
      this->initFAW(start_x, start_y, finish_x, finish_y, list_node, &tNode, map);
      counter = 0;
      if (start_x == finish_x && start_y == finish_y)
	this->end_of_path = true;
      while (counter < 4)
	{
	  if (tNode[counter]->getWeight() != -1 && tNode[counter]->getState() == OPEN
	      && this->end_of_path == false)
	    {
	      ret_node = FindArrivalWeight(tNode[counter]->getCoordX(), tNode[counter]->getCoordY(),
					   finish_x, finish_y, map, list_node);
	    }
	  counter = counter + 1;
	}
    }
  return (ret_node);
}

Node				*AStar::initializeNodes(Node ***tNode, int start_x, int start_y,
							int finish_x, int finish_y,
							const MyStringArray &map,
							std::list<Node*> &list_node)
{
  Node			*parent_node;
 
  parent_node = new Node(start_x, start_y, list_node.size(),
			 this->EstimateWeight(start_x, start_y, finish_x, finish_y,
					      map.GetCharAt(start_y, start_x)));

  (*tNode)[0] = new Node(start_x, start_y - 1, 0,
		      this->EstimateWeight(start_x, start_y - 1, finish_x, finish_y,
					   map.GetCharAt(start_y - 1, start_x)));
  (*tNode)[1] = new Node(start_x + 1, start_y, 0,
		      this->EstimateWeight(start_x + 1, start_y, finish_x, finish_y,
					   map.GetCharAt(start_y, start_x + 1)));
  (*tNode)[2] = new Node(start_x, start_y + 1, 0,
		      this->EstimateWeight(start_x, start_y + 1, finish_x, finish_y,
					   map.GetCharAt(start_y + 1, start_x)));
  (*tNode)[3] = new Node(start_x - 1, start_y, 0,
		      this->EstimateWeight(start_x - 1, start_y, finish_x, finish_y,
					   map.GetCharAt(start_y, start_x - 1)));
  return (parent_node);
}

void				AStar::initFAW(int start_x, int start_y, int finish_x, int finish_y,
						  std::list<Node*> &list_node, Node ***tNode,
						  const MyStringArray &map)
{
  int				y;
  Node				*switch_node;
  Node				*parent_node;

  y = 1;
  switch_node = NULL;
  if (!(parent_node = this->initializeNodes(tNode, start_x, start_y, finish_x,
					    finish_y, map, list_node)))
    throw MyException("InitializeNodes failure");
  this->setInList(list_node, parent_node, *tNode);
  while (y < 4)
    {
      if ((*tNode)[y]->getWeight() < (*tNode)[y - 1]->getWeight()
	  && (*tNode)[y]->getWeight() > 0)
	{
	  switch_node = (*tNode)[y];
	  (*tNode)[y] = (*tNode)[y - 1];
	  (*tNode)[y - 1] = switch_node;
	  y = 1;
	}
      y = y + 1;
    }
  
  (*tNode)[0] = this->ReturnNodeInList(list_node, (*tNode)[0]);
  (*tNode)[1] = this->ReturnNodeInList(list_node, (*tNode)[1]);
  (*tNode)[2] = this->ReturnNodeInList(list_node, (*tNode)[2]);
  (*tNode)[3] = this->ReturnNodeInList(list_node, (*tNode)[3]);
}

void				AStar::setInList(std::list<Node*> &list_node, Node *parent_node,
						 Node *tNode[4])
{
  this->setParent(list_node, parent_node);
  this->setChild(list_node, tNode[0], getParentIndex(list_node, parent_node));
  this->setChild(list_node, tNode[1], getParentIndex(list_node, parent_node));
  this->setChild(list_node, tNode[2], getParentIndex(list_node, parent_node));
  this->setChild(list_node, tNode[3], getParentIndex(list_node, parent_node));
}

Node				*AStar::ReturnNodeInList(std::list<Node*> &list_node, Node *node_to_use)
{
  unsigned int			counter;
  std::list<Node*>::iterator	it;
  
  counter = 0;
  it = list_node.begin();
  while (it != list_node.end())
    {
      if (node_to_use->getCoordX() == (*it)->getCoordX()
	  && node_to_use->getCoordY() == (*it)->getCoordY())
	return (*it);
      counter = counter + 1;
      ++it;
    }
  throw MyException("Out of List");
}

bool				AStar::NodeExists(std::list<Node*> &list_node, Node *node_to_use)
{
  unsigned int			counter;
  std::list<Node*>::iterator	it;
  
  counter = 0;
  it = list_node.begin();
  while (it != list_node.end())
    {
      if (node_to_use->getCoordX() == (*it)->getCoordX()
	  && node_to_use->getCoordY() == (*it)->getCoordY())
	return (true);
      counter = counter + 1;
      ++it;
    }
  return (false);
}

int				AStar::getParentIndex(std::list<Node*> &list_node,
							       Node *parent_to_use)
{
  unsigned int			counter;
  std::list<Node*>::iterator	it;
  
  counter = 0;
  it = list_node.begin();
  while (it != list_node.end())
    {
      if (parent_to_use->getCoordX() == (*it)->getCoordX()
	  && parent_to_use->getCoordY() == (*it)->getCoordY())
	return (counter);
      counter = counter + 1;
      ++it;
    }
  return (-1);
}

void				AStar::setParent(std::list<Node*> &list_node, Node *parent_to_add)
{
  unsigned int			counter;
  std::list<Node*>::iterator	it;

  counter = 0;
  it = list_node.begin();
  while (it != list_node.end())
    {
      if (parent_to_add->getCoordX() == (*it)->getCoordX()
	  && parent_to_add->getCoordY() == (*it)->getCoordY())
	{
	  if ((*it)->getState() == OPEN)
	    (*it)->setState(CLOSE);
	  return ;
	}
      counter = counter + 1;
      ++it;
    }
  parent_to_add->setParentIndex(0);
  parent_to_add->setState(CLOSE);
  list_node.push_back(parent_to_add);
}

void				AStar::setChild(std::list<Node*> &list_node, Node *child_to_add,
						int parent_index)
{
  unsigned int			counter;
  std::list<Node*>::iterator	it;

  counter = 0;
  it = list_node.begin();
  while (it != list_node.end())
    {
      if ((int)counter == parent_index)
	(*it)->setState(CLOSE);
      if (child_to_add->getCoordX() == (*it)->getCoordX()
	  && child_to_add->getCoordY() == (*it)->getCoordY())
	return ;
      counter = counter + 1;
      ++it;
    }
  child_to_add->setParentIndex(parent_index);
  child_to_add->setState(OPEN);
  list_node.push_back(child_to_add);
}

bool				AStar::IsObstacle(char pos_content)
{
  unsigned int			counter;

  counter = 0;
  while (counter < this->obstacles.size())
    {
      if (pos_content == this->obstacles[counter])
	return (true);
      counter = counter + 1;
    }
  return (false);
}

bool				AStar::IsLimit(int x, int y)
{
  if (x < 0 || x >= static_cast<int>(map_size_x))
    return (true);
  if (y < 0 || y >= static_cast<int>(map_size_y))
    return (true);
  return (false);
}

int				AStar::EstimateWeight(int x, int y, int finish_x, int finish_y,
						      char pos_content)
{
  Number<int>			weight_x2;
  Number<int>			weight_y2;
  Number<int>			ret_weight;

  if (this->IsObstacle(pos_content) == true || this->IsLimit(x, y) == true)
    ret_weight = -1;
  else
    {
      weight_x2 = finish_x - x;
      weight_y2 = finish_y - y;
      ret_weight = this->size_of_path + weight_x2.getAbsoluteValue() + weight_y2.getAbsoluteValue();
    }
  return (ret_weight.getNumber());
}

void				AStar::chooseTheGoodPath(std::list<Node*> &list_node,
							 std::list<Node*> &refined_node,
							 int index_to_give)
{
  std::list<Node*>::iterator	list_it;
  int				counter;

  counter = 0;
  if (index_to_give > 0)
    {
      list_it = list_node.begin();
      while (list_it != list_node.end())
	{
	  if (counter == index_to_give)
	    {
	      refined_node.push_back(*list_it);
	      if ((*list_it)->getParentIndex() >= 0)
		{
		  chooseTheGoodPath(list_node, refined_node, (*list_it)->getParentIndex());
		  return ;
		}
	    }
	  ++list_it;
	  counter = counter + 1;
	}
    }
}

std::list<Node*>	       	AStar::FindAllPath(int finish_x, int finish_y, const MyStringArray &map)
{
  std::list<Node*>		list_node;
  std::list<Node*>		refined_node;
  std::list<Node*>::iterator	list_it;
  int				counter;

  this->size_of_path = 0;
  this->end_of_path = false;
  FindArrivalWeight(this->x_start, this->y_start, finish_x, finish_y, map, list_node);
  refined_node.clear();

  list_it = list_node.begin();
  counter = 0;
  while (list_it != list_node.end() && ((*list_it)->getCoordX() != finish_x
					|| (*list_it)->getCoordY() != finish_y))
    {
      ++list_it;
      counter = counter + 1;
    }
  this->chooseTheGoodPath(list_node, refined_node, counter);
  refined_node.reverse();
  list_it = refined_node.begin();
  counter = -1;
  while (list_it != refined_node.end() && ++counter < (int)(refined_node.size() - 1))
    ++list_it;
  if ((*list_it)->getCoordX() != finish_x || (*list_it)->getCoordY() != finish_y)
    refined_node.clear();
  return (refined_node);
}

AStar::~AStar()
{

}
