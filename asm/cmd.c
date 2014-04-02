/*
** cmd.c for cmd in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  2 13:49:55 2014 alex-odet
** Last update Wed Apr  2 13:57:58 2014 alex-odet
*/

#include "struct.h"

t_cmd	tab[]=
  {
    {"live", &my_write_live},
    {NULL, NULL}
  };

char	*write_in_buff(char **cmd)
{
  int	i;
  int	j;

  i = 0;
  while (cmd[i])
    {
      my_strcmp(cmd[i],)
      i++;
    }
}
