//
// PlazzaWindow.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Wed Apr 16 09:32:50 2014 Bonnet Vivien
// Last Update Sat Apr 26 19:35:04 2014 Bonnet Vivien
//

#ifndef PLAZZA_WINDOW_HH_
# define PLAZZA_WINDOW_HH_

# include "Color.hh"
# include "Mutex.hh"
# include "Window.hh"

# define PLAZZA_WINDOW_ATTR	(A_NORMAL)

class	PlazzaWindow : public nc::Window
{
public:
  PlazzaWindow(const std::string& name, const nc::Color& color);
  ~PlazzaWindow();

public:
  virtual void	resize(int width, int height);
  virtual void	update() = 0;
};

#endif // !PLAZZA_WINDOW_HH_
