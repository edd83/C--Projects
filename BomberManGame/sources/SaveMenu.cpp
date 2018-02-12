//
// SaveMenu.cpp for Savemenu in /home/volpe_p/rendu/Bomberman/cpp_bomberman/client_graphique
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun  9 15:18:27 2014 volpe
// Last update Fri Jun 13 18:25:21 2014 ovoyan_s
//

#include	"SaveMenu.hh"

SaveMenu::SaveMenu(int WSizeX, int WSizeY)
{
  Point3D<float>	coordinates(-1, 0.50, 0);

  this->saveScreen = NULL;
  this->saveScreen = new GModel(4, coordinates, EntityNS::Menu34);
  this->saveButtons.resize(42);
  initLetterButton(WSizeX, WSizeY);
  initLetterButtonEnd(WSizeX, WSizeY);
  initSpecialChar(WSizeX, WSizeY);
  this->_nickname = "";
  this->menuStep = 0;
  this->stepPtr[0] = &SaveMenu::writeLetter;
  this->stepPtr[1] = &SaveMenu::writeNumber;
  this->stepPtr[2] = &SaveMenu::writeSpecialChar;
}

SaveMenu::SaveMenu()
{
  this->parseMod.parseFile("modparseModsFile"); 
}

SaveMenu::~SaveMenu()
{
}

void			SaveMenu::setMap(Map &map)
{
  this->_map = map;
}

std::vector<Button*>	SaveMenu::getSaveList() const
{
  return (this->saveButtons);
}

void			SaveMenu::initSpecialChar(int WSizeX, int WSizeY)
{
  float			hitbox[4];

  this->assignArray(hitbox, 95, 475, 150, 520, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-3.3, -1, 1), hitbox, 0.25, 26, EntityNS::Zero);
  this->assignArray(hitbox, 160, 425, 200, 467, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-2.3, -0.2, 1), hitbox, 0.25, 27, EntityNS::One);
  this->assignArray(hitbox, 225, 425, 265, 467, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-1.3, -0.2, 1), hitbox, 0.25, 28, EntityNS::Two);
  this->assignArray(hitbox, 290, 425, 330, 467, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-0.3, -0.2, 1), hitbox, 0.25, 29, EntityNS::Three);
  this->assignArray(hitbox, 260, 475, 300, 520, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-0.8, -1, 1), hitbox, 0.25, 30, EntityNS::Four);
  this->assignArray(hitbox, 490, 475, 530, 520, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(2.6, -1, 1), hitbox, 0.25, 31, EntityNS::Five);
  this->assignArray(hitbox, 460, 425, 500, 467, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(2.1, -0.2, 1), hitbox, 0.25, 32, EntityNS::Six);
  this->assignArray(hitbox, 525, 425, 565, 467, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(3.1, -0.2, 1), hitbox, 0.25, 33, EntityNS::Seven);
  this->assignArray(hitbox, 590, 425, 630, 467, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(4.1, -0.2, 1), hitbox, 0.25, 34, EntityNS::Eight);
  this->assignArray(hitbox, 650, 475, 700, 520, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(5.1, -1, 1), hitbox, 0.25, 35, EntityNS::Nine);
  this->assignArray(hitbox, 370, 510, 410, 560, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(0.9, -1.5, 1), hitbox, 0.25, 36, EntityNS::Del);
  this->assignArray(hitbox, 360, 406, 431, 490, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(0.9, -0.2, 1), hitbox, 0.5, 37, EntityNS::Enter);
  this->assignArray(hitbox, 550, 530, 590, 580, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(3.6, -1.8, 1), hitbox, 0.25, 38, EntityNS::Underscore);
  this->assignArray(hitbox, 200, 530, 240, 580, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-1.8, -1.8, 1), hitbox, 0.25, 39, EntityNS::Point);
  this->assignArray(hitbox, 300, 530, 340, 580, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-0.3, -1.8, 1), hitbox, 0.25, 40, EntityNS::Slash);
  this->assignArray(hitbox, 450, 530, 490, 580, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(2.1, -1.8, 1), hitbox, 0.25, 41, EntityNS::Dash);
}

