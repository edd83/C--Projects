//
// ModelManager.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/merge-client
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun 10 19:12:26 2014 ovoyan_s
// Last update Sun Jun 15 17:48:00 2014 Fabien Casoni
//

/*
**						MY INCLUDES
*/

#include					"ModelManager.hh"

ModelManager::ModelManager()
{
  GraphParsing					parseMod;

  parseMod.parseFile("modelsFile");
  this->loadPhysics(parseMod);
  this->loadLettersAM(parseMod);
  this->loadLettersNZ(parseMod);
  this->loadSpecials(parseMod);
}

gdl::Model					*ModelManager::loadMod(GraphParsing &parseMod,
								       const std::string &loadAsset)
{
  std::string					strErr;
  std::string					fileName;
  gdl::Model					*modelToRet;

  fileName = parseMod.getParsedFile(loadAsset, "modelsFile");
  strErr = "The loading of the file " + fileName + " encountered a problem.";
  modelToRet = new gdl::Model;
  if (!modelToRet->load(fileName))
    throw MyException (strErr);
  return (modelToRet);
}

void						ModelManager::loadPhysics(GraphParsing &parseMod)
{
  this->modList.push_back(this->loadMod(parseMod, "Bonus"));
  this->modList.push_back(this->loadMod(parseMod, "Bombe"));
  this->modList.push_back(this->loadMod(parseMod, "Player"));
  this->modList.push_back(this->loadMod(parseMod, "Wall"));
  this->modList.push_back(this->loadMod(parseMod, "Crate"));
  this->modList.push_back(this->loadMod(parseMod, "Menu3-4"));
  this->modList.push_back(this->loadMod(parseMod, "Menu2o5-10"));
}

void						ModelManager::loadLettersAM(GraphParsing &parseMod)
{
  this->modList.push_back(this->loadMod(parseMod, "LetterA"));
  this->modList.push_back(this->loadMod(parseMod, "LetterB"));
  this->modList.push_back(this->loadMod(parseMod, "LetterC"));
  this->modList.push_back(this->loadMod(parseMod, "LetterD"));
  this->modList.push_back(this->loadMod(parseMod, "LetterE"));
  this->modList.push_back(this->loadMod(parseMod, "LetterF"));
  this->modList.push_back(this->loadMod(parseMod, "LetterG"));
  this->modList.push_back(this->loadMod(parseMod, "LetterH"));
  this->modList.push_back(this->loadMod(parseMod, "LetterI"));
  this->modList.push_back(this->loadMod(parseMod, "LetterJ"));
  this->modList.push_back(this->loadMod(parseMod, "LetterK"));
  this->modList.push_back(this->loadMod(parseMod, "LetterL"));
  this->modList.push_back(this->loadMod(parseMod, "LetterM"));
}

void						ModelManager::loadLettersNZ(GraphParsing &parseMod)
{
  this->modList.push_back(this->loadMod(parseMod, "LetterN"));
  this->modList.push_back(this->loadMod(parseMod, "LetterO"));
  this->modList.push_back(this->loadMod(parseMod, "LetterP"));
  this->modList.push_back(this->loadMod(parseMod, "LetterQ"));
  this->modList.push_back(this->loadMod(parseMod, "LetterR"));
  this->modList.push_back(this->loadMod(parseMod, "LetterS"));
  this->modList.push_back(this->loadMod(parseMod, "LetterT"));
  this->modList.push_back(this->loadMod(parseMod, "LetterU"));
  this->modList.push_back(this->loadMod(parseMod, "LetterV"));
  this->modList.push_back(this->loadMod(parseMod, "LetterW"));
  this->modList.push_back(this->loadMod(parseMod, "LetterX"));
  this->modList.push_back(this->loadMod(parseMod, "LetterY"));
  this->modList.push_back(this->loadMod(parseMod, "LetterZ"));
}

void						ModelManager::loadSpecials(GraphParsing &parseMod)
{
  this->modList.push_back(this->loadMod(parseMod, "Number0"));
  this->modList.push_back(this->loadMod(parseMod, "Number1"));
  this->modList.push_back(this->loadMod(parseMod, "Number2"));
  this->modList.push_back(this->loadMod(parseMod, "Number3"));
  this->modList.push_back(this->loadMod(parseMod, "Number4"));
  this->modList.push_back(this->loadMod(parseMod, "Number5"));
  this->modList.push_back(this->loadMod(parseMod, "Number6"));
  this->modList.push_back(this->loadMod(parseMod, "Number7"));
  this->modList.push_back(this->loadMod(parseMod, "Number8"));
  this->modList.push_back(this->loadMod(parseMod, "Number9"));
  this->modList.push_back(this->loadMod(parseMod, "Del"));
  this->modList.push_back(this->loadMod(parseMod, "Enter"));
  this->modList.push_back(this->loadMod(parseMod, "Underscore"));
  this->modList.push_back(this->loadMod(parseMod, "Point"));
  this->modList.push_back(this->loadMod(parseMod, "Slash"));
  this->modList.push_back(this->loadMod(parseMod, "Dash"));
  this->modList.push_back(this->loadMod(parseMod, "BombMax"));
  this->modList.push_back(this->loadMod(parseMod, "Speed"));
  this->modList.push_back(this->loadMod(parseMod, "Armor"));
}

gdl::Model					*ModelManager::getModelAt(int index)
{
  if (index > static_cast<int>(this->modList.size()))
    throw MyException ("The entered index is invalid (too big)");
  if (index < 0)
    throw MyException ("The entered index is invalid (too low)");
  return (this->modList[index]);
}

gdl::Model					*ModelManager::getMod(const GModel *modelToUse)
{
  return (getModelAt(modelToUse->getModelType() - 1));
}

ModelManager::~ModelManager()
{

}
