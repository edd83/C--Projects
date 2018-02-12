/*
** Map.cpp for Map in /home/cuchet_a/Bomberman/cpp_bomberman/Core
** 
** Made by Cuchet Antony
** Login   <cuchet_a@cuchet.a.HP.EliteBook.8560p>
** 
** Started on  Thu May 15 10:40:01 2014 Cuchet Antony
// Last update Sun Jun 15 15:26:23 2014 ovoyan_s
*/

#include		"Map.hh"

Map::Map()
{
  std::list<Entity *>	Bonus;
  std::list<Entity *>	Bomb;
  std::list<Entity *>	Player;

  this->Length = 0;
  this->Width = 0;
  this->mapOfGame = new MyStringArray;
  this->listOfEntities = new std::list<std::list<Entity*> >;
  this->mapOfGame->clear();
  this->listOfEntities->clear();
  this->listOfEntities->push_back(Bomb);
  this->listOfEntities->push_back(Player);
  this->listOfEntities->push_back(Bonus);
}

Map::Map(const MyString &nameOfFileToLoad)
{
  std::ifstream		fileToLoad;
  MyStringArray		arrayBuffer;
  MyString		strRead;
  std::list<Entity *>	Bonus;
  std::list<Entity *>	Bomb;
  std::list<Entity *>	Player;

  this->checkName(nameOfFileToLoad);
  this->listOfEntities->clear();
  this->listOfEntities->push_back(Bomb);
  this->listOfEntities->push_back(Player);
  this->listOfEntities->push_back(Bonus);
  fileToLoad.open(const_cast<char*>(nameOfFileToLoad.c_str()), std::fstream::in);
  if (fileToLoad.bad() == true)
    throw MyException ("The file is not well opened");
  this->checkSize(fileToLoad);
  while (std::getline(fileToLoad, strRead))
    arrayBuffer.AddString(strRead);
  if (arrayBuffer.size() <= 0)
    throw MyException ("The size of file is invalid");
  this->checkCrypt(arrayBuffer, nameOfFileToLoad);
}

Map::~Map()
{

}

/*
**			SETTERS
*/

void			Map::setLength(unsigned int lenghtToSet)
{
  this->Length = lenghtToSet;
}

void			Map::setWidth(unsigned int widthToSet)
{
  this->Width = widthToSet;
}

void			Map::setCase(unsigned int posX, unsigned int posY, unsigned char nature)
{
  this->mapOfGame->SetCharAt(posX, posY, nature);
}

void			Map::addEntity(const Entity &entityToAdd)
{
  void			(Map::*add[4])(const Entity &);

  add[0] = &Map::addNoNature;
  add[1] = &Map::addBonus;
  add[2] = &Map::addBomb;
  add[3] = &Map::addPlayer;

  (this->*add[entityToAdd.getEntity()])(entityToAdd);
}

void			Map::addNoNature(const Entity &entityToAdd)
{
  (void)entityToAdd;
  throw MyException ("Type of entity unknown");
}

void			Map::addBomb(const Entity &entityToAdd)
{
  std::list<std::list<Entity *> >::iterator it;
  it = this->listOfEntities->begin();
  (*it).push_back(const_cast<Entity *>(&entityToAdd));  
}

void			Map::addBonus(const Entity &entityToAdd)
{
  std::list<std::list<Entity *> >::iterator it;
  it = this->listOfEntities->begin();
  ++(++it);
  (*it).push_back(const_cast<Entity *>(&entityToAdd));  
}

void			Map::addPlayer(const Entity &entityToAdd)
{
  std::list<std::list<Entity*> >::iterator it;
  it = this->listOfEntities->begin();
  ++it;
  (*it).push_back(const_cast<Entity *>(&entityToAdd));  
}

void			Map::modMap(const std::string &str)
{
  this->mapOfGame->AddString(str);
}

void			Map::setMap(const MyStringArray &mapToSet)
{
  std::string		strToUse("");

  *this->mapOfGame = mapToSet;
  if (this->mapOfGame->size() > 0)
    strToUse = *(this->mapOfGame->begin());
  this->Width = this->mapOfGame->size();
  this->Length = strToUse.size();
}

