/*
** fill_header.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Tue Mar  4 16:53:28 2014
** Last update Mon Mar 10 14:18:21 2014 alex-odet
*/

#include "struct.h"

header_t	*fill_header(char *str)
{
  int		i;
  header_t	*new;

  i = 0;
  new = xmalloc(sizeof(header_t));
  new->magic = COREWAR_EXEC_MAGIC;
  while (i < my_strlen(str))
    {
      new->prog_name[i] = str[i];
      i++;
    }
  new->prog_name[i] = 0;
  return (new);
}
