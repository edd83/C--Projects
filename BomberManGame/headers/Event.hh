//
// Event.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 12 17:55:09 2014 ovoyan_s
// Last update Sun Jun 15 16:04:38 2014 ovoyan_s
//

#ifndef				EVENT_HH_
# define			EVENT_HH_

/*
**				GDL INCLUDES
*/

# include			<Input.hh>
# include			<SdlContext.hh>

/*
**				GENERAL INCLUDES
*/

# include			<iostream>
# include			<string>

/*
**
*/

# include			"Time.hh"

class				Event
{
private:
  gdl::Input			game_input;
  bool				(Event::*mem_ptr[16])();
  int				eventId;
  int				mouseCoordinatesPush[2];
  int				mouseCoordinates[2];
  int				mouseWheel;
  Event();
  
public:
  Event(gdl::SdlContext *sdl_context);
  int				ret_input_id();
  bool				input_quit();
  bool				input_esc();
  bool				key_up();
  bool				key_down();
  bool				key_left();
  bool				key_right();
  bool				key_a();
  bool				key_e();
  bool				key_z();
  bool				key_s();
  bool				key_q();
  bool				key_d();
  bool				key_space();
  bool				key_m();
  bool				key_l();

  bool				leftMouseCoordPush();
  bool				MouseWheel();

  void				setEvent(int id_to_set);

  int				getEvent() const;
  void				getMouseCoord(int *coord_x, int *coord_y);
  void				getMouseCoordPush(int *coord_x, int *coord_y);
  int				getMouseWheel() const;
  ~Event();
};

#endif				/*	EVENT_HH_	*/