void			SaveMenu::initLetterButton(int WSizeX, int WSizeY)
{
  float			hitbox[4];

  this->assignArray(hitbox, 90, 45, 145, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-3.3, 5.5, 1), hitbox, 0.25, 0, EntityNS::letterA);
  this->assignArray(hitbox, 137, 107, 188, 153, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-2.6, 4.6, 1), hitbox, 0.25, 1, EntityNS::letterB);
  this->assignArray(hitbox, 190, 45, 230, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-1.9, 5.5, 1), hitbox, 0.25, 2, EntityNS::letterC);
  this->assignArray(hitbox, 233, 107, 277, 153, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-1.2, 4.6, 1), hitbox, 0.25, 3, EntityNS::letterD);
  this->assignArray(hitbox, 280, 45, 320, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-0.5, 5.5, 1), hitbox, 0.25, 4, EntityNS::letterE);
  this->assignArray(hitbox, 329, 107, 366, 153, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(0.2, 4.6, 1), hitbox, 0.25, 5, EntityNS::letterF);
  this->assignArray(hitbox, 380, 45, 410, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(0.9, 5.5, 1), hitbox, 0.25, 6, EntityNS::letterG);
  this->assignArray(hitbox, 423, 107, 459, 153, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(1.6, 4.6, 1), hitbox, 0.25, 7, EntityNS::letterH);
  this->assignArray(hitbox, 475, 45, 535, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(2.3, 5.5, 1), hitbox, 0.25, 8, EntityNS::letterI);
  this->assignArray(hitbox, 512, 107, 555, 153, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(3, 4.6, 1), hitbox, 0.25, 9, EntityNS::letterJ);
  this->assignArray(hitbox, 560, 45, 600, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(3.7, 5.5, 1), hitbox, 0.25, 10, EntityNS::letterK);
  this->assignArray(hitbox, 600, 107, 651, 153, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(4.4, 4.6, 1), hitbox, 0.25, 11, EntityNS::letterL);
  this->assignArray(hitbox, 645, 45, 700, 95, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(5.1, 5.5, 1), hitbox, 0.25, 12, EntityNS::letterM);
}

void			SaveMenu::initLetterButtonEnd(int WSizeX, int WSizeY)
{
  float			hitbox[4];

  this->assignArray(hitbox, 90, 223, 145, 261, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-3.3, 2.9, 1), hitbox, 0.25, 13, EntityNS::letterN);
  this->assignArray(hitbox, 137, 168, 188, 210, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-2.6, 3.7, 1), hitbox, 0.25, 14, EntityNS::letterO);
  this->assignArray(hitbox, 190, 223, 230, 261, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-1.9, 2.9, 1), hitbox, 0.25, 15, EntityNS::letterP);
  this->assignArray(hitbox, 233, 168, 277, 210, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-1.2, 3.7, 1), hitbox, 0.25, 16, EntityNS::letterQ);
  this->assignArray(hitbox, 280, 225, 320, 260, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(-0.5, 2.9, 1), hitbox, 0.25, 17, EntityNS::letterR);
  this->assignArray(hitbox, 329, 168, 366, 210, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(0.2, 3.7, 1), hitbox, 0.25, 18, EntityNS::letterS);
  this->assignArray(hitbox, 370, 225, 410, 260, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(0.9, 2.9, 1), hitbox, 0.25, 19, EntityNS::letterT);
  this->assignArray(hitbox, 423, 168, 459, 210, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(1.6, 3.7, 1), hitbox, 0.25, 20, EntityNS::letterU);
  this->assignArray(hitbox, 465, 225, 505, 260, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(2.3, 2.9, 1), hitbox, 0.25, 21, EntityNS::letterV);
  this->assignArray(hitbox, 512, 168, 555, 210, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(3, 3.7, 1), hitbox, 0.25, 22, EntityNS::letterW);
  this->assignArray(hitbox, 550, 225, 590, 260, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(3.7, 2.9, 1), hitbox, 0.25, 23, EntityNS::letterX);
  this->assignArray(hitbox, 600, 168, 651, 210, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(4.4, 3.7, 1), hitbox, 0.25, 24, EntityNS::letterY);
  this->assignArray(hitbox, 645, 225, 685, 260, WSizeX, WSizeY);
  this->butInit(new Point3D<float>(5.1, 2.9, 1), hitbox, 0.25, 25, EntityNS::letterZ);
}