void			Map::setEntityList(const std::list<std::list<Entity*> > &entityListToSet)
{
  std::list<std::list<Entity *> >::const_iterator	it;  
  std::list<Entity*>		listToAdd;
  std::list<Entity*>::const_iterator	itToUse;

  it = entityListToSet.begin();
  this->listOfEntities->clear();
  listToAdd.clear();
  itToUse = (*it).begin();
  while (itToUse != (*it).end())
    {
      listToAdd.push_back(*itToUse);
      ++itToUse;
    }

  this->listOfEntities->push_back(listToAdd);

  ++it;
  listToAdd.clear();
  itToUse = (*it).begin();
  while (itToUse != (*it).end())
    {
      listToAdd.push_back(*itToUse);
      ++itToUse;
    }
  this->listOfEntities->push_back(listToAdd);

  ++it;
  listToAdd.clear();
  itToUse = (*it).begin();
  while (itToUse != (*it).end())
    {
      listToAdd.push_back(*itToUse);
      ++itToUse;
    }
  this->listOfEntities->push_back(listToAdd);
}

/*
**			GETTERS
*/

unsigned int		Map::getLength() const
{
  return (this->Length);
}

unsigned int		Map::getWidth() const
{
  return (this->Width);
}

unsigned char		Map::getCase(unsigned int posX, unsigned int posY) const
{
  unsigned char		charToRet;

  if (posX > this->Length || posY > this->Width)
    return (10);
  charToRet = this->mapOfGame->GetCharAt(posY, posX);
  return (charToRet);
}

std::list<Entity *>	&Map::getBombList()
{
  std::list<std::list<Entity *> >::iterator	it;
  it = this->listOfEntities->begin();
  return (static_cast<std::list<Entity*>& >(*it));
}

std::list<Entity *>	&Map::getBonusList()
{
  std::list<std::list<Entity *> >::iterator	it;
  it = this->listOfEntities->begin();
  ++(++it);
  return (static_cast<std::list<Entity*>& >(*it));
}

std::list<Entity *>	&Map::getPlayerList()
{
  std::list<std::list<Entity *> >::iterator	it;

  it = this->listOfEntities->begin();
  ++it;
  return (static_cast<std::list<Entity*>& >(*it));
}

Bombe			*Map::getBombById(unsigned int pid)
{
  std::list<Entity *>::iterator	it;
  std::list<Entity*>	itList;
  Bombe			*bombe;

  itList = this->getBombList();
  it = itList.begin();
  while (it != itList.end())
    {
      if ((bombe = dynamic_cast<Bombe*>(*it)) != NULL)
	{
	  if (bombe->getPlayerId() == pid)
	    return (bombe);
	}
      ++it;
    }
  return (NULL);
}

Player				*Map::getPlayerById(int pid)
{
  std::list<Entity *>::iterator	it;
  std::list<Entity*>		list;
  Player			*play;

  list = this->getPlayerList();
  it = list.begin();
  while (it != list.end())
    {
      if ((play = dynamic_cast<Player*>(*it)) != NULL)
	{
	  if (play->getId() == pid)
	    return (play);
	}
      ++it;
    }
  return (NULL);
}

std::list<Entity *>::iterator	Map::getPlayerIT(int pid)
{
  std::list<Entity *>::iterator	it;
  std::list<Entity*>		list;
  
  list = this->getPlayerList();
  it = list.begin();
  while (it != list.end())
    {
      if ((static_cast<Player *>(*it))->getId() == pid)
	return (it);
      ++it;
    }
  return (it);
}

MyStringArray		*Map::getMap() const
{
  return (this->mapOfGame);
}

std::list<std::list<Entity *> >	*Map::getListEntity() const
{
  return (this->listOfEntities);
}

void						Map::showListSizes()
{
  std::list<std::list<Entity*> >::iterator	it;

  it = this->listOfEntities->begin();
  std::cout << (*it).size() << std::endl;
  ++it;
  std::cout << (*it).size() << std::endl;
  ++it;
  std::cout << (*it).size() << std::endl;
}

/*
**			LOAD FUNCTIONS
*/

