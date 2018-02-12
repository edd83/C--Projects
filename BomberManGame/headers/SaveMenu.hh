//
// SaveMenu.hh for SaveMenu in /home/volpe_p/rendu/Bomberman/cpp_bomberman/client_graphique
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun  9 15:23:04 2014 volpe
// Last update Tue Jun 10 21:07:33 2014 ovoyan_s
//

#ifndef				SAVEMENU_HH_
# define			SAVEMENU_HH_

/*
**				GENERAL INCLUDES
*/

# include			<vector>

/*
**				MY INCLUDES
*/

# include			"Button.hh"
# include			"Containers.hpp"
# include			"Event.hh"
# include			"Entity.hh"
# include			"Map.hh"
# include			"ModelManager.hh"

class				SaveMenu
{
private:
  GModel			*saveScreen;
  std::vector<Button*>		saveButtons;
  GraphParsing			parseMod;
  int				coordX;
  int				coordY;
  int				menuStep;
  bool		        	(SaveMenu::*stepPtr[3])(int);
  std::string			_nickname;
  Map				_map;

public:
  SaveMenu();
  SaveMenu(int WSizeX, int WSizeY);

  //				Initialization of save Menu buttons / screen
  void				assignArray(float hitbox[4], float minX, float minY,
					    float maxX, float maxY, float sizeX, float sizeY);
  void				butInit(Point3D<float> *cds, float hitbox[4],
					float scale, int index,	const EntityNS::Nature &nature);
  void				initLetterButton(int WSizeX, int WSizeY);
  void				initLetterButtonEnd(int WSizeX, int WSizeY);
  void				initSpecialChar(int WSizeX, int WSizeY);

  //				Updates

  bool				updateSave(int input_id, Event &event_catch);
  void				saveMatrixUpdates();
  void				setMap(Map &);

  //				Getters

  void				saveDraw(gdl::AShader *shader, const gdl::Clock &game_clock,
					 ModelManager &modelManager);
  std::vector<Button*>		getSaveList() const;

  bool				writeLetter(int);
  bool				writeNumber(int);
  bool				writeSpecialChar(int);
  bool			        Enter(Map &);

  int				isSaveButtonHit(int mouseCoordsX, int mouseCoordsY);
  
  ~SaveMenu();
};

#endif				/*	PRINCIPALMENU_HH_	*/
