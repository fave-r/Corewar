/*
** recup.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Feb 25 18:56:54 2014 romaric
** Last update Tue Apr  1 14:18:49 2014 alex-odet
*/

#include "struct.h"
#include "op.h"
#include "my.h"

char	*recup_name(char *str)
{
  int	i;
  int	j;
  char	*save;

  save = xmalloc(PROG_NAME_LENGTH * sizeof(char));
  i = 0;
  j = 0;
  while (str[i] != '"')
    i++;
  while (str[++i] != '"' && count_dot(str, i, '"') >= 1)
    {
      save[j] = str[i];
      j++;
    }
  save[j] = '\0';
  return (save);
}
