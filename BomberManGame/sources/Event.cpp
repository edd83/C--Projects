//
// Event.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 12 17:55:48 2014 ovoyan_s
// Last update Sun Jun 15 16:05:44 2014 ovoyan_s
//

/*
**				GENERAL INCLUDES
*/

#include			"Event.hh"

Event::Event()
{
  this->eventId = 0;
  this->mouseCoordinates[0] = 0;
  this->mouseCoordinates[1] = 0;
  this->mouseWheel = 0;
}

Event::Event(gdl::SdlContext *sdl_context)
{
  sdl_context->updateInputs(this->game_input);
}

int				Event::ret_input_id()
{
  int                           counter;

  counter = 0;
  this->mem_ptr[0] = &Event::input_quit;
  this->mem_ptr[1] = &Event::input_esc;
  this->mem_ptr[2] = &Event::key_up;
  this->mem_ptr[3] = &Event::key_down;
  this->mem_ptr[4] = &Event::key_left;
  this->mem_ptr[5] = &Event::key_right;
  this->mem_ptr[6] = &Event::key_a;
  this->mem_ptr[7] = &Event::key_e;
  this->mem_ptr[8] = &Event::MouseWheel;
  this->mem_ptr[9] = &Event::key_q;
  this->mem_ptr[10] = &Event::key_d;
  this->mem_ptr[11] = &Event::key_z;
  this->mem_ptr[12] = &Event::key_s;
  this->mem_ptr[13] = &Event::key_space;
  this->mem_ptr[14] = &Event::key_m;
  this->mem_ptr[15] = &Event::key_l;
  while (counter < 16)
    {
      if ((this->*mem_ptr[counter])() == true)
        {
	  if (counter >= 8)
	    counter = counter + 1;
	  this->eventId = counter;
	  return (1);
	}
      counter = counter + 1;
    }
  if (this->leftMouseCoordPush() == true)
    {
      this->eventId = 8;
      return (1);
    }
  return (0);
}

bool				Event::input_quit()
{
  if (this->game_input.getInput(SDL_QUIT) == true)
    return (true);
  return (false);
}

bool				Event::input_esc()
{
  if (this->game_input.getKey(SDLK_ESCAPE) == true)
    return (true);
  return (false);
}

bool				Event::key_up()
{
  if (this->game_input.getKey(SDLK_UP) == true)
    return (true);
  return (false);
}

bool				Event::key_down()
{
  if (this->game_input.getKey(SDLK_DOWN) == true)
    return (true);
  return (false);
}

bool				Event::key_left()
{
  if (this->game_input.getKey(SDLK_LEFT) == true)
    return (true);
  return (false);
}

bool				Event::key_right()
{
  if (this->game_input.getKey(SDLK_RIGHT) == true)
    return (true);
  return (false);
}

bool				Event::key_a()
{
  if (this->game_input.getKey(SDLK_a) == true)
    return (true);
  return (false);
}

bool				Event::key_e()
{
  if (this->game_input.getKey(SDLK_e) == true)
    return (true);
  return (false);
}

bool				Event::key_z()
{
  if (this->game_input.getKey(SDLK_z) == true)
    return (true);
  return (false);
}

bool				Event::key_s()
{
  if (this->game_input.getKey(SDLK_s) == true)
    return (true);
  return (false);
}

bool				Event::key_q()
{
  if (this->game_input.getKey(SDLK_q) == true)
    return (true);
  return (false);
}

bool				Event::key_d()
{
  if (this->game_input.getKey(SDLK_d) == true)
    return (true);
  return (false);
}

bool				Event::key_space()
{
  if (this->game_input.getKey(SDLK_SPACE) == true)
    return (true);
  return (false);
}

bool				Event::key_m()
{
  if (this->game_input.getKey(SDLK_m) == true)
    return (true);
  return (false);
}

bool				Event::key_l()
{
  if (this->game_input.getKey(SDLK_l) == true)
    return (true);
  return (false);
}

bool				Event::leftMouseCoordPush()
{
  glm::ivec2			l;

  if (this->game_input.getInput(SDL_BUTTON_LEFT) == true)
    {
      l = this->game_input.getMousePosition();
      (this->mouseCoordinatesPush)[0] = l[0];
      (this->mouseCoordinatesPush)[1] = l[1];
      return (true);
    }
  return (false);
}

bool				Event::MouseWheel()
{
  glm::ivec2			l;

  l = this->game_input.getMouseWheel();
  if (l[1] != 0)
    {
      this->mouseWheel = l[1];
      return (true);
    }
  return (false);
}

void				Event::setEvent(int id_to_set)
{
  this->eventId = id_to_set;
}

int				Event::getEvent() const
{
  return (this->eventId);
}

void				Event::getMouseCoordPush(int *coord_x, int *coord_y)
{
  *coord_x = (this->mouseCoordinatesPush)[0];
  *coord_y = (this->mouseCoordinatesPush)[1];
}

void				Event::getMouseCoord(int *coord_x, int *coord_y)
{
  glm::ivec2			l;

  l = this->game_input.getMousePosition();
  *coord_x = l[0];
  *coord_y = l[1];
}

int				Event::getMouseWheel() const
{
  return (this->mouseWheel);
}

Event::~Event()
{

}