void			Map::loadMap(const MyString &nameOfFileToLoad)
{
  std::ifstream		fileToLoad;
  MyStringArray		arrayBuffer;
  MyStringArray		size;
  MyStringArray		map;
  MyStringArray		items;
  MyString		strRead;
  int			i;

  i = 2;
  this->checkName(nameOfFileToLoad);
  fileToLoad.open(const_cast<char*>(nameOfFileToLoad.c_str()), std::fstream::in);
  if (fileToLoad.bad() == true)
    throw MyException ("The file is not well opened");
  this->checkSize(fileToLoad);
  while (std::getline(fileToLoad, strRead))
    arrayBuffer.AddString(strRead);
  if (arrayBuffer.size() <= 0)
    throw MyException ("The size of file is invalid");
  this->checkCrypt(arrayBuffer, nameOfFileToLoad);
  size.AddString(arrayBuffer.GetStringAt(1));
  this->checkMapSize(size);
  map.AddString(arrayBuffer.GetStringAt(i));
  i = i + 1;
  while(arrayBuffer.GetStringAt(i).c_str()[0] != '#' && arrayBuffer.GetStringAt(i) != "")
  {
      map.AddString(arrayBuffer.GetStringAt(i));
      i ++;
  }
  if (arrayBuffer.GetStringAt(i).c_str()[0] == '#')
    map.AddString(arrayBuffer.GetStringAt(i));
  else
    throw MyException ("Wrong Map format in file");
  this->checkMap(map);
  i = i + 1;
  while (arrayBuffer.GetStringAt(i) != "")
  {
      items.AddString(arrayBuffer.GetStringAt(i));
      i = i + 1;
  }
  this->checkItem(items);
}

/*
**			SAVE FUNCTIONS
*/

void			Map::saveMap(const MyString &nameOfFileToSave)
{
  std::ofstream		fileToSave;
  std::list<std::list<Entity *> >::iterator	it;
  std::list<Entity *>::iterator	it2;

  this->checkName(nameOfFileToSave);
  fileToSave.open(const_cast<char*>(nameOfFileToSave.c_str()), std::fstream::trunc);
  if (fileToSave.bad() == true)
    throw MyException ("The file is not well opened");
  this->writeCryptKey(fileToSave, nameOfFileToSave);
  this->writeSize(fileToSave);
  this->writeMap(fileToSave);

  it = this->listOfEntities->begin();

  if ((*it).size() == 0)
    ++it;
  else
    {
      it2 = (*it).begin();
      while (it2 != (*it).end())
	{
	  this->writeBomb(fileToSave, static_cast<Bombe*>(*it2));
	  it2++;
	}
      ++it;
    }

  if ((*it).size() == 0)
    ++it;
  else
    {
      it2 = (*it).begin();
      while (it2 != (*it).end())
	{
	  this->writePlayer(fileToSave, static_cast<Player*>(*it2));
	  it2++;
	}
      ++it;
    }

  if ((*it).size() == 0)
    ++it;
  else
    {
      it2 = (*it).begin();
      while (it2 != (*it).end())
	{
	  this->writeBonMal(fileToSave, static_cast<Bonus*>(*it2));
	  it2++;
	}
      ++it;
    }
}

/*
**			CHECK  FUNCTIONS
*/

void			Map::checkName(const std::string &nameOfFileToCheck)
{
  if (nameOfFileToCheck.size() < 5)
    throw MyException("The file have an invalid name size");
  if (nameOfFileToCheck.substr(nameOfFileToCheck.size() - 4, 4) != ".bsf")
    throw MyException ("The extension of the file is invalid");
}

void			Map::checkSize(std::ifstream &fileToCheck)
{
  unsigned int		fileSize;

  fileToCheck.seekg(0, fileToCheck.end);
  fileSize = fileToCheck.tellg();
  fileToCheck.seekg(0, fileToCheck.beg);
  if (fileSize > MAX_SIZE_FILE)
    throw MyException ("The file have an invalid size");  
}

void				Map::checkCrypt(const MyStringArray &myArray,
						const MyString &fileToLoadName)
{
  MyString			genString;
  MyString			cryptString;
  MyStringArray			wordString;

  genString = myArray.GetStringAt(0);
  genString.StrWordTab(' ', &wordString);
  cryptString = wordString.GetStringAt(2);
  if (cryptString != this->crypt(fileToLoadName))
    throw MyException ("The file have a bad crypted code");
}

