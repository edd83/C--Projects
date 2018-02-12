//
// MyGame.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May  7 14:10:12 2014 ovoyan_s
// Last update Sun Jun 15 20:42:06 2014 ovoyan_s
//

#ifndef					MYGAME_HH_
# define				MYGAME_HH_

/*
**					GDL INCLUDES
*/

# include				<AShader.hh>
# include				<Clock.hh>
# include				<Game.hh>
# include				<Input.hh>
# include				<glm/gtc/matrix_transform.hpp>
# include				<glm/core/_detail.hpp>
# include				<Model.hh>
# include				<OpenGL.hh>
# include				<SdlContext.hh>

/*
**					GENERAL INCLUDES
*/

# include				<iostream>
# include				<list>
# include				<map>
# include				<string>
# include				<vector>

/*
**					MY INCLUDES
*/

# include				"Containers.hpp"
# include				"Entity.hh"
# include				"Event.hh"
# include				"GeneratorMap.hh"
# include				"GPlayer.hh"
# include				"BombermanAI.hh"
# include				"GraphParsing.hh"
# include				"InputAction.hh"
# include				"ModelManager.hh"
# include				"MyException.hh"
# include				"Pause.hh"
# include				"PrincipalMenu.hh"
# include				"SaveMenu.hh"
# include				"Scene.hh"
# include				"SoundManager.hh"
# include				"Window.hh"

class					MyGame : public gdl::Game
{
private:
  Window				*window;
  gdl::Clock				game_clock;
  gdl::AShader				*shader;
  unsigned int				gameStep;
  Map					_map;
  Pause					pause_actions;
  Scene					scene;
  int					i;
  bool					(MyGame::*updatePtr[5])(int, Event&);
  void					(MyGame::*drawPtr[5])();
  GraphParsing				parseModel;
  unsigned int				timer;
  PrincipalMenu				*principalMenu;
  SaveMenu				*saveMenu;
  GPlayer				*player;
  ModelManager				*modelManager;
  Player				*_myPlayer;
  SoundManager				mngr;
  bool					sound_paused;
  GModel				*ground;

  MyGame();

public:
  MyGame(int XSizeWindow, int YSizeWindow);
  MyGame(int XSizeWindow, int YSizeWindow, const std::string &name);
  MyGame(const std::string &name);

  void					initializeFP();
  bool					initialize();
  bool					doInputs(int input_id, Event &event_to_use);

  //					updates

  bool					update();
  bool					updatePause(int input_id, Event &event_catch);
  bool					updateInGame(int input_id, Event &event_catch);
  bool					updatePrincipalMenu(int input_id, Event &event_catch);
  bool					updateLoading(int input_id, Event &event_catch);
  bool					updateSave(int input_id, Event &event_catch);

  bool					updateMenu();
  bool					updateBonus();

  void					updateIA();

  //					modifiers

  //  void					modifyDecor(const MyStringArray &beforeMap);
  void					modifyEntities(const std::list<std::list<Entity*> >
						       &beforeEntityList);

  //					draws

  void					draw();
  void					drawInGame();
  void					drawPause();
  void					drawPrincipalMenu();
  void					drawLoading();
  void					drawSave();

  void					StopGame();
  gdl::Clock				GetClock();
  gdl::AShader				*GetShader();
  void					ShaderLoading();
  void					InitializePauseButtons();
  
  //					Creation of objects list

  void					createWallCrates();
  void					createMoveObjects();
  void					setMap(const MyStringArray &mapToSet);

  SoundManager				getSoundManager() const;
  void					sLoad(const std::string &, int);
  void					sPlay(int);
  void					letterM();

  ~MyGame();
};

#endif				/*	MYGAME_HH_	*/
