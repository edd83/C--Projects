//
// Game.cpp for Game in /home/volpe_p/rendu/Nibbler/src
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Apr  1 16:15:47 2014 volpe
// Last update Sun Apr  6 18:08:01 2014 volpe
//

#include		"../headers/Usleep.hpp"
#include		"../ncurses/headers/Display.hh"
#include		"../headers/Loader.hh"

Game::Game()
{
  this->Init();
}

Game::~Game()
{

}

void			Game::Init()
{
  this->_score = 0;
  this->_snake = new Snake();
  this->_collision = new Collision();
  this->_food = new Food();
  this->_stratFact = new StratFact();
  this->_hole = new Hole();
  this->_strategie = this->_stratFact->create(EASY);
  //
  this->_snake->addElem(this->_sList, HEAD, 400, 300);
  this->_snake->addElem(this->_sList, BODY, 380, 300);
  this->_snake->addElem(this->_sList, BODY, 360, 300);
  this->_snake->addElem(this->_sList, TAIL, 340, 300);
  //
  this->_food->addElem(this->_fList, this->_sList);
  sleep(1);
  this->_food->addElem(this->_fList, this->_sList);
  sleep(1);
  this->_food->addElem(this->_fList, this->_sList);
  //
  this->_hole->addElem(this->_assList, 500, 200, BLACKHOLE);
  this->_hole->addElem(this->_assList, 300, 160, BLACKHOLE);
  this->_hole->addElem(this->_assList, 120, 640, BLACKHOLE);
  this->_hole->addElem(this->_assList, 400, 540, BLACKHOLE);
  this->_hole->addElem(this->_assList, 640, 60, BLACKHOLE);

  this->_hole->addElem(this->_assList, 400, 240, BLACKHOLE);
  this->_hole->addElem(this->_assList, 320, 280, BLACKHOLE);
  this->_hole->addElem(this->_assList, 10, 400, BLACKHOLE);
  this->_hole->addElem(this->_assList, 180, 340, BLACKHOLE);
  this->_hole->addElem(this->_assList, 420, 680, BLACKHOLE);
}

// Debut -- Getters & Setters

int			Game::getSpeed() const
{
  return (this->_strategie->getSpeed());
}

std::list<ISnake *>	Game::getSList() const
{
  return (this->_sList);
}

std::list<IFood *>	Game::getFList() const
{
  return (this->_fList);
}

ISnake			*Game::getSnakeI() const
{
  return (this->_snake);
}

IFood			*Game::getFoodI() const
{
  return (this->_food);
}

Collision		*Game::getCollision() const
{
  return (this->_collision);
}

// Fin -- Getters & Setters

int			Game::checkCollision(std::list<ISnake *> &slist, std::list<IFood *> &flist, std::list<IHole *> &hlist) const
{
  int			ret;

  if (this->_collision->checkSAndF(slist, flist) == true)
    return (1);
  ret = this->_collision->checkSAndH(slist, hlist);
  if (ret == 1)
    return (1);
  if (ret == -1)
    return (-1);
  if (this->_collision->checkSAndS(slist) == true)
    return (-1);
  if (this->_collision->checkSAndW(slist) == true)
    return (-1);
  return (0);
}


void			Game::setSList(const std::list<ISnake *> &list)
{
  this->_sList = list;
}

void			Game::updateSList(std::list<ISnake *> &list) const
{
  ISnake	*back;

  back = new Snake();
  back->setX(list.back()->getX() - SIDE);
  back->setY(list.back()->getY());
  list.push_back(back);
}

std::list<IHole *>	Game::getHole() const
{
  return (this->_assList);
}

void			Game::setFList(std::list<IFood *> &list)
{
  this->_fList = list;
}

void			Game::updateFList(std::list<IFood *> &list)
{
  while (this->_strategie->getNbFood() > list.size())
    this->_food->addElem(list, this->_sList);
}

void			Game::displayCoord() const
{
  for (std::list<ISnake *>::const_iterator it = this->_sList.begin(); it != this->_sList.end(); ++it)
    std::cout << (*it)->getX() << "\t" << (*it)->getY() << std::endl;
}

void			Game::analyseLevel()
{
  if (this->_sList.size() > 10 && this->_sList.size() < 15)
    {
      delete(this->_strategie);
      this->_strategie = this->_stratFact->create(MEDIUM);
    }
  else if (this->_sList.size() >= 15)
    {
      delete(this->_strategie);
      this->_strategie = this->_stratFact->create(HARD);
    }
}

int			Game::getScore() const
{
  return (this->_score);
}

void			Game::setScore()
{
  this->_score += this->_strategie->getPts();
}

void			Game::start(char	*libpath)
{
  std::list<ISnake *>	tmp;
  std::list<IFood *>	tmpf;
  std::list<IHole *>	tmph;
  int			ret;
  maker_Display		pMaker;
  Loader		loader = Loader(libpath);

  pMaker = loader.Init();
  Display *my_graph = pMaker();
  ret = 0;
  if (my_graph->Init() == false)
    throw GameException("Error on creation of Window");
  while (my_graph->Window() == true && ret != -1)
    {
      tmp = this->getSList();
      tmpf = this->getFList();
      tmph = this->getHole();
      my_graph->Play(tmp, tmpf, tmph, this->getScore());
      ret = this->checkCollision(tmp, tmpf, tmph);
      if (ret == 1)
	{
	  this->setScore();
	  this->updateSList(tmp);
	  this->updateFList(tmpf);
	}
      this->setSList(tmp);
      this->setFList(tmpf);
      this->analyseLevel();
      Usleep::my_usleep(this->getSpeed());
    }
  my_graph->Finish();
  loader.close();
  printf("%d\n", this->getScore());
}
