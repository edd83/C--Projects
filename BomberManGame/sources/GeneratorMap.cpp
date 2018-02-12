//
// GeneratorMap.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/merge-client
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun 10 12:33:00 2014 ovoyan_s
// Last update Sun Jun 15 16:00:08 2014 ovoyan_s
//

#include	"GeneratorMap.hh"

GeneratorMap::GeneratorMap()
{
  this->mapSizeX = 0;
  this->mapSizeY = 0;
}

MyString		        GeneratorMap::genereBorderMap(int width)
{
    MyString			str;
    int				i;

    i = 0;
    while (i != width)
    {
        str+='1';
        i++;
    }
    return (str);
}

MyString		        GeneratorMap::genereSecondLine(int width)
{
  int				i, j;
  MyString			str;
  
  i = j = 0;
  str += '1';
  str += '0';
  str += '0';
  i = 3;
  while (i != (width - 1))
    {
      j = this->randElement.GetRandomRN(2);
      if (j == 0)
	str+='0';
      else
        {
	  j = this->randElement.GetRandomRN(3);
	  str+=(char)(j + 48);
        }
      i++;
    }
  str+='1';
  return (str);
}

MyString		        GeneratorMap::genereThirdLine(int width)
{
  int				i, j;
  MyString			str;
  
  i = j = 0;
  str += '1';
  str += '0';
  i = 2;
  while (i != (width - 1))
    {
      j = this->randElement.GetRandomRN(2);
      if (j == 0)
        {
	  str+='0';
        }
      else
        {
	  j = this->randElement.GetRandomRN(3);
	  str+=(char)(j + 48);
        }
      i++;
    }
  str+='1';
  return (str);
}

MyString		        GeneratorMap::genereAlmostLastLine(int width)
{
  int				i, j;
  MyString			str;
  
  i = j = 0;
  str += '1';
  i = 1;
  while (i != (width - 3))
    {
      j = this->randElement.GetRandomRN(2);
      if (j == 0)
        {
	  str+='0';
        }
      else
        {
	  j = this->randElement.GetRandomRN(3);
	  str+=(char)(j + 48);
        }
      i++;
    }
  str+='0';
  str+='0';
  str+='1';
  return (str);
}

MyString		        GeneratorMap::genereAlmostAlmostLastLine(int width)
{
  int				i, j;
  MyString			str;
  
  i = j = 0;
  str += '1';
  i = 1;
  while (i != (width - 2))
    {
      j = this->randElement.GetRandomRN(2);
      if (j == 0)
        {
	  str+='0';
        }
      else
        {
	  j = this->randElement.GetRandomRN(3);
	  str+=(char)(j + 48);
        }
      i++;
    }
  str+='0';
  str+='1';
  return (str);
}

void				GeneratorMap::genereMap(int length, int width)
{
  int				i, j, k;
  MyString			str;
  
  i = j = 0;
  i+=3;
  this->mapSizeY = length;
  this->mapSizeX = width;
  if (length < 7 && width < 7)
    throw MyException ("Generation de map impossible car \n Minimum 7 de hauteur et de largeur.\n");
  this->generatedMap.push_back(genereBorderMap(width));
  this->generatedMap.push_back(genereSecondLine(width));
  this->generatedMap.push_back(genereThirdLine(width));
  while(i != (length - 3))
    {
      str+='1';
      j ++;
      while(j != (width - 1))
	{
	 k = this->randElement.GetRandomRN(2);
	 if (k == 0)
           {
	     str+='0';
           }
	 else
           {
	     k = this->randElement.GetRandomRN(3);
	     str+=(char)(k + 48);
           }
	 j++;
	}
      str+='1';
      this->generatedMap.push_back(str);
      str = "";
      j = 0;
      i ++;
    }
  this->generatedMap.push_back(genereAlmostAlmostLastLine(width));
  this->generatedMap.push_back(genereAlmostLastLine(width));
  this->generatedMap.push_back(genereBorderMap(width));
}

void				GeneratorMap::generationEntities()
{
  int				counter;
  std::list<Entity*>		listBomb;
  std::list<Entity*>		listPlayers;
  std::list<Entity*>		listBonus;
  int				sizeOfMap;
  int				idPlayer;

  idPlayer = 2;
  listBomb.clear();
  listPlayers.clear();
  listBonus.clear();
  if (this->mapSizeX < 7 || this->mapSizeY < 7)
    throw MyException ("The map have bad sizes");
  counter = -1;
  sizeOfMap = this->generatedMap.size() * 0.4;
  while (++counter < sizeOfMap)
    {
      listPlayers.push_back(this->generationPlayer(listPlayers, idPlayer));
      idPlayer++;
    }
  if (listPlayers.size() <= 1)
    listPlayers.clear();

  if (listPlayers.size() <= 0)
    throw MyException ("The list of players is empty");
  this->entitiesList.push_back(listBomb);
  this->entitiesList.push_back(listPlayers);
  this->entitiesList.push_back(listBonus);
}

Player				*GeneratorMap::generationPlayer(const std::list<Entity*> &playersList, int idPlayer)
{
  unsigned int			counter;
  unsigned int			randX;
  unsigned int			randY;
  Player			*entityToRet;

  counter = 0;  
  entityToRet = NULL;
  while (counter < 100)
    {
      randX = this->randElement.GetRandomRN(this->mapSizeX);
      randY = this->randElement.GetRandomRN(this->mapSizeY);
      if (checkPlayersInMap(randX, randY, playersList) == true)
	{
	  entityToRet = new BombermanAI(randX, randY, idPlayer);
	  entityToRet->addBomb();
	  ++idPlayer;
	  return (entityToRet);
	}
      ++counter;
    }
  throw MyException ("Error in calculation of entity coordinates");
  return (NULL);
}

bool				GeneratorMap::checkPlayersInMap(int coordX, int coordY,
								std::list<Entity*> playersList)
{
  std::list<Entity*>::iterator	it;

  if (coordX >= this->mapSizeX || coordY >= this->mapSizeY
      || coordX < 0 || coordY < 0 || this->generatedMap.GetCharAt(coordY, coordX) != '0')
    return (false);

  unsigned int			coordXu = coordX;
  unsigned int			coordYu = coordY;

  it = playersList.begin();
  while (it != playersList.end())
    {
      if ((*it)->getX() == coordXu && (*it)->getY() == coordYu)
	return (false);
      ++it;
    }
  return (true);
}

std::list<std::list<Entity*> >	GeneratorMap::getEntityList() const
{
  return (this->entitiesList);
}

MyStringArray			GeneratorMap::getGeneratedMap() const
{
  return (this->generatedMap);
}

GeneratorMap::~GeneratorMap()
{

}
