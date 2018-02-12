//
// application.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 10:43:14 2014 Bonnet Vivien
// Last Update Fri Apr 25 18:07:44 2014 Bonnet Vivien
//

#ifndef APPLICATION_HH_
# define APPLICATION_HH_

namespace nc
{

class	Application
{
public:
  static void	urgencyEnd();

public:
  Application();
  virtual ~Application();

public:
  int	getWidth() const;
  int	getHeight() const;
  void	getWidthAndHeight(int& width, int& height) const;

public:
  void	setCursorVisibility(bool cursor);

public:
  void	clear();
  void	display();
};

}

#endif // !APPLICATION_HH_
