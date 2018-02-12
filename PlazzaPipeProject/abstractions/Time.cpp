//
// Time.cpp for plazza in /home/bonnet_v/programs/projects/cpp/plazza
// 
// Made by Bonnet Vivien
// Login   <bonnet_v@epitech.net>
// 
// Started on  Sun Apr 27 13:26:37 2014 Bonnet Vivien
// Last Update Sun Apr 27 13:45:41 2014 Bonnet Vivien
//

#include "Time.hh"
#include "TimeException.hh"

#include <unistd.h>

void
Time::sleepSecs(int secs)
{
  if (sleep(secs) != 0)
    throw TimeException("Sleep failed");
}

void
Time::sleepMsecs(int msecs)
{
  if (usleep(msecs * 1000) != 0)
    throw TimeException("Usleep failed");
}

void
Time::sleepUsecs(int usecs)
{
  if (usleep(usecs) != 0)
    throw TimeException("Usleep failed");
}