void				Map::checkMapSize(const MyStringArray &arrayToCheck)
{
  MyString			tmp;
  MyStringArray			chck;
  int				i;
  int				nb, nb2;
  std::string			tmp2;
  std::stringstream		yolo, yolo2;

  i = -1;
  yolo.str("");
  tmp = arrayToCheck.GetStringAt(0);
  tmp.StrWordTab(' ', &chck);
  if (chck.GetStringAt(0) != "Size" || chck.GetStringAt(1) != ":")
    throw MyException ("Error in the file at the size line");
  tmp2 = chck.GetStringAt(2);
  while (tmp2.c_str()[++i] != '\0')
    if (tmp2.c_str()[i] < '0' || tmp2.c_str()[i] > '9')
      throw MyException ("Error in the file at the size line");
  i = -1;
  yolo.str(tmp2);
  yolo >> nb;
  if (nb <= 0)
    throw MyException ("Error int the file at the size line");
  this->setLength(nb);
  tmp2 = chck.GetStringAt(3);
  while (tmp2.c_str()[++i] != '\0')
    if (tmp2.c_str()[i] < '0' || tmp2.c_str()[i] > '9')
      throw MyException ("Error in the file at the size line");
  yolo2.str(tmp2);
  yolo2 >> nb2;
  this->setWidth(nb2);
}

void				Map::checkMap(const MyStringArray &arrayToCheck)
{
  std::string			tmp;
  int				i, j, length;

  i = 0;
  j = -1;
  this->mapOfGame->clear();
  tmp = arrayToCheck.GetStringAt(0);
  if (tmp.c_str()[0] == '#')
    {
      while (tmp.c_str()[++j] != '\0')
	if (tmp.c_str()[j] != '#')
      throw MyException ("Error in the checking of the map4");
      length = j;
    }
  else
    throw MyException ("Error in the checking of the map5");
  ++i;
  if (static_cast<unsigned int>(length) != this->Length)
    throw MyException ("Error in the checking of the map6");
  j = -1;
  tmp = arrayToCheck.GetStringAt(1);
  while (tmp.c_str()[++j] != '\0')
    if (tmp.c_str()[j] != '1')
      throw MyException ("Error in the checking of the map7");
  if (j != length)
    throw MyException ("Error in the checking of the map8");
  j = 1;
  this->mapOfGame->AddString(tmp);
  while ((tmp = arrayToCheck.GetStringAt(++i)) != "")
    {
      if (tmp.c_str()[0] != '#')
        {
            j = -1;
            if (tmp.c_str()[0] != '1')
          throw MyException ("Error in the checking of the map9");
            while (tmp.c_str()[++j] != '\0')
                if (tmp.c_str()[j] != '0' && tmp.c_str()[j] != '1' && tmp.c_str()[j] != '2')
                    throw MyException ("Error in the checking of the map10");
            if (j != length)
                throw MyException ("Error in the checking of the map11");
            if (tmp.c_str()[(j - 1)] != '1')
                throw MyException ("Error in the checking of the map12");
	    this->mapOfGame->AddString(tmp);
        }
      else
        {
      if ((i - 1) != static_cast<int>(this->getWidth()))
        throw MyException ("Error in the checking of the map13");
	  j = 0;
	  while (tmp.c_str()[j] != '\0')
	    if (tmp.c_str()[j] != '#')
          throw MyException ("Error in the checking of the map14");
	    else
	      ++j;
	  if (j != length)
        throw MyException ("Error in the checking of the map15");
	  tmp = arrayToCheck.GetStringAt((i-1));
	  j = -1;
	  while (tmp.c_str()[++j] != '\0')
	    if (tmp.c_str()[j] != '1')
          throw MyException ("Error in the checking of the map16");
        }
    }
  if (static_cast<unsigned int>(i - 2) != this->Width)
      throw MyException ("Error in the checking of the map17");
}

