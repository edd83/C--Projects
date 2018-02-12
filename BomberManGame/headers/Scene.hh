//
// Scene.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May 28 11:19:23 2014 ovoyan_s
// Last update Sat Jun 14 12:18:13 2014 volpe
//

#ifndef				SCENE_HH_
# define			SCENE_HH_

/*
**				GDL INCLUDES
*/

# include			<glm/gtc/matrix_transform.hpp>
# include			<glm/core/_detail.hpp>

/*
**				GENERAL INCLUDES
*/

# include			<iostream>
# include			<string>
# include			<list>

/*
**				MY INCLUDES
*/

# include			"GModel.hh"

class				Scene
{
private:
  glm::mat4			projection;
  glm::mat4			inGameTransformation;
  glm::mat4			pauseTransformation;
  float				eyeX;
  float				eyeY;
  float				eyeZ;
  std::list<GModel*>		objectsList;

public:
  Scene();

  //				Setters

  void				setProjection(const glm::mat4 &projectionToSet);
  void				setIGTrans(const glm::mat4 &iGTransformation);
  void				setPauseTransformation(const glm::mat4 &pTransformation);
  void				moveEyeX(float eyeToSetX);
  void				moveEyeY(float eyeToSetY);
  void				moveEyeZ(float eyeToSetZ);
  void				setObjectsList(const std::list<GModel*> &objectsListToSet);

  //				Getters

  glm::mat4			getProjection() const;
  glm::mat4			getInGameTransformation() const;
  glm::mat4			getPauseTransformation() const;
  float				getEyeX() const;
  float				getEyeY() const;
  float				getEyeZ() const;
  std::list<GModel*>		&getListOfObjects();

  ~Scene();
};

#endif				/*	SCENE_HH_	*/
