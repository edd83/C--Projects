//
// PrincipalMenu.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun  3 19:06:36 2014 ovoyan_s
// Last update Sun Jun 15 17:47:52 2014 Fabien Casoni
//

/*
**			MY INCLUDES
*/

# include		"PrincipalMenu.hh"

PrincipalMenu::PrincipalMenu()
{
}

PrincipalMenu::PrincipalMenu(int WSizeX, int WSizeY)
{
  Point3D<float>	coordinates(-1, 0.50, 0);

  this->principalScreen = new GModel(4, coordinates, EntityNS::Menu34);
  this->loadingScreen = new GModel(4, coordinates, EntityNS::Menu34);
  this->assignPrincipalButtons(WSizeX, WSizeY);
  this->assignLoadingButtons(WSizeX, WSizeY);
  this->menuStep = 0;
  this->stepPtr[0] = &PrincipalMenu::play;
  this->stepPtr[1] = &PrincipalMenu::quit;
  this->stepPtr[2] = &PrincipalMenu::options;
  this->stepPtr[3] = &PrincipalMenu::load;
  this->stepPtr[4] = &PrincipalMenu::resume;
  this->parseLoadFiles.parseFile("loadingFile");
  this->parseMap = new Map;
}

void			PrincipalMenu::assignPrincipalButtons(float WSizeX, float WSizeY)
{
  float			hitbox[4];

  this->principalButtons.resize(5);
  this->assignArray(hitbox, 230, 265, 545, 340, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(0.5, 2, 1), hitbox, 0.25, 0, 0);
  this->assignArray(hitbox, 35, 450, 280, 510, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(-3, -0.75, 1), hitbox, 0.25, 1, 0);
  this->assignArray(hitbox, 480, 450, 735, 510, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(4, -0.75, 1), hitbox, 0.25, 2, 0);
  this->assignArray(hitbox, 35, 80, 285, 140, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(-3, 5, 1), hitbox, 0.25, 3, 0);
  this->assignArray(hitbox, 480, 80, 730, 140, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(4, 5, 1), hitbox, 0.25, 4, 0);
}

void			PrincipalMenu::assignLoadingButtons(float WSizeX, float WSizeY)
{ 
  float			hitbox[4];

  this->loadingButtons.resize(9);
  this->assignArray(hitbox, 35, 330, 350, 410, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(-2.5, 1, 1), hitbox, 0.25, 0, 1);
  this->assignArray(hitbox, 35, 230, 350, 315, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(-2.5, 2.5, 1), hitbox, 0.25, 1, 1);
  this->assignArray(hitbox, 35, 135, 350, 215, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(-2.5, 4, 1), hitbox, 0.25, 2, 1);
  this->assignArray(hitbox, 35, 40, 350, 115, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(-2.5, 5.5, 1), hitbox, 0.25, 3, 1);
  this->assignArray(hitbox, 450, 330, 765, 410, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(4, 1, 1), hitbox, 0.25, 4, 1);
  this->assignArray(hitbox, 450, 230, 765, 315, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(4, 2.5, 1), hitbox, 0.25, 5, 1);
  this->assignArray(hitbox, 450, 135, 765, 215, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(4, 4, 1), hitbox, 0.25, 6, 1);
  this->assignArray(hitbox, 450, 40, 765, 115, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(4, 5.5, 1), hitbox, 0.25, 7, 1);
  this->assignArray(hitbox, 240, 485, 560, 560, WSizeX, WSizeY);
  this->ButtonInitialization(new Point3D<float>(0.75, -1.5, 1), hitbox, 0.25, 8, 1);
}

void			PrincipalMenu::assignArray(float hitbox[4], float minX, float minY,
						   float maxX, float maxY, float sizeX, float sizeY)
{
  hitbox[0] = minX * sizeX / 800;
  hitbox[1] = minY * sizeY / 600;
  hitbox[2] = maxX * sizeX / 800;
  hitbox[3] = maxY * sizeY / 600;
}

void			PrincipalMenu::ButtonInitialization(Point3D<float> *cds, float hitbox[4],
							    float scale, int index, int aType)
{
  if (aType == 0)
    {
      this->principalButtons[index] = new Button(scale, *cds, 0, hitbox[0],
						 hitbox[1], hitbox[2], hitbox[3], EntityNS::Menu2510);
      
      this->principalButtons[index]->setShow(true);
      this->principalButtons[index]->RotationSelfX(90);
      this->principalButtons[index]->RotationSelfY(90);
    }
  else if (aType == 1)
    {
      this->loadingButtons[index] = new Button(scale, *cds, 0, hitbox[0],
						 hitbox[1], hitbox[2], hitbox[3], EntityNS::Menu2510);
      
      this->loadingButtons[index]->setShow(true);
      this->loadingButtons[index]->RotationSelfX(90);
      this->loadingButtons[index]->RotationSelfY(90);
    }
}

void			PrincipalMenu::principalDraw(gdl::AShader *shader, const gdl::Clock &game_clock,
						     ModelManager &modelManager)
{
  int			counter;

  counter = -1;
  this->principalScreen->Draw(shader, game_clock.getElapsed(),
			      modelManager.getMod(this->principalScreen));
  while (++counter < 5)
    this->principalButtons[counter]->Draw(shader, game_clock.getElapsed(),
					  modelManager.getMod(this->principalButtons[counter]));
}

