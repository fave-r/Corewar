/*
** fmod.c for corewar in /home/blackbird/work/Corewar/vm/graphic
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 12 16:52:24 2014 romaric
** Last update Sat Apr 12 17:11:13 2014 romaric
*/

#include "vm.h"

void    fmode(void)
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*musique;
  FMOD_CHANNEL	*channel;
  FMOD_RESULT	resultat;
  char		*str;

  str = "Martin Garrix - Animals.mp3";
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);
  FMOD_Sound_SetLoopCount(musique, -1);
  resultat = FMOD_System_CreateSound(system, str, FMOD_SOFTWARE
                                     | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  if (resultat != FMOD_OK)
    {
      my_putstr("Cannot find ", 2);
      my_putstr(str, 2);
      my_putstr(", put this file next to the executable 'corewar'", 2);
      write(2, "\n", 1);
    }
  else
    {
      FMOD_System_GetChannel(system, 9, &channel);
      FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
    }
}
