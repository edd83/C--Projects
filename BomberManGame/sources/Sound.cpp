//
// Sound.cpp for SoundManager in /home/casoni_f/test/fmod
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Sat Jun  7 18:48:09 2014 Fabien Casoni
// Last update Sat Jun  7 19:11:29 2014 Fabien Casoni
//

#include	"Sound.hh"

Sound::Sound()
{
}

Sound::Sound(int new_id)
{
  this->id = new_id;
}

Sound::~Sound()
{
}

int		Sound::getId() const
{
  return (this->id);
}

FMOD::Sound	*Sound::getSound() const
{
  return (this->sound);
}

void		Sound::setSound(FMOD::Sound *s)
{
  sound = s;
}
