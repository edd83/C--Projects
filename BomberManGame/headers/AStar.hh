//
// AStar.hh for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 20:09:34 2014 ovoyan_s
// Last update Thu Jun 12 14:54:34 2014 volpe
//

#ifndef			ASTAR_HH_
# define		ASTAR_HH_

/*
**			GENERAL LIBRARIES
*/

#include		<list>

/*
**			MY LIBRARIES
*/

# include		"Containers.hpp"
# include		"Node.hh"
# include		"Number.hpp"
# include		"Time.hh"

class			AStar
{
private:
  int			x_start;
  int			y_start;
  std::list<int>	x_ends;
  std::list<int>	y_ends;
  std::string		obstacles;
  int			depart_weight;
  int			end_weight;
  unsigned int		map_size_x;
  unsigned int		map_size_y;
  bool			end_of_path;
  unsigned int		size_of_path;

public:
  AStar();
  AStar(int x_depart, int y_depart, std::list<int> x_ends, std::list<int> y_ends,
	std::string obstacles);
  std::list<Node*>	GivePath(MyStringArray &map);
  Node			*FindArrivalWeight(int start_x, int start_y, int finish_x, int finish_y,
					  const MyStringArray &map, std::list<Node*> &list_node);
  Node			*initializeNodes(Node ***tNode, int start_x, int start_y, int finish_x,
					int finish_y, const MyStringArray &map,
					std::list<Node*> &list_node); 
  void			initFAW(int start_x, int start_y, int finish_x, int finish_y,
				   std::list<Node*> &list_node, Node ***tNode,
				   const MyStringArray &map);
  void			setInList(std::list<Node*> &list_node, Node *parent_node, Node *tNode[4]);
  Node			*ReturnNodeInList(std::list<Node*> &list_node, Node *node_to_use);
  bool			NodeExists(std::list<Node*> &list_node, Node *node_to_add);
  int			getParentIndex(std::list<Node*> &list_node, Node *parent_to_use);
  void			setParent(std::list<Node*> &list_node, Node *parent_to_add);
  void			setChild(std::list<Node*> &list_node, Node *child_to_add, int parent_index);
  bool			IsObstacle(char pos_content);
  bool			IsLimit(int x, int y);
  int			EstimateWeight(int x, int y, int finish_x, int finish_y, char pos_content);
  void			chooseTheGoodPath(std::list<Node*> &list_node, std::list<Node*> &refined_node,
					 int index_to_give);
  std::list<Node*>	FindAllPath(int finish_x, int finish_y, const MyStringArray &map);
  ~AStar();
};

#endif			/*	ASTAR_HH_	*/
