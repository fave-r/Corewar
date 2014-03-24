/*
** init.c for init in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Mon Mar 10 15:58:46 2014 alex-odet
** Last update Mon Mar 24 11:36:12 2014 romaric
*/

#include "struct.h"

header_t	*init()
{
  header_t	*p;
  int		i;

  p = xmalloc(sizeof(header_t));
  i = 0;
  p->magic = 0;
  while (i < PROG_NAME_LENGTH + 1)
    {
      p->prog_name[i] = 0;
      i++;
    }
  p->prog_name[i] = 0;
  i = 0;
  p->prog_size = 0;
  while (i < COMMENT_LENGTH + 1)
    {
      p->comment[i] = 0;
      i++;
    }
  p->comment[i] = 0;
  return (p);
}
