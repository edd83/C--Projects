//
// MyGame.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May  7 14:12:57 2014 ovoyan_s
// Last update Sun Jun 15 20:54:25 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"MyGame.hh"

MyGame::MyGame()
{
  Random		rand;

  this->parseModel.parseFile("modelsFile");
  this->window = new Window(800, 600);
  this->gameStep = 0;
  this->initializeFP();
  this->_myPlayer = NULL;
  this->sound_paused = false;
  rand.Srandom();
}

MyGame::MyGame(int sizeToSetX, int sizeToSetY)
{
  this->parseModel.parseFile("modelsFile");
  this->window = new Window(sizeToSetX, sizeToSetY);
  this->gameStep = 0;
  this->initializeFP();
  this->_myPlayer = NULL;
}

MyGame::MyGame(int sizeToSetX, int sizeToSetY, const std::string &nameToSet)
{
  this->parseModel.parseFile("modelsFile");
  this->window = new Window(sizeToSetX, sizeToSetY, nameToSet);
  this->gameStep = 0;
  this->initializeFP();
  this->_myPlayer = NULL;
}

MyGame::MyGame(const std::string &nameToSet)
{
  this->parseModel.parseFile("modelsFile");
  this->window = new Window(nameToSet);
  this->gameStep = 0;
  this->initializeFP();
  this->_myPlayer = NULL;
}

void					MyGame::initializeFP()
{
  this->updatePtr[0] = &MyGame::updatePrincipalMenu;
  this->updatePtr[1] = &MyGame::updateInGame;
  this->updatePtr[2] = &MyGame::updatePause;
  this->updatePtr[3] = &MyGame::updateLoading;
  this->updatePtr[4] = &MyGame::updateSave;
    
  this->drawPtr[0] = &MyGame::drawPrincipalMenu;
  this->drawPtr[1] = &MyGame::drawInGame;
  this->drawPtr[2] = &MyGame::drawPause;
  this->drawPtr[3] = &MyGame::drawLoading;
  this->drawPtr[4] = &MyGame::drawSave;
  this->i = 0;
}

bool					MyGame::initialize()
{
  this->window->getSDLContext()->start(this->window->getSizeX(), this->window->getSizeY(),
				       this->window->getName());
  glEnable(GL_DEPTH_TEST);
  this->ShaderLoading();
  this->scene.setProjection(static_cast<glm::mat4>
			    (glm::perspective(70.0, static_cast<double>(this->window->getSizeX())
					      / static_cast<double>(this->window->getSizeY()),
					      0.1, 300.0)));

  this->scene.moveEyeX(7.49);
  this->scene.moveEyeY(9.99);
  this->scene.moveEyeZ(30.99);
  this->scene.setIGTrans(glm::lookAt(glm::vec3(this->scene.getEyeX(), this->scene.getEyeY(),
					       this->scene.getEyeZ()),
				     glm::vec3(this->scene.getEyeX(),this->scene.getEyeY() - 5,
					       this->scene.getEyeZ() - 15), glm::vec3(0, 1, 0)));
  this->scene.setPauseTransformation(glm::lookAt(glm::vec3(1, 2, 7.5), glm::vec3(1, 2, 0),
						 glm::vec3(0, 1, 0)));

  this->shader->bind();
  this->shader->setUniform("view", this->scene.getPauseTransformation());
  this->shader->setUniform("projection", this->scene.getProjection());
  this->modelManager = new ModelManager;
  this->principalMenu = new PrincipalMenu(this->window->getSizeX(), this->window->getSizeY());
  this->saveMenu = new SaveMenu(this->window->getSizeX(), this->window->getSizeY());
  this->mngr.loadMainStream("Sounds/corsica.mp3");
  this->mngr.loadSound("Sounds/explode.wav");
  this->mngr.loadSound("Sounds/bomb.wav");
  this->mngr.loadSound("Sounds/powerup.wav");
  this->mngr.loadSound("Sounds/explose_break.mp3");
  this->mngr.play(0);
  InitializePauseButtons();
  return (true);
}

