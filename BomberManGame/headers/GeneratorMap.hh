//
// GeneratorMap.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/merge-client
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun 10 12:38:21 2014 ovoyan_s
// Last update Thu Jun 12 17:10:56 2014 volpe
//

#ifndef					GENERATORMAP_HH_
# define				GENERATORMAP_HH_

/*
**					MY INCLUDES
*/

# include				"Containers.hpp"
# include				"Entity.hh"
# include				"BombermanAI.hh"

class					GeneratorMap
{
private:
  MyStringArray				generatedMap;
  int					mapSizeX;
  int					mapSizeY;
  std::list<std::list<Entity*> >	entitiesList;
  Random				randElement;

public:
  GeneratorMap();
  ~GeneratorMap();

  //					Generation of map

  MyString				genereBorderMap(int width);
  MyString				genereSecondLine(int width);
  MyString				genereThirdLine(int width);
  MyString				genereAlmostLastLine(int width);
  MyString				genereAlmostAlmostLastLine(int width);
  void					genereMap(int lenght, int width);

  //					Generation of list of entities (players / bonus)

  void					generationEntities();
  Player				*generationPlayer(const std::list<Entity*> &playersList, int idPlayer);
  bool					checkPlayersInMap(int coordX, int coordY,
							  std::list<Entity*> playersList);

  //					Getters

  std::list<std::list<Entity*> >	getEntityList() const;
  MyStringArray				getGeneratedMap() const;
  int                       getLength() const;
  int                       getWidth() const;
};

#endif					/*	GENERATORMAP_HH_	*/