void			PrincipalMenu::loadingDraw(gdl::AShader *shader, const gdl::Clock &game_clock,
						   ModelManager &modelManager)
{
  int			counter;

  counter = -1;
  this->loadingScreen->Draw(shader, game_clock.getElapsed(),
			    modelManager.getMod(this->loadingScreen));
  while (++counter < 9)
    this->loadingButtons[counter]->Draw(shader, game_clock.getElapsed(),
					modelManager.getMod(this->loadingButtons[counter]));
}

bool			PrincipalMenu::updatePrincipal(int input_id, Event &event_catch)
{
  int			mouseCoords[2];
  int			hitButton;

  this->menuStep = 0;
  event_catch.getMouseCoord(&mouseCoords[0], &mouseCoords[1]);
  if (mouseCoords[0] != 0 && mouseCoords[1] != 0)
    {
      this->coordX = mouseCoords[0];
      this->coordY = mouseCoords[1];
    }
  this->principalMatrixUpdates();
  if (input_id == 8)
    {
      event_catch.getMouseCoordPush(&mouseCoords[0], &mouseCoords[1]);
      if ((hitButton = isPrincipalButtonHit(mouseCoords[0], mouseCoords[1])) >= 0
	  && hitButton <= 4)
	return ((this->*stepPtr[hitButton])());
    }
  return (true);
}

bool			PrincipalMenu::updateLoading(int input_id, Event &event_catch)
{
  int			mouseCoords[2];
  int			hitButton;

  this->menuStep = 0;
  event_catch.getMouseCoord(&mouseCoords[0], &mouseCoords[1]);
  if (mouseCoords[0] != 0 && mouseCoords[1] != 0)
    {
      this->coordX = mouseCoords[0];
      this->coordY = mouseCoords[1];
    }
  this->loadingMatrixUpdates();
  if (input_id == 8)
    {
      event_catch.getMouseCoordPush(&mouseCoords[0], &mouseCoords[1]);
      if ((hitButton = isLoadingButtonHit(mouseCoords[0], mouseCoords[1])) >= 0
	  && hitButton <= 8)
	{
	  this->slotId = hitButton + 1;
	  if (hitButton == 8)
	    this->menuStep = -5;
	  else
	    {
	      this->load();
	      this->menuStep = -4;
	    }
	}
    }
  return (true);
}

void			PrincipalMenu::principalMatrixUpdates()
{
  int			counter;

  counter = -1;
  this->principalScreen->itemMove(0.25, 0.50);
  this->principalScreen->RotationSelfX(90);
  this->principalScreen->RotationSelfY(90);

  while (++counter < 5)
    {
      if (this->principalButtons[counter]->isHit(this->coordX, this->coordY) == true)
	{
	  if (counter == 0)
	    this->principalButtons[0]->RotationSelfX(2);
	  else
	    this->principalButtons[counter]->RotationSelfZ(2);
	}
    }
}

int			PrincipalMenu::isPrincipalButtonHit(int mouseCoordsX, int mouseCoordsY)
{
  int			counter;

  counter = -1;
  while (++counter < 5)
    {
      if (this->principalButtons[counter]->isHit(mouseCoordsX, mouseCoordsY) == true)
	return (counter);
    }
  return (-1);
}

int			PrincipalMenu::isLoadingButtonHit(int mouseCoordsX, int mouseCoordsY)
{
  int			counter;

  counter = -1;
  while (++counter < 9)
    {
      if (this->loadingButtons[counter]->isHit(mouseCoordsX, mouseCoordsY) == true)
	return (counter);
    }
  return (-1);
}

void			PrincipalMenu::loadingMatrixUpdates()
{
  int			counter;

  counter = -1;
  this->loadingScreen->itemMove(0.25, 0.50);
  this->loadingScreen->RotationSelfX(90);
  this->loadingScreen->RotationSelfY(90);

  while (++counter < 9)
    {
      if (this->loadingButtons[counter]->isHit(this->coordX, this->coordY) == true)
	{
	  if (counter == 8)
	    this->loadingButtons[8]->RotationSelfX(2);
	  else
	    this->loadingButtons[counter]->RotationSelfZ(2);
	}
    }
}

bool			PrincipalMenu::play()
{
  this->menuStep = -1;
  return (true);
}

bool			PrincipalMenu::resume()
{
  this->slotId = 1;
  this->menuStep = 1;
  return (true);
}

bool			PrincipalMenu::load()
{
  this->menuStep = 1;
  return (true);
}

bool			PrincipalMenu::options()
{
  return (false);
}

bool			PrincipalMenu::quit()
{
  return (false);
}

GModel			*PrincipalMenu::getPrincipalScreen() const
{
  return (this->principalScreen);
}

std::vector<Button*>	PrincipalMenu::getPrincipalList() const
{
  return (this->principalButtons);
}

GModel			*PrincipalMenu::getLoadingScreen() const
{
  return (this->loadingScreen);
}

std::vector<Button*>	PrincipalMenu::getLoadingList() const
{
  return (this->loadingButtons);
}

int			PrincipalMenu::getMenuStep()
{
  return (this->menuStep);
}

Map			*PrincipalMenu::getMap()
{
  return (this->parseMap);
}

std::string		PrincipalMenu::getFileBySlot()
{
  MyString		fileIndex("Slot");
  std::stringstream	stm;
  std::string		fileOfLoad;

  stm.clear();
  stm << fileIndex << this->slotId;
  stm >> fileIndex;
  fileOfLoad = this->parseLoadFiles.getParsedFile(stm.str(), "loadingFile");
  return (fileOfLoad);
}

PrincipalMenu::~PrincipalMenu()
{

}
