//
// Button.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri May 16 13:11:06 2014 ovoyan_s
// Last update Tue Jun 10 20:23:12 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"Button.hh"

Button::Button()
{
  this->x_min = 0;
  this->y_min = 0;
  this->x_max = 0;
  this->y_max = 0;
}

Button::Button(float scale, const Point3D<float> &coordinates, int axis_use_to_set)
  : GModel(scale, coordinates, EntityNS::Wall)
{
  this->axis_use = axis_use_to_set;
  this->x_min = 0;
  this->y_min = 0;
  this->x_max = 0;
  this->y_max = 0;
}

Button::Button(float scale, const Point3D<float> &coordinates, int axis_use_to_set,
	       float minX, float minY, float maxX, float maxY, const EntityNS::Nature &buttonNature)
  : GModel(scale, coordinates, buttonNature)
{
  this->axis_use = axis_use_to_set;
  this->x_min = minX;
  this->y_min = minY;
  this->x_max = maxX;
  this->y_max = maxY;
}

void			Button::Resume()
{
  std::cout << "RESUME" << std::endl;
}

void			Button::Quit()
{
  std::cout << "QUIT" << std::endl;
}

void			Button::Save()
{
  std::cout << "SAVE" << std::endl;
}

bool			Button::isHit(int x_mouse_input, int y_mouse_input)
{
  if (x_mouse_input >= this->x_min && x_mouse_input <= this->x_max
      && y_mouse_input >= this->y_min && y_mouse_input <= this->y_max)
    return (true);
  return (false);
}

void			Button::setButtonHitbox(float x_tmin, float y_tmin,
						float x_tmax, float y_tmax)
{
  this->x_min = x_tmin;
  this->y_min = y_tmin;
  this->x_max = x_tmax;
  this->y_max = y_tmax;
}

void			Button::getButtonHitbox(float *x_tmin, float *y_tmin,
						float *x_tmax, float *y_tmax)
{
  *x_tmin = this->x_min;
  *y_tmin = this->y_min;
  *x_tmax = this->x_max;
  *y_tmax = this->y_max;
}

Button::~Button()
{

}