void					MyGame::InitializePauseButtons()
{
  Point3D<float>			coord_quit(-2, 0, 0);
  Point3D<float>			coord_resume(0, 3, 0);
  Point3D<float>			coord_save(2, 0, 0);
  
  this->pause_actions.setQuitButton(1, coord_quit, 0, this->window->getSizeX(),
				    this->window->getSizeY());
  this->pause_actions.setResumeButton(1, coord_resume, 1, this->window->getSizeX(),
				      this->window->getSizeY());
  this->pause_actions.setSaveButton(1, coord_save, 2, this->window->getSizeX(),
				    this->window->getSizeY());
}

void					MyGame::createWallCrates()
{
  float					counterY;
  float					counterX;
  float					scale;
  std::list<std::string>::iterator	it;
  std::list<GModel*>			objectsList;
  Point3D<float>			objectCoords(0, 0, 0);
  GModel				*modelToAdd;
  
  scale = 1;
  it = this->_map.getMap()->begin();
  counterY = -1;
  while (it != this->_map.getMap()->end()
	 && ++counterY < this->_map.getMap()->size())
    {
      std::string			lineMap;

      counterX = -1;
      lineMap = *it;
      while (++counterX < lineMap.size())
	{
	  objectCoords.SetCoordinates(counterX * 2, 0,
				      counterY * 2);
	  if (lineMap[counterX] == '1')
	    modelToAdd = new GModel(scale, objectCoords, EntityNS::Wall);
	  else if (lineMap[counterX] == '2')
	    modelToAdd = new GModel(scale, objectCoords, EntityNS::Crate);
	  modelToAdd->setCoordMapX(counterX);
	  modelToAdd->setCoordMapY(counterY);
	  objectsList.push_back(modelToAdd);
	}
      ++it;
    }
  this->scene.setObjectsList(objectsList);
}

// void						MyGame::modifyDecor(const MyStringArray &beforeMap)
// {
//   std::list<GModel*>::iterator			it;  
//   std::list<GModel*>::iterator			itEnd;
//   std::list<std::string>::const_iterator	strBeforeMap;
//   std::string					lineBeforeMap;
//   int						counterY;
//   int						counterX;
//   std::list<GModel*>				listToChange;

//   it = listToChange.begin();
//   itEnd = listToChange.end();
//   strBeforeMap = beforeMap.begin();
//   counterY = -1;
//   if (listToChange.size() > 0)
//     {
//       while (++counterY < static_cast<int>(beforeMap.size()) &&  strBeforeMap != beforeMap.end()
// 	     && it != itEnd)
// 	{
// 	  counterX = -1;
// 	  lineBeforeMap = *strBeforeMap;
// 	  while (++counterX < static_cast<int>(lineBeforeMap.size()) && it != itEnd)
// 	    {
// 	      if (lineBeforeMap[counterX] != '0')
// 		{
// 		  if (it != itEnd && *it != NULL && (*it)->getShow() == true)
// 		    {
// 		      if ((*it)->getCoordMapX() != counterX || (*it)->getCoordMapY() != counterY)
// 			(*it)->setShow(false);
// 		    }
// 		  else if (it != itEnd)
// 		    ++it;
// 		}
// 	    }
// 	  ++strBeforeMap;
// 	}
//     }
// }