void				Map::checkBomb(const MyStringArray &arrayToCheck)
{
  MyString		str;
  MyStringArray		oth;
  std::string		tmp;
  int			i, j;
  int			tab[5];
  std::list<std::list<Entity *> >::iterator	it;
  Bombe			*bombe;

  j = 0;
  i = 2;
  str = arrayToCheck.GetStringAt(0);
  str.StrWordTab(' ', &oth);
  if (oth.GetStringAt(0) != "Bomb")
    throw MyException ("Error in the checking of the bomb");
  if (oth.GetStringAt(1) != ":")
    throw MyException ("Error in the checking of the bomb");
  while ((tmp = oth.GetStringAt(i))!= "")
    {
      while (tmp.c_str()[j] != '\0')
	{
	  if (tmp.c_str()[j] < '0' || tmp.c_str()[j] > '9')
        throw MyException ("Error in the checking of the bomb");
	  j ++;
	}
      j = 0;
      if (i > 7)
        throw MyException ("Error in the checking of the bomb");
      tab[i - 2] = std::atoi(tmp.c_str());
      i ++;    
    }
  if (i < 7)
    throw MyException ("Error in the checking of the bomb");
  bombe = new Bombe(tab[0], tab[1], (unsigned int)tab[2]);
  bombe->setRange(static_cast<unsigned int>(tab[3]));
  bombe->setTimer(static_cast<unsigned int>(tab[4]));
  it = this->listOfEntities->begin();
  ++it;
  (*it).push_back(bombe);
}

void				Map::checkPlayer(const MyStringArray &arrayToCheck)
{
  MyString		str;
  MyStringArray		oth;
  std::string		tmp;
  int			i, j;
  int			tab[9];
  std::list<std::list<Entity *> >::iterator	it;
  std::list<Entity *>::iterator	it2;
  Player		*player;

  j = 0;
  i = 2;
  str = arrayToCheck.GetStringAt(0);
  str.StrWordTab(' ', &oth);
  if (oth.GetStringAt(0) != "Player")
    throw MyException ("Error in the checking of the player");
  if (oth.GetStringAt(1) != ":")
    throw MyException ("Error in the checking of the player");
  while ((tmp = oth.GetStringAt(i)) != "")
    {
      while (tmp.c_str()[j] != '\0')
	{
	  if (tmp.c_str()[j] < '0' || tmp.c_str()[j] > '9')
            throw MyException ("Error in the checking of the player");
	  j ++;
	}
      j = 0;
      if (i > 11)
        throw MyException ("Error in the checking of the player");
      tab[i - 2] = std::atoi(tmp.c_str());
      i ++;
    }
  if (i < 11)
    throw MyException ("Error in the checking of the player");
  if (tab[6] > 3 || tab[8] > 3)
    throw MyException ("Error in the checking of the player");
  i = 0;
  player = new Player(tab[0], tab[1], tab[2]);
  player->setDir(static_cast<eMove>(tab[6] - 1));
  player->setSpeed(tab[4]);
  player->setHp(tab[3]);
  player->setState(static_cast<eState>(tab[8]));
  player->setScore(tab[5]);
  player->setNbBomb(tab[7]);
  it = this->listOfEntities->begin();
  ++it;
  it2 = (*it).begin();
  while (it2 != (*it).end())
    {
      if ((dynamic_cast<Bombe *>(*it2))->getPlayerId() == static_cast<unsigned char>(player->getId()))
	{
	  player->addBomb((dynamic_cast<Bombe *>(*it2)));
	  i ++;
	}
      it2++;
    }
  while(i != tab[7])
    {
      player->addBomb();
      i ++;
    }
  it = this->listOfEntities->begin();
  ++(++it);
  (*it).push_back(player);
}

