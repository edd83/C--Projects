//
// Graphic.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Tue Apr 15 16:08:28 2014 Bonnet Vivien
// Last Update Sun Apr 27 15:54:04 2014 Bonnet Vivien
//

#ifndef GRAPHIC_MODULE_HH_
# define GRAPHIC_MODULE_HH_

# include <list>
# include <map>

# include "Application.hh"
# include "KitchenGraphic.hh"
# include "Prompt.hh"
# include "Register.hh"
# include "Window.hh"

class		GraphicModule : public nc::Application
{
private:
  typedef std::list<KitchenGraphic*>	KitchenList;
  typedef void				(GraphicModule::*Method)();

  typedef std::map<nc::Window::Event, GraphicModule::Method>	GraphicEventHandler;
  typedef std::map<nc::Window::Event, Prompt::Method>		PromptEventHandler;

private:
  bool			m_loop;

protected:
  KitchenGraphic*	m_kitchen;
  Register		m_register;
  Prompt		m_prompt;
  GraphicEventHandler	m_graphicEventHandlers;
  PromptEventHandler	m_promptEventHandlers;
  Mutex			m_cursorMutex;
  int			m_width;
  int			m_height;


public:
  GraphicModule();
  ~GraphicModule();

private:
  void	resize();

protected:
  virtual void	getEvent(nc::Window::Event event);

public:
  void	resetCursor();
  void	loop();

protected:
  void		stopLoop();
  std::string	getPromptLine();

protected:
  void		addMessageToRegister(const std::string& message, Register::ColorID id);
  void		selectKitchen(KitchenGraphic* kitchen);
};

#endif // !GRAPHIC_MODULE_HH_
