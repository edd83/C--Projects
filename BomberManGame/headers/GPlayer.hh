//
// GPlayer.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Jun  2 19:25:24 2014 ovoyan_s
// Last update Sun Jun 15 17:08:00 2014 ovoyan_s
//

#ifndef				GPLAYER_HH_
# define			GPLAYER_HH_

/*
**				GENERAL INCLUDES
*/

/*
**				MY INCLUDES
*/

namespace			GraphPlayer
{
  enum				ActionToDo
    {
      None,
      Left,
      Right,
      Up,
      Down,
      PutBomb
    };
};

# include			"Entity.hh"
# include			"GModel.hh"
# include			"GraphParsing.hh"
# include			"Map.hh"
# include			"Player.hh"

class				GPlayer : public GModel
{
private:
  unsigned int			frameCounter;
  GraphPlayer::ActionToDo	direction;
  void				(GPlayer::*fptr[4])(Map &, int, int, std::list<GModel*>&);
  gdl::Model			*objectModel;

public:
  GPlayer();
  GPlayer(float scaleToSet, GraphParsing &parseModel, const Point3D<float> &coordinates);
  void				changeActionToDo(const GraphPlayer::ActionToDo &actionToDo);
  void				doAction(Map &, int, int, std::list<GModel*>&);
  void				moveLeft(Map &, int, int, std::list<GModel*>&);
  void				moveRight(Map &, int, int, std::list<GModel*>&);
  void				moveUp(Map &, int, int, std::list<GModel*>&);
  void				moveDown(Map &, int, int, std::list<GModel*>&);
  void				drawPlayer(gdl::AShader *shader, double clockTime);
  void				putBomb(Map &, int, int, std::list<GModel*>&);

  GraphPlayer::ActionToDo	getActionToDo() const;
  unsigned int			getFrameCounter() const;
  gdl::Model			*getModel() const;
  ~GPlayer();
};

#endif			/*	GPLAYER_HH_	*/