void						MyGame::createMoveObjects()
{
  std::list<std::list<Entity*> >::iterator	it;
  std::list<Entity*>::iterator			entIt;
  std::list<GModel*>				objectsList;
  GModel					*modelToSet;
  Point3D<float>				objectCoords(0, 0, 0);
  float						scale;
  int						modelId;
  bool						isPlayer;

  scale = 1;
  objectsList = this->scene.getListOfObjects();
  it = this->_map.getListEntity()->begin();
  isPlayer = false;
  while (it != this->_map.getListEntity()->end())
    {
      entIt = (*it).begin();
      while (entIt != (*it).end())
	{
	  if ((*entIt)->getEntity() != EntityNS::NoNature)
	    {
	      objectCoords.SetCoordinates((*entIt)->getX() * scale * (2 / scale), 0,
					  (*entIt)->getY() * scale * (2 / scale));
	      if ((*entIt)->getEntity() == EntityNS::Bonus)
		{
		  objectCoords.SetCoordinates(objectCoords.GetX() + scale / 2, 0.33,
					      objectCoords.GetZ() + scale / 2);
		  modelToSet = new GModel(scale / 1.5, objectCoords, EntityNS::Bonus);
		}
	      else if ((*entIt)->getEntity() == EntityNS::Player)
		{
		  objectCoords.SetCoordinates(objectCoords.GetX(), 0,
					      objectCoords.GetZ());
		  modelToSet = new GPlayer(scale / 200, this->parseModel, objectCoords);
		  if (isPlayer == false)
		    this->player = static_cast<GPlayer*>(modelToSet);
		  isPlayer = true;
		}
	      else if ((*entIt)->getEntity() == EntityNS::Bombe)
		{
		  modelToSet = new GModel(scale, objectCoords, EntityNS::Bombe);
		}
	      modelToSet->setCoordMapX((*entIt)->getX());
	      modelToSet->setCoordMapY((*entIt)->getY());
	      objectsList.push_back(modelToSet);
	      ++modelId;
	    }
	  ++entIt;
	}
      ++it;
    }
  Point3D<float>		coordNull(-50, -20, -50);
  Point3D<float>		coordWall(50, -20, -50);
  GModel			*wall;

  this->ground = new GModel(200, coordNull, EntityNS::Menu34); 
  wall = new GModel(200, coordWall, EntityNS::Menu34);
  wall->RotationSelfX(90);
  objectsList.push_back(this->ground);
  objectsList.push_back(wall);
  this->scene.setObjectsList(objectsList);
}

bool					MyGame::doInputs(int input_id, Event &event_to_use)
{
  InputAction                           input_action;

  if (this->gameStep == 2)
    return (input_action.doInputsPause(input_id, event_to_use,
				       &this->gameStep, this->pause_actions,
				       this->shader, this->scene));
  return (input_action.doInputsInGame(input_id, this->scene, this->shader,
				      event_to_use));
}

 /*
 **					Updates
 */

bool					MyGame::update()
{
  Event					event_catch(this->window->getSDLContext());
  int					input_id;

  input_id = -1;
  this->window->getSDLContext()->updateClock(this->game_clock);
  if ((input_id = event_catch.ret_input_id()) > 0)
    if ((input_id = event_catch.getEvent()) == 0)
      return (false);
  this->timer = this->timer + 1;
  return ((this->*updatePtr[this->gameStep])(input_id, event_catch));
}

bool					MyGame::updatePause(int input_id, Event &event_catch)
{
  if (input_id > 0)
    {
      if (input_id == 1)
	{
	  this->gameStep = 1;
	  this->shader->setUniform("view", this->scene.getInGameTransformation());
	}
      else
	if (this->doInputs(input_id, event_catch) == false)
	  return (false);
    }
  this->updateMenu();
  return (true);
}

bool						MyGame::updateInGame(int input_id, Event &event_catch)
{
  std::list<GModel*>::iterator			it;
  std::list<GModel*>::iterator			endIt;
  std::list<GModel*>				listOfModels;
  std::list<std::list<Entity*> >::iterator	entityList;

  listOfModels = this->scene.getListOfObjects(); 
  if (input_id > 0)
    {
      if (input_id == 1)
	{
	  this->gameStep = 2;
	  this->shader->setUniform("view", this->scene.getPauseTransformation());
	}
      else if (input_id >= 10 && input_id <= 13)
	this->player->changeActionToDo(static_cast<GraphPlayer::ActionToDo>(input_id - 9));
      else if (input_id == 14)
	{
	  entityList = this->_map.getListEntity()->begin();
	  ++entityList;
	  if ((*entityList).begin() != (*entityList).end())
	    {
	      std::list<Entity*>		 l;
	      Player				*play;

	      play = dynamic_cast<Player*>(*(*entityList).begin());
	      if (play == NULL)
		std::cout << "LOL" << std::endl;
	      //play->setBomb(this->_map, this->scene.getListOfObjects());
	    }
	}
      else
	if (this->doInputs(input_id, event_catch) == false)
	  return (false);
    }
  this->updateIA();
  it = listOfModels.begin();
  while (it != listOfModels.end())
    {
      if ((*it)->getModelType() == EntityNS::Player)
	{
	  static_cast<GPlayer*>((*it))->doAction(this->_map, (*it)->getCoordMapX(), 
						 (*it)->getCoordMapY(), this->scene.getListOfObjects());
	}
      ++it;
    }
  if (input_id == 15)
    this->letterM();
  this->updateBonus();
  this->mngr.update();
  return (true);
}


