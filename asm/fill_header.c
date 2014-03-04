/*
** fill_header.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Tue Mar  4 16:53:28 2014
** Last update Tue Mar  4 17:26:01 2014 romaric
*/

#include "struct.h"

header_t	*fill_header(header_t *ptr, char *str)
{
  header_t	*new;

  printf("str = %s\n", str);
  new = xmalloc(sizeof(header_t));
  new->magic = COREWAR_EXEC_MAGIC;
  new->prog_name = str;
  return (new);
}
