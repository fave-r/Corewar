/*
** cmd.c for cmd in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  2 13:49:55 2014 alex-odet
** Last update Sat Apr 12 23:49:42 2014 alex-odet
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

void	write_in_buff(char **cmd, int *len, int fd)
{
  int	j;

  *len = 0;
  j = 0;
  if (cmd[0] != NULL)
    while (j < 15)
      {
	if ((my_strcmp(cmd[0], tab[j].cmd)) == 0)
	  tab[j].ptr(cmd[1], len, fd);
	j++;
      }
}
