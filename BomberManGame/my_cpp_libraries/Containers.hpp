//
// Containers.hpp for ecosysteme in /home/ovoyan_s/rendu/ECOSYSTEME
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri May  2 13:32:00 2014 ovoyan_s
// Last update Mon May 26 23:29:20 2014 ovoyan_s
//

#ifndef				CONTAINERS_HPP_
# define			CONTAINERS_HPP_

/*
**				GENERAL INCLUDES
*/

//				CPP includes

# include			<iostream>
# include			<list>
# include			<sstream>
# include			<string>

//				C includes

# include			<cstdlib>
# include			<ctime>

/*
**				MY INCLUDES
*/

# include			"Random.hh"
# include			"MyException.hh"

class				MyStringArray : public std::list<std::string>
{
public:
  MyStringArray();
  MyStringArray(const std::list<std::string> &string_array_to_set);
  MyStringArray			&operator=(const MyStringArray &string_array_to_set);
  MyStringArray			&operator=(const std::list<std::string> &string_array_to_set);
  void				SetStringArray(const MyStringArray &sa_to_set);
  void				SetStringArray(const std::list<std::string> &strng_array_to_set);
  void				SetRandomStringArray(int x_size, int y_size, int rand_index);
  void				AddString(const std::string &str_to_add);
  void              AddString2(const std::string &str_to_add);
  std::string			GetStringAt(int index) const;
  void				Show();
  char				GetCharAt(unsigned int str_index, unsigned int char_index) const;
  void				SetCharAt(unsigned int str_index, unsigned int char_index,
					  unsigned char charToChange);
  std::list<std::string>	GetStringArray() const;
  ~MyStringArray();
};

class				MyString : public std::string
{
private:
  Random			random;
public:
  MyString();
  MyString(const std::string &string_to_set);
  MyString			&operator=(const std::string &string_to_set);

  //				Manipulations

  void				SetString(const std::string &string_to_set);
  void				StrReplaceAll(const std::string &string_to_change,
					      const std::string &string_to_set);
  void				PushBack(const std::string &string_to_change);
  void				RandomString(int string_size);
  void				RandomStringWithIndex(int string_size, int random_index);
  void				RandomNumberString(int string_size, int random_index);

  //				Getters

  int				NbOfWords();
  std::string			StrWordString(const std::string &str_to_use, int *counter,
					      char split_char);
  void				StrWordTab(char split_char, MyStringArray *list_to_sent);
  std::string			GetSectionOfString(char c, int iterator1, int iterator2);
  int				ToInt();
  double			ToDouble();
  int				GetOccurences(const std::string &string_of_occurence);
  
  ~MyString();
};

template <class T>
class				Point3D
{
private:
  T				coordinates[3];
public:
  Point3D()
  {
    this->coordinates[0] = 0;
    this->coordinates[1] = 0;
    this->coordinates[2] = 0;
  }

  Point3D(T coords_to_set[3])
  {
    this->coordinates[0] = coords_to_set[0];
    this->coordinates[1] = coords_to_set[1];
    this->coordinates[2] = coords_to_set[2];
  }

  template <typename W>
  Point3D(const Point3D<W> &coords_to_set)
  {
    this->coordinates[0] = coords_to_set.GetX();
    this->coordinates[1] = coords_to_set.GetY();
    this->coordinates[2] = coords_to_set.GetZ();
  }

  Point3D(T x, T y, T z)
  {
    this->coordinates[0] = x;
    this->coordinates[1] = y;
    this->coordinates[2] = z;
  }

  template <typename W>
  Point3D			&operator=(const Point3D<W> &coords_to_set)
  {
    this->coordinates[0] = coords_to_set.GetX();
    this->coordinates[1] = coords_to_set.GetY();
    this->coordinates[2] = coords_to_set.GetZ();
    return (*this);
  }

  Point3D			&operator=(T coords_to_set[3])
  {
    this->coordinates[0] = coords_to_set[0];
    this->coordinates[1] = coords_to_set[1];
    this->coordinates[2] = coords_to_set[2];
    return (*this);
  }

  void				SetCoordinates(T coords_to_set[3])
  {
    this->coordinates[0] = coords_to_set[0];
    this->coordinates[1] = coords_to_set[1];
    this->coordinates[2] = coords_to_set[2];
  }

  void				SetCoordinates(T c_x, T c_y, T c_z)
  {
    this->coordinates[0] = c_x;
    this->coordinates[1] = c_y;
    this->coordinates[2] = c_z;
  }

  T				GetX() const
  {
    return (this->coordinates[0]);
  }

  T				GetY() const
  {
    return (this->coordinates[1]);
  }

  T				GetZ() const
  {
    return (this->coordinates[2]);
  }

  ~Point3D()
  {

  }

};

template <class T>
class				Point2D
{
private:
  T				coordinates[2];
public:
  Point2D()
  {
    this->coordinates[0] = 0;
    this->coordinates[1] = 0;
  }

  Point2D(T coords_to_set[2])
  {
    this->coordinates[0] = coords_to_set[0];
    this->coordinates[1] = coords_to_set[1];
  }

  template <typename W>
  Point2D(const Point2D<W> &coords_to_set)
  {
    this->coordinates[0] = coords_to_set.GetX();
    this->coordinates[1] = coords_to_set.GetY();
  }

  Point2D(T x, T y)
  {
    this->coordinates[0] = x;
    this->coordinates[1] = y;
  }

  template <typename W>
  Point2D			&operator=(const Point2D<W> &coords_to_set)
  {
    this->coordinates[0] = coords_to_set.GetX();
    this->coordinates[1] = coords_to_set.GetY();
    return (*this);
  }

  Point2D			&operator=(T coords_to_set[2])
  {
    this->coordinates[0] = coords_to_set[0];
    this->coordinates[1] = coords_to_set[1];
    return (*this);
  }

  void				SetCoordinates(T coords_to_set[2])
  {
    this->coordinates[0] = coords_to_set[0];
    this->coordinates[1] = coords_to_set[1];
  }

  T				GetX() const
  {
    return (this->coordinates[0]);
  }

  T				GetY() const
  {
    return (this->coordinates[0]);
  }

  ~Point2D()
  {

  }
};

#endif			/*	CONTAINERS_HH_	*/
