//
// Scene.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May 28 13:02:54 2014 ovoyan_s
// Last update Sun Jun 15 17:47:48 2014 Fabien Casoni
//

/*
**				MY INCLUDES
*/

#include			"Scene.hh"

Scene::Scene()
{

}

/*
**				SETTERS
*/

void				Scene::setProjection(const glm::mat4 &projectionToSet)
{
  this->projection = projectionToSet;
}

void				Scene::setIGTrans(const glm::mat4 &inGTransformationToSet)
{
  this->inGameTransformation = inGTransformationToSet;
}

void				Scene::setPauseTransformation(const glm::mat4 &pTransformationToSet)
{
  this->pauseTransformation = pTransformationToSet;
}

void				Scene::moveEyeX(float eyeToSetX)
{
  this->eyeX = eyeToSetX;
}

void				Scene::moveEyeY(float eyeToSetY)
{
  this->eyeY = eyeToSetY;
}

void				Scene::moveEyeZ(float eyeToSetZ)
{
  this->eyeZ = eyeToSetZ;
}

void				Scene::setObjectsList(const std::list<GModel*> &objectsListToSet)
{
  this->objectsList = objectsListToSet;
}

/*
**				GETTERS
*/

glm::mat4			Scene::getProjection() const
{
  return (this->projection);
}

glm::mat4			Scene::getInGameTransformation() const
{
  return (this->inGameTransformation);
}

glm::mat4			Scene::getPauseTransformation() const
{
  return (this->pauseTransformation);
}

float				Scene::getEyeX() const
{
  return (this->eyeX);
}

float				Scene::getEyeY() const
{
  return (this->eyeY);
}

float				Scene::getEyeZ() const
{
  return (this->eyeZ);
}

std::list<GModel*>		&Scene::getListOfObjects()
{
  return (this->objectsList);
}

Scene::~Scene()
{

}


