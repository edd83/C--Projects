//
// StringTransformer.hpp for abstract_vm in /home/bonnet_v/programs/projects/cpp/abstract_vm
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Feb 19 11:25:25 2014 Bonnet Vivien
// Last Update Mon Apr 14 16:19:34 2014 Bonnet Vivien
//

#ifndef STRING_TRANSFORMER_HPP_
# define STRING_TRANSFORMER_HPP_

# include <string>
# include <sstream>

# include "StringException.hh"

class		StringTransformer
{
public:
  template <typename T>
  static T			castTo(const std::string &string)
    {
      std::istringstream	iss(string);
      T				data;

      iss >> data;
      if (iss.rdstate() & std::istringstream::failbit)
	throw StringException((std::string)("Cannot cast ") + string);
      return (data);
    }

  template <typename T>
  static std::string		castFrom(T thing)
    {
      std::ostringstream	oss;

      oss << thing;
      return (oss.str());
    }
};

#endif // !STRING_TRANSFORMER_HPP_
