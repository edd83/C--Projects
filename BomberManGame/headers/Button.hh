//
// Button.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri May 16 13:11:31 2014 ovoyan_s
// Last update Tue Jun 10 20:22:59 2014 ovoyan_s
//

#ifndef					BUTTON_HH_
# define				BUTTON_HH_

/*
**							GDL INCLUDES
*/

# include				<glm/gtc/matrix_transform.hpp>

/*
**							MY INCLUDES
*/

# include				"GModel.hh"
# include		                "Number.hpp"
# include				"Entity.hh"

class							Button : public GModel
{
private:
  float					x_min;
  float					y_min;
  float					x_max;
  float					y_max;
  int					axis_use;
  Button();

public:
  Button(float scale, const Point3D<float> &coordinates, int axis_use_to_set);
  Button(float scale, const Point3D<float> &coordinates, int axis_use_to_set,
	 float minX, float minY, float maxX, float maxY, const EntityNS::Nature &buttonNature);
  void				Resume();
  void				Quit();
  void				Save();
  void				setButtonHitbox(float x_min, float y_min,
									float x_max, float y_max);
  void				getButtonHitbox(float *x_min, float *y_min,
						float *x_max, float *y_max);
  bool				isHit(int x_mouse_input, int y_mouse_input);

  ~Button();
};

#endif							/*	BUTTON_HH_	*/
