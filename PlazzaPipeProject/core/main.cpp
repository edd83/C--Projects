//
// main.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Thu Apr 10 13:44:20 2014 Bonnet Vivien
// Last Update Sun Apr 27 10:55:04 2014 Bonnet Vivien
//

#include <exception>
#include <iostream>

#include "Plazza.hh"
#include "PlazzaException.hh"
#include "NcursesException.hh"

int		main(int argc, char **argv)
{
  Plazza	*app;
  int		return_value;

  try
    {
      app = new Plazza(argc, argv);
      app->launch();
      delete (app);
      return_value = 0;
    }

  catch (const PlazzaException& plazzaException)
    {
      nc::Application::urgencyEnd();
      std::cerr << "Plazza fatal error : " << plazzaException.what() << std::endl;
      return_value = 1;
    }

  catch (const nc::NcursesException& ncursesException)
    {
      nc::Application::urgencyEnd();
      std::cerr << "Ncurses fatal error : " << ncursesException.what() << std::endl;
      return_value = 1;
    }

  catch (const std::exception& exception)
    {
      std::cerr << "Fatal error : " << exception.what() << std::endl;
      return_value = 2;
    }

  catch (...)
    {
      std::cerr << "MEGA Fatal error : unknow" << std::endl;
      return_value = 3;
    }

  return (return_value);
}