void						MyGame::updateIA()
{
  std::list<Entity*>::iterator			it;
  std::list<Entity*>				lll;
  Player					*playerToUse;
  BombermanAI					*aiToUse;
  MyStringArray					beforeMap;

  beforeMap = static_cast<MyStringArray>(*this->_map.getMap());
  lll = this->_map.getPlayerList();
  it = lll.begin();
  if (it != lll.end())
    ++it;
  while (it != lll.end())
    {
      playerToUse = static_cast<Player*>(*it);
      if (playerToUse->getId() == 2)
	this->_myPlayer = playerToUse;
      if (playerToUse->getId() >= 3)
	{
	  aiToUse = static_cast<BombermanAI*>(playerToUse);
	  aiToUse->start(this->_map, this->scene.getListOfObjects());
	}
      ++it;
    }
  lll = this->_map.getBombList();
  it = lll.begin();
  // while (it != lll.end())
  //   {
  //     Bombe			*bombe = static_cast<Bombe*>(*it);

  //     bombe->decrementTimer();
  //     if (bombe->getTimer() == 0)
  // 	bombe->explose(this->_map, this->scene.getListOfObjects());
  //     ++it;
  //     }
  //  this->modifyDecor(beforeMap);
}

bool					MyGame::updatePrincipalMenu(int input_id, Event &event_catch)
{
  GeneratorMap				generatedMap;
  Random				rand;

  if (this->principalMenu->updatePrincipal(input_id, event_catch) == false)
    return (false);
  if (this->principalMenu->getMenuStep() != 0)
    {
      this->gameStep += this->principalMenu->getMenuStep() + 2; 
      if (this->gameStep == 1)
	{
	  generatedMap.genereMap(rand.GetRandomRN(20) + 7, rand.GetRandomRN(20) + 7);
	  generatedMap.generationEntities();
	  this->_map.setMap(generatedMap.getGeneratedMap());
	  this->_map.setEntityList(generatedMap.getEntityList());
	  this->createWallCrates();
	  this->createMoveObjects();
	  this->shader->setUniform("view", this->scene.getInGameTransformation());
	  this->shader->setUniform("projection", this->scene.getProjection());	 
	}
    }
  return (true);
}

bool					MyGame::updateLoading(int input_id, Event &event_catch)
{
  if (this->principalMenu->updateLoading(input_id, event_catch) == false)
    return (false);
  if (this->principalMenu->getMenuStep() != 0)
    {
      this->gameStep += this->principalMenu->getMenuStep() + 2; 
      if (this->gameStep == 1)
	{
	  this->_map.loadMap(this->principalMenu->getFileBySlot());
	  this->createWallCrates();
	  this->createMoveObjects();
	  this->shader->setUniform("view", this->scene.getInGameTransformation());
	  this->shader->setUniform("projection", this->scene.getProjection());
	}
    }
  return (true);
}

bool					MyGame::updateSave(int input_id, Event &event_catch)
{
  if (input_id == 1)
    this->gameStep = 2;
  else
    {
      this->saveMenu->setMap(this->_map);
      this->saveMenu->updateSave(input_id, event_catch);
    }
  return (true);
}

