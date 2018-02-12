//
// Sound.hh for SoundManager in /home/casoni_f/test/fmod
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Sat Jun  7 18:44:52 2014 Fabien Casoni
// Last update Sat Jun  7 19:11:00 2014 Fabien Casoni
//

#ifndef		_SOUND_HH_
# define	_SOUND_HH_

#include	<fmod.hpp>

class		Sound
{
private:
  int		id;
  FMOD::Sound	*sound;

public:
  Sound();
  Sound(int);
  ~Sound();
  int		getId() const;
  FMOD::Sound	*getSound() const;
  void		setSound(FMOD::Sound *);
};

#endif		/* _SOUND_HH_ */
