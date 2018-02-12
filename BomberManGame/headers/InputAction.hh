//
// InputAction.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 12 18:21:08 2014 ovoyan_s
// Last update Thu Jun  5 19:50:55 2014 ovoyan_s
//

#ifndef			INPUTACTION_HH_
# define		INPUTACTION_HH_

/*
**			GDL INCLUDES
*/

# include		<AShader.hh>

/*
**			GENERAL INCLUDES
*/

# include		<iostream>
# include		<string>

/*
**			MY INCLUDES
*/

# include		"Event.hh"
# include		"GPlayer.hh"
# include		"Pause.hh"
# include		"Scene.hh"

class			InputAction
{
private:
  bool			(InputAction::*mem_ptr[7])(Scene*);
  int			wheelId;
public:
  InputAction();
  bool			DoInputAction(int input_id, Scene *scene);
  bool			KeyUp(Scene *scene);
  bool			KeyDown(Scene *scene);
  bool			KeyLeft(Scene *scene);
  bool			KeyRight(Scene *scene);
  bool			KeyA(Scene *scene);
  bool			KeyZ(Scene *scene);
  bool			AvRec(Scene *scene);
  int			clicMenu(unsigned int gameStep, const Pause &pause_buttons,
				 int x_mouse_coord, int y_mouse_coord);

  bool			doInputsPause(int input_id, Event &event_to_use,
				      unsigned int *gameStep, const Pause &pause_actions,
				      gdl::AShader *shader, Scene &scene);
  bool			doInputsInGame(int input_id, Scene &scene, gdl::AShader *shader,
				       const Event &eventToUse);
  
  ~InputAction();
};

#endif			/*	INPUTACTION_HH_	*/