void			SaveMenu::butInit(Point3D<float> *cds, float hitbox[4],
					  float scale, int index, const EntityNS::Nature &nature)
{
  this->saveButtons[index] = new Button(scale, *cds, 0, hitbox[0], hitbox[1], hitbox[2], hitbox[3],
					nature);
}

void			SaveMenu::saveMatrixUpdates()
{
  int			counter;

  counter = -1;
  this->saveScreen->itemMove(0.25, 0.50);
  this->saveScreen->RotationSelfX(90);
  this->saveScreen->RotationSelfY(90);
  while (++counter < 42)
    if (this->saveButtons[counter]->isHit(this->coordX, this->coordY) == true)
      this->saveButtons[counter]->RotationSelfZ(2);
}

void			SaveMenu::assignArray(float hitbox[4], float minX, float minY,
					      float maxX, float maxY, float sizeX, float sizeY)
{
  hitbox[0] = minX * sizeX / 800;
  hitbox[1] = minY * sizeY / 600;
  hitbox[2] = maxX * sizeX / 800;
  hitbox[3] = maxY * sizeY / 600;
}

void			SaveMenu::saveDraw(gdl::AShader *shader, const gdl::Clock &game_clock,
					   ModelManager &modelManager)
{
  int			counter;

  counter = -1;
  this->saveScreen->Draw(shader, game_clock.getElapsed(),
			 modelManager.getMod(this->saveScreen));
  while (++counter < 42)
    {
      this->saveButtons[counter]->Draw(shader, game_clock.getElapsed(),
				       modelManager.getMod(this->saveButtons[counter]));
    }
}

int			SaveMenu::isSaveButtonHit(int mouseCoordsX, int mouseCoordsY)
{
  int			counter;

  counter = -1;
  while (++counter < 42)
    {
      if (this->saveButtons[counter]->isHit(mouseCoordsX, mouseCoordsY) == true)
	return (counter);
    }
  return (-1);
}

bool			SaveMenu::updateSave(int input_id, Event &event_catch)
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
  this->saveMatrixUpdates();
  if (input_id == 8)
    {
      event_catch.getMouseCoordPush(&mouseCoords[0], &mouseCoords[1]);
      if ((hitButton = isSaveButtonHit(mouseCoords[0], mouseCoords[1])) >= 0
	  && hitButton <= 25)
	return ((this->*stepPtr[0])(hitButton));
      else if (hitButton > 25 && hitButton <= 35)
	return ((this->*stepPtr[1])(hitButton));
      else if (hitButton == 37)
	return (this->Enter(this->_map));
      return ((this->*stepPtr[2])(hitButton));
    }
  return (true);
}

bool			SaveMenu::writeLetter(int id)
{
  this->_nickname += (char)(id + 65);
  return (true);
}

bool			SaveMenu::writeNumber(int id)
{
  this->_nickname += (char)(id+22);
  return (true);
}

bool			SaveMenu::writeSpecialChar(int id)
{
  if (id == 36)
    {
      if (this->_nickname.length() > 0)
	this->_nickname.erase(this->_nickname.length());
    }
  else if (id == 38)
    this->_nickname += '_';
  else if (id == 39)
    this->_nickname += '.';
  else if (id == 40)
    this->_nickname += '/';
  else if (id == 41)
    this->_nickname += '-';
  return (true);
}
 
bool	SaveMenu::Enter(Map &map)
{
  this->_nickname += ".bsf";
  map.saveMap(this->_nickname);
  return (true);
}
