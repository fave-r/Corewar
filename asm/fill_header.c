/*
** fill_header.c for fill_header in /home/odet_a/work/Corewar/asm
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Wed Feb 26 11:34:10 2014 
** Last update Wed Feb 26 15:25:36 2014 
*/

#include "struct.h"

header_t	*fill_header(header_t *ptr, char *str)
{
  header_t	*new;

  printf("str = %s\n", str);
  new = xmalloc(sizeof(header_t));
  new->magic = COREWAR_EXEC_MAGIC;
  //  new->prog_name = str;
  return (new);
}
