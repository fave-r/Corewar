/*
** cmd.c for cmd in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  2 13:49:55 2014 alex-odet
** Last update Sun Apr  6 15:18:45 2014 romaric
*/

#include "struct.h"

t_cmd	tab[]=
  {
    {"live", &my_write_live},
    {"zjmp", &my_write_zjmp},
    {NULL, NULL}
  };

char	*write_in_buff(char **cmd)
{
  int	len;
  int	i;
  int	j;
  int	x;
  char	*tmp;
  char	*big_buff;

  i = 0;
  len = 0;
  while (cmd[i])
    {
      j = 0;
      while (tab[j].cmd)
	{
	  x = my_strcmp(cmd[i], tab[j].cmd);
	  j++;
	}
      tmp = NULL;
      big_buff = tab[j].ptr(cmd[i + 1], &len);
      i += 2;
    }
  return (big_buff);
}
