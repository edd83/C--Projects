//
// GPlayer.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Jun  2 19:25:41 2014 ovoyan_s
// Last update Sun Jun 15 20:39:54 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"GPlayer.hh"

GPlayer::GPlayer()
{
}

GPlayer::GPlayer(float scaleToSet, GraphParsing &parseModel, const Point3D<float> &coordinates)
{
  this->typeOfModel = EntityNS::Player;
  this->transMatrix = new glm::mat4;
  this->objectModel = new gdl::Model;
  this->scale = scaleToSet;
  this->coordX = coordinates.GetX();
  this->coordY = coordinates.GetY();
  this->coordZ = coordinates.GetZ();
  this->setTransformation(glm::translate(this->getTransformation(), glm::vec3(this->coordX,
                                                                              this->coordY,
                                                                              this->coordZ)));
  this->setTransformation(glm::scale(this->getTransformation(), glm::vec3(this->scale, this->scale,
                                                                          this->scale)));
  this->size = 1.5;
  this->frameCounter = 0;
  this->direction = GraphPlayer::None;
  this->fptr[0] = &GPlayer::moveLeft;
  this->fptr[1] = &GPlayer::moveRight;
  this->fptr[2] = &GPlayer::moveUp;
  this->fptr[3] = &GPlayer::moveDown;
  if (this->objectModel->load(parseModel.getParsedFile("Player", "modelsFile")) != true)
    throw MyException ("The loading of model is invalid");
}

void			GPlayer::drawPlayer(gdl::AShader *shader, double clockTime)
{
  this->objectModel->draw(*shader, *this->transMatrix, clockTime);
}

void			GPlayer::changeActionToDo(const GraphPlayer::ActionToDo &actionToDo)
{
  if ((this->frameCounter == 1 || this->frameCounter == 0) && this->direction == GraphPlayer::None)
    {
      this->frameCounter = 31;
      if (actionToDo != GraphPlayer::None)
	this->direction = actionToDo;
    }
}

void			GPlayer::doAction(Map &map, int x, int y, std::list<GModel*> &list)
{
  if (this->frameCounter > 0 && this->direction != GraphPlayer::None)
    {
      (this->*fptr[this->direction - 1])(map, x, y, list);
      --this->frameCounter;
    }
  else if (this->frameCounter == 0 && this->direction != GraphPlayer::None)
    {
      if (this->direction == GraphPlayer::Left || this->direction == GraphPlayer::Right)
	{
	  if (this->direction == GraphPlayer::Left && map.getCase(x - 1, y) == '0')
	    this->coordMapX = this->coordMapX - 1;
	  else if (this->direction == GraphPlayer::Right && map.getCase(x + 1, y) == '0')
	    this->coordMapX = this->coordMapX + 1;
	}
      else if (this->direction == GraphPlayer::Up || this->direction == GraphPlayer::Down)
	{
	  if (this->direction == GraphPlayer::Up && map.getCase(x, y - 1) == '0')
	    this->coordMapY = this->coordMapY - 1;
	  else if (this->direction == GraphPlayer::Down && map.getCase(x, y + 1) == '0')
	    this->coordMapY = this->coordMapY + 1;
	}
      this->direction = GraphPlayer::None;
    }
  else
      this->direction = GraphPlayer::None;
}

void			GPlayer::moveLeft(Map &map, int x, int y, std::list<GModel*>&)
{
  if (map.getCase(x - 1, y) == '0')
    {
      this->setCoordX(this->coordX - 0.065);
      if (this->angleOfRotationX.getNumber() != 270)
	this->RotationSelfY(270 - this->angleOfRotationX.getNumber());
    }
}

void			GPlayer::moveRight(Map &map, int x, int y, std::list<GModel*>&)
{
  if (map.getCase(x + 1, y) == '0')
    {
      this->setCoordX(this->coordX + 0.065);
      if (this->angleOfRotationX.getNumber() != 90)
	this->RotationSelfY(90 - this->angleOfRotationX.getNumber());
    }
}

void			GPlayer::moveUp(Map &map, int x, int y, std::list<GModel*>&)
{
  if (map.getCase(x, y - 1) == '0')
    {
      this->setCoordZ(this->coordZ - 0.065);
      if (this->angleOfRotationX.getNumber() != 180)
	this->RotationSelfY(180 - this->angleOfRotationX.getNumber());
    }
}

void			GPlayer::moveDown(Map &map, int x, int y, std::list<GModel*>&)
{ 
  if (map.getCase(x, y + 1) == '0')
    {
      this->setCoordZ(this->coordZ + 0.065);
      if (this->angleOfRotationX.getNumber() != 0)
	this->RotationSelfY(-1 * this->angleOfRotationX.getNumber());
    }
}

void			GPlayer::putBomb(Map &, int x, int y, std::list<GModel*> &bombList)
{
  Point3D<float>	coords(x * 2, 0, y * 2);
  
  bombList.push_back(new GModel(1, coords, EntityNS::Bombe));
}

unsigned int		GPlayer::getFrameCounter() const
{
  return (this->frameCounter);
}

gdl::Model		*GPlayer::getModel() const
{
  return (this->objectModel);
}

GraphPlayer::ActionToDo	GPlayer::getActionToDo() const
{
  return (this->direction);
}

GPlayer::~GPlayer()
{

}
