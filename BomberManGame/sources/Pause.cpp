//
// Pause.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 12 19:20:32 2014 ovoyan_s
// Last update Sun Jun 15 17:47:56 2014 Fabien Casoni
//

/*
**			MY INCLUDES
*/

#include		"Pause.hh"

Pause::Pause()
{
}

void			Pause::setQuitButton(float scale, const Point3D<float> &point_to_set,
					     int axis_use_to_set, int w_size_x, int w_size_y)
{
  float			x_min;
  float			y_min;
  float			x_max;
  float			y_max;

  x_min = 170 * w_size_x / 800;
  y_min = 280 * w_size_y / 600;
  x_max = 370 * w_size_x / 800;
  y_max = 450 * w_size_y / 600;
  this->quit_button = new Button(scale, point_to_set, axis_use_to_set);
  this->quit_button->setButtonHitbox(x_min, y_min, x_max, y_max);
}

void			Pause::setResumeButton(float scale, const Point3D<float> &point_to_set,
					       int axis_use_to_set, int w_size_x, int w_size_y)
{
  float			x_min;
  float			y_min;
  float			x_max;
  float			y_max;

  x_min = 300 * w_size_x / 800;
  y_min = 70 * w_size_y / 600;
  x_max = 520 * w_size_x / 800;
  y_max = 250 * w_size_y / 600;
  this->resume_button = new Button(scale, point_to_set, axis_use_to_set);
  this->resume_button->setButtonHitbox(x_min, y_min, x_max, y_max);
}

void			Pause::setSaveButton(float scale, const Point3D<float> &point_to_set,
					     int axis_use_to_set, int w_size_x, int w_size_y)
{
  float			x_min;
  float			y_min;
  float			x_max;
  float			y_max;

  x_min = 450 * w_size_x / 800;
  y_min = 280 * w_size_y / 600;
  x_max = 650 * w_size_x / 800;
  y_max = 450 * w_size_y / 600;
  this->save_button = new Button(scale, point_to_set, axis_use_to_set);
  this->save_button->setButtonHitbox(x_min, y_min, x_max, y_max);
}

Button			*Pause::getQuitButton() const
{
  return (this->quit_button);
}

Button			*Pause::getResumeButton() const
{
  return (this->resume_button);
}

Button			*Pause::getSaveButton() const
{
  return (this->save_button);
}

Pause::~Pause()
{

}
