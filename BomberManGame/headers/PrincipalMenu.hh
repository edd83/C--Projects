//
// PrincipalMenu.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun  3 19:06:52 2014 ovoyan_s
// Last update Fri Jun 13 16:08:54 2014 ovoyan_s
//

#ifndef					PRINCIPALMENU_HH_
# define				PRINCIPALMENU_HH_

/*
**					GENERAL INCLUDES
*/

# include				<sstream>
# include				<vector>

/*
**					MY INCLUDES
*/

# include				"Button.hh"
# include				"Containers.hpp"
# include				"Event.hh"
# include				"GeneratorMap.hh"
# include				"GraphParsing.hh"
# include				"Map.hh"
# include				"ModelManager.hh"

class					PrincipalMenu
{
private:
  GModel				*principalScreen;
  std::vector<Button*>			principalButtons;
  GModel				*loadingScreen;
  std::vector<Button*>			loadingButtons;
  bool					(PrincipalMenu::*stepPtr[5])();
  int					menuStep;
  int					coordX;
  int					coordY;
  GraphParsing				parseLoadFiles;
  Map					*parseMap;
  int					slotId;

  PrincipalMenu();

public:
  PrincipalMenu(int WSizeX, int WSizeY);

  //					Initialization of principal Menu buttons / screen
  void					assignPrincipalButtons(float WSizeX, float WSizeY);
  void					assignLoadingButtons(float WSizeX, float WSizeY);
  void					assignArray(float hitbox[4], float minX, float minY,
						    float maxX, float maxY, float sizeX, float sizeY);
  void					ButtonInitialization(Point3D<float> *cds, float hitbox[4],
							     float scale, int index, int aType);

  //					Drawing General Functions

  void					principalDraw(gdl::AShader *shader,
						      const gdl::Clock &game_clock,
						      ModelManager &modelManager);
  void					loadingDraw(gdl::AShader *shader, const gdl::Clock &game_clock,
						    ModelManager &modelManager);

  //					Update General Functions

  bool					updatePrincipal(int input_id, Event &event_catch);
  bool					updateLoading(int input_id, Event &event_catch);

  //					Principal Menu Update Functions

  void					principalMatrixUpdates();
  int					isPrincipalButtonHit(int mouseCoordsX, int mouseCoordsY);

  //					Loading Menu Update Functions

  void					loadingMatrixUpdates();
  int					isLoadingButtonHit(int mouseCoordsX, int mouseCoordsY);

  //					Principal Menu Buttons Functions

  bool					play();
  bool					resume();
  bool					load();
  bool					options();
  bool					quit();

  //					Getters

  GModel				*getPrincipalScreen() const;
  std::vector<Button*>			getPrincipalList() const;
  GModel				*getLoadingScreen() const;
  std::vector<Button*>			getLoadingList() const;
  int					getMenuStep();
  Map					*getMap();
  std::string				getFileBySlot();
  ~PrincipalMenu();
};

#endif					/*	PRINCIPALMENU_HH_	*/