void				Map::checkBonMal(const MyStringArray &arrayToCheck)
{
  MyString			str;
  MyStringArray			oth;
  std::string			tmp;
  int				i, j;
  int				tab[3];
  std::list<std::list<Entity *> >::iterator	it;
  Bonus				*bonus;

  j = 0;
  i = 2;
  str = arrayToCheck.GetStringAt(0);
  str.StrWordTab(' ', &oth);
  if (oth.GetStringAt(0) != "Bonus")
    throw MyException ("Error in the checking of the BonMal");
  if (oth.GetStringAt(1) != ":")
    throw MyException ("Error in the checking of the BonMal");
  while ((tmp = oth.GetStringAt(i)) != "")
    {
      while (tmp.c_str()[j] != '\0')
	{
	  if (tmp.c_str()[j] < '0' || tmp.c_str()[j] > '9')
	    throw MyException ("Error in the checking of the BonMal");
	  j ++;
	}
      j = 0;
      if (i > 5)
	throw MyException ("Error in the checking of the BonMal");
      tab[i - 2] = std::atoi(tmp.c_str());
      i ++;
    }
  if (i < 5)
    throw MyException ("Error in the checking of the BonMal");
  it = this->listOfEntities->begin();
  bonus = new Bonus(tab[0], tab[1], static_cast<BonusId>(tab[2]));
  (*it).push_back(bonus);
}

void            Map::checkItem(const MyStringArray &arrayToCheck)
{
    this->checkItemBomb(arrayToCheck);
    this->checkItemPlayer(arrayToCheck);
    this->checkItemBonMal(arrayToCheck);
}

void            Map::checkItemBomb(const MyStringArray &arrayToCheck)
{
    int             i;
    MyStringArray   oth;
    MyStringArray   tmp;
    MyString        exc;

    i = -1;
    while (arrayToCheck.GetStringAt(++i) != "")
    {
        exc = arrayToCheck.GetStringAt(i);
        exc.StrWordTab(' ', &tmp);
        oth.AddString2(exc);
        if (tmp.GetStringAt(0) == "Bomb")
            this->checkBomb(oth);
        else if (tmp.GetStringAt(0) != "Player" && tmp.GetStringAt(0) != "Bonus")
            throw MyException ("Error in the checking of the map1");
    }
}

void            Map::checkItemPlayer(const MyStringArray &arrayToCheck)
{
    int             i;
    MyStringArray   oth;
    MyStringArray   tmp;
    MyString        exc;

    i = -1;
    while (arrayToCheck.GetStringAt(++i) != "")
    {
        exc = arrayToCheck.GetStringAt(i);
        exc.StrWordTab(' ', &tmp);
        oth.AddString2(exc);
        if (tmp.GetStringAt(0) == "Player")
            this->checkPlayer(oth);
        else if (tmp.GetStringAt(0) != "Bomb" && tmp.GetStringAt(0) != "Bonus")
            throw MyException ("Error in the checking of the map2");
    }
}

void            Map::checkItemBonMal(const MyStringArray &arrayToCheck)
{
    int             i;
    MyStringArray   oth;
    MyStringArray   tmp;
    MyString        exc;

    i = -1;
    while (arrayToCheck.GetStringAt(++i) != "")
    {
        exc = arrayToCheck.GetStringAt(i);
        exc.StrWordTab(' ', &tmp);
        oth.AddString2(exc);
        if (tmp.GetStringAt(0) == "Bonus")
            this->checkBonMal(oth);
        else if (tmp.GetStringAt(0) != "Player" && tmp.GetStringAt(0) != "Bomb")
            throw MyException ("Error in the checking of the map3");
    }
}

/*
**			CRYPTAGE FUNCTION
*/

std::string             Map::crypt(const std::string &name) const
{
  std::string           key;
  unsigned int		counter;
  unsigned int		modCounter;

  counter = 0;
  while (counter < (name.size() - 4))
    {
      modCounter = name[counter];
      if (counter + 1 + name.size() - 4 == 0)
	throw MyException ("Modulation by 0");
      modCounter = modCounter % (counter + 1 + (name.size() - 4));
      modCounter = ((modCounter + 33) % 127);
      key += static_cast<char>(modCounter);
      counter = counter + 1;
    }
  return (key);
}

/*
**			FILE WRITERS
*/

void			Map::writeCryptKey(std::ofstream &fileToSave, const MyString &nameOfFileToSave)
{
  MyString		fileName(nameOfFileToSave);

  fileName.StrReplaceAll(".bsf", "");
  fileToSave << "Cryptkey : " << this->crypt(nameOfFileToSave) << std::endl;
}

