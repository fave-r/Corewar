/*
** fill_header.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Tue Mar  4 16:53:28 2014
** Last update Thu Mar 13 10:17:50 2014 Thibaut Lopez
*/

#include "struct.h"
#include "my.h"

header_t	*fill_header(char *name, char *comment)
{
  int		i;
  header_t	*new;

  i = 0;
  new = xmalloc(sizeof(header_t));
  new->magic = COREWAR_EXEC_MAGIC;
  while (i < my_strlen(name) && i < PROG_NAME_LENGTH)
    {
      new->prog_name[i] = name[i];
      i++;
    }
  new->prog_name[i] = 0;
  i = 0;
  while (i < my_strlen(comment) && i < COMMENT_LENGTH)
    {
      new->comment[i] = comment[i];
      i++;
    }
  new->comment[i] = 0;
  return (new);
}
