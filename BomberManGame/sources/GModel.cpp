//
// GModel.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May 28 19:20:49 2014 ovoyan_s
// Last update Fri Jun 13 20:10:33 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"GModel.hh"

GModel::GModel()
{
  this->isClimb = false;
}

GModel::GModel(float scaleToSet, const Point3D<float> &coordinates, const EntityNS::Nature &typeToSet)
{
  this->toShow = true;
  this->typeOfModel = typeToSet;
  this->transMatrix = new glm::mat4(1);
  this->scale = scaleToSet;
  this->coordX = coordinates.GetX();
  this->coordY = coordinates.GetY();
  this->coordZ = coordinates.GetZ();
  this->angleOfRotationX = 0;
  this->setTransformation(glm::translate(this->getTransformation(), glm::vec3(this->coordX,
									      this->coordY,
									      this->coordZ)));
  this->setTransformation(glm::scale(this->getTransformation(), glm::vec3(this->scale, this->scale,
									  this->scale)));
  if (this->typeOfModel == EntityNS::Bombe || this->typeOfModel == EntityNS::Wall
      || this->typeOfModel == EntityNS::Crate || this->typeOfModel == EntityNS::Bonus)
    this->size = 1;
  else if (this->typeOfModel == EntityNS::Player)
    this->size = 1.5;
  this->isClimb = false;
}

void                                    GModel::Draw(gdl::AShader *shader, double clockTime,
						     gdl::Model *objectModel)
{
  if (this->toShow == true)
    objectModel->draw(*shader, *this->transMatrix, clockTime);
}

void					GModel::RotationX(float rotationAngle)
{
  glm::mat4             transformRot;

  this->angleOfRotationX = (this->angleOfRotationX + rotationAngle);
  this->angleOfRotationX = this->angleOfRotationX % 360;
  transformRot = glm::mat4(1);
  if (this->angleOfRotationX < 0)
    this->angleOfRotationX = (this->angleOfRotationX * -1) + 360; 
  this->setTransformation(glm::translate(transformRot, glm::vec3(this->coordX + 0.5, this->coordY + 0.5,
								 this->coordZ + 0.5))
			  * glm::rotate(transformRot, this->angleOfRotationX.getNumber(),
					glm::vec3(1, 0, 0))
			  * glm::scale(transformRot, glm::vec3(this->scale, this->scale, this->scale)));
}

void					GModel::RotationY(float rotationAngle)
{
  glm::mat4             transformRot;

  this->angleOfRotationY = (this->angleOfRotationY + rotationAngle);
  this->angleOfRotationY = this->angleOfRotationY % 360;
  transformRot = glm::mat4(1);
  if (this->angleOfRotationY < 0)
    this->angleOfRotationY = (this->angleOfRotationY * -1) + 360; 
  this->setTransformation(glm::rotate(transformRot, this->angleOfRotationY.getNumber(),
				      glm::vec3(0, 0, 1))
			  * glm::scale(transformRot, glm::vec3(this->scale, this->scale, this->scale))
			  * glm::translate(transformRot, glm::vec3(this->coordX, this->coordY,
								   this->coordZ)));
}

void					GModel::RotationZ(float rotationAngle)
{
  glm::mat4             transformRot;

  this->angleOfRotationZ = (this->angleOfRotationZ + rotationAngle);
  this->angleOfRotationZ = this->angleOfRotationZ % 360;
  transformRot = glm::mat4(1);
  if (this->angleOfRotationZ < 0)
    this->angleOfRotationZ = (this->angleOfRotationZ * -1) + 360; 
  this->setTransformation(glm::rotate(transformRot, this->angleOfRotationZ.getNumber(),
				      glm::vec3(0, 0, 1))
			  * glm::scale(transformRot, glm::vec3(this->scale, this->scale, this->scale))
			  * glm::translate(transformRot, glm::vec3(this->coordX, this->coordY,
								   this->coordZ)));
}

void					GModel::RotationSelfX(float rotationAngle)
{
  glm::mat4             transformRot;

  this->angleOfRotationX = (this->angleOfRotationX + rotationAngle);
  this->angleOfRotationX = this->angleOfRotationX % 360;
  if (this->angleOfRotationX < 0)
    this->angleOfRotationX = (this->angleOfRotationX * -1) + 360; 
  transformRot = this->getTransformation();
  transformRot = glm::translate(transformRot, glm::vec3(1, 1, 0));
  transformRot = glm::rotate<float>(transformRot, rotationAngle, glm::vec3(1, 0, 0));
  transformRot = glm::translate(transformRot, glm::vec3(-1, -1, 0));
  this->setTransformation(transformRot);
}

