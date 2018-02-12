//
// Color.hh for plazza in /home/bonnet_v/programs/projects/cpp/ncurses
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 13:50:28 2014 Bonnet Vivien
// Last Update Fri Apr 25 16:43:00 2014 Bonnet Vivien
//

#ifndef COLOR_HH_
# define COLOR_HH_

namespace nc
{

class	Color
{
private:
  static int	g_counter;

private:
  int	m_id;
  short	m_foreground;
  short	m_background;

public:
  Color();
  Color(short foreground, short background);
  ~Color();

public:
  int	getAttr() const;
};

}

#endif // !COLOR_HH_
