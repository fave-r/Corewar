/*
** check_cmdini.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Apr  8 15:28:07 2014 romaric
** Last update Tue Apr  8 15:59:00 2014 romaric
*/

#include "struct.h"

void	check_cmdini(int *i, int *fd, char *cmd, char *str)
{
  *i = 0;
  *fd = xopen(str, O_RDONLY);
  cmd = NULL;
}

void	check_cmdnext(char *tmp, char *cmd, int *i)
{
  my_printf(1, "%s\n", tmp);
  if (tmp[0] == '\t' || my_strchr(':', tmp) != -1)
    cmd = cmd_exist(tmp, &(*i));
}
