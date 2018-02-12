//
// InputAction.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 12 18:39:51 2014 ovoyan_s
// Last update Sun Jun 15 21:31:39 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"InputAction.hh"

InputAction::InputAction()
{
  this->mem_ptr[0] = &InputAction::KeyUp;
  this->mem_ptr[1] = &InputAction::KeyDown;
  this->mem_ptr[2] = &InputAction::KeyLeft;
  this->mem_ptr[3] = &InputAction::KeyRight;
  this->mem_ptr[4] = &InputAction::KeyA;
  this->mem_ptr[5] = &InputAction::KeyZ;
  this->mem_ptr[6] = &InputAction::AvRec;
  this->wheelId = 0;
}

bool			InputAction::DoInputAction(int input_id, Scene *scene)
{
  if (input_id >= 2 && input_id <= 7)
    {
      if ((this->*mem_ptr[input_id - 2])(scene) == false)
	return (false);
    }
  if (input_id == 9)
    if ((this->*mem_ptr[6])(scene) == false)
      return (false);    
  return (true);
}

bool			InputAction::KeyUp(Scene *scene)
{
  if (scene->getEyeY() < 40)
    scene->moveEyeY(scene->getEyeY() + 0.5);
  return (true);
}

bool			InputAction::KeyDown(Scene *scene)
{
  if (scene->getEyeY() > 1)
    scene->moveEyeY(scene->getEyeY() - 0.5);
  return (true);
}

bool			InputAction::KeyLeft(Scene *scene)
{
  if (scene->getEyeX() > -30)
    scene->moveEyeX(scene->getEyeX() - 0.5);
  return (true);
}

bool			InputAction::KeyRight(Scene *scene)
{
  if (scene->getEyeX() < 40)
    scene->moveEyeX(scene->getEyeX() + 0.5);
  return (true);
}

bool			InputAction::KeyA(Scene *scene)
{
  if (scene->getEyeZ() < 40)
    scene->moveEyeZ(scene->getEyeZ() + 0.5);
  return (true);
}

bool			InputAction::KeyZ(Scene *scene)
{
  if (scene->getEyeZ() > -30)
    scene->moveEyeZ(scene->getEyeZ() - 0.5);
  return (true);
}

bool			InputAction::AvRec(Scene *scene)
{
  if (this->wheelId == 1)
    {
      if (scene->getEyeY() - 0.5 > 0)
	scene->moveEyeY(scene->getEyeY() - 0.5);
      scene->moveEyeZ(scene->getEyeZ() - 0.5);
    }
  else if (this->wheelId == -1)
    {
      if (scene->getEyeY() + 0.5 < 50)
	scene->moveEyeY(scene->getEyeY() + 0.5);
      scene->moveEyeZ(scene->getEyeZ() + 0.5);
    }
  return (true);
}

bool			InputAction::doInputsPause(int input_id, Event &event_to_use,
						   unsigned int *gameStep, const Pause &pause_actions,
						   gdl::AShader *shader, Scene &scene)
{
  int                                   mouse_coords[2];
  int                                   res_clicMenu;

  if (input_id == 8)
    {
      event_to_use.getMouseCoordPush(&(mouse_coords[0]), &(mouse_coords[1]));
      res_clicMenu = this->clicMenu(*gameStep, pause_actions,
				    mouse_coords[0], mouse_coords[1]);
      if (res_clicMenu == 1)
	{
	  std::cout << "QUIT" << std::endl;
	  return (false);
	}
      else if (res_clicMenu == 2)
	{
	  *gameStep = 1;
	  std::cout << "RESUME" << std::endl;
	  shader->setUniform("view", scene.getInGameTransformation());
	  scene.setIGTrans(glm::lookAt(glm::vec3(scene.getEyeX(), scene.getEyeY(), scene.getEyeZ()),
				       glm::vec3(scene.getEyeX(), scene.getEyeY() - 5,
						 scene.getEyeZ() - 15), glm::vec3(0, 1, 0)));
	  shader->setUniform("view", scene.getInGameTransformation());
	  return (true);
	}
      else if (res_clicMenu == 3)
	*gameStep = 4;
    }
  return (true);
}

bool			InputAction::doInputsInGame(int input_id, Scene &scene,
						    gdl::AShader *shader, const Event &eventToUse)
{
  if (input_id >= 2 && input_id <= 9)
    {
      if (input_id == 2 || input_id == 3)
	{
	  if (this->DoInputAction(input_id, &scene) == false)
	    return (false);
	}
      else if (input_id == 4 || input_id == 5)
	{
	  if (this->DoInputAction(input_id, &scene) == false)
	    return (false);
	}
      else if (input_id == 6 || input_id == 7)
	{
	  if (this->DoInputAction(input_id, &scene) == false)
	    return (false);
	}
      if (input_id == 9)
	{
	  this->wheelId = eventToUse.getMouseWheel();
	  if (this->DoInputAction(input_id, &scene) == false)
	    return (false);
	}
      scene.setIGTrans(glm::lookAt(glm::vec3(scene.getEyeX(), scene.getEyeY(), scene.getEyeZ()),
				   glm::vec3(scene.getEyeX(), scene.getEyeY() - 5,
					     scene.getEyeZ() - 15), glm::vec3(0, 1, 0)));
      shader->setUniform("view", scene.getInGameTransformation());
    }
  return (true);
}

int			InputAction::clicMenu(unsigned int gameStep, const Pause &pause_buttons,
					      int x_mouse_coord, int y_mouse_coord)
{
  if (gameStep == 2 && x_mouse_coord > 0 && y_mouse_coord > 0)
    {
      if (pause_buttons.getQuitButton()->isHit(x_mouse_coord, y_mouse_coord) == true)
	return (1);
      else if (pause_buttons.getResumeButton()->isHit(x_mouse_coord, y_mouse_coord) == true)
	return (2);
      else if (pause_buttons.getSaveButton()->isHit(x_mouse_coord, y_mouse_coord) == true)
	return (3);
    }
  return (0);
}

InputAction::~InputAction()
{

}