void			Map::writeSize(std::ofstream &fileToSave)
{
  unsigned int		counter;

  counter = 0;
  if (this->Length <= 5)
    throw MyException ("The Length of the map is equal or less than zero");
  if (this->Width <= 5)
    throw MyException ("The Width of the map is equal or less than zero");
  fileToSave << "Size : " << this->Length << " " << this->Width << std::endl;
  while (counter < this->Length)
    {
      fileToSave << "#";
      counter = counter + 1;
    }
  fileToSave << std::endl;
}

void			Map::writeMap(std::ofstream &fileToSave)
{
  unsigned int		counter;

  if (this->mapOfGame->size() <= 5)
    throw MyException("The map is too small");
  counter = 0;
  while (counter < this->mapOfGame->size())
    {
      fileToSave << this->mapOfGame->GetStringAt(counter) << std::endl;
      counter = counter + 1;
    }
  counter = 0;
  while (counter < this->Length)
    {
      fileToSave << "#";
      counter = counter + 1;
    }
  fileToSave << std::endl;
}

void			Map::writeBomb(std::ofstream &fileToSave, Bombe *bombToWrite)
{
  unsigned int		bombCoordX;
  unsigned int		bombCoordY;
  unsigned int		range;
  unsigned int		player_id;
  unsigned int		timer;

  bombCoordX = bombToWrite->getX();
  bombCoordY = bombToWrite->getY();
  range = bombToWrite->getRange();
  player_id = bombToWrite->getPlayerId();
  timer = bombToWrite->getTimer();

  if (bombCoordX > this->Length)
    throw MyException ("A bomb has a bad X coordinate");
  if (bombCoordY > this->Width)
    throw MyException ("A bomb has a bad Y coordinate");
  fileToSave << "Bomb : " << bombCoordX << " " << bombCoordY << " " << player_id
	     << " " << range << " " << timer << std::endl;
}

void			Map::writePlayer(std::ofstream &fileToSave, Player *player)
{
  unsigned int		x = player->getX();
  unsigned int		y = player->getY();

  if (x > this->Length)
    throw MyException ("A player has a bad X coordinate, check the graphic part.");

  if (y > this->Width)
    throw MyException ("A player has a bad Y coordinate, check the graphic part.");

  fileToSave << "Player : " << x << " " << y << " " << player->getId() << " " << player->getHp()
	     << " " << player->getSpeed() << " " << player->getScore() << " " << player->getDir()
	     << " " << player->getNbBombe() << " " << player->getState() << std::endl;
}

void			Map::writeBonMal(std::ofstream &fileToSave, Bonus *bonusToWrite)
{
  unsigned int		bonusCoordX;
  unsigned int		bonusCoordY;

  bonusCoordX = bonusToWrite->getX();
  bonusCoordY = bonusToWrite->getY();
  if (bonusCoordX > this->Length)
    throw MyException ("A bonus has a bad X coordinate");
  if (bonusCoordY > this->Width)
    throw MyException ("A bonus has a bad Y coordinate");
  fileToSave << "Bonus : " << bonusCoordX << " " << bonusCoordY << " " << bonusToWrite->getGuid() << std::endl;;
}

/*
**			AI FUNCTIONS
*/

bool			Map::wallCover(int playerX, int playerY, int bombX, int bombY)
{
  int			i = 1;

  if (playerX == bombX)
    {
      if (playerY >= bombY)
	{
	  while (bombY + i <= playerY)
	    {
	      if (this->getCase(playerX, bombY + i) != 0)
		return (true);
	      i++;
	    }
	}
      else
	{
	  while (bombY - i < playerY)
	    {
	      if (this->getCase(playerX, bombY - i) != 0)
		return (true);
	      i++;
	    }
	}
    }
  else if (playerY == bombY)
    {
      if (playerX >= bombX)
	{
	  while (bombX + i <= playerX)
	    {
	      if (this->getCase(bombX + i, playerY) != 0)
		return (true);
	    }
	}
      else
	{
	  while (bombX - i < playerY)
	    {
	      if (this->getCase(bombX - i, playerY) != 0)
		return (true);
	      i++;
	    }
	}
    }
  return (false);
}
