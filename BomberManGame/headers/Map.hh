//
// Map.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 26 15:56:43 2014 ovoyan_s
// Last update Sat Jun 14 18:01:33 2014 volpe
//

#ifndef					MAP_HH_
# define				MAP_HH_

# include				"Includes.hh"

class					Bonus;

class					Player;

class					Bombe;

class					Map
{
private:
  MyStringArray				*mapOfGame;
  std::list<std::list<Entity*> >	*listOfEntities;
  unsigned int				Length;
  unsigned int				Width;

public:

  //					Constructors / Destructors

  Map();
  Map(const MyString &nameOfFileToLoad);
  ~Map();

  //				Setters

  void				setLength(unsigned int lenghtToSet);
  void				setWidth(unsigned int widthToSet);
  void				setCase(unsigned int posX, unsigned int posY, unsigned char nature);
  void				addEntity(const Entity &entityToAdd);
  void				addNoNature(const Entity &entityToAdd);
  void				addBonus(const Entity &entityToAdd);
  void				addBomb(const Entity &entityToAdd);
  void				addPlayer(const Entity &entityToAdd);
  void				modMap(const std::string &str);
  void				setMap(const MyStringArray &mapToSet);
  void				setEntityList(const std::list<std::list<Entity*> > &entityListToSet);

  //				Getters

  unsigned int			getLength() const;
  unsigned int			getWidth() const;
  unsigned char			getCase(unsigned int posX, unsigned int posY) const;
  std::list<Entity *>		&getPlayerList();
  std::list<Entity *>		&getBonusList();
  std::list<Entity *>		&getBombList();
  Player			*getPlayerById(int);
  Bombe				*getBombById(unsigned int);
  MyStringArray			*getMap() const;
  std::list<std::list<Entity *> >	*getListEntity() const;
  std::list<Entity *>::iterator getPlayerIT(int);
  void				showListSizes();

  //				Load Function

  void				loadMap(const MyString &nameOfFileToLoad);

  //				Save Functions

  void				saveMap(const MyString &nameOfFileToSave);

  //				Check Of File Functions

  void				checkName(const std::string &nameOfFileToCheck);
  void				checkSize(std::ifstream &fileToCheck);
  void				checkCrypt(const MyStringArray &arrayToCheck,
					   const MyString &fileToLoadName);
  void				checkMapSize(const MyStringArray &arrayToCheck);
  void				checkMap(const MyStringArray &arrayToCheck);
  void				checkBomb(const MyStringArray &arrayToCheck);
  void				checkPlayer(const MyStringArray &arrayToCheck);
  void				checkBonMal(const MyStringArray &arrayToCheck);
  void				checkItem(const MyStringArray &arrayToCheck);
  void				checkItemBomb(const MyStringArray &arrayToCheck);
  void				checkItemPlayer(const MyStringArray &arrayToCheck);
  void				checkItemBonMal(const MyStringArray &arrayToCheck);

  //				Cryptage Function

  std::string			crypt(const std::string &name) const;

  //				File writers

  void				writeCryptKey(std::ofstream &fileToSave,
					      const MyString &nameOfFileToSave);
  void				writeSize(std::ofstream &fileToSave);
  void				writeMap(std::ofstream &fileToSave);
  void				writeBomb(std::ofstream &fileToSave, Bombe *bombToWrite);
  void				writePlayer(std::ofstream &fileToSave, Player *player);
  void				writeBonMal(std::ofstream &fileToSave, Bonus *bonusToWrite);

  //				AI Functions

  bool				wallCover(int playerX, int playerY, int bombX, int bombY);
};

#endif /* !MAP_HPP_ */
