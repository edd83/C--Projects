//
// Node.hh for PSU_2014_zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue May 13 15:55:40 2014 ovoyan_s
// Last update Fri Jun  6 11:43:36 2014 volpe
//

#ifndef			NODE_HH_
# define		NODE_HH_

/*
**			GENERAL LIBRARIES
*/

#include		<list>

/*
**			MY INCLUDES
*/

enum			eStateNode
  {
    OPEN,
    CLOSE
  };

class                   Node
{
private:
  int			_parent_index;
  int                   _x;
  int                   _y;
  int                   _weight;
  eStateNode		_state;
  Node();

public:
  Node(int x_coord_to_set, int y_coord_to_set, int index_to_set, int weight_to_set);
  Node			&operator=(const Node &other);
  void                  setParentIndex(int parent_index_to_set);
  void                  setWeight(int weight_to_set);
  void			setCoordX(int);
  void			setCoordY(int);
  void			setState(eStateNode);
  int			getParentIndex() const;
  int                   getCoordX() const;
  int                   getCoordY() const;
  int                   getWeight() const;
  eStateNode		getState() const;
  ~Node();
};

#endif			/*	NODE_HH_	*/
