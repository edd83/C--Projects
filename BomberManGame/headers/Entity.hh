//
// Entity.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon May 26 18:32:53 2014 ovoyan_s
// Last update Wed Jun 11 16:51:55 2014 ovoyan_s
//

#ifndef				ENTITY_HH_
# define			ENTITY_HH_

# include			<iostream>
# include			<string>

namespace			EntityNS
{
  enum				Nature
    {
      NoNature,
      Bonus,
      Bombe,
      Player,
      Wall,
      Crate,
      Menu34,
      Menu2510,
      letterA,
      letterB,
      letterC,
      letterD,
      letterE,
      letterF,
      letterG,
      letterH,
      letterI,
      letterJ,
      letterK,
      letterL,
      letterM,
      letterN,
      letterO,
      letterP,
      letterQ,
      letterR,
      letterS,
      letterT,
      letterU,
      letterV,
      letterW,
      letterX,
      letterY,
      letterZ,
      Zero,
      One,
      Two,
      Three,
      Four,
      Five,
      Six,
      Seven,
      Eight,
      Nine,
      Del,
      Enter,
      Underscore,
      Point,
      Slash,
      Dash,
    };
}

class				Entity
{
protected:
  unsigned int			_x;
  unsigned int			_y;
  EntityNS::Nature		typeOfEntity;

  Entity();
public:
  //				Constructor / Destructor

  Entity(unsigned int coordX, unsigned int coordY, const EntityNS::Nature &typeToSet);
  virtual ~Entity() { };

  //				Setters

  void				setX(unsigned int coordToSetX);
  void				setY(unsigned int coordToSetY);
  void				setEntity(const EntityNS::Nature &typeToSet);

  //				Getters

  unsigned int			getX() const;
  unsigned int			getY() const;
  EntityNS::Nature		getEntity() const;
};

#endif				/*	ENTITY_HH_	*/
