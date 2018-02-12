//
// KitchenGraphic.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 17:18:42 2014 Bonnet Vivien
// Last Update Sun Apr 27 18:25:06 2014 Bonnet Vivien
//

#ifndef KITCHEN_GRAPHIC_HH_
# define KITCHEN_GRAPHIC_HH_

# include "Mutex.hh"
# include "PlazzaWindow.hh"

# define KITCHEN_GRAPHIC_COLOR		(nc::Color(COLOR_BLACK, COLOR_YELLOW))

class	KitchenGraphic : public PlazzaWindow
{
protected:
  Mutex*	m_cursorMutex;
  bool		m_selected;

public:
  KitchenGraphic(const std::string& name, Mutex* mutex);
  virtual ~KitchenGraphic();

public:
  virtual void	resize(int width, int height);

public:
  bool	isSelected() const;

public:
  void	select();
  void	unselect();
};

#endif // !KITCHEN_GRAPHIC_HH_
