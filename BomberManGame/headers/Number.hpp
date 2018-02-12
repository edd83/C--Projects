//
// Number.hpp for cpp_libraries in /home/ovoyan_s/rendu/PSU_2013_zappy/ai_sources/my_cpp_libraries
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May  5 20:46:06 2014 ovoyan_s
// Last update Mon Jun  9 18:32:50 2014 ovoyan_s
//

#ifndef			NUMBER_HPP_
# define		NUMBER_HPP_

/*
**			GENERAL INCLUDES
*/

# include		<math.h>

/*
**			MY INCLUDES
*/

# include		"MyException.hh"

template <typename W>
class                   Number
{
private:
  W	                my_number;
public:
  Number()
  {
    this->my_number = 0;
  }

  template <typename T>
  Number(const Number<T> &number_to_set)
  {
    this->my_number = number_to_set.getNumber();
  }

  template <typename T>
  Number(const T &number_to_set)
  {
    this->my_number = number_to_set;
  }

  W			getAbsoluteValue()
  {
    if (this->my_number < 0)
      return (this->my_number * -1);
    else
      return (this->my_number);
  }

  template <typename T>
  Number<W>             &operator=(const Number<T> &number_to_use)
  {
    this->my_number = number_to_use.getNumber();
    return (*this);
  }

  template <typename T>
  Number<W>		&operator=(const T &number_to_use)
  {
    this->my_number = number_to_use;
    return (*this);
  }

  template <typename T>
  bool			operator<(const Number<T> &number_to_use)
  {
    if (this->my_number < number_to_use.getNumber())
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator<(const T &number_to_use)
  {
    if (this->my_number < number_to_use)
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator>(const Number &number_to_use)
  {
    if (this->my_number > number_to_use.getNumber())
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator>(const T &number_to_use)
  {
    if (this->my_number > number_to_use)
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator==(const Number &number_to_use)
  {
    if (this->my_number == number_to_use.getNumber())
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator==(const T &number_to_use)
  {
    if (this->my_number > number_to_use)
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator>=(const Number &number_to_use)
  {
    if (this->my_number >= number_to_use.getNumber())
      return (true);
    return (false);
  }
  
  template <typename T>
  bool                  operator>=(const T &number_to_use)
  {
    if (this->my_number >= number_to_use)
      return (true);
    return (false);
  }

  template <typename T>
  bool                  operator<=(const Number &number_to_use)
  {
    if (this->my_number <= number_to_use.getNumber())
      return (true);
    return (false);
  }

  template <typename T>
  bool			operator<=(const T &number_to_use)
  {
    if (this->my_number <= number_to_use)
      return (true);
    return (false);
  }

  template <typename T>
  Number<W>             &operator+(const Number<T> &number_to_use)
  {
    this->my_number = this->my_number + number_to_use.getNumber();
    return (*this);
  }

  template <typename T>
  Number                &operator+(const T &number_to_use)
  {
    this->my_number = this->my_number + number_to_use;
    return (*this);
  }

  template <typename T>
  Number<W>            &operator-(const Number<T> &number_to_use)
  {
    this->my_number = this->my_number + number_to_use.getNumber();
    return (*this);
  }

  template <typename T>
  Number<W>            &operator-(const T &number_to_use)
  {
    this->my_number = this->my_number - number_to_use;
    return (*this);
  }

  template <typename T>
  Number<W>             &operator*(const Number<T> &number_to_use)
  {
    this->my_number = this->my_number * number_to_use.getNumber();
    return (*this);
  }

  template <typename T>
  Number<W>             &operator*(const T &number_to_use)
  {
    this->my_number = this->my_number * number_to_use;
    return (*this);
  }

  template <typename T>
  Number<W>             &operator/(const Number<T> &number_to_use)
  {
    if (number_to_use.getNumber() == 0)
      throw MyException("Division by Zero");
    this->my_number = this->my_number / number_to_use.getNumber();
    return (*this);
  }

  template <typename T>
  Number<W>             &operator/(const T &number_to_use)
  {
    if (number_to_use == 0)
      throw MyException("Division by Zero");
    this->my_number = this->my_number / number_to_use;
      throw MyException("Number Division Error");
    return (*this);
  }

  template <typename T>
  Number<W>            &operator%(const Number<T> &number_to_use)
  {
    if (number_to_use.getNumber() == 0)
      throw MyException("Modulation by Zero");
    this->my_number = fmod((double)this->my_number, (double)number_to_use.getNumber());
    return (*this);
  }

  template <typename T>
  Number<W>            &operator%(const T &number_to_use)
  {
    if (number_to_use == 0)
      throw MyException("Modulation by Zero");
    this->my_number = fmod((double)this->my_number, (double)number_to_use);
    return (*this);
  }

  W			getNumber() const
  {
    return (this->my_number);
  }

  ~Number()
  {
  };
};

#endif			/*	NUMBER_HPP_	*/
