//
// Plazza.hh for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sun Apr 13 09:32:44 2014 Bonnet Vivien
// Last Update Sun Apr 27 17:39:21 2014 Bonnet Vivien
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

# include "GraphicModule.hh"
# include "PackFactory.hh"
# include "Schmidt.hh"
# include "Server.hh"
# include "Thread.hpp"

# define INPUT_NAME	("Input")

class			Plazza : public GraphicModule, public Server
{
private:
  typedef void			(Plazza::*Method)();
  typedef Thread<Plazza*, void>	PlazzaThread;

  typedef std::map<nc::Window::Event, Plazza::Method>	PlazzaEventHandler;

private:
  static void	waitForKitchen(Plazza* plazza);
  static void	launchPlazzaServer(Plazza* plazza);
  static void	getClientCommand(Plazza* plazza, const std::string& command);

private:
  std::list<Kitchen*>	m_kitchenList;
  PlazzaEventHandler	m_plazzaEventHandlers;
  PackFactory		m_packFactory;
  Schmidt		m_schmidt;
  char*			m_port;

public:
  Plazza(int argc, char **argv);
  ~Plazza();

private:
  Kitchen*	findFreeKitchen();
  Kitchen*	createAndPrepareKitchen();
  void		waitKitchen();

private:
  void	addPizzaToDo(const Pizza::Pack& pack);

public:
  void		analyseCommand(const std::string& command, const std::string& author,
			       Register::ColorID id);
  const char*	getPort() const;

private:
  void		getCommand();
  void		scrollUp();
  void		scrollDown();

protected:
  void	getEvent(nc::Window::Event event);

public:
  void	launch();
};

#endif // !PLAZZA_HH_
