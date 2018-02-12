//
// ModelManager.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/merge-client
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun 10 19:05:52 2014 ovoyan_s
// Last update Tue Jun 10 20:45:01 2014 ovoyan_s
//

#ifndef					MODELMANAGER_HH_
# define				MODELMANAGER_HH_

/*
**					GENERAL INCLUDES
*/

# include				<Model.hh>
# include				<vector>

/*
**					MY INCLUDES
*/

# include				"GModel.hh"
# include				"GraphParsing.hh"

class					ModelManager
{
private:
  std::vector<gdl::Model*>		modList;	
public:
  ModelManager();
  gdl::Model				*loadMod(GraphParsing &parseModel,
						   const std::string &loadAsset);

  void					loadPhysics(GraphParsing &parseModel);
  void					loadLettersAM(GraphParsing &parseModel);
  void					loadLettersNZ(GraphParsing &parseModel);
  void					loadSpecials(GraphParsing &parseModel);

  gdl::Model				*getModelAt(int index);
  gdl::Model				*getMod(const GModel *modelToUse);

  ~ModelManager();
};

#endif					/*	MODELMANAGER_HH_	*/
