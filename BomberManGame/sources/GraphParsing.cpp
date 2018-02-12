//
// GraphParsing.cpp for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri Jun  6 18:22:31 2014 ovoyan_s
// Last update Tue Jun 10 12:16:01 2014 ovoyan_s
//

/*
**					MY INCLUDES
*/

#include				"GraphParsing.hh"

GraphParsing::GraphParsing()
{
  this->stringArray = NULL;
}

void					GraphParsing::parseFile(const std::string &nameOfFileToParse)
{
  std::ifstream		fileToParse;
  std::string		lineOfFile;

  fileToParse.open(static_cast<const char*>(nameOfFileToParse.c_str()), std::fstream::in);
  this->stringArray = new MyStringArray;
  if (!fileToParse.good())
    throw MyException ("The file is invalid");
  while (std::getline(fileToParse, lineOfFile))
    this->stringArray->push_back(lineOfFile);
  if (this->stringArray->size() == 0)
    throw MyException ("The file is empty");
}

std::string				GraphParsing::getParsedFile(const std::string &modelNature,
								    const std::string &fileNature)
{
  std::list<std::string>::iterator	it;
  MyString				lineOfFile;
  MyStringArray				lineArray;
  int					counter;

  counter = -1;
  if (this->stringArray == NULL)
    this->stringArray = new MyStringArray;
  while (++counter < 10 && this->stringArray->size() == 0)
    this->parseFile(fileNature);
  it = this->stringArray->begin();
  while (it != this->stringArray->end())
    {
      lineOfFile = (*it);
      lineOfFile.StrWordTab(' ', &lineArray);
      if (lineArray.size() != 3)
	throw MyException ("The file is incorrect");
      if (lineArray.GetStringAt(0) == modelNature)
	return (lineArray.GetStringAt(2));
      ++it;
      counter = counter + 1;
    }
  throw MyException ("The file encountered a problem in her loading");
  return ("");
}

MyStringArray				GraphParsing::getStringArray()
{
  return (*this->stringArray);
}

GraphParsing::~GraphParsing()
{

}
