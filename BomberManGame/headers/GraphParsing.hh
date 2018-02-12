//
// GraphParsing.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri Jun  6 18:15:02 2014 ovoyan_s
// Last update Mon Jun  9 23:59:10 2014 ovoyan_s
//

#ifndef				GRAPHPARSING_HH_
# define			GRAPHPARSING_HH_

/*
**				GENERAL INCLUDES
*/

# include			<fstream>
# include			<iostream>
# include			<string>

/*
**				MY INCLUDES				
*/

# include			"Containers.hpp"

class				GraphParsing
{
private:
  MyStringArray			*stringArray;

public:
  GraphParsing();
  void				parseFile(const std::string &nameOfFileToParse);
  std::string			getParsedFile(const std::string &modelNature,
					      const std::string &fileNature);
  MyStringArray			getStringArray();
  ~GraphParsing();
};

#endif				/*	GRAPHPARSING_HH_	*/