void					GModel::RotationSelfY(float rotationAngle)
{
  glm::mat4             transformRot;

  this->angleOfRotationY = (this->angleOfRotationY + rotationAngle);
  this->angleOfRotationY = this->angleOfRotationY % 360;
  if (this->angleOfRotationY < 0)
    this->angleOfRotationY = (this->angleOfRotationY * -1) + 360; 

  transformRot = this->getTransformation();
  transformRot = glm::translate(transformRot, glm::vec3(1, 1, 0));
  transformRot = glm::rotate<float>(transformRot, rotationAngle, glm::vec3(0, 1, 0));
  transformRot = glm::translate(transformRot, glm::vec3(-1, -1, 0));
  this->setTransformation(transformRot);
}

void					GModel::RotationSelfZ(float rotationAngle)
{
  glm::mat4             transformRot;

  this->angleOfRotationZ = (this->angleOfRotationZ + rotationAngle);
  this->angleOfRotationZ = this->angleOfRotationZ % 360;
  if (this->angleOfRotationZ < 0)
    this->angleOfRotationZ = (this->angleOfRotationZ * -1) + 360; 
  transformRot = this->getTransformation();
  transformRot = glm::translate(transformRot, glm::vec3(1, 1, 0));
  transformRot = glm::rotate<float>(transformRot, rotationAngle, glm::vec3(0, 0, 1));
  transformRot = glm::translate(transformRot, glm::vec3(-1, -1, 0));
  this->setTransformation(transformRot);
}

void					GModel::itemMove(float lowPoint, float highPoint)
{
  if (isClimb == true)
    this->setCoordY(this->coordY + 0.005);
  else
    this->setCoordY(this->coordY - 0.005);

  if (this->coordY < lowPoint)
    this->isClimb = true;
  else if (this->coordY > highPoint)
    this->isClimb = false;
}

void					GModel::minecraftMove(float lowPoint, float highPoint)
{
  if (isClimb == true)
    this->setCoordY(this->coordY + 0.005);
  else
    this->setCoordY(this->coordY - 0.005);
  this->RotationSelfY(2);

  if (this->coordY < lowPoint)
    this->isClimb = true;
  else if (this->coordY > highPoint)
    this->isClimb = false;
}

/*
**					Setters
*/

void					GModel::setCoordX(float coordToSetX)
{
  this->setTransformation(glm::mat4(1));
  this->setTransformation(glm::translate(this->getTransformation(),
					 glm::vec3(coordToSetX, this->coordY, this->coordZ))
			  * glm::scale(this->getTransformation(), glm::vec3(this->scale,
									    this->scale,
									    this->scale)));
  this->coordX = coordToSetX;
}

void					GModel::setCoordY(float coordToSetY)
{
  this->setTransformation(glm::mat4(1));
  this->setTransformation(glm::translate(this->getTransformation(),
					 glm::vec3(this->coordX, coordToSetY, this->coordZ))
			  * glm::scale(this->getTransformation(), glm::vec3(this->scale,
									    this->scale,
									    this->scale)));
  this->coordY = coordToSetY;
}

void					GModel::setCoordZ(float coordToSetZ)
{
  this->setTransformation(glm::mat4(1));
  this->setTransformation(glm::translate(this->getTransformation(),
					 glm::vec3(this->coordX, this->coordY, coordToSetZ))
			  * glm::scale(this->getTransformation(), glm::vec3(this->scale,
									    this->scale,
									    this->scale)));
  this->coordZ = coordToSetZ;
}

void					GModel::setModelType(const EntityNS::Nature &modelTypeToSet)
{
  this->typeOfModel = modelTypeToSet;
}

void                                    GModel::setTransformation(const glm::mat4 &matrixToUse)
{
  *this->transMatrix = matrixToUse;
}

void					GModel::setCoordMapX(int coordX)
{
  this->coordMapX = coordX;
}

void					GModel::setCoordMapY(int coordY)
{
  this->coordMapY = coordY;
}

void					GModel::setShow(bool showToSet)
{
  this->toShow = showToSet;
}

/*
**					Getters
*/

float					GModel::getCoordX() const
{
  return (this->coordX);
}

float					GModel::getCoordY() const
{
  return (this->coordY);
}

float					GModel::getCoordZ() const
{
  return (this->coordZ);
}

EntityNS::Nature			GModel::getModelType() const
{
  return (this->typeOfModel);
}

glm::mat4                               GModel::getTransformation() const
{
  return (*this->transMatrix);
}

int					GModel::getCoordMapX() const
{
  return (this->coordMapX);
}

int					GModel::getCoordMapY() const
{
  return (this->coordMapY);
}

bool					GModel::getShow() const
{
  return (this->toShow);
}

GModel::~GModel()
{

}
