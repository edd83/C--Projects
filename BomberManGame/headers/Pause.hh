//
// Pause.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 12 19:21:44 2014 ovoyan_s
// Last update Tue Jun 10 20:46:43 2014 ovoyan_s
//

#ifndef			PAUSE_HH_
# define		PAUSE_HH_

/*
**			GENERAL INCLUDES
*/

# include		<BasicShader.hh>
# include		<glm/gtc/matrix_transform.hpp>
# include		<glm/core/_detail.hpp>

/*
**			MY INCLUDES
*/

# include		"Button.hh"
# include		"GModel.hh"
# include		"Containers.hpp"

class			Pause
{
private:
  Button		*quit_button;
  Button		*resume_button;
  Button		*save_button;

public:
  Pause();
  void			setQuitButton(float scale, const Point3D<float> &point_to_set,
				      int axis_use_to_set, int w_size_x, int w_size_y);
  void			setResumeButton(float scale, const Point3D<float> &point_to_set,
					int axis_use_to_set, int w_size_x, int w_size_y);
  void			setSaveButton(float scale, const Point3D<float> &point_to_set,
				      int axis_use_to_set, int w_size_x, int w_size_y);
  Button		*getQuitButton() const;
  Button		*getResumeButton() const;
  Button		*getSaveButton() const;

  ~Pause();
};

#endif			/*	PAUSE_HH_	*/
