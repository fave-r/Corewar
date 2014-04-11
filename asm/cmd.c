/*
** cmd.c for cmd in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  2 13:49:55 2014 alex-odet
** Last update Sat Apr 12 00:36:07 2014 alex-odet
*/

#include "struct.h"

t_cmd	tab[]=
  {
    {"live", &my_write_live},
    {"zjmp", &my_write_zjmp},
    {"fork", &my_write_fork},
    {"lfork", &my_write_lfork},
    {"add", &write_add},
    {"sub", &write_sub},
    {"and", &write_and},
    {"xor", &write_xor},
    {"or", &write_or},
    {"aff", &write_aff},
    {"ld", &my_write_ld},
    {"st", &my_write_st},
    {"ldi", &write_ldi},
    {"sti", &write_sti},
    {"lld", &write_lld},
    {"lldi", &write_lldi},
    {NULL, NULL}
  };

char	*write_in_buff(char **cmd, int *len, char *dest)
{
  int	i;
  int	j;
  int	x;
  char	*big_buff;

  *len = 0;
  i = 0;
  while (cmd[i])
    {
      j = 0;
      while (tab[j].cmd)
	{
	  x = my_strcmp(cmd[i], tab[j].cmd);
	  j++;
	}
      big_buff = tab[j].ptr(cmd[i + 1], len);
      strncat(dest, big_buff, len);
      //      free(big_buff);
      big_buff = dest;
      i += 2;
    }
  return (big_buff);
}
