//
// SoundManager.cpp for SoundManager in /home/casoni_f/test/fmod
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Sat Jun  7 13:53:51 2014 Fabien Casoni
// Last update Sun Jun 15 17:47:40 2014 Fabien Casoni
//

#include	<string>
#include	<fstream>
#include	"SoundManager.hh"

SoundManager::SoundManager()
{
  sid = 0;
  System_Create(&this->sys);
  this->sys->init(100, FMOD_INIT_NORMAL, NULL);
  this->sound_list.clear();
}

SoundManager::~SoundManager()
{
  this->sys->release();
}

int		SoundManager::play(int soundId)
{
  if (soundId > 0)
    this->sys->playSound(FMOD_CHANNEL_FREE, this->getSoundById(soundId), false, 0);
  else if (soundId == 0)
    this->sys->playSound(FMOD_CHANNEL_FREE, this->main_sound, false, &this->user_chan);
  else
    this->sys->playSound(FMOD_CHANNEL_FREE, this->user_music, false, &this->user_chan);
  return (0);
}

void		SoundManager::loadSound(const std::string &filename)
{
  FMOD::Sound	*s;
  Sound		*sound = new Sound(++sid);

  this->sys->createSound(filename.c_str(), FMOD_DEFAULT, 0, &s);
  sound->setSound(s);
  this->sound_list.push_back(sound);
}

void		SoundManager::loadStream(const std::string &filename)
{
  this->sys->createStream(filename.c_str(), FMOD_DEFAULT, 0, &this->user_music);
}

void		SoundManager::loadMainStream(const std::string &filename)
{
  this->sys->createStream(filename.c_str(), FMOD_DEFAULT, 0, &this->main_sound);
}


void		SoundManager::pause(FMOD::Channel *channel)
{
  channel->setPaused(true);
}

void		SoundManager::resume(FMOD::Channel *channel)
{
  channel->setPaused(false);
}

FMOD::Sound	*SoundManager::getUserMusic() const
{
  return (this->user_music);
}

FMOD::Sound	*SoundManager::getMainSound() const
{
  return (this->main_sound);
}

FMOD::Channel	*SoundManager::getUserChan() const
{
  return (this->user_chan);
}

std::string	SoundManager::getArtist()
{
  FMOD_TAG	tag;
  std::string	artist;

  this->user_music->getTag("ARTIST", 0, &tag);
  artist = static_cast<char *>(tag.data);
  return (artist);
}

std::string	SoundManager::getTitle()
{
  FMOD_TAG	tag;
  std::string	title;

  this->user_music->getTag("TITLE", 0, &tag);
  title = static_cast<char *>(tag.data);
  return (title);
}

unsigned int	SoundManager::getLength()
{
  unsigned int	i;

  this->user_music->getLength(&i, FMOD_TIMEUNIT_MS);
  return (i);
}

unsigned int	SoundManager::getCurrentPos()
{
  unsigned int	i;

  this->user_chan->getPosition(&i, FMOD_TIMEUNIT_MS);
  return (i);
}

void		SoundManager::fwd(unsigned int i)
{
  unsigned int	c;
  unsigned int	l;

  c = this->getCurrentPos();
  l = this->getLength();
  if (c + i < l)
    this->user_chan->setPosition(c + i, FMOD_TIMEUNIT_MS);
}

void		SoundManager::bwd(unsigned int i)
{
  unsigned int	c;

  c = this->getCurrentPos();
  if (c - i > 0)
    this->user_chan->setPosition(c - i, FMOD_TIMEUNIT_MS);
}

/*
Le volume est compris entre 0 et 1
*/

void		SoundManager::setVolume(FMOD::Channel *channel, float f)
{
  channel->setVolume(f);
}

void		SoundManager::add_echo(unsigned int i)
{
  this->sys->createDSPByType(FMOD_DSP_TYPE_ECHO, &this->echo);
  this->echo->setParameter(FMOD_DSP_ECHO_DELAY, i);
  this->sys->addDSP(this->echo, 0);
}

void		SoundManager::update()
{
  this->sys->update();
}
void		SoundManager::remove_effects()
{
  this->echo->remove();
}

FMOD::Sound	*SoundManager::getSoundById(int soundId)
{
  std::list<Sound *>::iterator	it;

  it = this->sound_list.begin();
  while (it != this->sound_list.end()
	 && (*it)->getId() != soundId)
    ++it;
  return ((*it)->getSound());
}
