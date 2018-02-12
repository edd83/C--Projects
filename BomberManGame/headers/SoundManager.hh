//
// SoundManager.hh for SoundManager in /home/casoni_f/test/fmod
// 
// Made by Fabien Casoni
// Login   <casoni_f@epitech.net>
// 
// Started on  Sat Jun  7 13:51:08 2014 Fabien Casoni
// Last update Sat Jun 14 13:16:07 2014 Fabien Casoni
//


#ifndef			_SOUND_MANAGER_HH_
# define		_SOUND_MANAGER_HH_

# include		<string>
# include		<list>
# include		<fmod.hpp>
# include		"GraphParsing.hh"
# include		"Sound.hh"

class			SoundManager
{
 private:
  int			sid;
  FMOD::Sound		*main_sound;
  FMOD::Channel		*user_chan;
  FMOD::System		*sys;
  std::list<Sound *>	sound_list;
  FMOD::Sound		*user_music;
  FMOD::DSP		*echo;
  GraphParsing		parser;

 public:
  SoundManager();
  ~SoundManager();

  int			play(int);
  void			loadSound(const std::string &);
  void			loadStream(const std::string &);
  void			loadMainStream(const std::string &);
  FMOD::Sound		*getUserMusic() const;
  FMOD::Sound		*getMainSound() const;
  FMOD::Channel		*getUserChan() const;
  std::string		getArtist();
  std::string		getTitle();
  unsigned int		getLength();
  unsigned int		getCurrentPos();
  void			pause(FMOD::Channel *);
  void			resume(FMOD::Channel *);
  void			fwd(unsigned int);
  void			bwd(unsigned int);
  void			setVolume(FMOD::Channel *, float);
  void			remove_effects();
  void			add_echo(unsigned int);
  void			update();
  FMOD::Sound		*getSoundById(int);
};


#endif			/* _SOUND_MANAGER_HH_ */