void					MyGame::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  (this->*drawPtr[this->gameStep])();
  this->window->getSDLContext()->flush();
}

void					MyGame::drawInGame()
{
  std::list<GModel*>		listToUse;
  std::list<GModel*>::iterator	it;

  listToUse = this->scene.getListOfObjects();
  it = listToUse.begin();
  while (it != listToUse.end())
    {
      if ((*it)->getModelType() == EntityNS::Player)
	static_cast<GPlayer*>(*it)->drawPlayer(this->shader, this->game_clock.getElapsed());
      else
	(*it)->Draw(this->shader, this->game_clock.getElapsed(),
		    this->modelManager->getMod(*it));
      ++it;	  
    }
  this->shader->bind();
}

void					MyGame::drawPause()
{
  this->pause_actions.getQuitButton()->Draw(this->shader, this->game_clock.getElapsed(),
					    this->modelManager->getMod(this->pause_actions.getQuitButton()));
  this->pause_actions.getResumeButton()->Draw(this->shader, this->game_clock.getElapsed(),
					      this->modelManager->getMod(this->pause_actions.getResumeButton()));
  this->pause_actions.getSaveButton()->Draw(this->shader, this->game_clock.getElapsed(),
					    this->modelManager->getMod(this->pause_actions.getSaveButton()));
}

void					MyGame::drawPrincipalMenu()
{
  this->principalMenu->principalDraw(this->shader, this->game_clock, *this->modelManager);
}

void					MyGame::drawLoading()
{
  this->principalMenu->loadingDraw(this->shader, this->game_clock, *this->modelManager);
}

void					MyGame::drawSave()
{
  this->saveMenu->saveDraw(this->shader, this->game_clock, *this->modelManager);
}

bool					MyGame::updateMenu()
{
  this->pause_actions.getQuitButton()->RotationSelfX(2);
  this->pause_actions.getQuitButton()->RotationSelfY(2);
  this->pause_actions.getResumeButton()->RotationSelfY(2);
  this->pause_actions.getResumeButton()->RotationSelfZ(2);
  this->pause_actions.getSaveButton()->RotationSelfZ(2);
  this->pause_actions.getSaveButton()->RotationSelfX(2);
  return (true);
}

bool					MyGame::updateBonus()
{
  std::list<GModel*>			objectsList;
  std::list<GModel*>::iterator		it;

  objectsList = this->scene.getListOfObjects();
  it = objectsList.begin();
  while (it != objectsList.end())
    {
      if ((*it)->getModelType() == EntityNS::Bonus)
	(*it)->minecraftMove(0.25, 0.50);
      ++it;
    }
  return (true);
}

gdl::Clock				MyGame::GetClock()
{
  return (this->game_clock);
}

void					MyGame::StopGame()
{
  this->window->getSDLContext()->stop();
}

gdl::AShader				*MyGame::GetShader()
{
  return (this->shader);
}

void					MyGame::ShaderLoading()
{
  this->shader = new gdl::BasicShader();
  if (!this->shader->load("basic.fp", GL_FRAGMENT_SHADER)
      || !this->shader->load("basic.vp", GL_VERTEX_SHADER)
      || !this->shader->build())
    throw MyException("Shader Error");
}

void					MyGame::setMap(const MyStringArray &mapToSet)
{
  this->_map.setMap(mapToSet);
}

SoundManager				MyGame::getSoundManager() const
{
  return (this->mngr);
}

void					MyGame::sLoad(const std::string &filename, int type)
{
  if (type == 1)
    this->mngr.loadStream(filename);
  else
    this->mngr.loadSound(filename);
}

void					MyGame::sPlay(int id)
{
  this->mngr.play(id);
}

void					MyGame::letterM()
{
  if (sound_paused)
    {
      this->mngr.resume(this->mngr.getUserChan());
      sound_paused = false;
    }
  else
    {
      this->mngr.pause(this->mngr.getUserChan());
      sound_paused = true;
    }
}

MyGame::~MyGame()
{

}
